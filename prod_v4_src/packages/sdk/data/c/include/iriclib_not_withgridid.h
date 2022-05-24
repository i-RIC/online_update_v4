#ifndef IRICLIB_NOT_WITHGRIDID_H
#define IRICLIB_NOT_WITHGRIDID_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

// from iriclib_bc.h
void IRICLIBDLL cg_iRIC_Read_BC_Count(int fid, const char* type, int* num);
int IRICLIBDLL cg_iRIC_Read_BC_IndicesSize(int fid, const char* type, int num, int* size);
int IRICLIBDLL cg_iRIC_Read_BC_IndicesSize2(int fid, const char* type, int num, int* size);
int IRICLIBDLL cg_iRIC_Read_BC_Indices(int fid, const char* type, int num, int* idx_arr);
int IRICLIBDLL cg_iRIC_Read_BC_Integer(int fid, const char* type, int num, const char* name, int* value);
int IRICLIBDLL cg_iRIC_Read_BC_Real(int fid, const char* type, int num, const char* name, double* value);
int IRICLIBDLL cg_iRIC_Read_BC_RealSingle(int fid, const char* type, int num, const char* name, float* value);
int IRICLIBDLL cg_iRIC_Read_BC_StringLen(int fid, const char* type, int num, const char* name, int* length);
int IRICLIBDLL cg_iRIC_Read_BC_String(int fid, const char* type, int num, const char* name, char* strvalue);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalSize(int fid, const char* type, int num, const char* name, int* size);
int IRICLIBDLL cg_iRIC_Read_BC_Functional(int fid, const char* type, int num, const char* name, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalWithName(int fid, const char* type, int num, const char* name, const char* paramname, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_BC_Functional_RealSingle(int fid, const char* type, int num, const char* name, float* x_arr, float* y_arr);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalWithName_RealSingle(int fid, const char* type, int num, const char* name, const char* paramname, float* v_arr);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalWithName_StringLen(int fid, const char* type, int num, const char* name, const char* paramname, int* length);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalWithName_String(int fid, const char* type, int num, const char* name, const char* paramname, char* strvalue);
int IRICLIBDLL cg_iRIC_Clear_BC(int fid);
int IRICLIBDLL cg_iRIC_Write_BC_Indices(int fid, const char* type, int num, int length, int* idx_arr);
int IRICLIBDLL cg_iRIC_Write_BC_Indices2(int fid, const char* type, int num, int length, int* idx_arr);
int IRICLIBDLL cg_iRIC_Write_BC_Integer(int fid, const char* type, int num, const char* name, int value);
int IRICLIBDLL cg_iRIC_Write_BC_Real(int fid, const char* type, int num, const char* name, double value);
int IRICLIBDLL cg_iRIC_Write_BC_String(int fid, const char* type, int num, const char* name, const char* value);
int IRICLIBDLL cg_iRIC_Write_BC_Functional(int fid, const char* type, int num, const char* name, int length, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_BC_FunctionalWithName(int fid, const char* type, int num, const char* name, const char* paramname, int length, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_BC_FunctionalWithName_String(int fid, const char* type, int num, const char* name, const char* paramname, const char* value);

// from iriclib_complex.h
int IRICLIBDLL cg_iRIC_Read_Grid_Complex_Node(int fid, const char* groupname, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Complex_Cell(int fid, const char* groupname, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Complex_Node(int fid, const char* groupname, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Complex_Cell(int fid, const char* groupname, int* v_arr);

// from iriclib_grid.h
int IRICLIBDLL cg_iRIC_Read_Grid2d_Str_Size(int fid, int* isize, int* jsize);
int IRICLIBDLL cg_iRIC_Read_Grid2d_Coords(int fid, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_Grid3d_Str_Size(int fid, int* isize, int* jsize, int* ksize);
int IRICLIBDLL cg_iRIC_Read_Grid3d_Coords(int fid, double* x_arr, double* y_arr, double* z_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_TriangleElementsSize(int fid, int* size);
int IRICLIBDLL cg_iRIC_Read_Grid_TriangleElementsSize2(int fid, int* size);
int IRICLIBDLL cg_iRIC_Read_Grid_TriangleElements(int fid, int* id_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_NodeCount(int fid, int* count);
int IRICLIBDLL cg_iRIC_Read_Grid_CellCount(int fid, int* count);
int IRICLIBDLL cg_iRIC_Read_Grid_IFaceCount(int fid, int* count);
int IRICLIBDLL cg_iRIC_Read_Grid_JFaceCount(int fid, int* count);
int IRICLIBDLL cg_iRIC_Read_Grid_KFaceCount(int fid, int* count);
int IRICLIBDLL cg_iRIC_Read_Grid_Real_Node(int fid, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Integer_Node(int fid, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Real_Cell(int fid, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Integer_Cell(int fid, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_FunctionalDimensionSize(int fid, const char* name, const char* dimname, int* count);
int IRICLIBDLL cg_iRIC_Read_Grid_FunctionalDimension_Integer(int fid, const char* name, const char* dimname, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_FunctionalDimension_Real(int fid, const char* name, const char* dimname, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_FunctionalTimeSize(int fid, const char* name, int* count);
int IRICLIBDLL cg_iRIC_Read_Grid_FunctionalTime(int fid, const char* name, double* time_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Integer_Node(int fid, const char* name, int dimid, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Real_Node(int fid, const char* name, int dimid, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Integer_Cell(int fid, const char* name, int dimid, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Real_Cell(int fid, const char* name, int dimid, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid1d_Coords(int fid, int isize, double* x_arr);
int IRICLIBDLL cg_iRIC_Write_Grid2d_Coords(int fid, int isize, int jsize, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_Grid3d_Coords(int fid, int isize, int jsize, int ksize, double* x_arr, double* y_arr, double* z_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Real_Node(int fid, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Integer_Node(int fid, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Real_Cell(int fid, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Integer_Cell(int fid, const char* name, int* v_arr);

// from iriclib_grid_solverlib.h
int IRICLIBDLL cg_iRIC_Read_Grid2d_Open(int fid, int* grid_handle);
int IRICLIBDLL cg_iRIC_Read_Sol_Grid2d_Open(int fid, int solid, int* grid_handle);

// from iriclib_sol_cell.h
int IRICLIBDLL cg_iRIC_Read_Sol_Cell_Integer(int fid, int step, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Cell_Real(int fid, int step, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Cell_Integer(int fid, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Cell_Real(int fid, const char* name, double* v_arr);

// from iriclib_sol_gridcoord.h
int IRICLIBDLL cg_iRIC_Read_Sol_Grid2d_Coords(int fid, int step, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Grid3d_Coords(int fid, int step, double* x_arr, double* y_arr, double* z_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Grid2d_Coords(int fid, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Grid3d_Coords(int fid, double* x_arr, double* y_arr, double* z_arr);

// from iriclib_sol_iface.h
int IRICLIBDLL cg_iRIC_Read_Sol_IFace_Integer(int fid, int step, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_IFace_Real(int fid, int step, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_IFace_Integer(int fid, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_IFace_Real(int fid, const char* name, double* v_arr);

// from iriclib_sol_jface.h
int IRICLIBDLL cg_iRIC_Read_Sol_JFace_Integer(int fid, int step, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_JFace_Real(int fid, int step, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_JFace_Integer(int fid, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_JFace_Real(int fid, const char* name, double* v_arr);

// from iriclib_sol_kface.h
int IRICLIBDLL cg_iRIC_Read_Sol_KFace_Integer(int fid, int step, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_KFace_Real(int fid, int step, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_KFace_Integer(int fid, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_KFace_Real(int fid, const char* name, double* v_arr);

// from iriclib_sol_node.h
int IRICLIBDLL cg_iRIC_Read_Sol_Node_Integer(int fid, int step, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Node_Real(int fid, int step, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Node_Integer(int fid, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Node_Real(int fid, const char* name, double* v_arr);

// from iriclib_sol_particle.h
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Count(int fid, int step, int* count);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Pos2d(int fid, int step, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Pos3d(int fid, int step, double* x_arr, double* y_arr, double* z_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Real(int fid, int step, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Integer(int fid, int step, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Pos2d(int fid, int count, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Pos3d(int fid, int count, double* x_arr, double* y_arr, double* z_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Real(int fid, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Integer(int fid, const char* name, int* v_arr);

// from iriclib_sol_particlegroup.h
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Count(int fid, int step, const char* groupname, int* count);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Pos2d(int fid, int step, const char* groupname, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Pos3d(int fid, int step, const char* groupname, double* x_arr, double* y_arr, double* z_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Real(int fid, int step, const char* groupname, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Integer(int fid, int step, const char* groupname, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_GroupBegin(int fid, const char* name);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_GroupEnd(int fid);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_Pos2d(int fid, double x, double y);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_Pos3d(int fid, double x, double y, double z);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_Integer(int fid, const char* name, int value);
int IRICLIBDLL cg_iRIC_Write_Sol_ParticleGroup_Real(int fid, const char* name, double value);

// from iriclib_sol_polydata.h
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_DataCount(int fid, int step, const char* groupname, int* count);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_CoordinateCount(int fid, int step, const char* groupname, int* count);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Pos2d(int fid, int step, const char* groupname, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Type(int fid, int step, const char* groupname, int* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Real(int fid, int step, const char* groupname, const char* name, double* v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Integer(int fid, int step, const char* groupname, const char* name, int* v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_GroupBegin(int fid, const char* name);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_GroupEnd(int fid);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Polygon(int fid, int numPoints, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Polyline(int fid, int numPoints, double* x_arr, double* y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Integer(int fid, const char* name, int value);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Real(int fid, const char* name, double value);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_NOT_WITHGRIDID_H
