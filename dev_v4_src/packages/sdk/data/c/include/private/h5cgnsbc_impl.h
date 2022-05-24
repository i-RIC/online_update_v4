#ifndef H5CGNSBC_IMPL_H
#define H5CGNSBC_IMPL_H

#include "../h5cgnsbc.h"

namespace iRICLib {

class H5CgnsBc::Impl
{
public:
	hid_t m_groupId;

	H5CgnsZoneBc* m_zoneBc;
};

} // namespace iRICLib

#endif // H5CGNSBC_IMPL_H
