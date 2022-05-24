#ifndef H5CGNSGEOGRAPHICDATATOP_H
#define H5CGNSGEOGRAPHICDATATOP_H

#include "iriclib_global.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsBase;
class H5CgnsGeographicDataGroup;

class IRICLIBDLL H5CgnsGeographicDataTop
{
public:
	H5CgnsGeographicDataTop(hid_t groupId, H5CgnsBase* base);
	~H5CgnsGeographicDataTop();

	std::vector<std::string> groupNames() const;
	bool groupExists(const std::string& name) const;
	H5CgnsGeographicDataGroup* group(const std::string& name);

	H5CgnsBase* base() const;

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsgeographicdatatop_impl.h"
#endif // _DEBUG

#endif // H5CGNSGEOGRAPHICDATATOP_H
