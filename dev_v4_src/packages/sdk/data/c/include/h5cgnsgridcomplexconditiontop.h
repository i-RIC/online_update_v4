#ifndef H5CGNSGRIDCOMPLEXCONDITIONTOP_H
#define H5CGNSGRIDCOMPLEXCONDITIONTOP_H

#include "iriclib_global.h"

#include <hdf5.h>

#include <string>

namespace iRICLib {

class H5CgnsBase;
class H5CgnsGridComplexConditionGroup;

class IRICLIBDLL H5CgnsGridComplexConditionTop
{
public:
	H5CgnsGridComplexConditionTop(hid_t groupId, H5CgnsBase* base);
	~H5CgnsGridComplexConditionTop();

	H5CgnsGridComplexConditionGroup* group(const std::string& name);
	bool groupExists(const std::string& name) const;

	int clear();

	H5CgnsBase* base() const;

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsgridcomplexconditiontop_impl.h"
#endif // _DEBUG

#endif // H5CGNSGRIDCOMPLEXCONDITIONTOP_H
