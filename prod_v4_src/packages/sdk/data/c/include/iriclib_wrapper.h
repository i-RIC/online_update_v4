// APIs used from Python wrapper is defined

#ifndef IRICLIB_WRAPPER_H
#define IRICLIB_WRAPPER_H

#include "iriclib_global.h"
#include "intarraycontainer.h"
#include "realarraycontainer.h"
// from iriclib_bc.h
int IRICLIBDLL cg_iRIC_Read_BC_Indices_WithGridId(int fid, int gid, const char* type, int num, IntArrayContainer& idx_arr);
int IRICLIBDLL cg_iRIC_Read_BC_Functional_WithGridId(int fid, int gid, const char* type, int num, const char* name, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalWithName_WithGridId(int fid, int gid, const char* type, int num, const char* name, const char* paramname, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_BC_Indices_WithGridId(int fid, int gid, const char* type, int num, IntArrayContainer& idx_arr);
int IRICLIBDLL cg_iRIC_Write_BC_Indices2_WithGridId(int fid, int gid, const char* type, int num, IntArrayContainer& idx_arr);
int IRICLIBDLL cg_iRIC_Write_BC_Functional_WithGridId(int fid, int gid, const char* type, int num, const char* name, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_BC_FunctionalWithName_WithGridId(int fid, int gid, const char* type, int num, const char* name, const char* paramname, RealArrayContainer& v_arr);

// from iriclib_cc.h
int IRICLIBDLL cg_iRIC_Read_Functional(int fid, const char* name, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_FunctionalWithName(int fid, const char* name, const char* paramname, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Functional(int fid, const char* name, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_FunctionalWithName(int fid, const char* name, const char* paramname, RealArrayContainer& v_arr);

// from iriclib_complex.h
int IRICLIBDLL cg_iRIC_Read_Complex_Functional_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Complex_FunctionalWithName_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, const char* paramname, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Complex_Node_WithGridId(int fid, int gid, const char* groupname, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Complex_Cell_WithGridId(int fid, int gid, const char* groupname, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Complex_Functional_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_Complex_FunctionalWithName_WithBaseId(int fid, int bid, const char* groupname, int num, const char* name, const char* paramname, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Complex_Node_WithGridId(int fid, int gid, const char* groupname, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Complex_Cell_WithGridId(int fid, int gid, const char* groupname, IntArrayContainer& v_arr);

// from iriclib_geo.h
int IRICLIBDLL iRIC_Geo_Polygon_Read_Points(int id, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL iRIC_Geo_Polygon_Read_HolePoints(int id, int holeid, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_Altitudes(int id, int pointid, RealArrayContainer& position_arr, RealArrayContainer& height_arr, IntArrayContainer& active_arr);

// from iriclib_geoutil.h

// from iriclib_grid.h
int IRICLIBDLL cg_iRIC_Read_Grid2d_Coords_WithGridId(int fid, int gid, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Grid3d_Coords_WithGridId(int fid, int gid, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_TriangleElements_WithGridId(int fid, int gid, IntArrayContainer& id_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Real_Node_WithGridId(int fid, int gid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Integer_Node_WithGridId(int fid, int gid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Real_Cell_WithGridId(int fid, int gid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Integer_Cell_WithGridId(int fid, int gid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_FunctionalDimension_Integer_WithGridId(int fid, int gid, const char* name, const char* dimname, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_FunctionalDimension_Real_WithGridId(int fid, int gid, const char* name, const char* dimname, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_FunctionalTime_WithGridId(int fid, int gid, const char* name, RealArrayContainer& time_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Integer_Node_WithGridId(int fid, int gid, const char* name, int dimid, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Real_Node_WithGridId(int fid, int gid, const char* name, int dimid, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Integer_Cell_WithGridId(int fid, int gid, const char* name, int dimid, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Real_Cell_WithGridId(int fid, int gid, const char* name, int dimid, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid1d_Coords_WithGridId(int fid, int isize, RealArrayContainer& x_arr, int* gid);
int IRICLIBDLL cg_iRIC_Write_Grid2d_Coords_WithGridId(int fid, int isize, int jsize, RealArrayContainer& x_arr, RealArrayContainer& y_arr, int* gid);
int IRICLIBDLL cg_iRIC_Write_Grid3d_Coords_WithGridId(int fid, int isize, int jsize, int ksize, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr, int* gid);
int IRICLIBDLL cg_iRIC_Write_Grid_Real_Node_WithGridId(int fid, int gid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Integer_Node_WithGridId(int fid, int gid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Real_Cell_WithGridId(int fid, int gid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Integer_Cell_WithGridId(int fid, int gid, const char* name, IntArrayContainer& v_arr);

// from iriclib_grid_solverlib.h
int IRICLIBDLL cg_iRIC_Read_Grid2d_Interpolate(int grid_handle, double x, double y, int* ok, int* count, IntArrayContainer& nodeids_arr, RealArrayContainer& weights_arr);
int IRICLIBDLL cg_iRIC_Read_Grid2d_InterpolateWithCell(int grid_handle, double x, double y, int cellId, IntArrayContainer& nodeids_arr, RealArrayContainer& weights_arr);

// from iriclib_not_withbaseid.h
int IRICLIBDLL cg_iRIC_Read_Complex_Functional(int fid, const char* groupname, int num, const char* name, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Complex_FunctionalWithName(int fid, const char* groupname, int num, const char* name, const char* paramname, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Complex_Functional(int fid, const char* groupname, int num, const char* name, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_Complex_FunctionalWithName(int fid, const char* groupname, int num, const char* name, const char* paramname, RealArrayContainer& v_arr);

// from iriclib_not_withgridid.h
int IRICLIBDLL cg_iRIC_Read_BC_Indices(int fid, const char* type, int num, IntArrayContainer& idx_arr);
int IRICLIBDLL cg_iRIC_Read_BC_Functional(int fid, const char* type, int num, const char* name, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_BC_FunctionalWithName(int fid, const char* type, int num, const char* name, const char* paramname, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_BC_Indices(int fid, const char* type, int num, IntArrayContainer& idx_arr);
int IRICLIBDLL cg_iRIC_Write_BC_Indices2(int fid, const char* type, int num, IntArrayContainer& idx_arr);
int IRICLIBDLL cg_iRIC_Write_BC_Functional(int fid, const char* type, int num, const char* name, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_BC_FunctionalWithName(int fid, const char* type, int num, const char* name, const char* paramname, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Complex_Node(int fid, const char* groupname, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Complex_Cell(int fid, const char* groupname, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Complex_Node(int fid, const char* groupname, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Complex_Cell(int fid, const char* groupname, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid2d_Coords(int fid, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Grid3d_Coords(int fid, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_TriangleElements(int fid, IntArrayContainer& id_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Real_Node(int fid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Integer_Node(int fid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Real_Cell(int fid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Integer_Cell(int fid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_FunctionalDimension_Integer(int fid, const char* name, const char* dimname, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_FunctionalDimension_Real(int fid, const char* name, const char* dimname, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_FunctionalTime(int fid, const char* name, RealArrayContainer& time_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Integer_Node(int fid, const char* name, int dimid, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Real_Node(int fid, const char* name, int dimid, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Integer_Cell(int fid, const char* name, int dimid, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Grid_Functional_Real_Cell(int fid, const char* name, int dimid, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid1d_Coords(int fid, int isize, RealArrayContainer& x_arr);
int IRICLIBDLL cg_iRIC_Write_Grid2d_Coords(int fid, int isize, int jsize, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_Grid3d_Coords(int fid, int isize, int jsize, int ksize, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Real_Node(int fid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Integer_Node(int fid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Real_Cell(int fid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Grid_Integer_Cell(int fid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Cell_Integer(int fid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Cell_Real(int fid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Cell_Integer(int fid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Cell_Real(int fid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Grid2d_Coords(int fid, int step, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Grid3d_Coords(int fid, int step, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Grid2d_Coords(int fid, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Grid3d_Coords(int fid, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_IFace_Integer(int fid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_IFace_Real(int fid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_IFace_Integer(int fid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_IFace_Real(int fid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_JFace_Integer(int fid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_JFace_Real(int fid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_JFace_Integer(int fid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_JFace_Real(int fid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_KFace_Integer(int fid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_KFace_Real(int fid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_KFace_Integer(int fid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_KFace_Real(int fid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Node_Integer(int fid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Node_Real(int fid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Node_Integer(int fid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Node_Real(int fid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Pos2d(int fid, int step, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Pos3d(int fid, int step, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Real(int fid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Integer(int fid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Pos2d(int fid, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Pos3d(int fid, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Real(int fid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Integer(int fid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Pos2d(int fid, int step, const char* groupname, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Pos3d(int fid, int step, const char* groupname, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Real(int fid, int step, const char* groupname, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Integer(int fid, int step, const char* groupname, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Pos2d(int fid, int step, const char* groupname, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Type(int fid, int step, const char* groupname, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Real(int fid, int step, const char* groupname, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Integer(int fid, int step, const char* groupname, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Polygon(int fid, int numPoints, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Polyline(int fid, int numPoints, RealArrayContainer& x_arr, RealArrayContainer& y_arr);

// from iriclib_sol_cell.h
int IRICLIBDLL cg_iRIC_Read_Sol_Cell_Integer_WithGridId(int fid, int gid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Cell_Real_WithGridId(int fid, int gid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Cell_Integer_WithGridId(int fid, int gid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Cell_Real_WithGridId(int fid, int gid, const char* name, RealArrayContainer& v_arr);

// from iriclib_sol_gridcoord.h
int IRICLIBDLL cg_iRIC_Read_Sol_Grid2d_Coords_WithGridId(int fid, int gid, int step, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Grid3d_Coords_WithGridId(int fid, int gid, int step, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Grid2d_Coords_WithGridId(int fid, int gid, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Grid3d_Coords_WithGridId(int fid, int gid, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);

// from iriclib_sol_iface.h
int IRICLIBDLL cg_iRIC_Read_Sol_IFace_Integer_WithGridId(int fid, int gid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_IFace_Real_WithGridId(int fid, int gid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_IFace_Integer_WithGridId(int fid, int gid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_IFace_Real_WithGridId(int fid, int gid, const char* name, RealArrayContainer& v_arr);

// from iriclib_sol_jface.h
int IRICLIBDLL cg_iRIC_Read_Sol_JFace_Integer_WithGridId(int fid, int gid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_JFace_Real_WithGridId(int fid, int gid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_JFace_Integer_WithGridId(int fid, int gid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_JFace_Real_WithGridId(int fid, int gid, const char* name, RealArrayContainer& v_arr);

// from iriclib_sol_kface.h
int IRICLIBDLL cg_iRIC_Read_Sol_KFace_Integer_WithGridId(int fid, int gid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_KFace_Real_WithGridId(int fid, int gid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_KFace_Integer_WithGridId(int fid, int gid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_KFace_Real_WithGridId(int fid, int gid, const char* name, RealArrayContainer& v_arr);

// from iriclib_sol_node.h
int IRICLIBDLL cg_iRIC_Read_Sol_Node_Integer_WithGridId(int fid, int gid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Node_Real_WithGridId(int fid, int gid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Node_Integer_WithGridId(int fid, int gid, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Node_Real_WithGridId(int fid, int gid, const char* name, RealArrayContainer& v_arr);

// from iriclib_sol_particle.h
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Pos2d_WithGridId(int fid, int gid, int step, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Pos3d_WithGridId(int fid, int gid, int step, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Real_WithGridId(int fid, int gid, int step, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_Particle_Integer_WithGridId(int fid, int gid, int step, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Pos2d_WithGridId(int fid, int gid, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Pos3d_WithGridId(int fid, int gid, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Real_WithGridId(int fid, int gid, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_Particle_Integer_WithGridId(int fid, int gid, const char* name, IntArrayContainer& v_arr);

// from iriclib_sol_particlegroup.h
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Pos2d_WithGridId(int fid, int gid, int step, const char* groupname, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Pos3d_WithGridId(int fid, int gid, int step, const char* groupname, RealArrayContainer& x_arr, RealArrayContainer& y_arr, RealArrayContainer& z_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Real_WithGridId(int fid, int gid, int step, const char* groupname, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_ParticleGroup_Integer_WithGridId(int fid, int gid, int step, const char* groupname, const char* name, IntArrayContainer& v_arr);

// from iriclib_sol_polydata.h
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Pos2d_WithGridId(int fid, int gid, int step, const char* groupname, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Type_WithGridId(int fid, int gid, int step, const char* groupname, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Real_WithGridId(int fid, int gid, int step, const char* groupname, const char* name, RealArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Read_Sol_PolyData_Integer_WithGridId(int fid, int gid, int step, const char* groupname, const char* name, IntArrayContainer& v_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Polygon_WithGridId(int fid, int gid, int numPoints, RealArrayContainer& x_arr, RealArrayContainer& y_arr);
int IRICLIBDLL cg_iRIC_Write_Sol_PolyData_Polyline_WithGridId(int fid, int gid, int numPoints, RealArrayContainer& x_arr, RealArrayContainer& y_arr);

// from iriclib_solution.h

#endif // IRICLIB_WRAPPER_H
