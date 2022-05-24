#ifndef IRICLIB_COMPLEX_H
#define IRICLIB_COMPLEX_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL cg_iRIC_Read_Complex_Count_WithBaseId(int fid, int bid, const char* groupname, int* num);
int IRICLIBDLL cg_iRIC_Read_Complex_Integer_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, int* value);
int IRICLIBDLL cg_iRIC_Read_Complex_Real_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, double* value);
int IRICLIBDLL cg_iRIC_Read_Complex_RealSingle_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, float* value);
int IRICLIBDLL cg_iRIC_Read_Complex_StringLen_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, int* length);
int IRICLIBDLL cg_iRIC_Read_Complex_String_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, char* strvalue);
int IRICLIBDLL cg_iRIC_Read_Complex_FunctionalSize_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, int* size);
int IRICLIBDLL cg_iRIC_Read_Complex_Functional_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_Complex_FunctionalWithName_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, const char* paramname, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Complex_Functional_RealSingle_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, float* x_arr, float* y_arr);
int IRICLIBDLL cg_iRIC_Read_Complex_FunctionalWithName_RealSingle_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, const char* paramname, float* v_arr);
int IRICLIBDLL cg_iRIC_Read_Complex_FunctionalWithName_StringLen_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, const char* paramname, int* length);
int IRICLIBDLL cg_iRIC_Read_Complex_FunctionalWithName_String_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, const char* paramname, char* strvalue);
int IRICLIBDLL cg_iRIC_Read_Grid_Complex_Node_WithGridId(int fid, int gid, const char* groupname, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Complex_Cell_WithGridId(int fid, int gid, const char* groupname, int* v_arr);

int IRICLIBDLL cg_iRIC_Clear_Complex_WithBaseId(int fid, int bid);
int IRICLIBDLL cg_iRIC_Write_Complex_Integer_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, int value);
int IRICLIBDLL cg_iRIC_Write_Complex_Real_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, double value);
int IRICLIBDLL cg_iRIC_Write_Complex_String_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, const char* value);
int IRICLIBDLL cg_iRIC_Write_Complex_Functional_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, int length, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_Complex_FunctionalWithName_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, const char* paramname, int length, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_Complex_FunctionalWithName_String_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, const char* paramname, const char* value);
int IRICLIBDLL cg_iRIC_Write_Grid_Complex_Node_WithGridId(int fid, int gid, const char* groupname, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Complex_Cell_WithGridId(int fid, int gid, const char* groupname, int* v_arr);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_COMPLEX_H
