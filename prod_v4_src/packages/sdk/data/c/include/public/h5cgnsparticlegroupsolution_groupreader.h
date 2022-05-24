#ifndef H5CGNSPARTICLEGROUPSOLUTION_GROUPREADER_H
#define H5CGNSPARTICLEGROUPSOLUTION_GROUPREADER_H

#include "../iriclib_global.h"
#include "../h5cgnsparticlegroupsolution.h"
#include "../h5cgnssolutioni.h"

namespace iRICLib {

class IRICLIBDLL H5CgnsParticleGroupSolution::GroupReader : public H5CgnsSolutionI
{
public:
	GroupReader(const std::string& groupName, H5CgnsParticleGroupSolution* sol);

	int readValueNames(std::vector<std::string>* names) const override;
	int readValueNames(std::set<std::string>* names) const override;
	int readValueType(const std::string& name, H5Util::DataArrayValueType *type) const override;
	int readValue(const std::string& name, std::vector<int>* values) const override;
	int readValue(const std::string& name, std::vector<double>* values) const override;
	int readValueAsDouble(const std::string& name, std::vector<double>* values) const override;

	H5CgnsZone* zone() const override;

private:
	std::string m_groupName;
	H5CgnsParticleGroupSolution* m_solution;
};

} // namespace iRICLib

#endif // H5CGNSPARTICLEGROUPSOLUTION_GROUPREADER_H
