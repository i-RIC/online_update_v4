#ifndef IRICLIB_BC_H
#define IRICLIB_BC_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

void IRICLIBDLL cg_iRIC_Read_BC_Count_WithGridId(int fid, int gid, const char* type, int* num);
int IRICLIBDLL cg_iRIC_Read_BC_IndicesSize_WithGridId(int fid, int gid, const char* type, int num, int* size);
int IRICLIBDLL cg_iRIC_Read_BC_IndicesSize2_WithGridId(int fid, int gid, const char* type, int num, int* size);
int IRICLIBDLL cg_iRIC_Read_BC_Indices_WithGridId(int fid, int gid, const char* type, int num, int* idx_arr);
int IRICLIBDLL cg_iRIC_Read_BC_Integer_WithGridId(int fid, int gid, const char* type, int num, const char* name, int* value);
int IRICLIBDLL cg_iRIC_Read_BC_Real_WithGridId(int fid, int gid, const char* type, int num, const char* name, double* value);
int IRICLIBDLL cg_iRIC_Read_BC_RealSingle_WithGridId(int fid, int gid, const char* type, int num, const char* name, float* value);
int IRICLIBDLL cg_iRIC_Read_BC_StringLen_WithGridId(int fid, int gid, const char* type, int num, const char* name, int* length);
int IRICLIBDLL cg_iRIC_Read_BC_String_WithGridId(int fid, int gid, const char* type, int num, const char* name, char* strvalue);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalSize_WithGridId(int fid, int gid, const char* type, int num, const char* name, int* size);
int IRICLIBDLL cg_iRIC_Read_BC_Functional_WithGridId(int fid, int gid, const char* type, int num, const char* name, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalWithName_WithGridId(int fid, int gid, const char* type, int num, const char* name, const char* paramname, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_BC_Functional_RealSingle_WithGridId(int fid, int gid, const char* type, int num, const char* name, float* x_arr, float* y_arr);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalWithName_RealSingle_WithGridId(int fid, int gid, const char* type, int num, const char* name, const char* paramname, float* v_arr);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalWithName_StringLen_WithGridId(int fid, int gid, const char* type, int num, const char* name, const char* paramname, int* length);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalWithName_String_WithGridId(int fid, int gid, const char* type, int num, const char* name, const char* paramname, char* strvalue);

int IRICLIBDLL cg_iRIC_Clear_BC_WithGridId(int fid, int gid);
int IRICLIBDLL cg_iRIC_Write_BC_Indices_WithGridId(int fid, int gid, const char* type, int num, int length, int* idx_arr);
int IRICLIBDLL cg_iRIC_Write_BC_Indices2_WithGridId(int fid, int gid, const char* type, int num, int length, int* idx_arr);
int IRICLIBDLL cg_iRIC_Write_BC_Integer_WithGridId(int fid, int gid, const char* type, int num, const char* name, int value);
int IRICLIBDLL cg_iRIC_Write_BC_Real_WithGridId(int fid, int gid, const char* type, int num, const char* name, double value);
int IRICLIBDLL cg_iRIC_Write_BC_String_WithGridId(int fid, int gid, const char* type, int num, const char* name, const char* value);
int IRICLIBDLL cg_iRIC_Write_BC_Functional_WithGridId(int fid, int gid, const char* type, int num, const char* name, int length, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_BC_FunctionalWithName_WithGridId(int fid, int gid, const char* type, int num, const char* name, const char* paramname, int length, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_BC_FunctionalWithName_String_WithGridId(int fid, int gid, const char* type, int num, const char* name, const char* paramname, const char* value);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_BC_H
