#ifndef IRICSOLVERLIB_RECT2D_H
#define IRICSOLVERLIB_RECT2D_H

#include "iriclib_global.h"

namespace iRICSolverLib {

class Point2D;

class IRICLIBDLL Rect2D
{
public:
	Rect2D();
	Rect2D(double xmin, double xmax, double ymin, double ymax);
	Rect2D(const Rect2D& rect);

	Rect2D& operator=(const Rect2D& rect);

	double xMin() const;
	double xMax() const;
	double yMin() const;
	double yMax() const;

	double xWidth() const;
	double yWidth() const;

	bool contains(double x, double y) const;
	bool contains(const Point2D& point) const;
	bool intersects(const Rect2D& rect) const;

	void setXMin(double xmin);
	void setXMax(double xmax);
	void setYMin(double ymin);
	void setYMax(double ymax);

private:
	double m_xMin;
	double m_xMax;
	double m_yMin;
	double m_yMax;
};

Rect2D operator +(const Rect2D& rect1, const Rect2D& rect2);

} // iRICSolverLib

#endif // IRICSOLVERLIB_RECT2D_H
