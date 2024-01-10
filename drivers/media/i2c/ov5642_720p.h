/* Settings array from
 * From 5e8e49e226b29c144ddf482afe7d3ad659c9897f Mon Sep 17 00:00:00 2001
 * From: Kazuya Nishimura <kazuya.nishimura@windriver.com>
 * Date: Mon, 20 Oct 2014 15:12:56 +0900
 * Subject: [PATCH] Enabled VIN driver for MMB
 */

/* 720p 30fps @ 1280x720 */
/* for the setting , 24MHz Mlck input and 90MHz Plck output */
/* refer to OV5642.c */

static struct regval_list OV5642_720P_30FPS[] =
{
	{0x3103, 0x93},
	{0x3008, 0x82},
	{0x3017, 0x7f},
	{0x3018, 0xfc},
	/* drive capability 4x */
	{ 0x302c, (3 << 5) | 0x02 },
	{0x3810, 0xc2},
	{0x3615, 0xf0},
	{0x3000, 0x00},
	{0x3001, 0x00},
	{0x3002, 0x00},
	{0x3003, 0x00},
	{0x3000, 0xf8},
	{0x3001, 0x48},
	{0x3002, 0x5c},
	{0x3003, 0x02},
	{0x3004, 0x07},
	{0x3005, 0xb7},
	{0x3006, 0x43},
	{0x3007, 0x37},
	{0x3011, 0x0f},	//PLL CONTROL 02 : Bit[5:0] PLL DIVP divider
	{0x3010, 0x10},	//PLL CONTROL 01 : Bit[7:4] PLL DIVS, Bit[3:0] PLL DIVM (MIPI divider ratio)
					//29-30fps
	{0x460c, 0x22},
	{0x3815, 0x04},
	{0x370d, 0x06},
	{0x370c, 0xa0},
	{0x3602, 0xfc},
	{0x3612, 0xff},
	{0x3634, 0xc0},
	{0x3613, 0x00},
	{0x3605, 0x7c},
	{0x3621, 0x09},
	{0x3622, 0x00},
	{0x3604, 0x40},
	{0x3603, 0xa7},
	{0x3603, 0x27},
	{0x4000, 0x21},
	{0x401d, 0x02},
	{0x3600, 0x54},
	{0x3605, 0x04},
	{0x3606, 0x3f},
	{0x3c01, 0x80},
	{REG_ISP_CTRL_00, 0x4f},
	{0x4300, 0x32}, /* YUV422: UYVY... */
	{0x5020, 0x04},
	{0x5181, 0x79},
	{0x5182, 0x00},
	{0x5185, 0x22},
	{0x5197, 0x01},
	{REG_ISP_CTRL_01, 0xff},
	{0x5500, 0x0a},
	{0x5504, 0x00},
	{0x5505, 0x7f},
	{0x5080, 0x08},
	{0x300e, 0x18},
	{0x4610, 0x00},
	{0x471d, 0x05},
	{0x4708, 0x06},
	/* POLARITY CTRL 00 
	 * [0] VSYNC - act low
	 * [1] HREF - act low
	 * [2] gate PCLK under HREF - no
	 * [3] gate PCLK under VSYNK - no
	 * [5] PCLK - falling edge
	 */
	{0x4740, 0x20},
	{0x3710, 0x10},
	{0x3632, 0x41},
	{0x3702, 0x40},
	{0x3620, 0x37},
	{0x3631, 0x01},
	{REG_OUT_WIDTH_HIGH, 0x02},	// TIMING DVPHO Bit[3:0] DVP output horizontal width high byte
	{REG_OUT_WIDTH_LOW, 0x80},	// TIMING DVPHO Bit[7:0] DVP output horizontal width low byte
					// 0x280 => 640
	{REG_OUT_HEIGHT_HIGH, 0x01},	// TIMING DVPVO Bit[3:0] DVP output vertical height high byte
	{REG_OUT_HEIGHT_LOW, 0xe0},	// TIMING DVPVO Bit[7:0] DVP output vertical height low byte
					// 0x1e0 => 480
	{REG_OUT_TOTAL_HEIGHT_HIGH, 0x07},	// TIMING VTS Bit[3:0] Total vertical size high byte [11:8]
	{REG_OUT_TOTAL_HEIGHT_LOW, 0xd0},	// TIMING VTS Bit[7:0] Total vertical size low byte [7:0]
             	// 0x7d0 => 2000
	{0x501f, 0x00},
	{REG_ISP_CTRL_00, 0x4f},
	{REG_OUTPUT_FORMAT, 0x32},   //UYVY
	{0x3503, 0x07},
	{0x3501, 0x73},
	{0x3502, 0x80},
	{0x350b, 0x00},
	{0x3503, 0x07},
	{0x3824, 0x11},
	{0x3501, 0x1e},
	{0x3502, 0x80},
	{0x350b, 0x7f},
	{REG_OUT_TOTAL_WIDTH_HIGH, 0x0c},
	{REG_OUT_TOTAL_WIDTH_LOW, 0x80},
	{REG_OUT_TOTAL_HEIGHT_HIGH, 0x03},	// TIMING VTS Bit[3:0] Total vertical size high byte [11:8]
	{REG_OUT_TOTAL_HEIGHT_LOW, 0xe8},	// TIMING VTS Bit[7:0] Total vertical size low byte [7:0]
             	// 0x3e8 => 1000
	{0x3a0d, 0x04},
	{0x3a0e, 0x03},
	{0x3818, 0xc1},
	{0x3705, 0xdb},
	{0x370a, 0x81},
	{REG_WINDOW_START_X_LOW, 0x80},
	{0x3621, 0xc7},
	{REG_WINDOW_START_X_LOW, 0x50},
	{REG_WINDOW_START_Y_LOW, 0x08},
	{0x3827, 0x08},
	{0x3810, 0xc0},
	{REG_WINDOW_WIDTH_HIGH, 0x05},
	{REG_WINDOW_WIDTH_LOW, 0x00},
	{REG_AVG_WINDOW_END_X_HIGH, 0x05},
	{REG_AVG_WINDOW_END_X_LOW, 0x00},
	{REG_WINDOW_HEIGHT_HIGH, 0x03},
	{REG_WINDOW_HEIGHT_LOW, 0xc0},
	{REG_AVG_WINDOW_END_Y_HIGH, 0x03},
	{REG_AVG_WINDOW_END_Y_LOW, 0xc0},
	{0x3a00, 0x78},
	{0x3a1a, 0x04},
	{0x3a13, 0x30},
	{0x3a18, 0x00},
	{0x3a19, 0x7c},
	{0x3a08, 0x12},
	{0x3a09, 0xc0},
	{0x3a0a, 0x0f},
	{0x3a0b, 0xa0},
	{0x3004, 0xff},
	{0x350c, 0x07},
	{0x350d, 0xd0},
	{0x3500, 0x00},
	{0x3501, 0x00},
	{0x3502, 0x00},
	{0x350a, 0x00},
	{0x350b, 0x00},
	{0x3503, 0x00},
	{0x528a, 0x02},
	{0x528b, 0x04},
	{0x528c, 0x08},
	{0x528d, 0x08},
	{0x528e, 0x08},
	{0x528f, 0x10},
	{0x5290, 0x10},
	{0x5292, 0x00},
	{0x5293, 0x02},
	{0x5294, 0x00},
	{0x5295, 0x02},
	{0x5296, 0x00},
	{0x5297, 0x02},
	{0x5298, 0x00},
	{0x5299, 0x02},
	{0x529a, 0x00},
	{0x529b, 0x02},
	{0x529c, 0x00},
	{0x529d, 0x02},
	{0x529e, 0x00},
	{0x529f, 0x02},
	{0x3a0f, 0x3c},
	{0x3a10, 0x30},
	{0x3a1b, 0x3c},
	{0x3a1e, 0x30},
	{0x3a11, 0x70},
	{0x3a1f, 0x10},
	{0x3030, 0x0b},
	{0x3a02, 0x00},
	{0x3a03, 0x7d},
	{0x3a04, 0x00},
	{0x3a14, 0x00},
	{0x3a15, 0x7d},
	{0x3a16, 0x00},
	{0x3a00, 0x78},
	{0x3a08, 0x09},
	{0x3a09, 0x60},
	{0x3a0a, 0x07},
	{0x3a0b, 0xd0},
	{0x3a0d, 0x08},
	{0x3a0e, 0x06},
	{0x5193, 0x70},
	{0x3620, 0x57},
	{0x3703, 0x98},
	{0x3704, 0x1c},
	{0x589b, 0x04},
	{0x589a, 0xc5},
	{0x528a, 0x00},
	{0x528b, 0x02},
	{0x528c, 0x08},
	{0x528d, 0x10},
	{0x528e, 0x20},
	{0x528f, 0x28},
	{0x5290, 0x30},
	{0x5292, 0x00},
	{0x5293, 0x00},
	{0x5294, 0x00},
	{0x5295, 0x02},
	{0x5296, 0x00},
	{0x5297, 0x08},
	{0x5298, 0x00},
	{0x5299, 0x10},
	{0x529a, 0x00},
	{0x529b, 0x20},
	{0x529c, 0x00},
	{0x529d, 0x28},
	{0x529e, 0x00},
	{0x529f, 0x30},
	{0x5282, 0x00},
	{0x5300, 0x00},
	{0x5301, 0x20},
	{0x5302, 0x00},
	{0x5303, 0x7c},
	{0x530c, 0x00},
	{0x530d, 0x0c},
	{0x530e, 0x20},
	{0x530f, 0x80},
	{0x5310, 0x20},
	{0x5311, 0x80},
	{0x5308, 0x20},
	{0x5309, 0x40},
	{0x5304, 0x00},
	{0x5305, 0x30},
	{0x5306, 0x00},
	{0x5307, 0x80},
	{0x5314, 0x08},
	{0x5315, 0x20},
	{0x5319, 0x30},
	{0x5316, 0x10},
	{0x5317, 0x08},
	{0x5318, 0x02},
	{0x5380, 0x01},
	{0x5381, 0x00},
	{0x5382, 0x00},
	{0x5383, 0x4e},
	{0x5384, 0x00},
	{0x5385, 0x0f},
	{0x5386, 0x00},
	{0x5387, 0x00},
	{0x5388, 0x01},
	{0x5389, 0x15},
	{0x538a, 0x00},
	{0x538b, 0x31},
	{0x538c, 0x00},
	{0x538d, 0x00},
	{0x538e, 0x00},
	{0x538f, 0x0f},
	{0x5390, 0x00},
	{0x5391, 0xab},
	{0x5392, 0x00},
	{0x5393, 0xa2},
	{0x5394, 0x08},
	{0x5480, 0x14},
	{0x5481, 0x21},
	{0x5482, 0x36},
	{0x5483, 0x57},
	{0x5484, 0x65},
	{0x5485, 0x71},
	{0x5486, 0x7d},
	{0x5487, 0x87},
	{0x5488, 0x91},
	{0x5489, 0x9a},
	{0x548a, 0xaa},
	{0x548b, 0xb8},
	{0x548c, 0xcd},
	{0x548d, 0xdd},
	{0x548e, 0xea},
	{0x548f, 0x10},
	{0x5490, 0x05},
	{0x5491, 0x00},
	{0x5492, 0x04},
	{0x5493, 0x20},
	{0x5494, 0x03},
	{0x5495, 0x60},
	{0x5496, 0x02},
	{0x5497, 0xb8},
	{0x5498, 0x02},
	{0x5499, 0x86},
	{0x549a, 0x02},
	{0x549b, 0x5b},
	{0x549c, 0x02},
	{0x549d, 0x3b},
	{0x549e, 0x02},
	{0x549f, 0x1c},
	{0x54a0, 0x02},
	{0x54a1, 0x04},
	{0x54a2, 0x01},
	{0x54a3, 0xed},
	{0x54a4, 0x01},
	{0x54a5, 0xc5},
	{0x54a6, 0x01},
	{0x54a7, 0xa5},
	{0x54a8, 0x01},
	{0x54a9, 0x6c},
	{0x54aa, 0x01},
	{0x54ab, 0x41},
	{0x54ac, 0x01},
	{0x54ad, 0x20},
	{0x54ae, 0x00},
	{0x54af, 0x16},
	{0x3406, 0x00},
	{0x5192, 0x04},
	{0x5191, 0xf8},
	{0x5193, 0x70},
	{0x5194, 0xf0},
	{0x5195, 0xf0},
	{0x518d, 0x3d},
	{0x518f, 0x54},
	{0x518e, 0x3d},
	{0x5190, 0x54},
	{0x518b, 0xc0},
	{0x518c, 0xbd},
	{0x5187, 0x18},
	{0x5188, 0x18},
	{0x5189, 0x6e},
	{0x518a, 0x68},
	{0x5186, 0x1c},
	{0x5181, 0x50},
	{0x5184, 0x25},
	{0x5182, 0x11},
	{0x5183, 0x14},
	{0x5184, 0x25},
	{0x5185, 0x24},
	{0x5025, 0x82},
	{0x3a0f, 0x7e},
	{0x3a10, 0x72},
	{0x3a1b, 0x80},
	{0x3a1e, 0x70},
	{0x3a11, 0xd0},
	{0x3a1f, 0x40},
	{0x5583, 0x40},
	{0x5584, 0x40},
	{0x5580, 0x02},
	{0x3633, 0x07},
	{0x3702, 0x10},
	{0x3703, 0xb2},
	{0x3704, 0x18},
	{0x370b, 0x40},
	{0x370d, 0x02},
	{0x3620, 0x52},
	{0x3c00, 0x04},

