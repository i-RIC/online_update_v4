#ifndef H5CGNSZONEBC_H
#define H5CGNSZONEBC_H

#include "iriclib_global.h"

#include <hdf5.h>

#include <string>

namespace iRICLib {

class H5CgnsBc;
class H5CgnsZone;

class IRICLIBDLL H5CgnsZoneBc
{
public:
	static std::string name();
	static std::string label();

	H5CgnsZoneBc(hid_t groupId, H5CgnsZone* zone);
	~H5CgnsZoneBc();

	int bcCount(const std::string& typeName) const;
	H5CgnsBc* bc(const std::string& typeName, int num);
	bool bcExists(const std::string& typeName, int num) const;
	int clear();

	H5CgnsZone* zone() const;

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnszonebc_impl.h"
#endif // _DEBUG

#endif // H5CGNSZONEBC_H
