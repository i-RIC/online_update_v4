#ifndef IRICSOLVERLIB_POINT2D_H
#define IRICSOLVERLIB_POINT2D_H

namespace iRICSolverLib {

class Point2D
{
public:
	Point2D();
	Point2D(double x, double y);

	double x() const;
	double y() const;

private:
	double m_x;
	double m_y;
};

Point2D operator+(const Point2D& p1, const Point2D& p2);
Point2D operator-(const Point2D& p1, const Point2D& p2);
double operator*(const Point2D& p1, const Point2D& p2);

} // iRICSolverLib

#include "private/iricsolverlib_point2d_detail.h"

#endif // IRICSOLVERLIB_POINT2D_H
