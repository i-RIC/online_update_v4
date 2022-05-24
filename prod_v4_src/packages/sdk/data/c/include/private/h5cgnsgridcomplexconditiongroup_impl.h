#ifndef H5CGNSGRIDCOMPLEXCONDITIONGROUP_IMPL_H
#define H5CGNSGRIDCOMPLEXCONDITIONGROUP_IMPL_H

#include "../h5cgnsgridcomplexconditiongroup.h"

#include <vector>

namespace iRICLib {

class H5CgnsGridComplexConditionGroup::Impl
{
public:
	Impl();
	~Impl();

	void loadItems();

	H5CgnsConditionGroup* openItem(int num, bool noErrorLog = false);
	H5CgnsConditionGroup* createItem(int num);

	static std::string itemName(int num);

	std::vector<H5CgnsConditionGroup*> m_items;

	hid_t m_groupId;
	std::string m_name;

	H5CgnsGridComplexConditionTop* m_top;
};

} // namespace iRICLib

#endif // H5CGNSGRIDCOMPLEXCONDITIONGROUP_IMPL_H
