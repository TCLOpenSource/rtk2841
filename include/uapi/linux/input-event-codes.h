/*
 * Input event codes
 *
 *    *** IMPORTANT ***
 * This file is not only included from C-code but also from devicetree source
 * files. As such this file MUST only contain comments and defines.
 *
 * Copyright (c) 1999-2002 Vojtech Pavlik
 * Copyright (c) 2015 Hans de Goede <hdegoede@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 */
#ifndef _UAPI_INPUT_EVENT_CODES_H
#define _UAPI_INPUT_EVENT_CODES_H

/*
 * Device properties and quirks
 */

#define INPUT_PROP_POINTER		0x00	/* needs a pointer */
#define INPUT_PROP_DIRECT		0x01	/* direct input devices */
#define INPUT_PROP_BUTTONPAD		0x02	/* has button(s) under pad */
#define INPUT_PROP_SEMI_MT		0x03	/* touch rectangle only */
#define INPUT_PROP_TOPBUTTONPAD		0x04	/* softbuttons at top of pad */
#define INPUT_PROP_POINTING_STICK	0x05	/* is a pointing stick */
#define INPUT_PROP_ACCELEROMETER	0x06	/* has accelerometer */

#define INPUT_PROP_MAX			0x1f
#define INPUT_PROP_CNT			(INPUT_PROP_MAX + 1)

/*
 * Event types
 */

#define EV_SYN			0x00
#define EV_KEY			0x01
#define EV_REL			0x02
#define EV_ABS			0x03
#define EV_MSC			0x04
#define EV_SW			0x05
#define EV_LED			0x11
#define EV_SND			0x12
#define EV_REP			0x14
#define EV_FF			0x15
#define EV_PWR			0x16
#define EV_FF_STATUS		0x17
#ifdef CONFIG_RTK_KDRV_TV030_IR
#define EV_KEY_TCL		0x19
#endif
#define EV_MAX			0x1f
#define EV_CNT			(EV_MAX+1)

/*
 * Synchronization events.
 */

#define SYN_REPORT		0
#define SYN_CONFIG		1
#define SYN_MT_REPORT		2
#define SYN_DROPPED		3
#define SYN_MAX			0xf
#define SYN_CNT			(SYN_MAX+1)

/*
 * Keys and buttons
 *
 * Most of the keys/buttons are modeled after USB HUT 1.12
 * (see http://www.usb.org/developers/hidpage).
 * Abbreviations in the comments:
 * AC - Application Control
 * AL - Application Launch Button
 * SC - System Control
 */

#define KEY_RESERVED		0
#define KEY_ESC			1
#define KEY_1			2
#define KEY_2			3
#define KEY_3			4
#define KEY_4			5
#define KEY_5			6
#define KEY_6			7
#define KEY_7			8
#define KEY_8			9
#define KEY_9			10
#define KEY_0			11
#define KEY_MINUS		12
#define KEY_EQUAL		13
#define KEY_BACKSPACE		14
#define KEY_TAB			15
#define KEY_Q			16
#define KEY_W			17
#define KEY_E			18
#define KEY_R			19
#define KEY_T			20
#define KEY_Y			21
#define KEY_U			22
#define KEY_I			23
#define KEY_O			24
#define KEY_P			25
#define KEY_LEFTBRACE		26
#define KEY_RIGHTBRACE		27
#define KEY_ENTER		28
#define KEY_LEFTCTRL		29
#define KEY_A			30
#define KEY_S			31
#define KEY_D			32
#define KEY_F			33
#define KEY_G			34
#define KEY_H			35
#define KEY_J			36
#define KEY_K			37
#define KEY_L			38
#define KEY_SEMICOLON		39
#define KEY_APOSTROPHE		40
#define KEY_GRAVE		41
#define KEY_LEFTSHIFT		42
#define KEY_BACKSLASH		43
#define KEY_Z			44
#define KEY_X			45
#define KEY_C			46
#define KEY_V			47
#define KEY_B			48
#define KEY_N			49
#define KEY_M			50
#define KEY_COMMA		51
#define KEY_DOT			52
#define KEY_SLASH		53
#define KEY_RIGHTSHIFT		54
#define KEY_KPASTERISK		55
#define KEY_LEFTALT		56
#define KEY_SPACE		57
#define KEY_CAPSLOCK		58
#define KEY_F1			59
#define KEY_F2			60
#define KEY_F3			61
#define KEY_F4			62
#define KEY_F5			63
#define KEY_F6			64
#define KEY_F7			65
#define KEY_F8			66
#define KEY_F9			67
#define KEY_F10			68
#define KEY_NUMLOCK		69
#define KEY_SCROLLLOCK		70
#define KEY_KP7			71
#define KEY_KP8			72
#define KEY_KP9			73
#define KEY_KPMINUS		74
#define KEY_KP4			75
#define KEY_KP5			76
#define KEY_KP6			77
#define KEY_KPPLUS		78
#define KEY_KP1			79
#define KEY_KP2			80
#define KEY_KP3			81
#define KEY_KP0			82
#define KEY_KPDOT		83

#ifdef CONFIG_CUSTOMER_TV030
#define KEY_MOUSE_KEY   84
#endif
#if defined(CONFIG_RTK_KDRV_TV036_10D_IR)

#define KEY_TTX_SUBPAGE	590
#define KEY_FAV_ADD		591
#define KEY_FAV 		592
#define KEY_FAV_SUB 	593
#define KEY_TTX_CANCEL 	594
#define KEY_REC_LIST 	595
#endif
#define KEY_JUMP        596
#define KEY_CAPTION     598

#define KEY_ZENKAKUHANKAKU	85
#define KEY_102ND		86
#define KEY_F11			87
#define KEY_F12			88
#define KEY_RO			89
#define KEY_KATAKANA		90
#define KEY_HIRAGANA		91
#define KEY_HENKAN		92
#define KEY_KATAKANAHIRAGANA	93
#define KEY_MUHENKAN		94
#define KEY_KPJPCOMMA		95
#define KEY_KPENTER		96
#define KEY_RIGHTCTRL		97
#define KEY_KPSLASH		98
#define KEY_SYSRQ		99
#define KEY_RIGHTALT		100
#define KEY_LINEFEED		101
#define KEY_HOME		102
#define KEY_UP			103
#define KEY_PAGEUP		104
#define KEY_LEFT		105
#define KEY_RIGHT		106
#define KEY_END			107
#define KEY_DOWN		108
#define KEY_PAGEDOWN		109
#define KEY_INSERT		110
#define KEY_DELETE		111
#define KEY_MACRO		112
#define KEY_MUTE		113
#define KEY_VOLUMEDOWN		114
#define KEY_VOLUMEUP		115
#define KEY_POWER		116	/* SC System Power Down */
#define KEY_KPEQUAL		117
#define KEY_KPPLUSMINUS		118
#define KEY_PAUSE		119
#define KEY_SCALE		120	/* AL Compiz Scale (Expose) */

#define KEY_KPCOMMA		121
#define KEY_HANGEUL		122
#define KEY_HANGUEL		KEY_HANGEUL
#define KEY_HANJA		123
#define KEY_YEN			124
#define KEY_LEFTMETA		125
#define KEY_RIGHTMETA		126
#define KEY_COMPOSE		127

