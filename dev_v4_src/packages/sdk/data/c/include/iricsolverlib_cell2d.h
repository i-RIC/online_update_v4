#ifndef IRICSOLVERLIB_CELL2D_H
#define IRICSOLVERLIB_CELL2D_H

#include "iriclib_global.h"

#include <cstdlib>

namespace iRICSolverLib {

class Grid2D;
class Point2D;
class Rect2D;

class IRICLIBDLL Cell2D
{
public:
	Cell2D(Grid2D* const grid);
	virtual ~Cell2D();

	int id() const;
	void setId(int id);

	int nodeCount() const;
	int nodeId(int id) const;
	Point2D node(int id) const;

	Rect2D boundingRect() const;

	virtual bool interpolate(const Point2D& point, double* weight) const = 0;
	virtual double area() const = 0;

protected:
	void addNode(int id);

private:
	class Impl;
	Impl* impl;

	// copy not allowed
	Cell2D(const Cell2D& cell);
	Cell2D& operator=(const Cell2D& cell);
};

} // iRICSolverLib

#ifdef _DEBUG
	#include "private/iricsolverlib_cell2d_impl.h"
#endif // _DEBUG

#endif // IRICSOLVERLIB_CELL2D_H
