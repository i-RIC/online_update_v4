#ifndef H5CGNSFLOWSOLUTION_IMPL_H
#define H5CGNSFLOWSOLUTION_IMPL_H

#include "../h5cgnsflowsolution.h"

namespace iRICLib {

class H5CgnsFlowSolution::Impl
{
public:
	std::string m_name;

	hid_t m_groupId;

	H5CgnsZone* m_zone;
};

} // namespace iRICLib

#endif // H5CGNSFLOWSOLUTION_IMPL_H