#define KEY_STOP		128	/* AC Stop */
#define KEY_AGAIN		129
#define KEY_PROPS		130	/* AC Properties */
#define KEY_UNDO		131	/* AC Undo */
#define KEY_FRONT		132
#define KEY_COPY		133	/* AC Copy */
#define KEY_OPEN		134	/* AC Open */
#define KEY_PASTE		135	/* AC Paste */
#define KEY_FIND		136	/* AC Search */
#define KEY_CUT			137	/* AC Cut */
#define KEY_HELP		138	/* AL Integrated Help Center */
#define KEY_MENU		139	/* Menu (show menu) */
#define KEY_CALC		140	/* AL Calculator */
#define KEY_SETUP		141
#define KEY_SLEEP		142	/* SC System Sleep */
#define KEY_WAKEUP		143	/* System Wake Up */
#define KEY_FILE		144	/* AL Local Machine Browser */
#define KEY_SENDFILE		145
#define KEY_DELETEFILE		146
#define KEY_XFER		147
#define KEY_PROG1		148
#define KEY_PROG2		149
#define KEY_WWW			150	/* AL Internet Browser */
#define KEY_MSDOS		151
#define KEY_COFFEE		152	/* AL Terminal Lock/Screensaver */
#define KEY_SCREENLOCK		KEY_COFFEE
#define KEY_ROTATE_DISPLAY	153	/* Display orientation for e.g. tablets */
#define KEY_DIRECTION		KEY_ROTATE_DISPLAY
#define KEY_CYCLEWINDOWS	154
#define KEY_MAIL		155
#define KEY_BOOKMARKS		156	/* AC Bookmarks */
#define KEY_COMPUTER		157
#define KEY_BACK		158	/* AC Back */
#define KEY_FORWARD		159	/* AC Forward */
#define KEY_CLOSECD		160
#define KEY_EJECTCD		161
#define KEY_EJECTCLOSECD	162
#define KEY_NEXTSONG		163
#define KEY_PLAYPAUSE		164
#define KEY_PREVIOUSSONG	165
#define KEY_STOPCD		166
#define KEY_RECORD		167
#define KEY_REWIND		168
#define KEY_PHONE		169	/* Media Select Telephone */
#define KEY_ISO			170
#define KEY_CONFIG		171	/* AL Consumer Control Configuration */
#define KEY_HOMEPAGE		172	/* AC Home */
#define KEY_REFRESH		173	/* AC Refresh */
#define KEY_EXIT		174	/* AC Exit */
#define KEY_MOVE		175
#define KEY_EDIT		176
#define KEY_SCROLLUP		177
#define KEY_SCROLLDOWN		178
#define KEY_KPLEFTPAREN		179
#define KEY_KPRIGHTPAREN	180
#define KEY_NEW			181	/* AC New */
#define KEY_REDO		182	/* AC Redo/Repeat */

#define KEY_F13			183
#define KEY_F14			184
#define KEY_F15			185
#define KEY_F16			186
#define KEY_F17			187
#define KEY_F18			188
#define KEY_F19			189
#define KEY_F20			190
#define KEY_F21			191
#define KEY_F22			192
#define KEY_F23			193
#define KEY_F24			194

#define KEY_PLAYCD		200
#define KEY_PAUSECD		201
#define KEY_PROG3		202
#define KEY_PROG4		203
#define KEY_DASHBOARD		204	/* AL Dashboard */
#define KEY_SUSPEND		205
#define KEY_CLOSE		206	/* AC Close */
#define KEY_PLAY		207
#define KEY_FASTFORWARD		208
#define KEY_BASSBOOST		209
#define KEY_PRINT		210	/* AC Print */
#define KEY_HP			211
#define KEY_CAMERA		212
#define KEY_SOUND		213
#define KEY_QUESTION		214
#define KEY_EMAIL		215
#define KEY_CHAT		216
#define KEY_SEARCH		217
#define KEY_CONNECT		218
#define KEY_FINANCE		219	/* AL Checkbook/Finance */
#define KEY_SPORT		220
#define KEY_SHOP		221
#define KEY_ALTERASE		222
#define KEY_CANCEL		223	/* AC Cancel */
#define KEY_BRIGHTNESSDOWN	224
#define KEY_BRIGHTNESSUP	225
#define KEY_MEDIA		226

#define KEY_SWITCHVIDEOMODE	227	/* Cycle between available video
					   outputs (Monitor/LCD/TV-out/etc) */
#define KEY_KBDILLUMTOGGLE	228
#define KEY_KBDILLUMDOWN	229
#define KEY_KBDILLUMUP		230

#define KEY_SEND		231	/* AC Send */
#define KEY_REPLY		232	/* AC Reply */
#define KEY_INFO_DEFINE		195	/* AC INFO */
#define KEY_FORWARDMAIL		233	/* AC Forward Msg */
#define KEY_SAVE		234	/* AC Save */
#define KEY_DOCUMENTS		235

#define KEY_BATTERY		236

#define KEY_BLUETOOTH		237
#define KEY_WLAN		238
#define KEY_UWB			239

#define KEY_UNKNOWN		240

#define KEY_VIDEO_NEXT		241	/* drive next video source */
#define KEY_VIDEO_PREV		242	/* drive previous video source */
#define KEY_BRIGHTNESS_CYCLE	243	/* brightness up, after max is min */
#define KEY_BRIGHTNESS_AUTO	244	/* Set Auto Brightness: manual
					  brightness control is off,
					  rely on ambient */
#define KEY_BRIGHTNESS_ZERO	KEY_BRIGHTNESS_AUTO
#define KEY_DISPLAY_OFF		245	/* display device to off state */

#define KEY_WWAN		246	/* Wireless WAN (LTE, UMTS, GSM, etc.) */
#define KEY_WIMAX		KEY_WWAN
#define KEY_RFKILL		247	/* Key that controls all radios */

#define KEY_MICMUTE		248	/* Mute / unmute the microphone */
#ifdef CONFIG_CUSTOMER_TV030
#define KEY_LANG    199
#define KEY_PICTURE 249
#define KEY_RF_LINK_STOP  252
#define KEY_MTS		253
#define KEY_TCL_TUNER       0xfe
 
#define KEY_RC_DOT          0x10a
#define KEY_USB_MEDIA		0x1e5
#define KEY_LAST_CHANNEL    0x1c7 
#define KEY_NUMBER          0x233
#define KEY_YOUTUBE         0x239
#define KEY_NETFLIX_FORWARD 0x23e
#define KEY_NETFLIX_NEXT    0X240
#define KEY_NETFLIX_FF      0x241
#define KEY_NETFLIX_STOP    0x242
#define KEY_NETFLIX_FB      0x243
#define KEY_CMP		        0x24d
#define KEY_VGA		        0x24e
#define KEY_AV1		        0x24f
#define KEY_MEDIA_PLAY      0x23f
#define KEY_TV_ON	        0x253
#define KEY_TV_OFF	        0x254
#define KEY_HDMI3	        0x252
#define KEY_HDMI4	        0x255
#define KEY_HDMI_1           0x256
#define KEY_HDMI2           0x257 
#define KEY_AV2		        0x258
#define KEY_APP_CAREVISION  0X25a




#else
#define KEY_RecentApplicationsDialog 249
#endif
#define KEY_SCREENSHOT	250

#define KEY_VOLUME_UP_ANDROID_O      0x2fe
#define KEY_VOLUME_DOWN_ANDROID_O    0x2fd
#define KEY_MUTE_ANDROID_O           0x2fc

/* Code 255 is reserved for special needs of AT keyboard driver */

#define BTN_MISC		0x100
#define BTN_0			0x100
#define BTN_1			0x101
#define BTN_2			0x102
#define BTN_3			0x103
#define BTN_4			0x104
#define BTN_5			0x105
#define BTN_6			0x106
#define BTN_7			0x107
#define BTN_8			0x108
#define BTN_9			0x109

#define BTN_MOUSE		0x110
#define BTN_LEFT		0x110
#define BTN_RIGHT		0x111
#define BTN_MIDDLE		0x112
#define BTN_SIDE		0x113
#define BTN_EXTRA		0x114
#define BTN_FORWARD		0x115
#define BTN_BACK		0x116
#define BTN_TASK		0x117

