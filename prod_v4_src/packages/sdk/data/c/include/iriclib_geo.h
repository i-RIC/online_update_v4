#ifndef IRICLIB_GEO_H
#define IRICLIB_GEO_H

#include "iriclib_global.h"

#ifdef __cplusplus
extern "C" {
#endif

int IRICLIBDLL iRIC_Geo_Polygon_Open(const char* filename, int* id);
int IRICLIBDLL iRIC_Geo_Polygon_Read_IntegerValue(int id, int* value);
int IRICLIBDLL iRIC_Geo_Polygon_Read_RealValue(int id, double* value);
int IRICLIBDLL iRIC_Geo_Polygon_Read_PointCount(int id, int* size);
int IRICLIBDLL iRIC_Geo_Polygon_Read_Points(int id, double* x_arr, double* y_arr);
int IRICLIBDLL iRIC_Geo_Polygon_Read_HoleCount(int id, int* count);
int IRICLIBDLL iRIC_Geo_Polygon_Read_HolePointCount(int id, int holeid, int* count);
int IRICLIBDLL iRIC_Geo_Polygon_Read_HolePoints(int id, int holeid, double* x_arr, double* y_arr);
int IRICLIBDLL iRIC_Geo_Polygon_Close(int id);

int IRICLIBDLL iRIC_Geo_RiverSurvey_Open(const char* filename, int* id);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_Count(int id, int* count);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_Position(int id, int pointid, double* x, double* y);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_Direction(int id, int pointid, double* vx, double* vy);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_Name(int id, int pointid, char* strvalue);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_RealName(int id, int pointid, double* name);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_LeftShift(int id, int pointid, double* shift);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_AltitudeCount(int id, int pointid, int* count);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_Altitudes(int id, int pointid, double* position_arr, double* height_arr, int* active_arr);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_FixedPointL(int id, int pointid, int* set, double* directionX, double* directionY, int* index);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_FixedPointR(int id, int pointid, int* set, double* directionX, double* directionY, int* index);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Read_WaterSurfaceElevation(int id, int pointid, int* set, double* value);
int IRICLIBDLL iRIC_Geo_RiverSurvey_Close(int id);

#ifdef __cplusplus
}
#endif

#endif // IRICLIB_GEO_H
