#ifndef IRICLIB_GEO_H
#define IRICLIB_GEO_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL iRIC_Geo_Polygon_Open(const char* filename, int* geo_handle);
int IRICLIBDLL iRIC_Geo_Polygon_Read_IntegerValue(int geo_handle, int* value);
int IRICLIBDLL iRIC_Geo_Polygon_Read_RealValue(int geo_handle, double* value);
int IRICLIBDLL iRIC_Geo_Polygon_Read_PointCount(int geo_handle, int* count);
int IRICLIBDLL iRIC_Geo_Polygon_Read_Points(int geo_handle, double* x_arr, double* y_arr);
int IRICLIBDLL iRIC_Geo_Polygon_Read_HoleCount(int geo_handle, int* count);
int IRICLIBDLL iRIC_Geo_Polygon_Read_HolePointCount(int geo_handle, int holeid, int* count);
int IRICLIBDLL iRIC_Geo_Polygon_Read_HolePoints(int geo_handle, int holeid, double* x_arr, double* y_arr);
int IRICLIBDLL iRIC_Geo_Polygon_Close(int geo_handle);

int IRICLIBDLL iRIC_Geo_RiverSurvey_Open(const char* filename, int* geo_handle);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_Count(int geo_handle, int* count);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_Position(int geo_handle, int csid, double* x, double* y);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_Direction(int geo_handle, int csid, double* dirx, double* diry);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_Name(int geo_handle, int csid, char* strvalue);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_RealName(int geo_handle, int csid, double* name);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_LeftShift(int geo_handle, int csid, double* shift);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_AltitudeCount(int geo_handle, int csid, int* count);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_Altitudes(int geo_handle, int csid, double* position_arr, double* height_arr, int* active_arr);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_FixedPointL(int geo_handle, int csid, int* set, double* dirx, double* diry, int* index);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_FixedPointR(int geo_handle, int csid, int* set, double* dirx, double* diry, int* index);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_WaterSurfaceElevation(int geo_handle, int csid, int* set, double* value);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Close(int geo_handle);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_GEO_H