#define BTN_JOYSTICK		0x120
#define BTN_TRIGGER		0x120
#define BTN_THUMB		0x121
#define BTN_THUMB2		0x122
#define BTN_TOP			0x123
#define BTN_TOP2		0x124
#define BTN_PINKIE		0x125
#define BTN_BASE		0x126
#define BTN_BASE2		0x127
#define BTN_BASE3		0x128
#define BTN_BASE4		0x129
#define BTN_BASE5		0x12a
#define BTN_BASE6		0x12b
#define BTN_DEAD		0x12f

#define BTN_GAMEPAD		0x130
#define BTN_SOUTH		0x130
#define BTN_A			BTN_SOUTH
#define BTN_EAST		0x131
#define BTN_B			BTN_EAST
#define BTN_C			0x132
#define BTN_NORTH		0x133
#define BTN_X			BTN_NORTH
#define BTN_WEST		0x134
#define BTN_Y			BTN_WEST
#define BTN_Z			0x135
#define BTN_TL			0x136
#define BTN_TR			0x137
#define BTN_TL2			0x138
#define BTN_TR2			0x139
#define BTN_SELECT		0x13a
#define BTN_START		0x13b
#define BTN_MODE		0x13c
#define BTN_THUMBL		0x13d
#define BTN_THUMBR		0x13e

#define BTN_DIGI		0x140
#define BTN_TOOL_PEN		0x140
#define BTN_TOOL_RUBBER		0x141
#define BTN_TOOL_BRUSH		0x142
#define BTN_TOOL_PENCIL		0x143
#define BTN_TOOL_AIRBRUSH	0x144
#define BTN_TOOL_FINGER		0x145
#define BTN_TOOL_MOUSE		0x146
#define BTN_TOOL_LENS		0x147
#define BTN_TOOL_QUINTTAP	0x148	/* Five fingers on trackpad */
#define BTN_TOUCH		0x14a
#define BTN_STYLUS		0x14b
#define BTN_STYLUS2		0x14c
#define BTN_TOOL_DOUBLETAP	0x14d
#define BTN_TOOL_TRIPLETAP	0x14e
#define BTN_TOOL_QUADTAP	0x14f	/* Four fingers on trackpad */

#define BTN_WHEEL		0x150
#define BTN_GEAR_DOWN		0x150
#define BTN_GEAR_UP		0x151

#define KEY_OK			0x160
#define KEY_SELECT		0x161
#define KEY_GOTO		0x162
#define KEY_CLEAR		0x163
#define KEY_POWER2		0x164
#define KEY_OPTION		0x165
#define KEY_INFO		0x166	/* AL OEM Features/Tips/Tutorial */
#define KEY_TIME		0x167
#define KEY_VENDOR		0x168
#define KEY_ARCHIVE		0x169
#define KEY_PROGRAM		0x16a	/* Media Select Program Guide */
#define KEY_CHANNEL		0x16b
#define KEY_FAVORITES		0x16c
#define KEY_EPG			0x16d
#define KEY_PVR			0x16e	/* Media Select Home */
#define KEY_MHP			0x16f
#define KEY_LANGUAGE		0x170
#define KEY_TITLE		0x171
#define KEY_SUBTITLE		0x172
#define KEY_ANGLE		0x173
#define KEY_ZOOM		0x174
#define KEY_MODE		0x175
#define KEY_KEYBOARD		0x176
#define KEY_SCREEN		0x177
#define KEY_PC			0x178	/* Media Select Computer */
#define KEY_TV			0x179	/* Media Select TV */
#define KEY_TV2			0x17a	/* Media Select Cable */
#define KEY_VCR			0x17b	/* Media Select VCR */
#define KEY_VCR2		0x17c	/* VCR Plus */
#define KEY_SAT			0x17d	/* Media Select Satellite */
#define KEY_SAT2		0x17e
#define KEY_CD			0x17f	/* Media Select CD */
#define KEY_TAPE		0x180	/* Media Select Tape */
#define KEY_RADIO		0x181
#define KEY_TUNER		0x182	/* Media Select Tuner */
#define KEY_PLAYER		0x183
#define KEY_TEXT		0x184
#define KEY_DVD			0x185	/* Media Select DVD */
#define KEY_AUX			0x186
#define KEY_MP3			0x187
#define KEY_AUDIO		0x188	/* AL Audio Browser */
#define KEY_VIDEO		0x189	/* AL Movie Browser */
#define KEY_DIRECTORY		0x18a
#define KEY_LIST		0x18b
#define KEY_MEMO		0x18c	/* Media Select Messages */
#define KEY_CALENDAR		0x18d
#define KEY_RED			0x18e
#define KEY_GREEN		0x18f
#define KEY_YELLOW		0x190
#define KEY_BLUE		0x191
#define KEY_CHANNELUP		0x192	/* Channel Increment */
#define KEY_CHANNELDOWN		0x193	/* Channel Decrement */
#define KEY_FIRST		0x194
#define KEY_LAST		0x195	/* Recall Last */
#define KEY_AB			0x196
#define KEY_NEXT		0x197
#define KEY_RESTART		0x198
#define KEY_SLOW		0x199
#define KEY_SHUFFLE		0x19a
#define KEY_BREAK		0x19b
#define KEY_PREVIOUS		0x19c
#define KEY_DIGITS		0x19d
#define KEY_TEEN		0x19e
#define KEY_TWEN		0x19f
#define KEY_VIDEOPHONE		0x1a0	/* Media Select Video Phone */
#define KEY_GAMES		0x1a1	/* Media Select Games */
#define KEY_ZOOMIN		0x1a2	/* AC Zoom In */
#define KEY_ZOOMOUT		0x1a3	/* AC Zoom Out */
#define KEY_ZOOMRESET		0x1a4	/* AC Zoom */
#define KEY_WORDPROCESSOR	0x1a5	/* AL Word Processor */
#define KEY_EDITOR		0x1a6	/* AL Text Editor */
#define KEY_SPREADSHEET		0x1a7	/* AL Spreadsheet */
#define KEY_GRAPHICSEDITOR	0x1a8	/* AL Graphics Editor */
#define KEY_PRESENTATION	0x1a9	/* AL Presentation App */
#define KEY_DATABASE		0x1aa	/* AL Database App */
#define KEY_NEWS		0x1ab	/* AL Newsreader */
#define KEY_VOICEMAIL		0x1ac	/* AL Voicemail */
#define KEY_ADDRESSBOOK		0x1ad	/* AL Contacts/Address Book */
#define KEY_MESSENGER		0x1ae	/* AL Instant Messaging */
#define KEY_DISPLAYTOGGLE	0x1af	/* Turn display (LCD) on and off */
#define KEY_BRIGHTNESS_TOGGLE	KEY_DISPLAYTOGGLE
#define KEY_SPELLCHECK		0x1b0   /* AL Spell Check */
#define KEY_LOGOFF		0x1b1   /* AL Logoff */

#define KEY_DOLLAR		0x1b2
#define KEY_EURO		0x1b3

#define KEY_FRAMEBACK		0x1b4	/* Consumer - transport controls */
#define KEY_FRAMEFORWARD	0x1b5
#define KEY_CONTEXT_MENU	0x1b6	/* GenDesc - system context menu */
#define KEY_MEDIA_REPEAT	0x1b7	/* Consumer - transport control */
#define KEY_10CHANNELSUP	0x1b8	/* 10 channels up (10+) */
#define KEY_10CHANNELSDOWN	0x1b9	/* 10 channels down (10-) */
#define KEY_IMAGES		0x1ba	/* AL Image Browser */

#define KEY_24G_TO_INFRARED 0x1bb
#define KEY_INFRARED_TO_24G 0x1bc
#define KEY_KK_LANGUAGE 0x1bd
#define KEY_KK_NET 0x1be
#define KEY_KK_VGA 0x1bf

#define KEY_DEL_EOL		0x1c0
#define KEY_DEL_EOS		0x1c1
#define KEY_INS_LINE		0x1c2
#define KEY_DEL_LINE		0x1c3

 //wangzhh add for factory remote control 20130604
