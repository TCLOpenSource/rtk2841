#include <linux/kconfig.h>
#include <linux/compiler.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/stat.h>			/* permission */
#include <linux/fs.h>			/* fs */
#include <linux/errno.h>		/* error codes */
#include <linux/types.h>		/* size_t */
#include <linux/fcntl.h>		/* O_ACCMODE */
#include <asm/uaccess.h>		/* copy_*_user */
#include <linux/semaphore.h>		/* semaphore */
#include <linux/kthread.h>		/* kernel thread */
#include <linux/freezer.h>		/* set freezable */
#include <linux/wait.h>			/* wait event */
#include <linux/jiffies.h>		/* jiffies */
#include <linux/delay.h>

/*
 * rbus registers
 */
#include <rtk_kdriver/RPCDriver.h>

#include "audio_hw_port.h"
#include "audio_hw_driver.h"
#include "audio_hw_atv.h"
#include "audio_hw_aio.h"
#include "audio_hw_app.h"
#include "audio_hw_rpc.h"

#define __ALOG_SUBTAG "rpc"

#define ENUM_KERNEL_RPC_AIN_ATV_SET_CLOCK	30
#define ENUM_KERNEL_RPC_ATV_MUTE		31
#define ENUM_KERNEL_RPC_BTSC_CTL		0x205

#define AIN_VOL_0DB             0
#define AIN_VOL_STEP_MIN        1
#define AIN_VOL_STEP_1DB        2 // 0.5dB per step
#define AIN_MAX_VOL             ((30)*AIN_VOL_STEP_1DB)
#define AIN_MIN_VOL             (-70*AIN_VOL_STEP_1DB)
#define AIN_GAIN_TO_INDEX(x)    (140 + x)