	{REG_ISP_CTRL_01, 0xFF},
	{0x5583, 0x50},
	{0x5584, 0x50},
	{0x5580, 0x02},
	{0x3c01, 0x80},
	{0x3c00, 0x04},
	{0x5800, 0x27},
	{0x5801, 0x22},
	{0x5802, 0x1b},
	{0x5803, 0x17},
	{0x5804, 0x16},
	{0x5805, 0x18},
	{0x5806, 0x20},
	{0x5807, 0x20},
	{0x5808, 0x1b},
	{0x5809, 0x15},
	{0x580a, 0x0f},
	{0x580b, 0x0d},
	{0x580c, 0x0d},
	{0x580d, 0x0e},
	{0x580e, 0x11},
	{0x580f, 0x18},
	{0x5810, 0x10},
	{0x5811, 0x0d},
	{0x5812, 0x08},
	{0x5813, 0x05},
	{0x5814, 0x04},
	{0x5815, 0x06},
	{0x5816, 0x09},
	{0x5817, 0x0e},
	{0x5818, 0x0d},
	{0x5819, 0x09},
	{0x581a, 0x03},
	{0x581b, 0x00},
	{0x581c, 0x00},
	{0x581d, 0x01},
	{0x581e, 0x05},
	{0x581f, 0x0b},
	{0x5820, 0x0d},
	{0x5821, 0x09},
	{0x5822, 0x03},
	{0x5823, 0x00},
	{0x5824, 0x00},
	{0x5825, 0x01},
	{0x5826, 0x05},
	{0x5827, 0x0b},
	{0x5828, 0x10},
	{0x5829, 0x0c},
	{0x582a, 0x08},
	{0x582b, 0x04},
	{0x582c, 0x03},
	{0x582d, 0x05},
	{0x582e, 0x09},
	{0x582f, 0x0e},
	{0x5830, 0x1b},
	{0x5831, 0x14},
	{0x5832, 0x0f},
	{0x5833, 0x0c},
	{0x5834, 0x0c},
	{0x5835, 0x0d},
	{0x5836, 0x10},
	{0x5837, 0x19},
	{0x5838, 0x25},
	{0x5839, 0x23},
	{0x583a, 0x1a},
	{0x583b, 0x16},
	{0x583c, 0x15},
	{0x583d, 0x18},
	{0x583e, 0x1f},
	{0x583f, 0x25},
	{0x5840, 0x10},
	{0x5841, 0x0e},
	{0x5842, 0x0e},
	{0x5843, 0x0e},
	{0x5844, 0x0f},
	{0x5845, 0x0a},
	{0x5846, 0x08},
	{0x5847, 0x0f},
	{0x5848, 0x0f},
	{0x5849, 0x0f},
	{0x584a, 0x0c},
	{0x584b, 0x0f},
	{0x584c, 0x09},
	{0x584d, 0x10},
	{0x584e, 0x11},
	{0x584f, 0x10},
	{0x5850, 0x0f},
	{0x5851, 0x0e},
	{0x5852, 0x08},
	{0x5853, 0x10},
	{0x5854, 0x10},
	{0x5855, 0x10},
	{0x5856, 0x0e},
	{0x5857, 0x0e},
	{0x5858, 0x0a},
	{0x5859, 0x0e},
	{0x585a, 0x0e},
	{0x585b, 0x0e},
	{0x585c, 0x0e},
	{0x585d, 0x0d},
	{0x585e, 0x08},
	{0x585f, 0x0b},
	{0x5860, 0x0a},
	{0x5861, 0x0a},
	{0x5862, 0x09},
	{0x5863, 0x0d},
	{0x5864, 0x13},
	{0x5865, 0x0e},
	{0x5866, 0x10},
	{0x5867, 0x10},
	{0x5868, 0x0e},
	{0x5869, 0x11},
	{0x586a, 0x12},
	{0x586b, 0x10},
	{0x586c, 0x10},
	{0x586d, 0x10},
	{0x586e, 0x10},
	{0x586f, 0x11},
	{0x5870, 0x15},
	{0x5871, 0x10},
	{0x5872, 0x10},
	{0x5873, 0x10},
	{0x5874, 0x11},
	{0x5875, 0x11},
	{0x5876, 0x14},
	{0x5877, 0x0f},
	{0x5878, 0x10},
	{0x5879, 0x10},
	{0x587a, 0x10},
	{0x587b, 0x11},
	{0x587c, 0x12},
	{0x587d, 0x0f},
	{0x587e, 0x0f},
	{0x587f, 0x10},
	{0x5880, 0x10},
	{0x5881, 0x0f},
	{0x5882, 0x12},
	{0x5883, 0x0e},
	{0x5884, 0x10},
	{0x5885, 0x10},
	{0x5886, 0x0e},
	{0x5887, 0x0e},
	{0x5180, 0xff},
	{0x5181, 0x52},
	{0x5182, 0x11},
	{0x5183, 0x14},
	{0x5184, 0x25},
	{0x5185, 0x24},
	{0x5186, 0x14},
	{0x5187, 0x14},
	{0x5188, 0x14},
	{0x5189, 0x6c},
	{0x518a, 0x60},
	{0x518b, 0xbd},
	{0x518c, 0x9c},
	{0x518d, 0x3d},
	{0x518e, 0x34},
	{0x518f, 0x57},
	{0x5190, 0x4a},
	{0x5191, 0xf8},
	{0x5192, 0x04},
	{0x5193, 0x70},
	{0x5194, 0xf0},
	{0x5195, 0xf0},
	{0x5196, 0x03},
	{0x5197, 0x01},
	{0x5198, 0x04},
	{0x5199, 0x00},
	{0x519a, 0x04},
	{0x519b, 0x35},
	{0x519c, 0x08},
	{0x519d, 0xb8},
	{0x519e, 0xa0},
	{0x528a, 0x00},
	{0x528b, 0x01},
	{0x528c, 0x04},
	{0x528d, 0x08},
	{0x528e, 0x10},
	{0x528f, 0x20},
	{0x5290, 0x30},
	{0x5292, 0x00},
	{0x5293, 0x00},
	{0x5294, 0x00},
	{0x5295, 0x01},
	{0x5296, 0x00},
	{0x5297, 0x04},
	{0x5298, 0x00},
	{0x5299, 0x08},
	{0x529a, 0x00},
	{0x529b, 0x10},
	{0x529c, 0x00},
	{0x529d, 0x20},
	{0x529e, 0x00},
	{0x529f, 0x30},
	{0x5282, 0x00},
	{0x5300, 0x00},
	{0x5301, 0x20},
	{0x5302, 0x00},
	{0x5303, 0x7c},
	{0x530c, 0x00},
	{0x530d, 0x10},
	{0x530e, 0x20},
	{0x530f, 0x80},
	{0x5310, 0x20},
	{0x5311, 0x80},
	{0x5308, 0x20},
	{0x5309, 0x40},
	{0x5304, 0x00},
	{0x5305, 0x30},
	{0x5306, 0x00},
	{0x5307, 0x80},
	{0x5314, 0x08},
	{0x5315, 0x20},
	{0x5319, 0x30},
	{0x5316, 0x10},
	{0x5317, 0x00},
	{0x5318, 0x02},
	{0x5380, 0x01},
	{0x5381, 0x00},
	{0x5382, 0x00},
	{0x5383, 0x1f},
	{0x5384, 0x00},
	{0x5385, 0x06},
	{0x5386, 0x00},
	{0x5387, 0x00},
	{0x5388, 0x00},
	{0x5389, 0xE1},
	{0x538A, 0x00},
	{0x538B, 0x2B},
	{0x538C, 0x00},
	{0x538D, 0x00},
	{0x538E, 0x00},
	{0x538F, 0x10},
	{0x5390, 0x00},
	{0x5391, 0xB3},
	{0x5392, 0x00},
	{0x5393, 0xA6},
	{0x5394, 0x08},
	{0x5480, 0x14},
	{0x5481, 0x21},
	{0x5482, 0x36},
	{0x5483, 0x57},
	{0x5484, 0x65},
	{0x5485, 0x71},
	{0x5486, 0x7D},
	{0x5487, 0x87},
	{0x5488, 0x91},
	{0x5489, 0x9A},
	{0x548A, 0xAA},
	{0x548B, 0xB8},
	{0x548C, 0xCD},
	{0x548D, 0xDD},
	{0x548E, 0xEA},
	{0x548F, 0x1d},
	{0x5490, 0x05},
	{0x5491, 0x00},
	{0x5492, 0x04},
	{0x5493, 0x20},
	{0x5494, 0x03},
	{0x5495, 0x60},
	{0x5496, 0x02},
	{0x5497, 0xB8},
	{0x5498, 0x02},
	{0x5499, 0x86},
	{0x549A, 0x02},
	{0x549B, 0x5B},
	{0x549C, 0x02},
	{0x549D, 0x3B},
	{0x549E, 0x02},
	{0x549F, 0x1C},
	{0x54A0, 0x02},
	{0x54A1, 0x04},
	{0x54A2, 0x01},
	{0x54A3, 0xED},
	{0x54A4, 0x01},
	{0x54A5, 0xC5},
	{0x54A6, 0x01},
	{0x54A7, 0xA5},
	{0x54A8, 0x01},
	{0x54A9, 0x6C},
	{0x54AA, 0x01},
	{0x54AB, 0x41},
	{0x54AC, 0x01},
	{0x54AD, 0x20},
	{0x54AE, 0x00},
	{0x54AF, 0x16},
	{0x54B0, 0x01},
	{0x54B1, 0x20},
	{0x54B2, 0x00},
	{0x54B3, 0x10},
	{0x54B4, 0x00},
	{0x54B5, 0xf0},
	{0x54B6, 0x00},
	{0x54B7, 0xDF},
	{0x5402, 0x3f},
	{0x5403, 0x00},
	{0x5500, 0x10},
	{0x5502, 0x00},
	{0x5503, 0x06},
	{0x5504, 0x00},
	{0x5505, 0x7f},
	{0x5025, 0x80},
	{0x3a0f, 0x48},	//0x30
	{0x3a10, 0x38},	//0x28
	{0x3a1b, 0x50},	//0x30
	{0x3a1e, 0x30},	//0x28
	{0x3a11, 0x71},	//0x61
	{0x3a1f, 0x10},
	{0x5688, 0xfd},
	{0x5689, 0xdf},
	{0x568a, 0xfe},
	{0x568b, 0xef},
	{0x568c, 0xfe},
	{0x568d, 0xef},
	{0x568e, 0xaa},
	{0x568f, 0xaa},

