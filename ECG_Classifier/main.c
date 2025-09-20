/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Final clean version for ECG classification.
  ******************************************************************************
  * @attention
  *
  * This code contains a single test case (a Normal Beat) and prints both
  * the prediction and its confidence level to the serial monitor.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_x-cube-ai.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include <math.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#ifndef HSEM_ID_0
#define HSEM_ID_0 (0U)
#endif


#define WINDOW_LENGTH 180   /*  Must match model input length from training */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim16;
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
/* Class labels for your 5 ECG categories */
static const char *class_symbol[5] = { "N", "S", "V", "F", "Q" };
static const char *class_name[5] = {
  "Normal Beat",
  "Supraventricular Ectopic Beat",
  "Ventricular Ectopic Beat",
  "Fusion Beat",
  "Unknown / Other"
};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_TIM16_Init(void);
void MX_USART3_UART_Init(void);

/* USER CODE BEGIN PFP */
void classify_and_print(const float *ecg_window);
void normalize_window(float *window, int length);
extern int ai_run_classification(const float *in_data, float *out_data);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* Helper function to print to the correct UART */
static void uart_print(const char *msg)
{
  HAL_UART_Transmit(&huart3, (uint8_t*)msg, (uint16_t)strlen(msg), HAL_MAX_DELAY);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/
  SCB_EnableICache();
  SCB_EnableDCache();
  HAL_Init();
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM16_Init();
  MX_USART3_UART_Init();

  /* Initialize the AI Engine */
  MX_X_CUBE_AI_Init();

  /* USER CODE BEGIN 2 */
  uart_print("\r\n\r\nSTM32H755ZI-Q ECG Classifier Initialized\r\n");
  uart_print("----------------------------------------\r\n");
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

    // --- Define a single input signal for classification ---
    // This is a known "Ventricular Ectopic Beat" from sample #527 of 231.csv file in MIT-BIH dataset.
    static const float sample_ecg_input[WINDOW_LENGTH] = {
      988.0f, 988.0f, 988.0f, 989.0f, 990.0f, 992.0f, 993.0f, 994.0f,
      996.0f, 997.0f, 998.0f, 999.0f, 1000.0f, 1000.0f, 1001.0f, 1001.0f,
      1001.0f, 1001.0f, 1002.0f, 1002.0f, 1002.0f, 1002.0f, 1002.0f, 1002.0f,
      1002.0f, 1002.0f, 1002.0f, 1002.0f, 1002.0f, 1002.0f, 1001.0f, 1001.0f,
      1000.0f, 999.0f, 997.0f, 996.0f, 995.0f, 994.0f, 993.0f, 993.0f,
      992.0f, 991.0f, 990.0f, 990.0f, 990.0f, 990.0f, 990.0f, 991.0f,
      991.0f, 992.0f, 992.0f, 992.0f, 993.0f, 994.0f, 994.0f, 994.0f,
      994.0f, 994.0f, 994.0f, 994.0f, 994.0f, 994.0f, 994.0f, 994.0f,
      994.0f, 994.0f, 994.0f, 995.0f, 996.0f, 997.0f, 998.0f, 999.0f,
      1000.0f, 1001.0f, 1002.0f, 1002.0f, 1003.0f, 1004.0f, 1004.0f, 1005.0f,
      1006.0f, 1007.0f, 1009.0f, 1010.0f, 1013.0f, 1019.0f, 1028.0f, 1042.0f,
      1059.0f, 1073.0f, 1080.0f, 1077.0f, 1063.0f, 1042.0f, 1018.0f, 996.0f,
      979.0f, 967.0f, 959.0f, 954.0f, 951.0f, 950.0f, 949.0f, 949.0f,
      950.0f, 952.0f, 953.0f, 955.0f, 956.0f, 958.0f, 959.0f, 960.0f,
      962.0f, 963.0f, 964.0f, 965.0f, 966.0f, 967.0f, 967.0f, 967.0f,
      967.0f, 967.0f, 968.0f, 968.0f, 968.0f, 968.0f, 968.0f, 968.0f,
      968.0f, 968.0f, 968.0f, 968.0f, 968.0f, 968.0f, 968.0f, 968.0f,
      968.0f, 968.0f, 968.0f, 969.0f, 969.0f, 970.0f, 970.0f, 970.0f,
      970.0f, 971.0f, 972.0f, 972.0f, 972.0f, 973.0f, 974.0f, 974.0f,
      974.0f, 974.0f, 974.0f, 974.0f, 974.0f, 974.0f, 974.0f, 974.0f,
      974.0f, 974.0f, 974.0f, 974.0f, 974.0f, 974.0f, 974.0f, 974.0f,
      974.0f, 974.0f, 974.0f, 974.0f, 974.0f, 974.0f, 974.0f, 974.0f
    };

    // Classify the input data and print the results.
    uart_print("\r\n--- Classifying Sample ECG Beat ---\r\n");
    classify_and_print(sample_ecg_input);

    // Wait for 5 seconds
    HAL_Delay(5000);

  }
  /* USER CODE END 3 */
}