//For setting SW decoder mute RPC(defined in AudioRPCBaseDS_data.h)
enum AUDIO_DVOL_LEVEL {
	ENUM_AUDIO_DVOL_MUTE = 100,
	ENUM_AUDIO_DVOL_KMINUS72p0DB = 101,
	ENUM_AUDIO_DVOL_KMINUS71p75DB = 102,
	ENUM_AUDIO_DVOL_KMINUS71p50DB = 103,
	ENUM_AUDIO_DVOL_KMINUS71p25DB = 104,
	ENUM_AUDIO_DVOL_KMINUS71p0DB = 105,
	ENUM_AUDIO_DVOL_KMINUS70p75DB = 106,
	ENUM_AUDIO_DVOL_KMINUS70p50DB = 107,
	ENUM_AUDIO_DVOL_KMINUS70p25DB = 108,
	ENUM_AUDIO_DVOL_KMINUS70p0DB = 109,
	ENUM_AUDIO_DVOL_KMINUS69p75DB = 110,
	ENUM_AUDIO_DVOL_KMINUS69p50DB = 111,
	ENUM_AUDIO_DVOL_KMINUS69p25DB = 112,
	ENUM_AUDIO_DVOL_KMINUS69p0DB = 113,
	ENUM_AUDIO_DVOL_KMINUS68p75DB = 114,
	ENUM_AUDIO_DVOL_KMINUS68p50DB = 115,
	ENUM_AUDIO_DVOL_KMINUS68p25DB = 116,
	ENUM_AUDIO_DVOL_KMINUS68p0DB = 117,
	ENUM_AUDIO_DVOL_KMINUS67p75DB = 118,
	ENUM_AUDIO_DVOL_KMINUS67p50DB = 119,
	ENUM_AUDIO_DVOL_KMINUS67p25DB = 120,
	ENUM_AUDIO_DVOL_KMINUS67p0DB = 121,
	ENUM_AUDIO_DVOL_KMINUS66p75DB = 122,
	ENUM_AUDIO_DVOL_KMINUS66p50DB = 123,
	ENUM_AUDIO_DVOL_KMINUS66p25DB = 124,
	ENUM_AUDIO_DVOL_KMINUS66p0DB = 125,
	ENUM_AUDIO_DVOL_KMINUS65p75DB = 126,
	ENUM_AUDIO_DVOL_KMINUS65p50DB = 127,
	ENUM_AUDIO_DVOL_KMINUS65p25DB = 128,
	ENUM_AUDIO_DVOL_KMINUS65p0DB = 129,
	ENUM_AUDIO_DVOL_KMINUS64p75DB = 130,
	ENUM_AUDIO_DVOL_KMINUS64p50DB = 131,
	ENUM_AUDIO_DVOL_KMINUS64p25DB = 132,
	ENUM_AUDIO_DVOL_KMINUS64p0DB = 133,
	ENUM_AUDIO_DVOL_KMINUS63p75DB = 134,
	ENUM_AUDIO_DVOL_KMINUS63p50DB = 135,
	ENUM_AUDIO_DVOL_KMINUS63p25DB = 136,
	ENUM_AUDIO_DVOL_KMINUS63p0DB = 137,
	ENUM_AUDIO_DVOL_KMINUS62p75DB = 138,
	ENUM_AUDIO_DVOL_KMINUS62p50DB = 139,
	ENUM_AUDIO_DVOL_KMINUS62p25DB = 140,
	ENUM_AUDIO_DVOL_KMINUS62p0DB = 141,
	ENUM_AUDIO_DVOL_KMINUS61p75DB = 142,
	ENUM_AUDIO_DVOL_KMINUS61p50DB = 143,
	ENUM_AUDIO_DVOL_KMINUS61p25DB = 144,
	ENUM_AUDIO_DVOL_KMINUS61p0DB = 145,
	ENUM_AUDIO_DVOL_KMINUS60p75DB = 146,
	ENUM_AUDIO_DVOL_KMINUS60p50DB = 147,
	ENUM_AUDIO_DVOL_KMINUS60p25DB = 148,
	ENUM_AUDIO_DVOL_KMINUS60p0DB = 149,
	ENUM_AUDIO_DVOL_KMINUS59p75DB = 150,
	ENUM_AUDIO_DVOL_KMINUS59p50DB = 151,
	ENUM_AUDIO_DVOL_KMINUS59p25DB = 152,
	ENUM_AUDIO_DVOL_KMINUS59p0DB = 153,
	ENUM_AUDIO_DVOL_KMINUS58p75DB = 154,
	ENUM_AUDIO_DVOL_KMINUS58p50DB = 155,
	ENUM_AUDIO_DVOL_KMINUS58p25DB = 156,
	ENUM_AUDIO_DVOL_KMINUS58p0DB = 157,
	ENUM_AUDIO_DVOL_KMINUS57p75DB = 158,
	ENUM_AUDIO_DVOL_KMINUS57p50DB = 159,
	ENUM_AUDIO_DVOL_KMINUS57p25DB = 160,
	ENUM_AUDIO_DVOL_KMINUS57p0DB = 161,
	ENUM_AUDIO_DVOL_KMINUS56p75DB = 162,
	ENUM_AUDIO_DVOL_KMINUS56p50DB = 163,
	ENUM_AUDIO_DVOL_KMINUS56p25DB = 164,
	ENUM_AUDIO_DVOL_KMINUS56p0DB = 165,
	ENUM_AUDIO_DVOL_KMINUS55p75DB = 166,
	ENUM_AUDIO_DVOL_KMINUS55p50DB = 167,
	ENUM_AUDIO_DVOL_KMINUS55p25DB = 168,
	ENUM_AUDIO_DVOL_KMINUS55p0DB = 169,
	ENUM_AUDIO_DVOL_KMINUS54p75DB = 170,
	ENUM_AUDIO_DVOL_KMINUS54p50DB = 171,
	ENUM_AUDIO_DVOL_KMINUS54p25DB = 172,
	ENUM_AUDIO_DVOL_KMINUS54p0DB = 173,
	ENUM_AUDIO_DVOL_KMINUS53p75DB = 174,
	ENUM_AUDIO_DVOL_KMINUS53p50DB = 175,
	ENUM_AUDIO_DVOL_KMINUS53p25DB = 176,
	ENUM_AUDIO_DVOL_KMINUS53p0DB = 177,
	ENUM_AUDIO_DVOL_KMINUS52p75DB = 178,
	ENUM_AUDIO_DVOL_KMINUS52p50DB = 179,
	ENUM_AUDIO_DVOL_KMINUS52p25DB = 180,
	ENUM_AUDIO_DVOL_KMINUS52p0DB = 181,
	ENUM_AUDIO_DVOL_KMINUS51p75DB = 182,
	ENUM_AUDIO_DVOL_KMINUS51p50DB = 183,
	ENUM_AUDIO_DVOL_KMINUS51p25DB = 184,
	ENUM_AUDIO_DVOL_KMINUS51p0DB = 185,
	ENUM_AUDIO_DVOL_KMINUS50p75DB = 186,
	ENUM_AUDIO_DVOL_KMINUS50p50DB = 187,
	ENUM_AUDIO_DVOL_KMINUS50p25DB = 188,
	ENUM_AUDIO_DVOL_KMINUS50p0DB = 189,
	ENUM_AUDIO_DVOL_KMINUS49p75DB = 190,
	ENUM_AUDIO_DVOL_KMINUS49p50DB = 191,
	ENUM_AUDIO_DVOL_KMINUS49p25DB = 192,
	ENUM_AUDIO_DVOL_KMINUS49p0DB = 193,
	ENUM_AUDIO_DVOL_KMINUS48p75DB = 194,
	ENUM_AUDIO_DVOL_KMINUS48p50DB = 195,
	ENUM_AUDIO_DVOL_KMINUS48p25DB = 196,
	ENUM_AUDIO_DVOL_KMINUS48p0DB = 197,
	ENUM_AUDIO_DVOL_KMINUS47p75DB = 198,
	ENUM_AUDIO_DVOL_KMINUS47p50DB = 199,
	ENUM_AUDIO_DVOL_KMINUS47p25DB = 200,
	ENUM_AUDIO_DVOL_KMINUS47p0DB = 201,
	ENUM_AUDIO_DVOL_KMINUS46p75DB = 202,
	ENUM_AUDIO_DVOL_KMINUS46p50DB = 203,
	ENUM_AUDIO_DVOL_KMINUS46p25DB = 204,
	ENUM_AUDIO_DVOL_KMINUS46p0DB = 205,
	ENUM_AUDIO_DVOL_KMINUS45p75DB = 206,
	ENUM_AUDIO_DVOL_KMINUS45p50DB = 207,
	ENUM_AUDIO_DVOL_KMINUS45p25DB = 208,
	ENUM_AUDIO_DVOL_KMINUS45p0DB = 209,
	ENUM_AUDIO_DVOL_KMINUS44p75DB = 210,
	ENUM_AUDIO_DVOL_KMINUS44p50DB = 211,
	ENUM_AUDIO_DVOL_KMINUS44p25DB = 212,
	ENUM_AUDIO_DVOL_KMINUS44p0DB = 213,
	ENUM_AUDIO_DVOL_KMINUS43p75DB = 214,
	ENUM_AUDIO_DVOL_KMINUS43p50DB = 215,
	ENUM_AUDIO_DVOL_KMINUS43p25DB = 216,
	ENUM_AUDIO_DVOL_KMINUS43p0DB = 217,
	ENUM_AUDIO_DVOL_KMINUS42p75DB = 218,
	ENUM_AUDIO_DVOL_KMINUS42p50DB = 219,
	ENUM_AUDIO_DVOL_KMINUS42p25DB = 220,
	ENUM_AUDIO_DVOL_KMINUS42p0DB = 221,
	ENUM_AUDIO_DVOL_KMINUS41p75DB = 222,
	ENUM_AUDIO_DVOL_KMINUS41p50DB = 223,
	ENUM_AUDIO_DVOL_KMINUS41p25DB = 224,
	ENUM_AUDIO_DVOL_KMINUS41p0DB = 225,
	ENUM_AUDIO_DVOL_KMINUS40p75DB = 226,
	ENUM_AUDIO_DVOL_KMINUS40p50DB = 227,
	ENUM_AUDIO_DVOL_KMINUS40p25DB = 228,
	ENUM_AUDIO_DVOL_KMINUS40p0DB = 229,
	ENUM_AUDIO_DVOL_KMINUS39p75DB = 230,
	ENUM_AUDIO_DVOL_KMINUS39p50DB = 231,
	ENUM_AUDIO_DVOL_KMINUS39p25DB = 232,
	ENUM_AUDIO_DVOL_KMINUS39p0DB = 233,
	ENUM_AUDIO_DVOL_KMINUS38p75DB = 234,
	ENUM_AUDIO_DVOL_KMINUS38p50DB = 235,
	ENUM_AUDIO_DVOL_KMINUS38p25DB = 236,
	ENUM_AUDIO_DVOL_KMINUS38p0DB = 237,
	ENUM_AUDIO_DVOL_KMINUS37p75DB = 238,
	ENUM_AUDIO_DVOL_KMINUS37p50DB = 239,
	ENUM_AUDIO_DVOL_KMINUS37p25DB = 240,
	ENUM_AUDIO_DVOL_KMINUS37p0DB = 241,
	ENUM_AUDIO_DVOL_KMINUS36p75DB = 242,
	ENUM_AUDIO_DVOL_KMINUS36p50DB = 243,
	ENUM_AUDIO_DVOL_KMINUS36p25DB = 244,
	ENUM_AUDIO_DVOL_KMINUS36p0DB = 245,
	ENUM_AUDIO_DVOL_KMINUS35p75DB = 246,
	ENUM_AUDIO_DVOL_KMINUS35p50DB = 247,
	ENUM_AUDIO_DVOL_KMINUS35p25DB = 248,
	ENUM_AUDIO_DVOL_KMINUS35p0DB = 249,
	ENUM_AUDIO_DVOL_KMINUS34p75DB = 250,
	ENUM_AUDIO_DVOL_KMINUS34p50DB = 251,
	ENUM_AUDIO_DVOL_KMINUS34p25DB = 252,
	ENUM_AUDIO_DVOL_KMINUS34p0DB = 253,
	ENUM_AUDIO_DVOL_KMINUS33p75DB = 254,
	ENUM_AUDIO_DVOL_KMINUS33p50DB = 255,
	ENUM_AUDIO_DVOL_KMINUS33p25DB = 256,
	ENUM_AUDIO_DVOL_KMINUS33p0DB = 257,
	ENUM_AUDIO_DVOL_KMINUS32p75DB = 258,
	ENUM_AUDIO_DVOL_KMINUS32p50DB = 259,
	ENUM_AUDIO_DVOL_KMINUS32p25DB = 260,
	ENUM_AUDIO_DVOL_KMINUS32p0DB = 261,
	ENUM_AUDIO_DVOL_KMINUS31p75DB = 262,
	ENUM_AUDIO_DVOL_KMINUS31p50DB = 263,
	ENUM_AUDIO_DVOL_KMINUS31p25DB = 264,
	ENUM_AUDIO_DVOL_KMINUS31p0DB = 265,
	ENUM_AUDIO_DVOL_KMINUS30p75DB = 266,
	ENUM_AUDIO_DVOL_KMINUS30p50DB = 267,
	ENUM_AUDIO_DVOL_KMINUS30p25DB = 268,
	ENUM_AUDIO_DVOL_KMINUS30p0DB = 269,
	ENUM_AUDIO_DVOL_KMINUS29p75DB = 270,
	ENUM_AUDIO_DVOL_KMINUS29p50DB = 271,
	ENUM_AUDIO_DVOL_KMINUS29p25DB = 272,
	ENUM_AUDIO_DVOL_KMINUS29p0DB = 273,
	ENUM_AUDIO_DVOL_KMINUS28p75DB = 274,
	ENUM_AUDIO_DVOL_KMINUS28p50DB = 275,
	ENUM_AUDIO_DVOL_KMINUS28p25DB = 276,
	ENUM_AUDIO_DVOL_KMINUS28p0DB = 277,
	ENUM_AUDIO_DVOL_KMINUS27p75DB = 278,
	ENUM_AUDIO_DVOL_KMINUS27p50DB = 279,
	ENUM_AUDIO_DVOL_KMINUS27p25DB = 280,
	ENUM_AUDIO_DVOL_KMINUS27p0DB = 281,
	ENUM_AUDIO_DVOL_KMINUS26p75DB = 282,
	ENUM_AUDIO_DVOL_KMINUS26p50DB = 283,
	ENUM_AUDIO_DVOL_KMINUS26p25DB = 284,
	ENUM_AUDIO_DVOL_KMINUS26p0DB = 285,
	ENUM_AUDIO_DVOL_KMINUS25p75DB = 286,
	ENUM_AUDIO_DVOL_KMINUS25p50DB = 287,
	ENUM_AUDIO_DVOL_KMINUS25p25DB = 288,
	ENUM_AUDIO_DVOL_KMINUS25p0DB = 289,
	ENUM_AUDIO_DVOL_KMINUS24p75DB = 290,
	ENUM_AUDIO_DVOL_KMINUS24p50DB = 291,
	ENUM_AUDIO_DVOL_KMINUS24p25DB = 292,
	ENUM_AUDIO_DVOL_KMINUS24p0DB = 293,
	ENUM_AUDIO_DVOL_KMINUS23p75DB = 294,
	ENUM_AUDIO_DVOL_KMINUS23p50DB = 295,
	ENUM_AUDIO_DVOL_KMINUS23p25DB = 296,
	ENUM_AUDIO_DVOL_KMINUS23p0DB = 297,
	ENUM_AUDIO_DVOL_KMINUS22p75DB = 298,
	ENUM_AUDIO_DVOL_KMINUS22p50DB = 299,
	ENUM_AUDIO_DVOL_KMINUS22p25DB = 300,
	ENUM_AUDIO_DVOL_KMINUS22p0DB = 301,
	ENUM_AUDIO_DVOL_KMINUS21p75DB = 302,
	ENUM_AUDIO_DVOL_KMINUS21p50DB = 303,
	ENUM_AUDIO_DVOL_KMINUS21p25DB = 304,
	ENUM_AUDIO_DVOL_KMINUS21p0DB = 305,
	ENUM_AUDIO_DVOL_KMINUS20p75DB = 306,
	ENUM_AUDIO_DVOL_KMINUS20p50DB = 307,
	ENUM_AUDIO_DVOL_KMINUS20p25DB = 308,
	ENUM_AUDIO_DVOL_KMINUS20p0DB = 309,
	ENUM_AUDIO_DVOL_KMINUS19p75DB = 310,
	ENUM_AUDIO_DVOL_KMINUS19p50DB = 311,
	ENUM_AUDIO_DVOL_KMINUS19p25DB = 312,
	ENUM_AUDIO_DVOL_KMINUS19p0DB = 313,
	ENUM_AUDIO_DVOL_KMINUS18p75DB = 314,
	ENUM_AUDIO_DVOL_KMINUS18p50DB = 315,
	ENUM_AUDIO_DVOL_KMINUS18p25DB = 316,
	ENUM_AUDIO_DVOL_KMINUS18p0DB = 317,
	ENUM_AUDIO_DVOL_KMINUS17p75DB = 318,
	ENUM_AUDIO_DVOL_KMINUS17p50DB = 319,
	ENUM_AUDIO_DVOL_KMINUS17p25DB = 320,
	ENUM_AUDIO_DVOL_KMINUS17p0DB = 321,
	ENUM_AUDIO_DVOL_KMINUS16p75DB = 322,
	ENUM_AUDIO_DVOL_KMINUS16p50DB = 323,
	ENUM_AUDIO_DVOL_KMINUS16p25DB = 324,
	ENUM_AUDIO_DVOL_KMINUS16p0DB = 325,
	ENUM_AUDIO_DVOL_KMINUS15p75DB = 326,
	ENUM_AUDIO_DVOL_KMINUS15p50DB = 327,
	ENUM_AUDIO_DVOL_KMINUS15p25DB = 328,
	ENUM_AUDIO_DVOL_KMINUS15p0DB = 329,
	ENUM_AUDIO_DVOL_KMINUS14p75DB = 330,
	ENUM_AUDIO_DVOL_KMINUS14p50DB = 331,
	ENUM_AUDIO_DVOL_KMINUS14p25DB = 332,
	ENUM_AUDIO_DVOL_KMINUS14p0DB = 333,
	ENUM_AUDIO_DVOL_KMINUS13p75DB = 334,
	ENUM_AUDIO_DVOL_KMINUS13p50DB = 335,
	ENUM_AUDIO_DVOL_KMINUS13p25DB = 336,
	ENUM_AUDIO_DVOL_KMINUS13p0DB = 337,
	ENUM_AUDIO_DVOL_KMINUS12p75DB = 338,
	ENUM_AUDIO_DVOL_KMINUS12p50DB = 339,
	ENUM_AUDIO_DVOL_KMINUS12p25DB = 340,
	ENUM_AUDIO_DVOL_KMINUS12p0DB = 341,
	ENUM_AUDIO_DVOL_KMINUS11p75DB = 342,
	ENUM_AUDIO_DVOL_KMINUS11p50DB = 343,
	ENUM_AUDIO_DVOL_KMINUS11p25DB = 344,
	ENUM_AUDIO_DVOL_KMINUS11p0DB = 345,
	ENUM_AUDIO_DVOL_KMINUS10p75DB = 346,
	ENUM_AUDIO_DVOL_KMINUS10p50DB = 347,
	ENUM_AUDIO_DVOL_KMINUS10p25DB = 348,
	ENUM_AUDIO_DVOL_KMINUS10p0DB = 349,
	ENUM_AUDIO_DVOL_KMINUS9p75DB = 350,
	ENUM_AUDIO_DVOL_KMINUS9p50DB = 351,
	ENUM_AUDIO_DVOL_KMINUS9p25DB = 352,
	ENUM_AUDIO_DVOL_KMINUS9p0DB = 353,
	ENUM_AUDIO_DVOL_KMINUS8p75DB = 354,
	ENUM_AUDIO_DVOL_KMINUS8p50DB = 355,
	ENUM_AUDIO_DVOL_KMINUS8p25DB = 356,
	ENUM_AUDIO_DVOL_KMINUS8p0DB = 357,
	ENUM_AUDIO_DVOL_KMINUS7p75DB = 358,
	ENUM_AUDIO_DVOL_KMINUS7p50DB = 359,
	ENUM_AUDIO_DVOL_KMINUS7p25DB = 360,
	ENUM_AUDIO_DVOL_KMINUS7p0DB = 361,
	ENUM_AUDIO_DVOL_KMINUS6p75DB = 362,
	ENUM_AUDIO_DVOL_KMINUS6p50DB = 363,
	ENUM_AUDIO_DVOL_KMINUS6p25DB = 364,
	ENUM_AUDIO_DVOL_KMINUS6p0DB = 365,
	ENUM_AUDIO_DVOL_KMINUS5p75DB = 366,
	ENUM_AUDIO_DVOL_KMINUS5p50DB = 367,
	ENUM_AUDIO_DVOL_KMINUS5p25DB = 368,
	ENUM_AUDIO_DVOL_KMINUS5p0DB = 369,
	ENUM_AUDIO_DVOL_KMINUS4p75DB = 370,
	ENUM_AUDIO_DVOL_KMINUS4p50DB = 371,
	ENUM_AUDIO_DVOL_KMINUS4p25DB = 372,
	ENUM_AUDIO_DVOL_KMINUS4p0DB = 373,
	ENUM_AUDIO_DVOL_KMINUS3p75DB = 374,
	ENUM_AUDIO_DVOL_KMINUS3p50DB = 375,
	ENUM_AUDIO_DVOL_KMINUS3p25DB = 376,
	ENUM_AUDIO_DVOL_KMINUS3p0DB = 377,
	ENUM_AUDIO_DVOL_KMINUS2p75DB = 378,
	ENUM_AUDIO_DVOL_KMINUS2p50DB = 379,
	ENUM_AUDIO_DVOL_KMINUS2p25DB = 380,
	ENUM_AUDIO_DVOL_KMINUS2p0DB = 381,
	ENUM_AUDIO_DVOL_KMINUS1p75DB = 382,
	ENUM_AUDIO_DVOL_KMINUS1p50DB = 383,
	ENUM_AUDIO_DVOL_KMINUS1p25DB = 384,
	ENUM_AUDIO_DVOL_KMINUS1p0DB = 385,
	ENUM_AUDIO_DVOL_KMINUS0p75DB = 386,
	ENUM_AUDIO_DVOL_KMINUS0p50DB = 387,
	ENUM_AUDIO_DVOL_KMINUS0p25DB = 388,
	ENUM_AUDIO_DVOL_K0p0DB = 389,
	ENUM_AUDIO_DVOL_K0p25DB = 390,
	ENUM_AUDIO_DVOL_K0p50DB = 391,
	ENUM_AUDIO_DVOL_K0p75DB = 392,
	ENUM_AUDIO_DVOL_K1p0DB = 393,
	ENUM_AUDIO_DVOL_K1p25DB = 394,
	ENUM_AUDIO_DVOL_K1p50DB = 395,
	ENUM_AUDIO_DVOL_K1p75DB = 396,
	ENUM_AUDIO_DVOL_K2p0DB = 397,
	ENUM_AUDIO_DVOL_K2p25DB = 398,
	ENUM_AUDIO_DVOL_K2p50DB = 399,
	ENUM_AUDIO_DVOL_K2p75DB = 400,
	ENUM_AUDIO_DVOL_K3p0DB = 401,
	ENUM_AUDIO_DVOL_K3p25DB = 402,
	ENUM_AUDIO_DVOL_K3p50DB = 403,
	ENUM_AUDIO_DVOL_K3p75DB = 404,
	ENUM_AUDIO_DVOL_K4p0DB = 405,
	ENUM_AUDIO_DVOL_K4p25DB = 406,
	ENUM_AUDIO_DVOL_K4p50DB = 407,
	ENUM_AUDIO_DVOL_K4p75DB = 408,
	ENUM_AUDIO_DVOL_K5p0DB = 409,
	ENUM_AUDIO_DVOL_K5p25DB = 410,
	ENUM_AUDIO_DVOL_K5p50DB = 411,
	ENUM_AUDIO_DVOL_K5p75DB = 412,
	ENUM_AUDIO_DVOL_K6p0DB = 413,
	ENUM_AUDIO_DVOL_K6p25DB = 414,
	ENUM_AUDIO_DVOL_K6p50DB = 415,
	ENUM_AUDIO_DVOL_K6p75DB = 416,
	ENUM_AUDIO_DVOL_K7p0DB = 417,
	ENUM_AUDIO_DVOL_K7p25DB = 418,
	ENUM_AUDIO_DVOL_K7p50DB = 419,
	ENUM_AUDIO_DVOL_K7p75DB = 420,
	ENUM_AUDIO_DVOL_K8p0DB = 421,
	ENUM_AUDIO_DVOL_K8p25DB = 422,
	ENUM_AUDIO_DVOL_K8p50DB = 423,
	ENUM_AUDIO_DVOL_K8p75DB = 424,
	ENUM_AUDIO_DVOL_K9p0DB = 425,
	ENUM_AUDIO_DVOL_K9p25DB = 426,
	ENUM_AUDIO_DVOL_K9p50DB = 427,
	ENUM_AUDIO_DVOL_K9p75DB = 428,
	ENUM_AUDIO_DVOL_K10p0DB = 429,
	ENUM_AUDIO_DVOL_K10p25DB = 430,
	ENUM_AUDIO_DVOL_K10p50DB = 431,
	ENUM_AUDIO_DVOL_K10p75DB = 432,
	ENUM_AUDIO_DVOL_K11p0DB = 433,
	ENUM_AUDIO_DVOL_K11p25DB = 434,
	ENUM_AUDIO_DVOL_K11p50DB = 435,
	ENUM_AUDIO_DVOL_K11p75DB = 436,
	ENUM_AUDIO_DVOL_K12p0DB = 437,
	ENUM_AUDIO_DVOL_K12p25DB = 438,
	ENUM_AUDIO_DVOL_K12p50DB = 439,
	ENUM_AUDIO_DVOL_K12p75DB = 440,
	ENUM_AUDIO_DVOL_K13p0DB = 441,
	ENUM_AUDIO_DVOL_K13p25DB = 442,
	ENUM_AUDIO_DVOL_K13p50DB = 443,
	ENUM_AUDIO_DVOL_K13p75DB = 444,
	ENUM_AUDIO_DVOL_K14p0DB = 445,
	ENUM_AUDIO_DVOL_K14p25DB = 446,
	ENUM_AUDIO_DVOL_K14p50DB = 447,
	ENUM_AUDIO_DVOL_K14p75DB = 448,
	ENUM_AUDIO_DVOL_K15p0DB = 449,
	ENUM_AUDIO_DVOL_K15p25DB = 450,
	ENUM_AUDIO_DVOL_K15p50DB = 451,
	ENUM_AUDIO_DVOL_K15p75DB = 452,
	ENUM_AUDIO_DVOL_K16p0DB = 453,
	ENUM_AUDIO_DVOL_K16p25DB = 454,
	ENUM_AUDIO_DVOL_K16p50DB = 455,
	ENUM_AUDIO_DVOL_K16p75DB = 456,
	ENUM_AUDIO_DVOL_K17p0DB = 457,
	ENUM_AUDIO_DVOL_K17p25DB = 458,
	ENUM_AUDIO_DVOL_K17p50DB = 459,
	ENUM_AUDIO_DVOL_K17p75DB = 460,
	ENUM_AUDIO_DVOL_K18p0DB = 461,
	ENUM_AUDIO_DVOL_K18p25DB = 462,
	ENUM_AUDIO_DVOL_K18p50DB = 463,
	ENUM_AUDIO_DVOL_K18p75DB = 464,
	ENUM_AUDIO_DVOL_K19p0DB = 465,
	ENUM_AUDIO_DVOL_K19p25DB = 466,
	ENUM_AUDIO_DVOL_K19p50DB = 467,
	ENUM_AUDIO_DVOL_K19p75DB = 468,
	ENUM_AUDIO_DVOL_K20p0DB = 469,
	ENUM_AUDIO_DVOL_K20p25DB = 470,
	ENUM_AUDIO_DVOL_K20p50DB = 471,
	ENUM_AUDIO_DVOL_K20p75DB = 472,
	ENUM_AUDIO_DVOL_K21p0DB = 473,
	ENUM_AUDIO_DVOL_K21p25DB = 474,
	ENUM_AUDIO_DVOL_K21p50DB = 475,
	ENUM_AUDIO_DVOL_K21p75DB = 476,
	ENUM_AUDIO_DVOL_K22p0DB = 477,
	ENUM_AUDIO_DVOL_K22p25DB = 478,
	ENUM_AUDIO_DVOL_K22p50DB = 479,
	ENUM_AUDIO_DVOL_K22p75DB = 480,
	ENUM_AUDIO_DVOL_K23p0DB = 481,
	ENUM_AUDIO_DVOL_K23p25DB = 482,
	ENUM_AUDIO_DVOL_K23p50DB = 483,
	ENUM_AUDIO_DVOL_K23p75DB = 484,
	ENUM_AUDIO_DVOL_K24p0DB = 485,
	ENUM_AUDIO_DVOL_K24p25DB = 486,
	ENUM_AUDIO_DVOL_K24p50DB = 487,
	ENUM_AUDIO_DVOL_K24p75DB = 488,
	ENUM_AUDIO_DVOL_K25p0DB = 489,
	ENUM_AUDIO_DVOL_K25p25DB = 490,
	ENUM_AUDIO_DVOL_K25p50DB = 491,
	ENUM_AUDIO_DVOL_K25p75DB = 492,
	ENUM_AUDIO_DVOL_K26p0DB = 493,
	ENUM_AUDIO_DVOL_K26p25DB = 494,
	ENUM_AUDIO_DVOL_K26p50DB = 495,
	ENUM_AUDIO_DVOL_K26p75DB = 496,
	ENUM_AUDIO_DVOL_K27p0DB = 497,
	ENUM_AUDIO_DVOL_K27p25DB = 498,
	ENUM_AUDIO_DVOL_K27p50DB = 499,
	ENUM_AUDIO_DVOL_K27p75DB = 500,
	ENUM_AUDIO_DVOL_K28p0DB = 501,
	ENUM_AUDIO_DVOL_K28p25DB = 502,
	ENUM_AUDIO_DVOL_K28p50DB = 503,
	ENUM_AUDIO_DVOL_K28p75DB = 504,
	ENUM_AUDIO_DVOL_K29p0DB = 505,
	ENUM_AUDIO_DVOL_K29p25DB = 506,
	ENUM_AUDIO_DVOL_K29p50DB = 507,
	ENUM_AUDIO_DVOL_K29p75DB = 508,
	ENUM_AUDIO_DVOL_K30p0DB = 509,
};
typedef enum AUDIO_DVOL_LEVEL AUDIO_DVOL_LEVEL;

