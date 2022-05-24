#ifndef H5GROUPCLOSER_H
#define H5GROUPCLOSER_H

#include "iriclib_global.h"

#include <hdf5.h>

namespace iRICLib {

class IRICLIBDLL H5GroupCloser
{
public:
	H5GroupCloser(hid_t groupId);
	~H5GroupCloser();

private:
	hid_t m_groupId;
};

} // namespace iRICLib

#endif // H5GROUPCLOSER_H
