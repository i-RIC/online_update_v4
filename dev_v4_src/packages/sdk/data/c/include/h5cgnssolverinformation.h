#ifndef H5CGNSSOLVERINFORMATION_H
#define H5CGNSSOLVERINFORMATION_H

#include "iriclib_global.h"

#include <hdf5.h>

#include <string>

namespace iRICLib {

class IRICLIBDLL H5CgnsSolverInformation
{
public:
	H5CgnsSolverInformation(hid_t groupId);
	~H5CgnsSolverInformation();

	int readSolverName(std::string* name);
	int readSolverVersion(std::string* version);

	int writeSolverName(const std::string& name);
	int writeSolverVersion(const std::string& version);

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnssolverinformation_impl.h"
#endif // _DEBUG

#endif // H5CGNSSOLVERINFORMATION_H
