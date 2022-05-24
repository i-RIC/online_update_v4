#ifndef H5CGNSBC_H
#define H5CGNSBC_H

#include "iriclib_global.h"

#include "h5cgnsconditiongroup.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsZoneBc;

class IRICLIBDLL H5CgnsBc : public H5CgnsConditionGroup
{
public:
	static std::string label();

	H5CgnsBc(const std::string& name, hid_t groupId, H5CgnsZoneBc* zoneBc);
	~H5CgnsBc();

	int readIndicesSize(int* size) const;
	int readIndicesValueCount(int* size) const;
	int readIndices(std::vector<int>* indices) const;
	int writeIndices(const std::vector<int>& indices) const;

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsbc_impl.h"
#endif // _DEBUG



#endif // H5CGNSBC_H
