#ifndef IRICLIB_SOL_PARTICLEGROUPIMAGE_H
#define IRICLIB_SOL_PARTICLEGROUPIMAGE_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroupImage_Count_WithGridId(int fid, int gid, int step, const char* groupname, int* count);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroupImage_Pos2d_WithGridId(int fid, int gid, int step, const char* groupname, double* x_arr, double* y_arr, double* size_arr, double* angle_arr);

int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroupImage_GroupBegin_WithGridId(int fid, int gid, const char* groupname);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroupImage_GroupEnd_WithGridId(int fid, int gid);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroupImage_Pos2d_WithGridId(int fid, int gid, double x, double y, double size, double angle);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_SOL_PARTICLEGROUPIMAGE_H
