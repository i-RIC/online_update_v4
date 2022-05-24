#ifndef IRICLIB_SOL_POLYDATA_H
#define IRICLIB_SOL_POLYDATA_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_DataCount_WithGridId(int fid, int gid, int step, const char* groupname, int* count);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_CoordinateCount_WithGridId(int fid, int gid, int step, const char* groupname, int* count);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Pos2d_WithGridId(int fid, int gid, int step, const char* groupname, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Type_WithGridId(int fid, int gid, int step, const char* groupname, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Real_WithGridId(int fid, int gid, int step, const char* groupname, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Integer_WithGridId(int fid, int gid, int step, const char* groupname, const char* name, int* v_arr);

int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_GroupBegin_WithGridId(int fid, int gid, const char* name);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_GroupEnd_WithGridId(int fid, int gid);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Polygon_WithGridId(int fid, int gid, int numPoints, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Polyline_WithGridId(int fid, int gid, int numPoints, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Integer_WithGridId(int fid, int gid, const char* name, int value);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Real_WithGridId(int fid, int gid, const char* name, double value);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_SOL_POLYDATA_H
