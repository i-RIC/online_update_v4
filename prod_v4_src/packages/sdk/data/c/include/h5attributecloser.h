#ifndef H5ATTRIBUTECLOSER_H
#define H5ATTRIBUTECLOSER_H

#include "iriclib_global.h"

#include <hdf5.h>

namespace iRICLib {

class IRICLIBDLL H5AttributeCloser
{
public:
	H5AttributeCloser(hid_t attributeId);
	~H5AttributeCloser();

private:
	hid_t m_attributeId;
};

} // namespace iRICLib

#endif // H5ATTRIBUTECLOSER_H
