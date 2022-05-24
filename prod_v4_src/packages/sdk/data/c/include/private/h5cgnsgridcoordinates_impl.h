#ifndef H5CGNSGRIDCOORDINATES_IMPL_H
#define H5CGNSGRIDCOORDINATES_IMPL_H

#include "../h5cgnsgridcoordinates.h"

namespace iRICLib {

class H5CgnsGridCoordinates::Impl
{
public:
	Impl();
	~Impl();

	std::vector<hsize_t> dimensions() const;

	std::string m_name;
	hid_t m_groupId;
	H5CgnsZone* m_zone;
};

} // namespace iRICLib

#endif // H5CGNSGRIDCOORDINATES_IMPL_H