#define	KEY_VOLUME_DETECT  0x1c4
#define	KEY_FACTORY_MENU 0x1c5
#define	KEY_BURN_TV 0x1c6
#define	KEY_KK_FAC_RESET 0x1c7
#ifdef CONFIG_CUSTOMER_TV030
#define	KEY_QUICK_MENU   0x1c8
#else
#define	KEY_BALANCE 0x1c8
#endif
#define   KEY_BACKLIGHT_DETECT 0x1c9
#define   KEY_MIC_DETECT 0x1ca
#define   KEY_KK_F1 0x1cb
#define   KEY_KK_F2 0x1cc
#define   KEY_KK_F3  0x1cd
#define   KEY_KK_PROGRAM_FAVORITE  0x1ce
#define   KEY_KK_PROGRAM_LIST  0x1cf


#define KEY_FN			0x1d0
#define KEY_FN_ESC		0x1d1
#define KEY_FN_F1		0x1d2
#define KEY_FN_F2		0x1d3
#define KEY_FN_F3		0x1d4
#define KEY_FN_F4		0x1d5
#define KEY_FN_F5		0x1d6
#define KEY_FN_F6		0x1d7
#define KEY_FN_F7		0x1d8
#define KEY_FN_F8		0x1d9
#define KEY_FN_F9		0x1da
#define KEY_FN_F10		0x1db
#define KEY_FN_F11		0x1dc
#define KEY_FN_F12		0x1dd
#define KEY_FN_1		0x1de
#define KEY_FN_2		0x1df
#define KEY_FN_D		0x1e0
#define KEY_FN_E		0x1e1
#define KEY_FN_F		0x1e2
#define KEY_FN_S		0x1e3
#define KEY_FN_B		0x1e4

 //wangzhh add for factory remote control 20130604
#define	KEY_KK_CHANNEL_RETURN  0x1e5
#define   KEY_KK_EPG  0x1e6
#define   KEY_KK_3D     0x1e7

#define	KEY_USB  0x1e8


#define	KEY_VOICE_SEARCH 0x1e9
#define	KEY_START_HANDWRITING 0x1ea
#define KEY_FINISH_HANDWRITING 0x1eb
#define KEY_HEADPHONE_INSET 0x1ec
#define KEY_HEADPHONE_PULLOUT  0x1ed

#define KEY_MOUSE_CENTERED  0x1ee
#define KEY_MOUSE_OK_DOWN  0x1ef
#define KEY_MOUSE_OK_UP  0x1f0

#define KEY_MORE	0x20c
// chenshibing,add for bluetooth remote control
#define KEY_BTCTL   0x20d

#define KEY_BRL_DOT1		0x1f1
#define KEY_BRL_DOT2		0x1f2
#define KEY_BRL_DOT3		0x1f3
#define KEY_BRL_DOT4		0x1f4
#define KEY_BRL_DOT5		0x1f5
#define KEY_BRL_DOT6		0x1f6
#define KEY_BRL_DOT7		0x1f7
#define KEY_BRL_DOT8		0x1f8
#define KEY_BRL_DOT9		0x1f9
#define KEY_BRL_DOT10		0x1fa

#define KEY_NUMERIC_0		0x200	/* used by phones, remote controls, */
#define KEY_NUMERIC_1		0x201	/* and other keypads */
#define KEY_NUMERIC_2		0x202
#define KEY_NUMERIC_3		0x203
#define KEY_NUMERIC_4		0x204
#define KEY_NUMERIC_5		0x205
#define KEY_NUMERIC_6		0x206
#define KEY_NUMERIC_7		0x207
#define KEY_NUMERIC_8		0x208
#define KEY_NUMERIC_9		0x209
#define KEY_NUMERIC_STAR	0x20a
#define KEY_NUMERIC_POUND	0x20b
#define KEY_NUMERIC_A		0x20c	/* Phone key A - HUT Telephony 0xb9 */
#define KEY_NUMERIC_B		0x20d
#define KEY_NUMERIC_C		0x20e
#define KEY_NUMERIC_D		0x20f

#define KEY_CAMERA_FOCUS	0x210
#define KEY_WPS_BUTTON		0x211	/* WiFi Protected Setup key */

#define KEY_TOUCHPAD_TOGGLE	0x212	/* Request switch touchpad on or off */
#define KEY_TOUCHPAD_ON		0x213
#define KEY_TOUCHPAD_OFF	0x214

#define KEY_CAMERA_ZOOMIN	0x215
#define KEY_CAMERA_ZOOMOUT	0x216
#define KEY_CAMERA_UP		0x217
#define KEY_CAMERA_DOWN		0x218
#define KEY_CAMERA_LEFT		0x219
#define KEY_CAMERA_RIGHT	0x21a

#define KEY_ATTENDANT_ON	0x21b
#define KEY_ATTENDANT_OFF	0x21c
#define KEY_ATTENDANT_TOGGLE	0x21d	/* Attendant call on or off */
#define KEY_LIGHTS_TOGGLE	0x21e	/* Reading light on or off */
#ifdef CONFIG_CUSTOMER_TV030
#define KEY_SET         0x231
#endif

#define KEY_KBDINPUTASSIST_PREV		0x260
#define KEY_KBDINPUTASSIST_NEXT		0x261
#define KEY_KBDINPUTASSIST_PREVGROUP	0x262
#define KEY_KBDINPUTASSIST_NEXTGROUP	0x263
#define KEY_KBDINPUTASSIST_ACCEPT		0x264
#define KEY_KBDINPUTASSIST_CANCEL		0x265

#define BTN_DPAD_UP		0x260
#define BTN_DPAD_DOWN		0x261
#define BTN_DPAD_LEFT		0x262
#define BTN_DPAD_RIGHT		0x263

#define KEY_ALS_TOGGLE		0x230	/* Ambient light sensor */

#define KEY_BUTTONCONFIG		0x240	/* AL Button Configuration */
#define KEY_TASKMANAGER		0x241	/* AL Task/Project Manager */
#define KEY_JOURNAL		0x242	/* AL Log/Journal/Timecard */
#define KEY_CONTROLPANEL		0x243	/* AL Control Panel */
#define KEY_APPSELECT		0x244	/* AL Select Task/Application */
#define KEY_SCREENSAVER		0x245	/* AL Screen Saver */
#define KEY_VOICECOMMAND		0x246	/* Listening Voice Command */

#define KEY_BRIGHTNESS_MIN		0x250	/* Set Brightness to Minimum */
#ifdef CONFIG_CUSTOMER_TV030

#define KEY_GLOBAL_PLAY		251	/* Set Brightness to Maximum */
#define KEY_BRIGHTNESS_MAX		0x251	/* Set Brightness to Maximum */
#else
#define KEY_BRIGHTNESS_MAX		0x251	/* Set Brightness to Maximum */
#endif

#define KEY_PICTURE_MODE    	0x220
#define KEY_SOUND_MODE      	0x221
#define KEY_DISPLAY_RATIO   	0x222
#define KEY_DISPLAY     	0x223
#define KEY_VII         	0x224
#define KEY_SOURCE      	0x225
#define KEY_SHORTCUT   		0x226
#define KEY_HAIER_USB		KEY_MEDIA
#ifdef CONFIG_CUSTOMER_TV030
#define KEY_RC_RF_UNCONNECT     0x22b
#define KEY_RF_LINK_S           0x22f  
#define KEY_RF_LINK_F           0x22d 
#endif


#define KEY_CARD_READER 0x259
//wangzhh add for customer 20130530
#define KEY_HOLD 0x26a
#define KEY_FREEZE   0x26b
#define KEY_AV    0x26c
#define KEY_YPBPR1 0x26d
#define KEY_HDMI1   0x26e
#define KEY_KK_TV   0x26f



