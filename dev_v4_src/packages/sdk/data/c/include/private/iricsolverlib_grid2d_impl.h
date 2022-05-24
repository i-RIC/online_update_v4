#ifndef IRICSOLVERLIB_GRID2D_IMPL_H
#define IRICSOLVERLIB_GRID2D_IMPL_H

#include "../iricsolverlib_grid2d.h"

#include <vector>

namespace iRICLib
{
class H5CgnsGridCoordinates;
class H5CgnsZone;
}

namespace iRICSolverLib {

class Grid2D::Impl
{
public:
	Impl(Grid2D* grid);
	~Impl();

	int loadNodes(iRICLib::H5CgnsGridCoordinates* coords);
	int loadCells(const iRICLib::H5CgnsZone& zone);
	int loadStructuredGrid(const iRICLib::H5CgnsZone& zone);
	int loadUnstructuredGrid(const iRICLib::H5CgnsZone& zone);

	void setupBackGrid();

	int structuredIndex(int i, int j, int* size) const;

	Grid2D* m_grid;
	std::vector<Point2D> m_nodes;
	std::vector<Cell2D*> m_cells;

	std::vector<double> m_backGridX;
	std::vector<double> m_backGridY;

	std::vector< std::vector<Cell2D*> > m_backGridCells;
};

} // iRICSolverLib

#endif // IRICSOLVERLIB_GRID2D_IMPL_H
