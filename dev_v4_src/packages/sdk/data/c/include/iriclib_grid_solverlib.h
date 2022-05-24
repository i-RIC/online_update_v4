#ifndef IRICLIB_GRID_SOLVERLIB_H
#define IRICLIB_GRID_SOLVERLIB_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL cg_iRIC_Read_Grid2d_Open_WithGridId(int fid, int gid, int* grid_handle);
int IRICLIBDLL cg_iRIC_Read_Sol_Grid2d_Open_WithGridId(int fid, int gid, int solid, int* grid_handle);
int IRICLIBDLL cg_iRIC_Read_Grid2d_Close(int grid_handle);
int IRICLIBDLL cg_iRIC_Read_Grid2d_CellArea(int grid_handle, int cellId, double* area);
int IRICLIBDLL cg_iRIC_Read_Grid2d_FindCell(int grid_handle, double x, double y, int* cellId);
int IRICLIBDLL cg_iRIC_Read_Grid2d_CellNodeCount(int grid_handle, int cellId, int* count);
int IRICLIBDLL cg_iRIC_Read_Grid2d_Interpolate(int grid_handle, double x, double y, int* ok, int* count, int* nodeids_arr, double* weights_arr);
int IRICLIBDLL cg_iRIC_Read_Grid2d_InterpolateWithCell(int grid_handle, double x, double y, int cellId, int* nodeids_arr, double* weights_arr);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_GRID_SOLVERLIB_H