//For setting ATV clock RPC(defined in rtk_snd.h)
#define S_OK		0x10000000

enum ENUM_AUDIO_KERNEL_RPC_CMD {
	ENUM_KERNEL_RPC_CREATE_AGENT,
	ENUM_KERNEL_RPC_INIT_RINGBUF,
	ENUM_KERNEL_RPC_PRIVATEINFO,
	ENUM_KERNEL_RPC_RUN,
	ENUM_KERNEL_RPC_PAUSE,
	ENUM_KERNEL_RPC_SWITCH_FOCUS,
	ENUM_KERNEL_RPC_MALLOC_ADDR,
	ENUM_KERNEL_RPC_VOLUME_CONTROL,
	ENUM_KERNEL_RPC_FLUSH,
	ENUM_KERNEL_RPC_CONNECT,
	ENUM_KERNEL_RPC_SETREFCLOCK,
	ENUM_KERNEL_RPC_DAC_I2S_CONFIG,
	ENUM_KERNEL_RPC_DAC_SPDIF_CONFIG,
	ENUM_KERNEL_RPC_HDMI_OUT_EDID,
	ENUM_KERNEL_RPC_HDMI_OUT_EDID2,
	ENUM_KERNEL_RPC_HDMI_SET,
	ENUM_KERNEL_RPC_HDMI_MUTE,
	ENUM_KERNEL_RPC_ASK_DBG_MEM_ADDR,
	ENUM_KERNEL_RPC_DESTROY,
	ENUM_KERNEL_RPC_STOP,

