#ifndef H5CGNSGEOGRAPHICDATATOP_IMPL_H
#define H5CGNSGEOGRAPHICDATATOP_IMPL_H

#include "../h5cgnsgeographicdatatop.h"

#include <map>

namespace iRICLib {

class H5CgnsBase;

class H5CgnsGeographicDataTop::Impl
{
public:
	Impl(H5CgnsGeographicDataTop* top);
	~Impl();

	int loadGroups();
	H5CgnsGeographicDataGroup* createGroup(const std::string& name);

	hid_t m_groupId;
	std::map<std::string, H5CgnsGeographicDataGroup*> m_groups;

	H5CgnsBase* m_base;

private:
	H5CgnsGeographicDataTop* m_top;
};

} // namespace iRICLib

#endif // H5CGNSGEOGRAPHICDATATOP_IMPL_H
