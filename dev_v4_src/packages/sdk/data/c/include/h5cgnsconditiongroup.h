#ifndef H5CGNSCONDITIONGROUP_H
#define H5CGNSCONDITIONGROUP_H

#include "iriclib_global.h"

#include "h5cgnsfile.h"

#include <hdf5.h>

#include <string>

namespace iRICLib {

// Group that contains information about calculation condition, boundary condition etc.
class IRICLIBDLL H5CgnsConditionGroup
{
public:
	H5CgnsConditionGroup(const std::string& name, hid_t groupId, H5CgnsFile::Mode mode);
	virtual ~H5CgnsConditionGroup();

	std::string name() const;
	H5CgnsFile::Mode mode() const;

	int readIntegerValue(const std::string& name, int* value) const;
	int readRealValueAsFloat(const std::string& name, float* value) const;
	int readRealValueAsDouble(const std::string& name, double* value) const;
	int readStringLen(const std::string& name, int* length) const;
	int readString(const std::string& name, char* value) const;
	int readFunctionalSize(const std::string& name, int* size) const;
	int readFunctional(const std::string& name, double* x, double* y) const;
	int readFunctionalWithName(const std::string& name, const std::string& paramName, double* data) const;
	int readFunctional(const std::string& name, float* x, float* y) const;
	int readFunctionalWithName(const std::string& name, const std::string& paramName, float* data) const;
	int readFunctionalWithNameStringLen(const std::string& name, const std::string& paramName, int* length) const;
	int readFunctionalWithNameString(const std::string& name, const std::string& paramName, char* value) const;

	int writeIntegerValue(const std::string& name, int value);
	int writeRealValue(const std::string& name, double value);
	int writeString(const std::string& name, const std::string& value);
	int writeFunctional(const std::string& name, int length, double* x, double* y);
	int writeFunctionalWithName(const std::string& name, const std::string& paramName, int length, double* data);
	int writeFunctionalWithNameString(const std::string& name, const std::string& paramName, const std::string& value);

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsconditiongroup_impl.h"
#endif // _DEBUG

#endif // H5CGNSCONDITIONGROUP_H
