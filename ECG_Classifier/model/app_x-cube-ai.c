/**
  ******************************************************************************
  * @file    app_x-cube-ai.c
  * @brief   AI program body - ECG 5-class classifier (clean)
  ******************************************************************************
  */
#ifdef __cplusplus
 extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "app_x-cube-ai.h"
#include "bsp_ai.h"
#include "aiSystemPerformance.h"
#include "ai_datatypes_defines.h"

/* Include generated network headers (adjust names if different) */
#include "network_data.h"
#include "network.h"

/* Derive NUM_INPUTS/NUM_CLASSES from generated macros */
#ifndef NUM_INPUTS
  #if defined(AI_NETWORK_IN_1_SIZE)
    #define NUM_INPUTS (AI_NETWORK_IN_1_SIZE)
  #elif defined(AI_NETWORK_IN_1_SIZE_BYTES)
    #define NUM_INPUTS (AI_NETWORK_IN_1_SIZE_BYTES / sizeof(float))
  #else
    #error "NUM_INPUTS not defined: check network_data.h"
  #endif
#endif

#ifndef NUM_CLASSES
  #if defined(AI_NETWORK_OUT_1_SIZE)
    #define NUM_CLASSES (AI_NETWORK_OUT_1_SIZE)
  #elif defined(AI_NETWORK_OUT_1_SIZE_BYTES)
    #define NUM_CLASSES (AI_NETWORK_OUT_1_SIZE_BYTES / sizeof(float))
  #else
    #error "NUM_CLASSES not defined: check network_data.h"
  #endif
#endif

/* NOTE: DEF_DATA_IN / DEF_DATA_OUT macro in app_x-cube-ai.h expands to define
   the data_ins / data_outs arrays. We declare them extern and then expand the macro. */
extern ai_i8* data_ins[];
extern ai_i8* data_outs[];

DEF_DATA_IN
DEF_DATA_OUT

/* Activations */
AI_ALIGNED(32)
static uint8_t pool0[AI_NETWORK_DATA_ACTIVATION_1_SIZE];
ai_handle data_activations0[] = {pool0};

/* Externs for generated network runtime objects (provided by network.c/h) */
extern ai_handle network;
extern ai_buffer* ai_input;
extern ai_buffer* ai_output;

/* Class labels */
const char* ecg_labels[NUM_CLASSES] = {
    "N: Normal beat",
    "S: Supraventricular ectopic beat",
    "V: Ventricular ectopic beat",
    "F: Fusion beat",
    "Q: Unknown beat"
};

/* Stable softmax */
static void softmax_stable(const float *vals, float *probs, int n)
{
    float maxv = vals[0];
    for (int i = 1; i < n; ++i) if (vals[i] > maxv) maxv = vals[i];

    float sum = 0.0f;
    for (int i = 0; i < n; ++i) {
        float e = expf(vals[i] - maxv);
        probs[i] = e;
        sum += e;
    }
    if (sum <= 0.0f) {
        float u = 1.0f / n;
        for (int i = 0; i < n; ++i) probs[i] = u;
        return;
    }
    for (int i = 0; i < n; ++i) probs[i] /= sum;
}

/* External application-provided data buffer and index (define these in main.c) */
extern const float *ecg_sample_inputs;
extern int global_index;

int acquire_and_process_data(ai_i8* data[])
{
    if (!data || !data[0]) {
        printf("acquire_and_process_data: invalid buffers\r\n");
        return -1;
    }
    if (!ecg_sample_inputs) {
        printf("acquire_and_process_data: ecg_sample_inputs NULL\r\n");
        return -1;
    }

    float* input_data = (float*)data[0];
    for (int i = 0; i < NUM_INPUTS; ++i) input_data[i] = ecg_sample_inputs[i];
    return 0;
}

int post_process(ai_i8* data[])
{
    if (!data || !data[0]) {
        printf("post_process: invalid buffers\r\n");
        return -1;
    }
    float* out = (float*)data[0];
    float raw[NUM_CLASSES];
    float probs[NUM_CLASSES];
    for (int i=0;i<NUM_CLASSES;i++) raw[i] = out[i];

    softmax_stable(raw, probs, NUM_CLASSES);

    int pred = 0;
    float maxp = probs[0];
    for (int i=1;i<NUM_CLASSES;i++){
        if (probs[i] > maxp){ maxp = probs[i]; pred = i; }
    }

    printf("---- ECG Sample %d ----\r\n", global_index);
    for (int i=0;i<NUM_CLASSES;i++){
        printf("Class %d (%s): prob=%.6f  raw=%.6f\r\n", i, ecg_labels[i], probs[i], out[i]);
    }
    printf("PREDICTION -> %d (%s) with probability %.6f\r\n", pred, ecg_labels[pred], maxp);
    printf("-------------------------\r\n\r\n");

    return pred;
}

/* Minimal bootstrap/run routines that call the generated functions */
static void ai_log_err(const ai_error err, const char *fct)
{
  if (fct) printf("AI - Error (%s) - type=0x%02x code=0x%02x\r\n", fct, err.type, err.code);
  else printf("AI - Error - type=0x%02x code=0x%02x\r\n", err.type, err.code);
  for (;;) {}
}

static int ai_boostrap(ai_handle *act_addr)
{
  ai_error err = ai_network_create_and_init(&network, act_addr, NULL);
  if (err.type != AI_ERROR_NONE) { ai_log_err(err, "ai_network_create_and_init"); return -1; }

  ai_input = ai_network_inputs_get(network, NULL);
  ai_output = ai_network_outputs_get(network, NULL);

#if defined(AI_NETWORK_INPUTS_IN_ACTIVATIONS)
  for (int idx=0; idx < AI_NETWORK_IN_NUM; idx++) data_ins[idx] = ai_input[idx].data;
#else
  for (int idx=0; idx < AI_NETWORK_IN_NUM; idx++) ai_input[idx].data = data_ins[idx];
#endif

#if defined(AI_NETWORK_OUTPUTS_IN_ACTIVATIONS)
  for (int idx=0; idx < AI_NETWORK_OUT_NUM; idx++) data_outs[idx] = ai_output[idx].data;
#else
  for (int idx=0; idx < AI_NETWORK_OUT_NUM; idx++) ai_output[idx].data = data_outs[idx];
#endif

  return 0;
}

static int ai_run(void)
{
  ai_i32 batch = ai_network_run(network, ai_input, ai_output);
  if (batch != 1) {
    ai_log_err(ai_network_get_error(network), "ai_network_run");
    return -1;
  }
  return 0;
}

void MX_X_CUBE_AI_Init(void)
{
    MX_UARTx_Init();
    aiSystemPerformanceInit();
    if (ai_boostrap(data_activations0) != 0) {
        printf("AI bootstrap failed\r\n");
        for(;;);
    }
    printf("AI bootstrapped OK\r\n");
}

void MX_X_CUBE_AI_Process(void)
{
    aiSystemPerformanceProcess();
    HAL_Delay(50);

    if (acquire_and_process_data(data_ins) != 0) { printf("acquire failed\r\n"); return; }
    if (ai_run() != 0) { printf("ai_run failed\r\n"); return; }
    post_process(data_outs);
}

#ifdef __cplusplus
}
#endif