#if defined(CONFIG_YK_54LU_SHUTTLE)||defined(CONFIG_YK_76J_SHUTTLE)||defined(CONFIG_YK_54LU)
#define KEY_NEW_SHUTTLE_LEFT   		26
#define KEY_NEW_SHUTTLE_RIGHT  	 	27
#define KEY_CENTER					28
#define KEY_MEDIA_NEXT				163
#define KEY_MEDIA_PLAY_PAUSE		164
#define KEY_MEDIA_PREVIOUS			165
#define KEY_MEDIA_STOP				166
#define KEY_MEDIA_RECORD			167
#define KEY_MEDIA_REWIND			168
#define KEY_SENSE_ALL 				183
#define KEY_SENSE_MENU				184
#define KEY_SENSE_CENTER			185
#define KEY_SENSE_BACK				186
#define KEY_SENSE_VOLUME_UP			187
#define KEY_SENSE_VOLUME_DOWN		188
#define KEY_SENSE_CHANNEL_UP		189
#define KEY_SENSE_CHANNEL_DOWN		190
#define KEY_SENSE_LEAVE				191
#define KEY_MEDIA_FAST_FORWARD		208

#define KEY_SCREEN_DISPLAY     		0x166

#define KEY_3D_DEL					0x1d0
#define KEY_ALTERNATE				0x1d1
#define KEY_VOICE       			0x1d3
#define KEY_TV_INPUT				0x1d2
#define KEY_SHARE					0x1d4
#define KEY_IMAGE_MODE    			0x1d5
#define KEY_SOUND_MODE      		0x1d6
#define KEY_DISPLAY_MODE   			0x1d7
#define KEY_MEDIA_SONG_SYSTEM		0x1d9
#define KEY_MEDIA_RELATIONSHIP		0x1da
#define KEY_MEDIA_BOOKING			0x1db
#define KEY_MEDIA_AUDIO_CONTROL		0x1dc
#define KEY_MEDIA_FUNCTION			0x1dd
#define KEY_MEDIA_ORIGINAL_SOUNDTRACK	0x1de
#define KEY_MEDIA_SELECTED_SONGS	0x1df

#define KEY_MEDIA_PRIORITY			0x1e0
#define KEY_MEDIA_DELETE			0x1e1
#define KEY_MEDIA_SCORE_DISPLAY		0x1e2
#define KEY_INPUT_NUMBER			0x1e3
#define KEY_3D_MODE     			0x1e4

#define KEY_SEEK_SIGNAL				0x1f1
#define KEY_CENTER_LONG				0x1f2
#define KEY_LOCAL_MEDIA				0x1f3
#define KEY_RESEARCH				0x1f4
#define KEY_SETTING					0x1f5
#define KEY_MYSTEP					0x1f6

#define KEY_FACTORY_FACTORY_MODE	0x200
#define KEY_FACTORY_RESET			0x201
#define KEY_FACTORY_SOURCE_ADD		0x202
#define KEY_FACTORY_SOURCE_REDUCE	0x203
#define KEY_FACTORY_OUTSET			0x204
#define KEY_FACTORY_BUS_OFF			0x205
#define KEY_FACTORY_AGING_MODE		0x206
#define KEY_FACTORY_AUTO_ADC		0x207
#define KEY_FACTORY_AV1				0x208
#define KEY_FACTORY_RF_AGC			0x209
#define KEY_FACTORY_AV2				0x20a
#define KEY_FACTORY_AV3				0x20b

#define KEY_FACTORY_S1				0x2c0
#define KEY_FACTORY_YUV1			0x2c1
#define KEY_FACTORY_YUV2			0x2c2
#define KEY_FACTORY_VGA				0x2c3
#define KEY_FACTORY_HDMI1			0x2c4
#define KEY_FACTORY_HDMI2			0x2c5
#define KEY_FACTORY_HDMI3			0x2c6
#define KEY_FACTORY_KALA_OK			0x2c7
#define KEY_FACTORY_UPLAYER			0x2c8
#define KEY_FACTORY_LAN				0x2c9
#define KEY_FACTORY_DREAM_PANEL		0x2ca
#define KEY_FACTORY_WHITE_BALANCE	0x2cb
#define KEY_FACTORY_ALONE_LISTEN	0x2cc
#define KEY_FACTORY_CA_CARD			0x2cd
#define KEY_FACTORY_BARCODE			0x2ce
#define KEY_FACTORY_SEARCH_UP		0x2cf

#define KEY_FACTORY_SEARCH_DOWN		0x2d0
#define KEY_CHILD_LOCK 				0x2d1
#define KEY_SHUTTLE_LEFT_SPEED_1	0x2d4
#define KEY_SHUTTLE_LEFT_SPEED_2	0x2d5
#define KEY_SHUTTLE_LEFT_SPEED_3	0x2d6
#define KEY_SHUTTLE_LEFT_SPEED_4	0x2d7
#define KEY_SHUTTLE_LEFT_SPEED_5	0x2d8
#define KEY_SHUTTLE_RIGHT_SPEED_1	0x2da
#define KEY_SHUTTLE_RIGHT_SPEED_2	0x2db
#define KEY_SHUTTLE_RIGHT_SPEED_3	0x2dc
#define KEY_SHUTTLE_RIGHT_SPEED_4	0x2dd
#define KEY_SHUTTLE_RIGHT_SPEED_5	0x2de

#define KEY_TIME_SPOT				0x2e0
#define KEY_USER_SWITCH				0x2e1
#define KEY_VOICE_END				0x2e2
#define KEY_POWER_LONG				0x2e3
#define KEY_COOCAA					0x2e4
#define KEY_HOME_LONG				0x2e5
#define KEY_BACK_LONG				0x2e6
#define KEY_NOTIFICATION			0x2e7
#define KEY_FACTORY_WLAN_SCAN 		0x2e8
#else
#ifdef CONFIG_CUSTOMER_TV030
#define KEY_3D_MODE     0x17f
#define KEY_TV_INPUT	0x1d7
#define KEY_MEDIA_RECORD			167

#else 
#define KEY_3D_MODE     				0x227
#endif
#define KEY_VOICE       				0x228
#define KEY_3D_DEL						0x229
#define KEY_MEDIA_SONG_SYSTEM			0x22a
#define KEY_MEDIA_RELATIONSHIP			0x22b
#define KEY_MEDIA_BOOKING				0x22c
#define KEY_MEDIA_AUDIO_CONTROL			0x22d
#define KEY_MEDIA_FUNCTION				0x22e
#define KEY_MEDIA_ORIGINAL_SOUNDTRACK	0x22f

#define KEY_MEDIA_SELECTED_SONGS	0x230
#define KEY_MEDIA_PRIORITY			0x231
#define KEY_MEDIA_DELETE			0x232
#define KEY_MEDIA_SCORE_DISPLAY		0x233
#define KEY_INPUT_NUMBER			0x234
#define KEY_SHUTTLE_LEFT_SPEED_1	0x235
#define KEY_SHUTTLE_LEFT_SPEED_2	0x236
#define KEY_SHUTTLE_LEFT_SPEED_3	0x237
#define KEY_SHUTTLE_LEFT_SPEED_4	0x238
#define KEY_SHUTTLE_LEFT_SPEED_5	0x239
#define KEY_SHUTTLE_RIGHT_SPEED_1	0x23a
#define KEY_SHUTTLE_RIGHT_SPEED_2	0x23b
#define KEY_SHUTTLE_RIGHT_SPEED_3	0x23c
#define KEY_SHUTTLE_RIGHT_SPEED_4	0x23d
#define KEY_SHUTTLE_RIGHT_SPEED_5	0x23e
#define KEY_TIME_SPOT				0x23f

