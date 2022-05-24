#ifndef IRICLIB_INIT_H
#define IRICLIB_INIT_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL cg_iRIC_Open(const char* filename, int mode, int* fid);
int IRICLIBDLL cg_iRIC_Close(int fid);
int IRICLIBDLL iRIC_InitOption(int option);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_INIT_H
