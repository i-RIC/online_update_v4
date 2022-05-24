#ifndef H5CGNSCONDITIONGROUP_IMPL_H
#define H5CGNSCONDITIONGROUP_IMPL_H

#include "../h5cgnsconditiongroup.h"

#include <set>

namespace iRICLib {

class H5CgnsConditionGroup::Impl
{
public:
	int openOrCreateGroups(const std::string& name, const std::string& paramName, const std::string& type, hid_t* groupId);

	std::string m_name;
	H5CgnsFile::Mode m_mode;

	std::set<std::string> m_names;

	hid_t m_groupId;
};

} // namespace iRICLib

#endif // H5CGNSCONDITIONGROUP_IMPL_H