#define KEY_USER_SWITCH				0x240
#define KEY_VOICE_END				0x241
#define KEY_POWER_LONG				0x242
#define KEY_FACTORY_FACTORY_MODE	0x243
#define KEY_FACTORY_RESET			0x244
#define KEY_FACTORY_SOURCE_ADD		0x245
#define KEY_FACTORY_SOURCE_REDUCE	0x246
#define KEY_FACTORY_OUTSET		0x247
#define KEY_FACTORY_BUS_OFF		0x248
#define KEY_FACTORY_AGING_MODE	0x249
#ifdef CONFIG_CUSTOMER_TV030
#define	KEY_GLOBO_PLAY          0x24a
#else
#define KEY_FACTORY_AUTO_ADC	0x24a
#endif
#define KEY_FACTORY_AV1			0x24b
#ifdef CONFIG_CUSTOMER_TV030
#define	KEY_ALL_APP             0x24c
#else
#define KEY_FACTORY_RF_AGC		0x24c
#endif
#define KEY_FACTORY_AV2			0x24d
#define KEY_FACTORY_AV3			0x24e
#define KEY_FACTORY_S1			0x24f
#define KEY_FACTORY_YUV1		0x250
#define KEY_FACTORY_YUV2		0x251
#define KEY_FACTORY_VGA			0x252
#define KEY_FACTORY_HDMI1		0x253
#define KEY_FACTORY_HDMI2		0x254
#define KEY_FACTORY_HDMI3		0x255
#define KEY_FACTORY_KALA_OK		0x256
#define KEY_FACTORY_UPLAYER		0x257
#define KEY_FACTORY_LAN			0x258
#define KEY_FACTORY_DREAM_PANEL		0x259
#define KEY_FACTORY_WHITE_BALANCE	0x25a
#define KEY_FACTORY_ALONE_LISTEN	0x25b
#define KEY_FACTORY_CA_CARD			0x25c
#define KEY_FACTORY_BARCODE			0x25d
#define KEY_FACTORY_SEARCH_UP		0x25e
#define KEY_FACTORY_SEARCH_DOWN		0x25f

#define KEY_SENSE_ALL 			0x260
#define KEY_SENSE_MENU			0x261
#define KEY_SENSE_CENTER		0x262
#define KEY_SENSE_BACK			0x263
#define KEY_SENSE_VOLUME_UP		0x264
#define KEY_SENSE_VOLUME_DOWN	0x265
#define KEY_SENSE_CHANNEL_UP	0x266
#define KEY_SENSE_CHANNEL_DOWN	0x267
#define KEY_SENSE_LEAVE			0x268
#define KEY_CHILD_LOCK 			0x269

#define KEY_NEW_SHUTTLE_LEFT   	0x270
#define KEY_NEW_SHUTTLE_RIGHT   0x271
#define KEY_COOCAA				0x272
#define KEY_HOME_LONG			0x273
#define KEY_BACK_LONG			0x274
#define KEY_NOTIFICATION		0x275
#define KEY_CENTER_LONG			0x276
#define KEY_SEEK_SIGNAL			0x277
#define KEY_LOCAL_MEDIA			0x278
#define KEY_RESEARCH			0x279
#define KEY_SETTING				0x27a
#define KEY_MYSTEP				0x27b
#endif

#define KEY_PIP             0x27c
#define KEY_POP             0x27d
#define KEY_MP              0x27e
#define KEY_TOOLS           0x27f

//hardy20140318
#define KEY_FACTORY_LOGOLED			0x280
#define KEY_FACTORY_TEST			0x281
#define KEY_FACTORY_PRESETCH		0x282
#define KEY_FACTORY_AUTOSCANCH		0x283
//end

#if defined(CONFIG_RTK_KDRV_TV001_IR)
#define KEY_AUDIOMTS			0x284
#define KEY_AUDIOMODE			0x285
#define KEY_ROI                         0x286
#define KEY_FAVCH                       0x287
#endif

#if defined(CONFIG_TV015_IR)
//Add New TPVFactoryIrDA key
#define KEY_TPVFAC_TEST1		0x290
#define KEY_TPVFAC_TEST2		0x291
#define KEY_TPVFAC_CLK			0x292	//CLK(test clock  timer)
#define KEY_TPVFAC_VOL_MAX		0x293	//Vol-MAX(set volume to max)
#define KEY_TPVFAC_VOL_BUZZ		0x294	//Vol-Buzz(set volume by require)
#define KEY_TPVFAC_VOL_L		0x295	//VOL-L(set the volume balance to Left SPK,Sound Left)
#define KEY_TPVFAC_VOL_R		0x296	//VOL-R(set the volume balance to Right SPK,Sound Right)
#define KEY_TPVFAC_CC_TT		0x297	//CC/TT (enable/disable CC/TT function)
#define KEY_TPVFAC_B_I			0x298	//Burn in mode On/Off
#define KEY_TPVFAC_CH_SCAN		0x299	//auto scan the channel / exit scan
#define KEY_TPVFAC_PRE_CH		0x29A	//Pre-CH(Factory Presetting channel OK)
#define KEY_TPVFAC_ADTV			0x29B	//Anterna  Cable(change source to TV, and set to Antenna/Digital TV)
#define KEY_TPVFAC_RST			0x29C	//RST(reset to default for Factory settings)
#define KEY_TPVFAC_FAC			0x29D	//FAC
#define KEY_TPVFAC_CSM			0x29E	//CSM
#define KEY_TPVFAC_PATTERN		0x29F	//Pattern(set Pattern to Red/Green/ Blue/White/Black/Off)
#define KEY_TPVFAC_CTC			0x2A0	//CTC(show color temperature---e.g:normal/warm/cool)
#define KEY_TPVFAC_CH_UP		0x2A1	//Ch+
#define KEY_TPVFAC_CH_DOWN		0x2A2	//Ch-
#define KEY_TPVFAC_MENU			0x2A3	//MENU
#define KEY_TPVFAC_MUTE			0x2A4	//MUTE
#define KEY_TPVFAC_UP			0x2A5	//UP
#define KEY_TPVFAC_DOWN			0x2A6	//DOWN
#define KEY_TPVFAC_OK			0x2A7	//OK/ENTER
#define KEY_TPVFAC_PIC			0x2A8	//PIC(Change picture mode--- e.g.  User/vivid/standard/movie etc))
#define KEY_TPVFAC_AUDIO		0x2A9	//Audio(enable/disable SRS, or change the audio mode)
#define KEY_TPVFAC_2D3D			0x2AA	//2D/3D(switch 3D /2D Mode )
#define KEY_TPVFAC_ARC			0x2AB	//ARC(ENABLE/DISABLE ARC)
#define KEY_TPVFAC_CI			0x2AC	//CI+(display CI+KEY Status)
#define KEY_TPVFAC_VIRGIN		0x2AD	//Virgin(Virgin Mode on/off)
#define KEY_TPVFAC_CVBS			0x2AE	//CVBS(Change Source to AV)
#define KEY_TPVFAC_YPBPR		0x2AF	//YPbPr SCART(Change Source to YPbPr)
#define KEY_TPVFAC_HDMI			0x2B0	//HDMI(Change Source to HDMI)
#define KEY_TPVFAC_VGA			0x2B1	//VGA(Change Source to VGA)
#define KEY_TPVFAC_CLONE		0x2B2	//CLONE(test clone box port)
#define KEY_TPVFAC_DCR			0x2B3	//DCR(Enable/Disable DCR function)
#define KEY_TPVFAC_ADC			0x2B4	//ADC(only activity when source in  YPbPr & PC)
#define KEY_TPVFAC_BLK			0x2B5	//BLK(Backlight set to 50%/100%/0%)
#define KEY_TPVFAC_WP			0x2B6	//W/P(EDID Write Control)
#define KEY_TPVFAC_LS			0x2B7	//Light sensor(ENABLE/DISABLE Light sensor)
#define KEY_TPVFAC_USB			0x2B8	//USB(Change Source to USB)
#define KEY_TPVFAC_RJ45			0x2B9	//RJ45(test RJ45 port)
#define KEY_TPVFAC_RS232		0x2BA	//RS232(RS232 ON/OFF)
#define KEY_TPVFAC_0			0x2BB	//Number 0 Key
#define KEY_TPVFAC_1			0x2BC
#define KEY_TPVFAC_2			0x2BD
#define KEY_TPVFAC_3			0x2BE
#define KEY_TPVFAC_4			0x2BF
#define KEY_TPVFAC_5			0x2C0
#define KEY_TPVFAC_6			0x2C1
#define KEY_TPVFAC_7			0x2C2
#define KEY_TPVFAC_8			0x2C3
#define KEY_TPVFAC_9			0x2C4

