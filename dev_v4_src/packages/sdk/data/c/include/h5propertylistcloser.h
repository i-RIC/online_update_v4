#ifndef H5PROPERTYLISTCLOSER_H
#define H5PROPERTYLISTCLOSER_H

#include "iriclib_global.h"

#include <hdf5.h>

namespace iRICLib {

class IRICLIBDLL H5PropertyListCloser
{
public:
	H5PropertyListCloser(hid_t propertyListId);
	~H5PropertyListCloser();

private:
	hid_t m_propertyListId;
};

} // namespace iRICLib

#endif // H5PROPERTYLISTCLOSER_H
