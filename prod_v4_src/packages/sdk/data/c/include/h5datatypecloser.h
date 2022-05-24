#ifndef H5DATATYPECLOSER_H
#define H5DATATYPECLOSER_H

#include "iriclib_global.h"

#include <hdf5.h>

namespace iRICLib {

class IRICLIBDLL H5DataTypeCloser
{
public:
	H5DataTypeCloser(hid_t dataTypeId);
	~H5DataTypeCloser();

private:
	hid_t m_dataTypeId;
};

} // namespace iRICLib

#endif // H5DATATYPECLOSER_H
