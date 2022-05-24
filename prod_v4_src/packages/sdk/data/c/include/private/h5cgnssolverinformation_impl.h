#ifndef H5CGNSSOLVERINFORMATION_IMPL_H
#define H5CGNSSOLVERINFORMATION_IMPL_H

#include "../h5cgnssolverinformation.h"

#include <set>

namespace iRICLib {

class H5CgnsSolverInformation::Impl
{
public:
	Impl();
	~Impl();

	hid_t m_groupId;
	std::set<std::string> m_names;
};

} // namespace iRICLib

#endif // H5CGNSSOLVERINFORMATION_IMPL_H
