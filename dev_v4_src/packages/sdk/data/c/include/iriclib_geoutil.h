#ifndef IRICLIB_GEOUTIL_H
#define IRICLIB_GEOUTIL_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL cg_iRIC_Read_Geo_Count(int fid, const char* name, int* count);
int IRICLIBDLL cg_iRIC_Read_Geo_Filename(int fid, const char* name, int geoid, char* strvalue, int* type);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_GEOUTIL_H
