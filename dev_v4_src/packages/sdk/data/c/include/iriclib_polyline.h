#ifndef IRICLIB_POLYGON_H
#define IRICLIB_POLYGON_H

#include "iriclib_global.h"
#include <vector>

namespace iRICLib {
class IRICLIBDLL InternalPolyline {
public:
	InternalPolyline();
	~InternalPolyline();
	double* x;
	double* y;
	int pointCount;
};

class IRICLIBDLL Polyline {
public:
	Polyline();
	~Polyline();
	std::vector<double> values;
	InternalPolyline* polyline;

	int load(const char* filename, bool noDimensions = false);
	int save(const char* filename, bool noDimensions = false);
	void clear();
};
}

#endif // IRICLIB_POLYGON_H
