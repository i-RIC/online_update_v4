#ifndef IRICSOLVERLIB_POINT2D_DETAIL_H
#define IRICSOLVERLIB_POINT2D_DETAIL_H

#include "../iricsolverlib_point2d.h"

namespace iRICSolverLib {

inline Point2D::Point2D() :
	m_x (0), m_y(0)
{}

inline Point2D::Point2D(double x, double y) :
	m_x (x), m_y(y)
{}

inline double Point2D::x() const
{
	return m_x;
}

inline double Point2D::y() const
{
	return m_y;
}

inline Point2D operator+(const Point2D& p1, const Point2D& p2)
{
	return Point2D(p1.x() + p2.x(), p1.y() + p2.y());
}

inline Point2D operator-(const Point2D& p1, const Point2D& p2)
{
	return Point2D(p1.x() - p2.x(), p1.y() - p2.y());
}

inline double operator*(const Point2D& p1, const Point2D& p2)
{
	return p1.x() * p2.y() - p1.y() * p2.x();
}

} // iRICSolverLib

#endif // IRICSOLVERLIB_POINT2D_DETAIL_H
