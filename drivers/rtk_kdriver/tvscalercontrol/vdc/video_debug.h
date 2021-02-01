#ifndef VIDEO_DEBUG_H
#define VIDEO_DEBUG_H

/*----------------------------------------------------------------------------- 
 * Debug module init/exit functions
 *----------------------------------------------------------------------------*/
int module_video_debug_init(void);
void module_video_debug_exit(void);

/*----------------------------------------------------------------------------- 
 * Debug record interface
 *----------------------------------------------------------------------------*/
/**
 * BUGBUG: Do not enable debug record feature currently. Need 
 * more review and debug. 
 */
#undef VIDEO_DEBUG_ENABLE_RECROD

enum {
	VIDEO_DEBUG_RECORD_ATTR_RO = 0,
	VIDEO_DEBUG_RECORD_ATTR_WO,
	VIDEO_DEBUG_RECORD_ATTR_RW,
};

int moudle_video_debug_register_record(unsigned int addr, int nlayer, int attr);
void moudle_video_debug_unregister_record(unsigned int addr);
unsigned int module_video_debug_record_read(unsigned int addr);
int module_video_debug_record_write(unsigned int addr, unsigned int value);
int module_video_debug_record_show(unsigned int addr);
int module_video_debug_record_clear(unsigned int addr);
int module_video_debug_record_start(void);
int module_video_debug_record_stop(void);
bool module_video_debug_record_active(void);

#endif /* VIDEO_DEBUG_H */