	/* check if Audio get memory pool from AP */
	ENUM_KERNEL_RPC_CHECK_READY,

	/* get mute and volume level */
	ENUM_KERNEL_RPC_GET_MUTE_N_VOLUME,
	ENUM_KERNEL_RPC_EOS,
	ENUM_KERNEL_RPC_ADC0_CONFIG
};

struct RBUF_HEADER {
	unsigned int magic;   /* Magic number */
	unsigned int begin_addr;
	unsigned int size;

	/* RINGBUFFER_TYPE, choose a type from RINGBUFFER_TYPE */
	unsigned int buf_id;

	unsigned int wr_ptr;
	unsigned int num_rd_ptr;
	unsigned int reserve2;  /* Reserve for Red Zone */
	unsigned int reserve3;  /* Reserve for Red Zone */

	unsigned int rd_ptr[4];

	int file_offset;
	int req_file_offset;
	int file_size;

	/* Can't be sought if data is streamed by HTTP */
	int b_seekable;
};

struct RBUF_HEADER_ARM {
	unsigned long magic;
	unsigned long begin_addr;
	unsigned long size;

	unsigned long buf_id;

	unsigned long wr_ptr;
	unsigned long num_rd_ptr;
	unsigned long reserve2;
	unsigned long reserve3;

	unsigned long rd_ptr[4];

