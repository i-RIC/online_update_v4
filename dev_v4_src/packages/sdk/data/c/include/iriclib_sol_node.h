#ifndef IRICLIB_SOL_NODE_H
#define IRICLIB_SOL_NODE_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL cg_iRIC_Read_Sol_Node_Integer_WithGridId(int fid, int gid, int step, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Node_Real_WithGridId(int fid, int gid, int step, const char* name, double* v_arr);

int IRICLIBDLL cg_iRIC_Write_Sol_Node_Integer_WithGridId(int fid, int gid, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Node_Real_WithGridId(int fid, int gid, const char* name, double* v_arr);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_SOL_NODE_H
