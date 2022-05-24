#ifndef H5CGNSPARTICLESOLUTION_IMPL_H
#define H5CGNSPARTICLESOLUTION_IMPL_H

#include "../h5cgnsparticlesolution.h"

namespace iRICLib {

class H5CgnsParticleSolution::Impl
{
public:
	std::string m_name;

	hid_t m_groupId;

	H5CgnsZone* m_zone;
};

} // namespace iRICLib

#endif // H5CGNSPARTICLESOLUTION_IMPL_H
