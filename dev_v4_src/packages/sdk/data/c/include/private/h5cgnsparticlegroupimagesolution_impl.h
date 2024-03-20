#ifndef H5CGNSPARTICLEGROUPIMAGESOLUTION_IMPL_H
#define H5CGNSPARTICLEGROUPIMAGESOLUTION_IMPL_H

#include "../h5cgnsparticlegroupimagesolution.h"

#include <map>
#include <vector>

namespace iRICLib {

class H5CgnsParticleGroupImageSolution::Impl
{
public:
	Impl();
	void clear();

	std::string m_name;
	std::string m_groupName;
	std::vector<double> m_coordinateX;
	std::vector<double> m_coordinateY;
	std::vector<double> m_size;
	std::vector<double> m_angle;

	hid_t m_groupId;

	H5CgnsZone* m_zone;
};

} // namespace iRICLib

#endif // H5CGNSPARTICLEGROUPIMAGESOLUTION_IMPL_H
