/**
  ******************************************************************************
  * @file    network_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-10-15T11:06:33+0530
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "network_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_network_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_network_weights_array_u64[411] = {
  0x3dec51b73f048aefU, 0x3e1cc9c8beba160dU, 0xbe25a9a5bf05f7faU, 0xbf14232abe54337cU,
  0xbf0646bebf308beaU, 0xbf19b0aabed96148U, 0xbe8254abbe84acd1U, 0x3f25084dbebb0a70U,
  0xbe9ae0383dbd473fU, 0xbefaad1dbd378fe2U, 0x3e8bc60cbee4dde0U, 0x3da75dc4beb98a19U,
  0x3ec9df373e88b436U, 0x3e80937a3d9de1c7U, 0xbef1da08bea9479aU, 0x3ed8f52b3f83e9cbU,
  0x3e5d68ab3f2e7434U, 0xbe9be29c3f0e9d03U, 0xbd9a11083e3291b4U, 0x3f0c14063f1d99b6U,
  0xbe4fd83f3e833a86U, 0x3e88c641beb1ab22U, 0x3e4930aa3eacaaccU, 0x3f11e19a3e636ae0U,
  0x3e4f0f283f1dad02U, 0x3dfc1f5c3ec241f1U, 0x3ed4cfbf3ebb8e59U, 0x3b46557b3e869404U,
  0xbe2f33ca3e1ff04cU, 0x3e5aa8d8be4ae38aU, 0x3eac9b543d8c783bU, 0x3df4f461be4e9065U,
  0xbea99cff3f174545U, 0x3e24d8603da39541U, 0x3e9d699f3e85b049U, 0x3e582396be44ccf6U,
  0x3e5a15ce3d851883U, 0xbe30412a3e8f190cU, 0xbd66441e3ec74992U, 0x3e16f9c2bed2429dU,
  0xbe34a658bde0ca57U, 0x3e074e40bdbe943fU, 0xbe45a1303ec9ac8dU, 0x3e0340eabe8d99c8U,
  0xbdeb2344be8bfb27U, 0xbe54096ebe2cb57eU, 0xbe3c33623dea5aacU, 0x3f0011c33e3a5dc8U,
  0xbee60f223f202753U, 0x3f297c1bbf079085U, 0x3f50b4743d0e2b82U, 0xbe8346243ec25a8cU,
  0xbdde930c3eea53fcU, 0x3f3100cdbe208affU, 0x3efd7ebebe35191dU, 0xbe9dab2ebe958934U,
  0x3ede237f3f00691cU, 0x3ef49dd4bdb71c2aU, 0x3ef4ffd2bc904503U, 0xbeae6d79bf35d6f8U,
  0x3dc340203ecab50bU, 0x3eb92f49bdddc342U, 0x3eddc5843dfc5b2eU, 0x3e46cb733e49a580U,
  0xbe95a4573e411787U, 0xbd0877673e0240a0U, 0x3c405c7a3eddacc6U, 0x3e8d52633d014d95U,
  0x3e328da43e0f20feU, 0x3dfd99f53dae5809U, 0x3cbba1d0bd003a6aU, 0x3e94442bbdf72a95U,
  0x3f33a5ce3f7589f9U, 0x3f89f5413eab31edU, 0x3f8730a4be6af5b5U, 0xbe16a4ba3f87a209U,
  0xbe59abf1bdd4d802U, 0x3d1f4d893e84d7ceU, 0x3ecd32663eec2a0aU, 0xbf82b4103e6e6b1bU,
  0xbf8bb183bf01faaeU, 0xbda5b91cbf0c1dc2U, 0xbe2f71a1bccfd9beU, 0xbfd8e5ecbecf25d3U,
  0x3efbbd023d430121U, 0x3e9e3533bc6c4647U, 0x3e008dbf3df688adU, 0x3c6108c8beaf21ffU,
  0x3edd8f823eeb9098U, 0x3e3fb8993ed4d69bU, 0x3efc4e283eb541bbU, 0xbe1dc758bdba71bdU,
  0x3eb96d073ef430d7U, 0x3ea790a1bd337e7eU, 0x3e354dca3ef398b5U, 0xbe40dfb7bc824b1aU,
  0xbfb4e7ad3d8e72d8U, 0xbd1486a5bfc0e1d0U, 0xbeb0c3253be96efdU, 0x3e833c2a3f0402a9U,
  0xbfe2c9c1bec59301U, 0xbf0f9fa8bf00ea7bU, 0xbf5d6b3cbef8565dU, 0x3ef4db603e899afaU,
  0xbc5a5fb8bf0e4152U, 0xbf6ecf00bf37a6f6U, 0xbf4f7b35becb1150U, 0x3ed84e303e6349deU,
  0x3e90144a3e619a4aU, 0x3e6e830abca408f6U, 0x3ea2e06f3e3104b9U, 0xbdc3e5343d504e08U,
  0xbe86735a3da583d5U, 0x3d0468e13e44b2c0U, 0xbe3e96c33ea654abU, 0xbe273d113defe5baU,
  0xbda192f63ea22488U, 0x3e9af4adbe9fbbafU, 0xbd2048783d49c626U, 0xbe2a71643e1b96a2U,
  0xbf1edf02bcb9d396U, 0x3e7b2e24bf626ed1U, 0x3e27553cbe292a62U, 0x3e7c89a23efa74a8U,
  0xbfa946aabebd8743U, 0xbe597cb63ddfded0U, 0xbf4963c83ec59c3eU, 0xbd585d7e3e831e25U,
  0xbf2c4448bf32a915U, 0xbf3c806cbf458bc9U, 0xbf2b2c593e9b0854U, 0x3de8e2cb3da7bb64U,
  0x3ec7404e3dd27485U, 0x3f0801563ebe5117U, 0x3d142fae3e4cf8e1U, 0xbe8607b5be9c3bf1U,
  0x3ed2c8443d35dc80U, 0x3e5ba9c53e9f13caU, 0x3d93756d3e880440U, 0xbe9ec481bb8d7e26U,
  0xbcc78a733ef8789dU, 0x3ec0a3c7bdf5e12bU, 0x3f01afb43ed67ec1U, 0xbb21064c3d24b8c1U,
  0x3c2d59593b3f8d74U, 0x3e2179f83d3b8a08U, 0xbe28edab3eaad89bU, 0xbf106b83bed87cffU,
  0x3e322b1abe05875bU, 0xbde565683d8f123eU, 0xbd2b75ce3e6f23cdU, 0xbf02d625bec8f1fdU,
  0xbdd75444bd8675a1U, 0xbd11bc5e3ddcee57U, 0xbb858d763ed83004U, 0xbe2fb5e13deb8336U,
  0xbe0ebef63eac18b5U, 0x3dfa3b573e934d63U, 0x3f00a1ae3f154e51U, 0xbe474264bd740675U,
  0xbe7819173e2794ebU, 0x3eb95ddf3dc829dbU, 0xbde75c203eaa2702U, 0xbda9fce93df573f1U,
  0xbdb857f73df86e70U, 0x3ee17cb8be223dd0U, 0x3e0d73043f01e330U, 0xbd3bd058bd1f95d1U,
  0x3e44b133bd445494U, 0x3cbd382a3e6175b3U, 0xbebd65f13e100d98U, 0x3da44c7ebe2ac243U,
  0x3ea77edebc588e2eU, 0xbe7f53603e96008aU, 0x3cf2b480bd07affcU, 0x3d478668be3b8191U,
  0x3e9c45b03e0f9589U, 0xbe96a7003ebd187bU, 0xbe95e27abc41fe0aU, 0xbeae8187bdf88ca0U,
  0x3e76bc0abdd9eecdU, 0xbea25ca53eebb897U, 0x3deb440dbee98291U, 0x3f15e82abf11ed23U,
  0x3e30b2513e504ef3U, 0x3e38be98bd6de5abU, 0x3d7e0ff5becaa67aU, 0x3eb4bc2e3f05dc65U,
  0x3f17f96dbd996c2eU, 0x3c1ae5503e3891faU, 0xbda25ad6bea21393U, 0x3ed44878bf99711cU,
  0xbe82c28e3c438907U, 0xbea10541beb1b75cU, 0xbdb61ca03dcc6ee4U, 0x3dbfd287bea1dc6eU,
  0x3e1c070e3d8bcdfcU, 0xbd47fcc73dad8f07U, 0x3e70669bbd18e62aU, 0x3e8b44913c83dd0eU,
  0xbc10f325bd4e0240U, 0x3dfad00a3eb187d8U, 0x3dbe2eed3e61c669U, 0x3eb520c03dfa9f5aU,
  0x3e35d9153d008052U, 0x3e925251bd247d48U, 0x3d0b3f04be59c723U, 0xbef11c693e63a457U,
  0x3e86e29e3e4caaeaU, 0x3ecb9cbf3e26fcf8U, 0x3e91d668bd88dc35U, 0xbef9ea55beb4ac1dU,
  0x3da61ca13ed8bbdbU, 0x3e2414f43e846e41U, 0x3e253f053e15aaf7U, 0xbf3dafd2be51b2b9U,
  0x3dd8ce803e85ae95U, 0x3dce885b3c282b56U, 0x3e852d92bf439c59U, 0x3d136d3f3e84d157U,
  0x3e7c7dcc3eafec99U, 0x3e4ae09a3e8a16cbU, 0xbf049dd3be205c9eU, 0x3e5ac37f3b2de822U,
  0x3d27ebf93eeca271U, 0x3e513365bf6713a1U, 0x3e5eb8ee3fd18bd1U, 0x3ccd8a64bf49e505U,
  0xbd5a37fbbf05e4e7U, 0x3f0edb083d8efe19U, 0xbed16efdbe428073U, 0xbcec0808beb164d7U,
  0x3c3ae9ce3d7104f8U, 0x3e8fc6503e9e659dU, 0x3e311e353fd5cd72U, 0xbe56fae4be583354U,
  0x3e86b111bf701375U, 0xbd3605c63d5bc532U, 0xbf3699debe884331U, 0x3ea138fa3c255645U,
  0xbd5dee683e0beb38U, 0xbf0843493f447fa2U, 0xbd2a26293fa19f60U, 0x3d84827abf18dbd4U,
  0x3e819fadbf6cebecU, 0x3f096d523ec42e8aU, 0xbe95ecef3e65a174U, 0x3e461534bf679630U,
  0x3d8822e3beaf206fU, 0xbde99a743fb91bd9U, 0xbf82bb2640232b6fU, 0x3edde97fbe1b7671U,
  0xbf012d4d3ed1c8f5U, 0x3e4ef451be5df072U, 0xbfb8cb6abf9a98b0U, 0xbf5521b43ee165f4U,
  0xbf49a641be7e13e2U, 0xbe717c013f0840c5U, 0x3aa4dfdfbf01a5b1U, 0xbd293b2a3eeaf83cU,
  0xbdca8d653e8ae29cU, 0x3e07b796bddf5dbfU, 0xbe8bceb0bd9effe5U, 0x3eceb967be2aa9c3U,
  0x3e8a28123e88259bU, 0xbe47ecef3e789f58U, 0x3e9dcd5d3fe0733aU, 0x3e7533f6bfbcb9fbU,
  0x3ecaea26bf2422d7U, 0xbd051b233ec532a3U, 0xbf0e64f1bdf8e0a0U, 0xbd9ba536bec87be2U,
  0xbede21e6beb9cbe8U, 0xbe83577cbf00db87U, 0x3c8a9eeb3f369357U, 0xbea8d982bd8c95a2U,
  0x3e6703f93ebefc2dU, 0xbeeac5cc3e23fddeU, 0x3ecdaf40be87c9e2U, 0x3e82e16cbe0f7559U,
  0xbe765aa1bd7de60bU, 0xbeba2301be74cb10U, 0xbecc5500be92b3ccU, 0xbe23c42abe3ddafbU,
  0xbe271e483ebf5cb3U, 0x3ce51380bd0bbcdfU, 0xbee10bf23e965684U, 0x3e3420dd3df1e1e9U,
  0xbebf81f9bedd1e14U, 0x3e05b4673d5c6e02U, 0xbe8f584fbe42a15fU, 0xbed9af893de9f53bU,
  0xbd9e482dbe112e75U, 0x3e4c66773eae3fb7U, 0xbe4d27133e0b7468U, 0xbce3b30bbd95da25U,
  0x3e8a1673beac4f04U, 0xbec68d933ecde645U, 0xbb847000bedbe7bdU, 0xbdb9953cbd0ea198U,
  0xbd2e7868be7ba067U, 0x3eae5ff9bdd238ecU, 0xbe294a0cbd3bb010U, 0x3e4e12b2bebc2086U,
  0x3e524431be14618aU, 0x3e6a3222be9b8218U, 0xbe91382cbe6a3d13U, 0x3e1da2f8beb4dec6U,
  0xbe2d1c223e9a9451U, 0xbe4f84e03b5b7881U, 0xbde1f9d4be361bc5U, 0x3e8ddcdbbe862f1bU,
  0x3dfd1bee3e816ca2U, 0xbbe5bfdebf4e0fc2U, 0xbe268daf3fd79344U, 0x3eb1b04dbeb5938cU,
  0xbddbd71bbe1cb593U, 0x3ee001d63eb64268U, 0xbecbdca53e975474U, 0x3e7a755b3e855ed8U,
  0x3f07c21d3e18370aU, 0x3f00f3403ef6f1aeU, 0xbefacbbb3fa4b95eU, 0x3ec1ad86be85099bU,
  0xbf703d61be98bfe8U, 0x3f1216e4bf328999U, 0xbf9970d3bf483dc7U, 0xbf35762e3ea1d75eU,
  0xbd9ceb953f3a233bU, 0x3d79fd3dbe9737d8U, 0xbf0574593faa765cU, 0x3e081441bf020e09U,
  0xbdccd93f3c6a9fe6U, 0x3f153d563d9bdc3dU, 0xbe209b1bbcfab467U, 0xbf25c2f7bde3001cU,
  0x3bec14b0bde3e5c6U, 0xbd564d6b3f3e669aU, 0xbe33c93a3f8ad20aU, 0x3e5aabeb3ec5f6b9U,
  0xbeeb559a3e80052dU, 0xbeaa8e85bde8783aU, 0xbf13562bbd0fa0e8U, 0xbe57f34b3eeee446U,
  0x3f3182edbf0aeaacU, 0xbecfe37e3f844538U, 0xbe690ad83cd6fd80U, 0xbdd8fdb53ec69c2eU,
  0x3e93aa8e3de23a47U, 0xbef8d8663ea30df4U, 0x3f07a4913ec4cd6cU, 0xbe0ba4ef3ea5f21fU,
  0xbc2a87303e0c7debU, 0xbe596c093de8b785U, 0xbdd17f543d06345eU, 0xbc0ada54bcee3022U,
  0xbcddecabU, 0x3e1bff4bbbc4be4dU, 0x3e3883983e16951dU, 0xbeaa3999bdf3ac8dU,
  0xbf8a0e413ea60cf4U, 0xbfb158ebbf6fefc4U, 0xbf57a47dbf05cdf7U, 0xbe911e41beab7de3U,
  0xbef75a2abe6a8c10U, 0x3da85422be6b0100U, 0x3ec92ac93e23b770U, 0x3f1d4cc9be8c7bddU,
  0xbf3b2478bf1a1a27U, 0xbecd401abf2a07c1U, 0xbeda94eb3e46a89aU, 0x3eb390c13d50bf5fU,
  0xbe4885583e9417c6U, 0x3c565b6e3de3f834U, 0xbf811df3bef51817U, 0xbf81885e3e54ce56U,
  0x3ef4d87a3f90f3e4U, 0x3f54e16a3ea2fcb4U, 0x3f04b6dcbc795a2eU, 0xbec9c985bdc898eeU,
  0xbdfa4cacbd9a4191U, 0x3f4d16adbec7d4ceU, 0x3ec6ec7d3f0a8d28U, 0xbed45dfa3ef0b553U,
  0xbe856d44be117909U, 0x3e8d4a51bdb57508U, 0x3e127c443db606f9U, 0x3eedfe3c3ead884eU,
  0xbeb56bec3ef856bdU, 0xbe60d354be34f910U, 0xbda02d8b3e1b6d32U, 0xbe9d788f3eb67682U,
  0x3edbdad2bf32d68cU, 0xbce370db3e9ea18eU, 0x3eaa3b78bf29f943U, 0xbbc8e06cbf3ff71eU,
  0xbebb4cb43db43117U, 0xbf157caf3e8de283U, 0xbf8e220fbf42e70eU, 0x3dbae60cbf46241cU,
  0xbf365afcbfc8eb37U, 0xbf9d2582bf512f80U, 0xbf30d6413f0573adU, 0xbedd85813e89a0f2U,
  0x3df713683e1d8fbeU, 0xbfc5b44a3e7ab011U, 0xbff47681bf7ca310U, 0x3e7b7b923e1cc0c9U,
  0x3f562dee3e89b1ffU, 0xbf449ad4be7ccabdU, 0x3e150638bed66105U,
};


ai_handle g_network_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_network_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

