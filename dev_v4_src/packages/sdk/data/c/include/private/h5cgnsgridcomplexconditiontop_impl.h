#ifndef H5CGNSGRIDCOMPLEXCONDITIONTOP_IMPL_H
#define H5CGNSGRIDCOMPLEXCONDITIONTOP_IMPL_H

#include "../h5cgnsgridcomplexconditiontop.h"

#include <map>

namespace iRICLib {

class H5CgnsGridComplexConditionTop::Impl
{
public:
	Impl(H5CgnsGridComplexConditionTop* top);
	~Impl();

	void loadGroups();
	void clear();

	H5CgnsGridComplexConditionGroup* openOrCreateGroup(const std::string& name);
	H5CgnsGridComplexConditionGroup* openGroup(const std::string& name);
	H5CgnsGridComplexConditionGroup* createGroup(const std::string& name);

	std::map<std::string, H5CgnsGridComplexConditionGroup*> m_groupMap;

	hid_t m_groupId;
	H5CgnsBase* m_base;

private:
	H5CgnsGridComplexConditionTop* m_top;
};

} // namespace iRICLib

#endif // H5CGNSGRIDCOMPLEXCONDITIONTOP_IMPL_H
