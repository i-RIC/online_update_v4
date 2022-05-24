#ifndef H5CGNSGRIDCOMPLEXCONDITIONGROUP_H
#define H5CGNSGRIDCOMPLEXCONDITIONGROUP_H

#include "iriclib_global.h"

#include <hdf5.h>

#include <string>

namespace iRICLib {

class H5CgnsGridComplexConditionTop;
class H5CgnsConditionGroup;

class IRICLIBDLL H5CgnsGridComplexConditionGroup
{
public:
	H5CgnsGridComplexConditionGroup(hid_t groupId, const std::string& name, H5CgnsGridComplexConditionTop* top);
	~H5CgnsGridComplexConditionGroup();

	H5CgnsConditionGroup* item(int num);
	int itemCount() const;

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#endif // H5CGNSGRIDCOMPLEXCONDITIONGROUP_H
