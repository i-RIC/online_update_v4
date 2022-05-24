#ifndef H5DATASPACECLOSER_H
#define H5DATASPACECLOSER_H

#include <hdf5.h>

namespace iRICLib {

class H5DataSpaceCloser
{
public:
	H5DataSpaceCloser(hid_t dataSpaceId);
	~H5DataSpaceCloser();

private:
	hid_t m_dataSpaceId;
};

} // namespace iRICLib

#endif // H5DATASPACECLOSER_H
