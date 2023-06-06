#ifndef H5CGNSFLOWSOLUTION_IMPL_H
#define H5CGNSFLOWSOLUTION_IMPL_H

#include "../h5cgnsflowsolution.h"

#include <unordered_set>

namespace iRICLib {

class H5CgnsFlowSolution::Impl
{
public:
	int loadNames();
	int checkNameExists(const std::string& name);

	std::string m_name;

	hid_t m_groupId;

	std::unordered_set<std::string> m_names;
	H5CgnsZone* m_zone;
};

} // namespace iRICLib

#endif // H5CGNSFLOWSOLUTION_IMPL_H
