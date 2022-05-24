#ifndef H5CGNSPOLYDATASOLUTION_IMPL_H
#define H5CGNSPOLYDATASOLUTION_IMPL_H

#include "../h5cgnspolydatasolution.h"

#include <map>
#include <vector>

namespace iRICLib {

class H5CgnsPolyDataSolution::Impl
{
public:
	Impl();
	void clear();

	std::string m_name;
	std::string m_groupName;
	std::vector<double> m_coordinateX;
	std::vector<double> m_coordinateY;
	std::vector<int> m_types;
	std::vector<int> m_sizes;
	std::map<std::string, std::vector<int> > m_intValues;
	std::map<std::string, std::vector<double> > m_realValues;

	hid_t m_groupId;

	H5CgnsZone* m_zone;
};

} // namespace iRICLib

#endif // H5CGNSPOLYDATASOLUTION_IMPL_H
