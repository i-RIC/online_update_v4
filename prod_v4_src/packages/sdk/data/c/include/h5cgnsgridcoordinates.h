#ifndef H5CGNSGRIDCOORDINATES_H
#define H5CGNSGRIDCOORDINATES_H

#include "iriclib_global.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsZone;

class IRICLIBDLL H5CgnsGridCoordinates
{
public:
	static std::string label();

	H5CgnsGridCoordinates(const std::string& name, hid_t groupId, H5CgnsZone* zone);
	~H5CgnsGridCoordinates();

	std::string name() const;

	int readCoordinatesX(std::vector<double>* values) const;
	int readCoordinatesY(std::vector<double>* values) const;
	int readCoordinatesZ(std::vector<double>* values) const;

	int writeCoordinatesX(const std::vector<double>& coords) const;
	int writeCoordinatesY(const std::vector<double>& coords) const;
	int writeCoordinatesZ(const std::vector<double>& coords) const;

	int copyTo(H5CgnsGridCoordinates* coords);

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsgridcoordinates_impl.h"
#endif // _DEBUG

#endif // H5CGNSGRIDCOORDINATES_H
