#ifndef H5CGNSGRIDATTRIBUTES_H
#define H5CGNSGRIDATTRIBUTES_H

#include "iriclib_global.h"
#include "h5util.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsZone;

class IRICLIBDLL H5CgnsGridAttributes
{
public:
	H5CgnsGridAttributes(hid_t groupId, H5CgnsZone* zone);
	~H5CgnsGridAttributes();

	int getValueNames(std::vector<std::string>* names) const;
	int getValueNames(std::set<std::string>* names) const;
	int getValueType(const std::string& name, H5Util::DataArrayValueType *type) const;
	int readValue(const std::string& name, std::vector<int>* values) const;
	int readValue(const std::string& name, std::vector<double>* values) const;

	int readFunctionalDimensionSize(const std::string& name, const std::string& dimname, int* size) const;
	int readFunctionalDimension(const std::string& name, const std::string& dimname, std::vector<int>* values) const;
	int readFunctionalDimension(const std::string& name, const std::string& dimname, std::vector<double>* values) const;
	int readFunctional(const std::string& name, int dimid, std::vector<int>* values) const;
	int readFunctional(const std::string& name, int dimid, std::vector<double>* values) const;

	int writeValue(const std::string& name, const std::vector<int>& values) const;
	int writeValue(const std::string& name, const std::vector<double>& values) const;

	int writeFunctionalDimension(const std::string& name, const std::string& dimname, const std::vector<int>& values) const;
	int writeFunctionalDimension(const std::string& name, const std::string& dimname, const std::vector<double>& values) const;
	int writeFunctional(const std::string& name, int dimid, const std::vector<int>& values) const;
	int writeFunctional(const std::string& name, int dimid, const std::vector<double>& values) const;

	H5CgnsZone* zone() const;

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsgridattributes_impl.h"
#endif // _DEBUG

#endif // H5CGNSGRIDATTRIBUTES_H