	long file_offset;
	long req_file_offset;
	long file_size;

	long b_seekable;
};

struct RPCRES {
	int result;
	int data;
};

//For setting ATV clock RPC(defined in rtk_snd.c)
#ifndef RPC_ACPU_NOT_READY
#define RPC_ACPU_NOT_READY -3
#endif

#ifdef CONFIG_ARM64
#define ALIGN4 (0xFFFFFFFFFFFFFFFCLL)
#else
#define ALIGN4 (0xFFFFFFFC)
#endif

enum MIXER_ADDR {
	MIXER_ADDR_0,
	MIXER_ADDR_1,
	MIXER_ADDR_2,
	MIXER_ADDR_3,
	MIXER_ADDR_4,
	MIXER_ADDR_5,
	MIXER_ADDR_6,
	MIXER_ADDR_7,
	MIXER_ADDR_MAX
};

struct snd_card_mars {
	struct snd_card *card;
	spinlock_t mixer_lock;
	struct work_struct work_volume;
	struct mutex rpc_lock;
	int ao_pin_id[MIXER_ADDR_MAX];
	int ao_flash_volume[MIXER_ADDR_MAX];
	int ao_flash_change[MIXER_ADDR_MAX];
};

enum AUDIO_SW_PATH {
	AUDIO_PATH_DECODER_AO = 0,
	AUDIO_PATH_AO,
	AUDIO_PATH_AO_BYPASS
};

