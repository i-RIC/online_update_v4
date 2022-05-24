#ifndef H5OBJECTCLOSER_H
#define H5OBJECTCLOSER_H

#include <hdf5.h>

namespace iRICLib {

class H5ObjectCloser
{
public:
	H5ObjectCloser(hid_t objectId);
	~H5ObjectCloser();

private:
	hid_t m_objectId;
};

} // namespace iRICLib

#endif // H5OBJECTCLOSER_H