/**
  * @brief  Normalizes an ECG window (makes its mean=0 and standard deviation=1).
  */
void normalize_window(float *window, int length)
{
  if (length <= 1) return;

  double sum = 0.0;
  for (int i = 0; i < length; ++i) {
    sum += window[i];
  }
  float mean = (float)(sum / length);

  double sum_sq_diff = 0.0;
  for (int i = 0; i < length; ++i) {
    float diff = window[i] - mean;
    sum_sq_diff += diff * diff;
  }
  float std_dev = (float)sqrt(sum_sq_diff / length) + 1e-6f;

  for (int i = 0; i < length; ++i) {
    window[i] = (window[i] - mean) / std_dev;
  }
}

/**
  * @brief  The core classification and printing logic.
  */
void classify_and_print(const float *ecg_window)
{
  char buf[128];
  int class_id = -1;
  static float ai_output_buffer[5];
  static float processed_input[WINDOW_LENGTH];

  // Step 1: Copy input data to a modifiable buffer
  memcpy(processed_input, ecg_window, WINDOW_LENGTH * sizeof(float));

  // Step 2: Pre-process the data by normalizing it
  normalize_window(processed_input, WINDOW_LENGTH);

  // Step 3: Run inference
  class_id = ai_run_classification(processed_input, ai_output_buffer);

  // Step 4: Print the results
  if (class_id >= 0 && class_id < 5) {
    // Convert confidence (float) to percentage (integer) for printing
    int confidence_percent = (int)(ai_output_buffer[class_id] * 100);

    snprintf(buf, sizeof(buf), "Prediction: %s (%s) | Confidence: %d%%\r\n",
             class_name[class_id], class_symbol[class_id], confidence_percent);
  } else {
    snprintf(buf, sizeof(buf), "Error: Inference failed or returned an invalid class ID (%d).\r\n", class_id);
  }
  uart_print(buf);
}

/**
  * @brief System Clock Configuration
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);
  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 480;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLQ = 20;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_1;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) { Error_Handler(); } // Corrected line
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;
  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK) { Error_Handler(); }
}

/**
  * @brief TIM16 Initialization Function
  */
void MX_TIM16_Init(void)
{
  htim16.Instance = TIM16;
  htim16.Init.Prescaler = 480-1;
  htim16.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim16.Init.Period = 65535;
  htim16.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim16.Init.RepetitionCounter = 0;
  htim16.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim16) != HAL_OK) { Error_Handler(); }
}

/**
  * @brief USART3 Initialization Function
  */
void MX_USART3_UART_Init(void)
{
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart3.Init.ClockPrescaler = UART_PRESCALER_DIV1;
  huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart3) != HAL_OK) { Error_Handler(); }
  if (HAL_UARTEx_SetTxFifoThreshold(&huart3, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK) { Error_Handler(); }
  if (HAL_UARTEx_SetRxFifoThreshold(&huart3, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK) { Error_Handler(); }
  if (HAL_UARTEx_DisableFifoMode(&huart3) != HAL_OK) { Error_Handler(); }
}

/**
  * @brief GPIO Initialization Function
  */
void MX_GPIO_Init(void)
{
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
}

/* USER CODE BEGIN 4 */

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/**
  * @brief  Retargets the C library printf function to the USART.
  */
PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
  return ch;
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  */
void Error_Handler(void)
{
  __disable_irq();
  while (1) {}
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif /* USE_FULL_ASSERT */
