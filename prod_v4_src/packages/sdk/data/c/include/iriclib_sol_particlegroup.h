#ifndef IRICLIB_SOL_PARTICLEGROUP_H
#define IRICLIB_SOL_PARTICLEGROUP_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Count_WithGridId(int fid, int gid, int step, const char* groupname, int* count);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Pos2d_WithGridId(int fid, int gid, int step, const char* groupname, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Pos3d_WithGridId(int fid, int gid, int step, const char* groupname, double* x_arr, double* y_arr, double* z_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Real_WithGridId(int fid, int gid, int step, const char* groupname, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Integer_WithGridId(int fid, int gid, int step, const char* groupname, const char* name, int* v_arr);

int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_GroupBegin_WithGridId(int fid, int gid, const char* name);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_GroupEnd_WithGridId(int fid, int gid);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_Pos2d_WithGridId(int fid, int gid, double x, double y);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_Pos3d_WithGridId(int fid, int gid, double x, double y, double z);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_Integer_WithGridId(int fid, int gid, const char* name, int value);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_Real_WithGridId(int fid, int gid, const char* name, double value);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_SOL_PARTICLEGROUP_H