#else
//lyg,20140325,CVT remote
#define KEY_CVTFAC_10_P			0x290
#define KEY_CVTFAC_DOT			0x291
#define KEY_CVTAUTO				0x292
#define KEY_CVTFAC_PVR			0x293
#define KEY_CVTFAC_TUNE			0x294
#define KEY_CVTFAC_CALIBRATION1	0x295
#define KEY_CVTFAC_CALIBRATION2	0x296
#define KEY_CVTFAC_VERSION		0x297
#define KEY_CVTFAC_AGING_MODE	0x298
#define KEY_CVTFAC_PANEL1		0x299
#define KEY_CVTFAC_PANEL2		0x29a
#define KEY_CVTFAC_F1			0x29b
#define KEY_CVTFAC_F2			0x29c
#define KEY_CVTFAC_F3			0x29d
#define KEY_CVTFAC_F4			0x29e
#define KEY_CVTFAC_F5			0x29f
#define KEY_CVTFAC_F6			0x2a0
#define KEY_CVTFAC_F7			0x2a1
#define KEY_CVTFAC_NICAM		0x2a2
#define KEY_CVTFAC_TTXCC		0x2a3
#define KEY_CVTFAC_RESET		0x2a4
//lyg,20140325,CVT remote end

//lyg,20140403,MTC remote
#define KEY_MTCFAC_DTV1			0x2a5
#define KEY_MTCFAC_DTV2			0x2a6
#define KEY_MTCFAC_DTV3			0x2a7
#define KEY_MTCFAC_REC			0x2a8
#define KEY_MTCFAC_ATV1			0x2a9
#define KEY_MTCFAC_ATV2			0x2aa
#define KEY_MTCFAC_ATV3			0x2ab
#define KEY_MTCFAC_SCART1		0x2ac
#define KEY_MTCFAC_SCART2		0x2ad
#define KEY_MTCFAC_DVD			0x2ae
#define KEY_MTCFAC_DVB_S		0x2af
#define KEY_MTCFAC_DVD_USB		0x2b0
#define KEY_MTCFAC_DVD_DISK		0x2b1
#define KEY_MTCFAC_DVB_S_RESET	0x2b2
#define KEY_MTCFAC_PLAY			0x2b3
#define KEY_MTCFAC_STOP			0x2b4
#define KEY_MTCFAC_RESET		0x2b5
//lyg,20140325,MTC remote end
#endif

#define BTN_TRIGGER_HAPPY		0x2c0
#define BTN_TRIGGER_HAPPY1		0x2c0
#define BTN_TRIGGER_HAPPY2		0x2c1
#define BTN_TRIGGER_HAPPY3		0x2c2
#define BTN_TRIGGER_HAPPY4		0x2c3
#define BTN_TRIGGER_HAPPY5		0x2c4
#define BTN_TRIGGER_HAPPY6		0x2c5
#define BTN_TRIGGER_HAPPY7		0x2c6
#define BTN_TRIGGER_HAPPY8		0x2c7
#define BTN_TRIGGER_HAPPY9		0x2c8
#define BTN_TRIGGER_HAPPY10		0x2c9
#define BTN_TRIGGER_HAPPY11		0x2ca
#define BTN_TRIGGER_HAPPY12		0x2cb
#define BTN_TRIGGER_HAPPY13		0x2cc
#define BTN_TRIGGER_HAPPY14		0x2cd
#define BTN_TRIGGER_HAPPY15		0x2ce
#define BTN_TRIGGER_HAPPY16		0x2cf
#define BTN_TRIGGER_HAPPY17		0x2d0
#define BTN_TRIGGER_HAPPY18		0x2d1
#define BTN_TRIGGER_HAPPY19		0x2d2
#define BTN_TRIGGER_HAPPY20		0x2d3
#define BTN_TRIGGER_HAPPY21		0x2d4
#define BTN_TRIGGER_HAPPY22		0x2d5
#define BTN_TRIGGER_HAPPY23		0x2d6
#define BTN_TRIGGER_HAPPY24		0x2d7
#define BTN_TRIGGER_HAPPY25		0x2d8
#define BTN_TRIGGER_HAPPY26		0x2d9
#define BTN_TRIGGER_HAPPY27		0x2da
#define BTN_TRIGGER_HAPPY28		0x2db
#define BTN_TRIGGER_HAPPY29		0x2dc
#define BTN_TRIGGER_HAPPY30		0x2dd
#define BTN_TRIGGER_HAPPY31		0x2de
#define BTN_TRIGGER_HAPPY32		0x2df
#define BTN_TRIGGER_HAPPY33		0x2e0
#define BTN_TRIGGER_HAPPY34		0x2e1
#define BTN_TRIGGER_HAPPY35		0x2e2
#define BTN_TRIGGER_HAPPY36		0x2e3
#define BTN_TRIGGER_HAPPY37		0x2e4
#define BTN_TRIGGER_HAPPY38		0x2e5
#define BTN_TRIGGER_HAPPY39		0x2e6
#define BTN_TRIGGER_HAPPY40		0x2e7

#ifdef CONFIG_RTK_KDRV_SUPPORT_ALC_COMMAND
 #ifdef CONFIG_CUSTOMER_TV010
  #if defined(CONFIG_RTK_KDRV_YK_54LU_SHUTTLE) ||defined(CONFIG_RTK_KDRV_YK_54LU)
   #define KEY_ALC_HELLO_MIDOLI   (KEY_POWER)
   #define KEY_ALC_HELLO_MENU (KEY_HOME)
   #define KEY_ALC_HELLO_VOLUME_LOUDER (KEY_VOLUMEUP)
   #define KEY_ALC_HELLO_VOLUME_DOWN (KEY_VOLUMEDOWN)

   #define KEY_ALC_CONFIRM        (KEY_CENTER)
   #define KEY_ALC_START_PLAY (KEY_MEDIA_PLAY_PAUSE)
   #define KEY_ALC_PAUSE (KEY_MEDIA_PLAY_PAUSE)
   #define KEY_ALC_STOP (KEY_MEDIA_STOP)

   #define KEY_ALC_GO_PREVIOUS (KEY_UP)
   #define KEY_ALC_GO_NEXT (KEY_DOWN)
   #define KEY_ALC_GO_RIGHT (KEY_RIGHT)
   #define KEY_ALC_GO_LEFT (KEY_LEFT)
   #define KEY_ALC_ALEXA (KEY_MUTE)
  #else
   #define KEY_ALC_HELLO_MIDOLI   (KEY_POWER)
   #define KEY_ALC_HELLO_MENU (KEY_HOME)
   #define KEY_ALC_HELLO_VOLUME_LOUDER (KEY_VOLUMEUP)
   #define KEY_ALC_HELLO_VOLUME_DOWN (KEY_VOLUMEDOWN)

   #define KEY_ALC_CONFIRM        (KEY_ENTER)
   #define KEY_ALC_START_PLAY (KEY_RED)
   #define KEY_ALC_PAUSE (KEY_GREEN)
   #define KEY_ALC_STOP (KEY_BLUE)

   #define KEY_ALC_GO_PREVIOUS (KEY_UP)
   #define KEY_ALC_GO_NEXT (KEY_DOWN)
   #define KEY_ALC_GO_RIGHT (KEY_RIGHT)
   #define KEY_ALC_GO_LEFT (KEY_LEFT)
   #define KEY_ALC_ALEXA (KEY_MUTE)
  #endif
 #else
   #define KEY_ALC_HELLO_MIDOLI	0x2e8
   #define KEY_ALC_HELLO_MENU 0x2e9
   #define KEY_ALC_HELLO_VOLUME_LOUDER 0x2ea
   #define KEY_ALC_HELLO_VOLUME_DOWN 0x2eb

   #define KEY_ALC_CONFIRM	0x2ec
   #define KEY_ALC_START_PLAY 0x2ed
   #define KEY_ALC_PAUSE 0x2ee
   #define KEY_ALC_STOP 0x2ef

   #define KEY_ALC_GO_PREVIOUS	0x2f0
   #define KEY_ALC_GO_NEXT 0x2f1
   #define KEY_ALC_GO_RIGHT 0x2f2
   #define KEY_ALC_GO_LEFT 0x2f3
 #endif