enum RTK_SND_FLUSH_STATE {
	RTK_SND_FLUSH_STATE_NONE = 0,
	RTK_SND_FLUSH_STATE_WAIT,
	RTK_SND_FLUSH_STATE_FINISH
};

struct rtk_snd_pcm {
	struct snd_card_mars *card;
	spinlock_t lock;
	spinlock_t *pcm_lock;
	struct timer_list *timer;
	struct tasklet_struct *elapsed_tasklet;
	int elapsed_tasklet_finish;
	int elapsed_underflow_debouce;
	struct tasklet_struct trigger_tasklet;
	struct work_struct work_resume;
	struct work_struct work_pause;
	struct work_struct work_flush;
	uint32_t empty_timeout;
	int running;

	enum RTK_SND_FLUSH_STATE flush_state;
	unsigned int pcm_buffer_head;
	unsigned int pcm_size;		/* buffer sizze */
	unsigned int pcm_count;		/* period length */
	unsigned int pcm_bps;		/* bytes per second */
	unsigned int pcm_jiffie;	/* bytes per one jiffie */
	unsigned int pcm_irq_pos;	/* IRQ position */
	unsigned int pcm_buf_pos;	/* position in buffer */
	unsigned int remain_sample;

	snd_pcm_access_t access;	/* access mode */
	snd_pcm_format_t format;	/* SNDRV_PCM_FORMAT_* */
	unsigned int rate;		/* rate in Hz */
	unsigned int channels;		/* channels */
	snd_pcm_uframes_t period_size;	/* period size */
	unsigned int periods;		/* periods */
	snd_pcm_uframes_t buffer_size;	/* buffer size */
	unsigned int sample_bits;

