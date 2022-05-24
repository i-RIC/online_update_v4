#ifndef IRICSOLVERLIB_GRID2D_H
#define IRICSOLVERLIB_GRID2D_H

#include "iriclib_global.h"

namespace iRICSolverLib {

class Cell2D;
class Point2D;
class Rect2D;

class IRICLIBDLL Grid2D
{
public:
	Grid2D();
	~Grid2D();

	int load(int fid, int gid);
	int load(int fid, int gid, int solid);

	int nodeCount() const;
	Point2D node(int nodeId) const;

	int cellCount() const;
	Cell2D* cell(int cellId) const;

	Rect2D boundingRect() const;

	bool findCell(const Point2D& point, int* cellId) const;
	bool interpolate(const Point2D& point, int *count, int* nodeIds, double* weight) const;

	void addNode(const Point2D& p);
	void addNode(double x, double y);

	void addTriCell(int id1, int id2, int id3);
	void addQuadCell(int id1, int id2, int id3, int id4);

	void setupBackGrid();

private:
	class Impl;
	Impl* impl;
};

} // iRICSolverLib

#ifdef _DEBUG
	#include "private/iricsolverlib_grid2d_impl.h"
#endif // _DEBUG

#endif // IRICSOLVERLIB_GRID2D_H
