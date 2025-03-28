#ifndef H5CGNSGRIDATTRIBUTES_IMPL_H
#define H5CGNSGRIDATTRIBUTES_IMPL_H

#include "../h5cgnsgridattributes.h"

#include <unordered_set>

namespace iRICLib {

class H5CgnsGridAttributes::Impl
{
public:
	Impl();
	~Impl();

	hid_t m_groupId;

	std::unordered_set<std::string> m_names;

	H5CgnsZone* m_zone;
};

} // namespace iRICLib

#endif // H5CGNSGRIDATTRIBUTES_IMPL_H