	snd_pcm_uframes_t buffer_byte_size;	/* buffer size */

	unsigned int sample_jiffies;
	unsigned int period_jiffies;
	unsigned int wp;
	unsigned int rp_real;
	unsigned int out_sample_width;
	int output_frame_bytes;
	int input_frame_bytes;
	int output_sample_bytes;
	int input_sample_bytes;

	struct RBUF_HEADER_ARM ring_bak[8];
	/* ALSA buffer control */
	snd_pcm_uframes_t appl_ptr;
	/* buffer control */
	int freerun;
	unsigned int ring_init;
	unsigned int extend_to_32be_ratio;
	/* realtek hw control */
	int ao_agent;
	int ao_pin_id;
	int dec_agent;
	int dec_pin_id;
	int agent_id;
	int pin_id;
	int volume;
	int volume_change;
	enum AUDIO_SW_PATH audiopath;
	struct page *page;
	struct RBUF_HEADER *ring; /* realtek hw ring buffer control */
	struct RBUF_HEADER *inband; /* realtek hw ring buffer control */

	struct RBUF_HEADER hw_ring[8];
	struct RBUF_HEADER hw_inband_ring[8];
	unsigned int hw_inband_data[256];

	struct RBUF_HEADER *ao_in_ring;
	struct RBUF_HEADER ao_in_ring_instance[8];

	unsigned int *ao_in_ring_p[8];
	struct snd_pcm_substream *substream;

	dma_addr_t phy_addr; /* for UNCAC_BASE */

	long total_data_wb;	/* total data write in byte */
	long pre_time_ms; /* last time that updata wp in millisecond */
	long current_time_ms; /* current time in millisecond */
	unsigned long pre_wr_ptr;

	long max_level; /* max data in ring buffer */
	long min_level; /* min data in ring buffer */
};









static int audio_send_rpc_command(int opt,
	unsigned long command, unsigned long param1,
	unsigned long param2, unsigned long param2_LE,
	unsigned long *retvalue)
{
	int ret, count;
	struct RPCRES *audio_ret;
	ret = 0;
	count = 0;
	alog_debug("[ALSA] start audio_send_rpc_command\n");

#if 1
	do {
		ret = send_rpc_command(opt, command, param1, param2, retvalue);

		if (ret == RPC_FAIL) {
			alog_err("[ALSA] RPC to ACPU fail!!\n");
			return -1;
		}

		if (ret == RPC_OK)
			break;

		// RPC_ACPU_NOT_READY
		msleep(100);
		count++;
	} while (count <= 100);

	if (ret == RPC_ACPU_NOT_READY) {
		alog_err("[ALSA] wait ACPU ready timeout!!!\n");
		return -1;
	}
#else
	if (send_rpc_command(opt, command, param1, param2, retvalue))
		ret = -1;
#endif

	alog_debug("command %lx, param1 %lx, param2_LE %lx, param2 %lx, retvalue %p\n",
		command, param1, param2_LE, param2, retvalue);

	audio_ret = (struct RPCRES *)param2_LE;

	if (command == ENUM_KERNEL_RPC_CHECK_READY ||
	command == ENUM_KERNEL_RPC_PRIVATEINFO ||
	command == ENUM_KERNEL_RPC_GET_MUTE_N_VOLUME) {
		if (*retvalue != S_OK) {
			alog_err("[ALSA] RPC S_OK fail\n");
			alog_err("[ALSA] retvalue %lx\n", *retvalue);
			ret = -1;
		}
	} else {
		if (*retvalue != S_OK || ntohl(audio_ret->result) != S_OK) {
			alog_err("[ALSA] RPC S_OK fail\n");
			alog_err("[ALSA] retvalue %lx, result %x, command %lx\n",
				*retvalue, ntohl(audio_ret->result), command);
			ret = -1;
		}
	}

	return ret;
}

