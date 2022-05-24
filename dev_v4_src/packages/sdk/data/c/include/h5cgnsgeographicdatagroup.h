#ifndef H5CGNSGEOGRAPHICDATAGROUP_H
#define H5CGNSGEOGRAPHICDATAGROUP_H

#include "iriclib_global.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsGeographicDataTop;

class IRICLIBDLL H5CgnsGeographicDataGroup
{
public:
	enum class Type {
		Unknown = 0,
		Polygon = 1,
		RiverSurvey = 2,
		Pointmap = 3,
		Polyline = 4,
	};

	H5CgnsGeographicDataGroup(hid_t groupId);
	~H5CgnsGeographicDataGroup();

	int count(int* count) const;
	int read(int id, std::string* filename, Type* type);

	int add(const std::string& filename, Type type);
	int clear();

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsgeographicdatagroup_impl.h"
#endif // _DEBUG


#endif // H5CGNSGEOGRAPHICDATAGROUP_H
