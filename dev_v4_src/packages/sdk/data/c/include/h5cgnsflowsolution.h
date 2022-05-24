#ifndef H5CGNSFLOWSOLUTION_H
#define H5CGNSFLOWSOLUTION_H

#include "iriclib_global.h"
#include "h5cgnssolutioni.h"
#include "h5util.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsZone;

class IRICLIBDLL H5CgnsFlowSolution : public H5CgnsSolutionI
{
public:
	static std::string label();

	H5CgnsFlowSolution(const std::string& name, hid_t groupId, H5CgnsZone* zone);
	virtual ~H5CgnsFlowSolution();

	std::string name() const;

	int readValueNames(std::vector<std::string>* names) const override;
	int readValueNames(std::set<std::string>* names) const override;
	int readValueType(const std::string& name, H5Util::DataArrayValueType *type) const override;
	int readValue(const std::string& name, std::vector<int>* values) const override;
	int readValue(const std::string& name, std::vector<double>* values) const override;
	int readValueAsDouble(const std::string& name, std::vector<double>* values) const override;
	int writeValue(const std::string& name, const std::vector<int>& values) const;
	int writeValue(const std::string& name, const std::vector<double>& values) const;

	H5CgnsZone* zone() const override;

private:
	virtual int dataDims(std::vector<hsize_t>* dims) const = 0;

	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsflowsolution_impl.h"
#endif // _DEBUG

#endif // H5CGNSFLOWSOLUTION_H