#endif

#if defined(CONFIG_RTK_KDRV_TV002_IR)
#define KEY_SYNC_MENU			0x2f4
#define KEY_GOOGLE_PLAY			0x2f5
#define KEY_NETFLIX			0x2f6
#define KEY_RETUEN_CH			0x2f7
#define KEY_PIC_OFF			0x2f8
#endif

// #ifndef VENDOR_EDIT
// zihua.bu@tcl.com, 2020/11/27, add STAN key
#define KEY_IQIYI           0x249
#define KEY_PRIMEVIDEO      0x2fd
#define KEY_FPTPLAYER       0x2f9
#define KEY_STAN            0x28e
#define KEY_ZEE             0x21f
// #endif /* VENDOR_EDIT */

/* We avoid low common keys in module aliases so they don't get huge. */
#define KEY_MIN_INTERESTING	KEY_MUTE
#define KEY_RESERVER_MIN  (KEY_MAX - 6)
#define KEY_RESERVER_MAX (KEY_MAX - 1)
#define KEY_MAX			0x2ff
#define KEY_CNT			(KEY_MAX+1)

/*
 * Relative axes
 */

#define REL_X			0x00
#define REL_Y			0x01
#define REL_Z			0x02
#define REL_RX			0x03
#define REL_RY			0x04
#define REL_RZ			0x05
#define REL_HWHEEL		0x06
#define REL_DIAL		0x07
#define REL_WHEEL		0x08
#define REL_MISC		0x09
#define REL_MAX			0x0f
#define REL_CNT			(REL_MAX+1)

/*
 * Absolute axes
 */

#define ABS_X			0x00
#define ABS_Y			0x01
#define ABS_Z			0x02
#define ABS_RX			0x03
#define ABS_RY			0x04
#define ABS_RZ			0x05
#define ABS_THROTTLE		0x06
#define ABS_RUDDER		0x07
#define ABS_WHEEL		0x08
#define ABS_GAS			0x09
#define ABS_BRAKE		0x0a
#define ABS_HAT0X		0x10
#define ABS_HAT0Y		0x11
#define ABS_HAT1X		0x12
#define ABS_HAT1Y		0x13
#define ABS_HAT2X		0x14
#define ABS_HAT2Y		0x15
#define ABS_HAT3X		0x16
#define ABS_HAT3Y		0x17
#define ABS_PRESSURE		0x18
#define ABS_DISTANCE		0x19
#define ABS_TILT_X		0x1a
#define ABS_TILT_Y		0x1b
#define ABS_TOOL_WIDTH		0x1c

#define ABS_VOLUME		0x20

#define ABS_MISC		0x28

#define ABS_MT_SLOT		0x2f	/* MT slot being modified */
#define ABS_MT_TOUCH_MAJOR	0x30	/* Major axis of touching ellipse */
#define ABS_MT_TOUCH_MINOR	0x31	/* Minor axis (omit if circular) */
#define ABS_MT_WIDTH_MAJOR	0x32	/* Major axis of approaching ellipse */
#define ABS_MT_WIDTH_MINOR	0x33	/* Minor axis (omit if circular) */
#define ABS_MT_ORIENTATION	0x34	/* Ellipse orientation */
#define ABS_MT_POSITION_X	0x35	/* Center X touch position */
#define ABS_MT_POSITION_Y	0x36	/* Center Y touch position */
#define ABS_MT_TOOL_TYPE	0x37	/* Type of touching device */
#define ABS_MT_BLOB_ID		0x38	/* Group a set of packets as a blob */
#define ABS_MT_TRACKING_ID	0x39	/* Unique ID of initiated contact */
#define ABS_MT_PRESSURE		0x3a	/* Pressure on contact area */
#define ABS_MT_DISTANCE		0x3b	/* Contact hover distance */
#define ABS_MT_TOOL_X		0x3c	/* Center X tool position */
#define ABS_MT_TOOL_Y		0x3d	/* Center Y tool position */


#define ABS_MAX			0x3f
#define ABS_CNT			(ABS_MAX+1)

/*
 * Switch events
 */

#define SW_LID			0x00  /* set = lid shut */
#define SW_TABLET_MODE		0x01  /* set = tablet mode */
#define SW_HEADPHONE_INSERT	0x02  /* set = inserted */
#define SW_RFKILL_ALL		0x03  /* rfkill master switch, type "any"
					 set = radio enabled */
#define SW_RADIO		SW_RFKILL_ALL	/* deprecated */
#define SW_MICROPHONE_INSERT	0x04  /* set = inserted */
#define SW_DOCK			0x05  /* set = plugged into dock */
#define SW_LINEOUT_INSERT	0x06  /* set = inserted */
#define SW_JACK_PHYSICAL_INSERT 0x07  /* set = mechanical switch set */
#define SW_VIDEOOUT_INSERT	0x08  /* set = inserted */
#define SW_CAMERA_LENS_COVER	0x09  /* set = lens covered */
#define SW_KEYPAD_SLIDE		0x0a  /* set = keypad slide out */
#define SW_FRONT_PROXIMITY	0x0b  /* set = front proximity sensor active */
#define SW_ROTATE_LOCK		0x0c  /* set = rotate locked/disabled */
#define SW_LINEIN_INSERT	0x0d  /* set = inserted */
#define SW_MUTE_DEVICE		0x0e  /* set = device disabled */
#define SW_MAX			0x0f
#define SW_CNT			(SW_MAX+1)

/*
 * Misc events
 */

#define MSC_SERIAL		0x00
#define MSC_PULSELED		0x01
#define MSC_GESTURE		0x02
#define MSC_RAW			0x03
#define MSC_SCAN		0x04
#define MSC_TIMESTAMP		0x05
#define MSC_MAX			0x07
#define MSC_CNT			(MSC_MAX+1)

/*
 * LEDs
 */

#define LED_NUML		0x00
#define LED_CAPSL		0x01
#define LED_SCROLLL		0x02
#define LED_COMPOSE		0x03
#define LED_KANA		0x04
#define LED_SLEEP		0x05
#define LED_SUSPEND		0x06
#define LED_MUTE		0x07
#define LED_MISC		0x08
#define LED_MAIL		0x09
#define LED_CHARGING		0x0a
#define LED_MAX			0x0f
#define LED_CNT			(LED_MAX+1)

/*
 * Autorepeat values
 */

#define REP_DELAY		0x00
#define REP_PERIOD		0x01
#define REP_MAX			0x01
#define REP_CNT			(REP_MAX+1)

/*
 * Sounds
 */

#define SND_CLICK		0x00
#define SND_BELL		0x01
#define SND_TONE		0x02
#define SND_MAX			0x07
#define SND_CNT			(SND_MAX+1)

#endif
