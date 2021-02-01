#ifndef __SCALER_API_H__
#define __SCALER_API_H__

#ifdef __cplusplus
extern "C" {
#endif

//#include <rtd_types.h>

/*==================== Definitions ================= */



/*==================== Variables ================= */


/*==================== Functions ================== */
void fwif_scaler_setcapturewindowshift(unsigned char display, char shiftx, char shifty);

void Scaler_ChangeOSDWinFor3D(bool bSetTo3D);
#ifdef __cplusplus
}
#endif

#endif // __SCALER_API_H__


