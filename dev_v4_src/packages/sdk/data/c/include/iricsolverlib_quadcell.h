#ifndef IRICSOLVERLIB_QUADCELL_H
#define IRICSOLVERLIB_QUADCELL_H

#include "iriclib_global.h"
#include "iricsolverlib_cell2d.h"

namespace iRICSolverLib {

class IRICLIBDLL QuadCell : public Cell2D
{
public:
	QuadCell(int id1, int id2, int id3, int id4, Grid2D* const grid);
	~QuadCell();

	bool interpolate(const Point2D& point, double* weight) const;
	double area() const;
};

} // iRICSolverLib

#endif // IRICSOLVERLIB_QUADCELL_H
