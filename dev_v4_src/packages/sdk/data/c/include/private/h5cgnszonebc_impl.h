#ifndef H5CGNSZONEBC_IMPL_H
#define H5CGNSZONEBC_IMPL_H

#include "../h5cgnszonebc.h"

#include <map>

namespace iRICLib {

class H5CgnsZoneBc::Impl
{
public:
	Impl(H5CgnsZoneBc* zoneBc);
	~Impl();

	void loadBcs();
	H5CgnsBc* createBc(const std::string& name);
	void clear();

	std::string name(const std::string& typeName, int num);

	hid_t m_groupId;
	std::map<std::string, H5CgnsBc*> m_bcMap;

	H5CgnsZone* m_zone;

private:
	H5CgnsZoneBc* m_zoneBc;
};

} // namespace iRICLib

#endif // H5CGNSZONEBC_IMPL_H