int32_t rtk_snd_set_atv_clock(AUDIO_RPC_SET_ATV_CLOCK *atv_clk_info)
{	
	AUDIO_RPC_SET_ATV_CLOCK *info, *info_audio;
	struct RPCRES *res, *res_audio;
	unsigned long ret;

	dma_addr_t dat;
	void *p;

	if(!audio_driver_data) {
		alog_err("audio_driver_data is NULL!!!\n");
		return -1;
	}
	if(atv_clk_info == NULL)
	{
		alog_err("atv_clk_info is NULL\n");
		return -1;
	}

	audio_driver_data->clsdev->dma_mask = &audio_driver_data->clsdev->coherent_dma_mask;

	if(dma_set_mask(audio_driver_data->clsdev, DMA_BIT_MASK(32))) {
		alog_err("DMA not supported\n");
	}

	arch_setup_dma_ops(audio_driver_data->clsdev, 0, 0, NULL, false);
	p = dma_alloc_coherent(audio_driver_data->clsdev, 4096, &dat, GFP_KERNEL | __GFP_DMA);

	if (!p) {
		alog_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	info = p;
	info_audio = (AUDIO_RPC_SET_ATV_CLOCK *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(AUDIO_RPC_SET_ATV_CLOCK) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(AUDIO_RPC_SET_ATV_CLOCK) + 8) &
			0xFFFFFFFC));

	alog_debug("[atv_clk_info] %ld %d", atv_clk_info->instanceID, atv_clk_info->atv_type);

	/* send atv clock info */
	info->instanceID = htonl(atv_clk_info->instanceID); //endian swap
	info->atv_type = htonl(atv_clk_info->atv_type);	//endian swap

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_AIN_ATV_SET_CLOCK,
		(unsigned int) info_audio,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		alog_err("%s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(audio_driver_data->clsdev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(audio_driver_data->clsdev, 4096, p, dat);

	return 0;
}

int32_t rtk_snd_set_decoder_mute(bool mute, ENUM_AI_PATH path_sel)
{	
	AUDIO_CONFIG_COMMAND *vir_audioConfig, *phy_audioConfig;
	struct RPCRES *res, *res_audio;
	unsigned long ret;
	dma_addr_t dat;
	void *p;

	int ch;

	if(!audio_driver_data) {
		alog_err("audio_driver_data is NULL!!!\n");
		return -1;
	}

	audio_driver_data->clsdev->dma_mask = &audio_driver_data->clsdev->coherent_dma_mask;

	if(dma_set_mask(audio_driver_data->clsdev, DMA_BIT_MASK(32))) {
		alog_err("DMA not supported\n");
	}

	arch_setup_dma_ops(audio_driver_data->clsdev, 0, 0, NULL, false);
	p = dma_alloc_coherent(audio_driver_data->clsdev, 4096, &dat, GFP_KERNEL | __GFP_DMA);

	if (!p) {
		alog_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	vir_audioConfig = p;
	phy_audioConfig = (AUDIO_CONFIG_COMMAND *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(AUDIO_CONFIG_COMMAND) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(AUDIO_CONFIG_COMMAND) + 8) &
			0xFFFFFFFC));

	/* send sw decoder info */
    	vir_audioConfig->msg_id = htonl(AUDIO_CONFIG_CMD_SET_AI_VOLUME);
    	vir_audioConfig->value[0] = htonl(true); //always enable SET_AI_VOLUME function
    	vir_audioConfig->value[1] = htonl(path_sel);

	//if mute = 1, volume = ENUM_AUDIO_DVOL_MUTE, ENUM_AUDIO_DVOL_K0p0DB AIN_VOL_0DB
	for(ch=0;ch<8;ch++)
    	{
        	vir_audioConfig->value[2 + ch] = htonl(mute?ENUM_AUDIO_DVOL_MUTE:ENUM_AUDIO_DVOL_K0p0DB);
    	}
	

	alog_debug("[atv_decoder_info] %x %x", mute, path_sel);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_ATV_MUTE,
		(unsigned int) phy_audioConfig,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		alog_err("%s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(audio_driver_data->clsdev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(audio_driver_data->clsdev, 4096, p, dat);

	return 0;
}

int32_t rtk_snd_enhance_btsc_separation(bool enable)
{	
	AUDIO_CONFIG_COMMAND *vir_audioConfig, *phy_audioConfig;
	struct RPCRES *res, *res_audio;
	unsigned long ret;
	dma_addr_t dat;
	void *p;

	if(!audio_driver_data) {
		alog_err("audio_driver_data is NULL!!!\n");
		return -1;
	}

	audio_driver_data->clsdev->dma_mask = &audio_driver_data->clsdev->coherent_dma_mask;

	if(dma_set_mask(audio_driver_data->clsdev, DMA_BIT_MASK(32))) {
		alog_err("DMA not supported\n");
	}

	arch_setup_dma_ops(audio_driver_data->clsdev, 0, 0, NULL, false);
	p = dma_alloc_coherent(audio_driver_data->clsdev, 4096, &dat, GFP_KERNEL | __GFP_DMA);

	if (!p) {
		alog_err("[ALSA] %d alloc memory fail\n", __LINE__);
		return -ENOMEM;
	}

	vir_audioConfig = p;
	phy_audioConfig = (AUDIO_CONFIG_COMMAND *)((uint) dat|0xa0000000);

	res = (struct RPCRES *)
		((((unsigned long)p + sizeof(AUDIO_CONFIG_COMMAND) + 8) & ALIGN4));
	res_audio = (struct RPCRES *)
		(((((unsigned int) dat|0xa0000000) + sizeof(AUDIO_CONFIG_COMMAND) + 8) &
			0xFFFFFFFC));

	/* send btsc separation enhance config */
    	vir_audioConfig->value[0] = htonl(enable);
    	vir_audioConfig->value[1] = htonl(5); //down 5dB if L/R diff between hi_th, low_th
    	vir_audioConfig->value[2] = htonl(15); //low_th
		vir_audioConfig->value[3] = htonl(25); //high_th	

	alog_debug("[atv_btsc_enhance_info] %d", enable);

	if (audio_send_rpc_command(RPC_AUDIO,
		ENUM_KERNEL_RPC_BTSC_CTL,
		(unsigned int) phy_audioConfig,
		(unsigned int) res_audio,
		(unsigned long) res, &ret)) {
		alog_err("%s %d RPC fail\n", __func__, __LINE__);
		dma_free_coherent(audio_driver_data->clsdev, 4096, p, dat);
		return -1;
	}

	dma_free_coherent(audio_driver_data->clsdev, 4096, p, dat);

	return 0;
}