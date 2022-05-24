#ifndef H5CGNSSOLUTIONI_H
#define H5CGNSSOLUTIONI_H

#include "iriclib_global.h"
#include "h5util.h"

#include <set>
#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsZone;

class IRICLIBDLL H5CgnsSolutionI
{
public:
	H5CgnsSolutionI() {};
	virtual ~H5CgnsSolutionI() {};

	virtual int readValueNames(std::vector<std::string>* names) const = 0;
	virtual int readValueNames(std::set<std::string>* names) const = 0;
	virtual int readValueType(const std::string& name, H5Util::DataArrayValueType *type) const = 0;
	virtual int readValue(const std::string& name, std::vector<int>* values) const = 0;
	virtual int readValue(const std::string& name, std::vector<double>* values) const = 0;
	virtual int readValueAsDouble(const std::string& name, std::vector<double>* values) const = 0;

	virtual H5CgnsZone* zone() const = 0;
};

} // namespace iRICLib

#endif // H5CGNSSOLUTIONI_H