	{REG_WINDOW_START_X_HIGH,	0x1 },
	{REG_WINDOW_START_X_LOW,	0x50},
						//0x150 = 336
	{REG_WINDOW_START_Y_HIGH,	0x0 },
	{REG_WINDOW_START_Y_LOW,	0x8 },
						//0x8 = 8
	{REG_WINDOW_WIDTH_HIGH,		0x5 },
	{REG_WINDOW_WIDTH_LOW,		0x0 },
						//0x500 = 1280
	{REG_WINDOW_HEIGHT_HIGH,	0x3 },
	{REG_WINDOW_HEIGHT_LOW,		0xc0},
						//0x3c0 = 960
	{REG_OUT_WIDTH_HIGH,		0x5 },	// TIMING DVPHO Bit[3:0] DVP output horizontal width high byte
	{REG_OUT_WIDTH_LOW,		0x00},	// TIMING DVPHO Bit[7:0] DVP output horizontal width low byte
						// 0x500 => 1280
	{REG_OUT_HEIGHT_HIGH,		0x2 },	// TIMING DVPVO Bit[3:0] DVP output vertical height high byte
//	{REG_OUT_HEIGHT_LOW,		0xd0},	// TIMING DVPVO Bit[7:0] DVP output vertical height low byte
						// 0x2d0 => 720
	{REG_OUT_HEIGHT_LOW,		0xd5},	// TIMING DVPVO Bit[7:0] DVP output vertical height low byte
						// 0x2d5 => 725
	{REG_OUT_TOTAL_WIDTH_HIGH,	0xc },	// TIMING HTS Bit[3:0] Total horizontal size high byte [11:8]
	{REG_OUT_TOTAL_WIDTH_LOW,	0x80},	// TIMING HTS Bit[7:0] Total horizontal size low byte [7:0]
						// 0xc80 => 3200
	{REG_OUT_TOTAL_HEIGHT_HIGH,	0x3 },	// TIMING VTS Bit[3:0] Total vertical size high byte [11:8]
	{REG_OUT_TOTAL_HEIGHT_LOW,	0xe8},	// TIMING VTS Bit[7:0] Total vertical size low byte [7:0]
						// 0x3e8 => 1000
	{REG_ISP_CTRL_01,		0x7f},
	{REG_AVG_WINDOW_START_X_HIGH,	0x0 },
	{REG_AVG_WINDOW_START_X_LOW,	0x0 },
	{REG_AVG_WINDOW_END_X_HIGH,	0x5 },
	{REG_AVG_WINDOW_END_X_LOW,	0x0 },
	{REG_AVG_WINDOW_START_Y_HIGH,	0x0 },
	{REG_AVG_WINDOW_START_Y_LOW,	0x0 },
	{REG_AVG_WINDOW_END_Y_HIGH,	0x3 },
	//{REG_AVG_WINDOW_END_Y_LOW,	0xc0},
	{REG_AVG_WINDOW_END_Y_LOW,	0xc0},
	{0x3815, 0x02},
	{0x3503, 0x00},
	//{0x4730, 0x01},
	{0x4730, 0x00},
	{REG_OUTPUT_FORMAT,		0x32},

	{0xffff, 0xff},
};
