#ifndef H5DATASETCLOSER_H
#define H5DATASETCLOSER_H

#include "iriclib_global.h"

#include <hdf5.h>

namespace iRICLib {

class IRICLIBDLL H5DatasetCloser
{
public:
	H5DatasetCloser(hid_t datasetId);
	~H5DatasetCloser();

private:
	hid_t m_datasetId;
};

} // namespace iRICLib

#endif // H5DATASETCLOSER_H
