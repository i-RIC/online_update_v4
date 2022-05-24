#ifndef IRICLIB_CC_H
#define IRICLIB_CC_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL cg_iRIC_Read_Integer(int fid, const char* name, int* value);
int IRICLIBDLL cg_iRIC_Read_Real(int fid, const char* name, double* value);
int IRICLIBDLL cg_iRIC_Read_RealSingle(int fid, const char* name, float* value);
int IRICLIBDLL cg_iRIC_Read_StringLen(int fid, const char* name, int* length);
int IRICLIBDLL cg_iRIC_Read_String(int fid, const char* name, char* strvalue);
int IRICLIBDLL cg_iRIC_Read_FunctionalSize(int fid, const char* name, int* size);
int IRICLIBDLL cg_iRIC_Read_Functional(int fid, const char* name, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_FunctionalWithName(int fid, const char* name, const char* paramname, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Functional_RealSingle(int fid, const char* name, float* x_arr, float* y_arr);
int IRICLIBDLL cg_iRIC_Read_FunctionalWithName_RealSingle(int fid, const char* name, const char* paramname, float* v_arr);
int IRICLIBDLL cg_iRIC_Read_FunctionalWithName_String(int fid, const char* name, const char* paramname, char* strvalue);
int IRICLIBDLL cg_iRIC_Read_FunctionalWithName_StringLen(int fid, const char* name, const char* paramname, int* length);

int IRICLIBDLL cg_iRIC_Write_Integer(int fid, const char* name, int value);
int IRICLIBDLL cg_iRIC_Write_Real(int fid, const char* name, double value);
int IRICLIBDLL cg_iRIC_Write_String(int fid, const char* name, const char* value);
int IRICLIBDLL cg_iRIC_Write_Functional(int fid, const char* name, int length, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_FunctionalWithName(int fid, const char* name, const char* paramname, int length, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_FunctionalWithName_String(int fid, const char* name, const char* paramname, const char* value);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_CC_H
