#ifndef H5CGNSGEOGRAPHICDATAGROUP_IMPL_H
#define H5CGNSGEOGRAPHICDATAGROUP_IMPL_H

#include "../h5cgnsgeographicdatagroup.h"

namespace iRICLib {

class H5CgnsGeographicDataGroup::Impl
{
public:
	Impl();
	~Impl();

	hid_t m_groupId;
	int m_count;
};

} // namespace iRICLib

#endif // H5CGNSGEOGRAPHICDATAGROUP_IMPL_H
