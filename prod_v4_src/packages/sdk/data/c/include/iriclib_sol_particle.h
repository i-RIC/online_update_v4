#ifndef IRICLIB_SOL_PARTICLE_H
#define IRICLIB_SOL_PARTICLE_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Count_WithGridId(int fid, int gid, int step, int* count);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Pos2d_WithGridId(int fid, int gid, int step, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Pos3d_WithGridId(int fid, int gid, int step, double* x_arr, double* y_arr, double* z_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Real_WithGridId(int fid, int gid, int step, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Integer_WithGridId(int fid, int gid, int step, const char* name, int* v_arr);

int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Pos2d_WithGridId(int fid, int gid, int count, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Pos3d_WithGridId(int fid, int gid, int count, double* x_arr, double* y_arr, double* z_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Real_WithGridId(int fid, int gid, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Integer_WithGridId(int fid, int gid, const char* name, int* v_arr);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_SOL_PARTICLE_H
