#ifndef H5CGNSPOLYDATASOLUTION_GROUPREADER_H
#define H5CGNSPOLYDATASOLUTION_GROUPREADER_H

#include "../iriclib_global.h"
#include "../h5cgnspolydatasolution.h"
#include "../h5cgnssolutioni.h"

#include <vector>

namespace iRICLib {

class IRICLIBDLL H5CgnsPolyDataSolution::GroupReader : public H5CgnsSolutionI
{
public:
	GroupReader(const std::string& groupName, H5CgnsPolyDataSolution* sol);

	int readValueNames(std::vector<std::string>* names) const override;
	int readValueNames(std::set<std::string>* names) const override;
	int readValueType(const std::string& name, H5Util::DataArrayValueType *type) const override;
	int readValue(const std::string& name, std::vector<int>* values) const override;
	int readValue(const std::string& name, std::vector<double>* values) const override;
	int readValueAsDouble(const std::string& name, std::vector<double>* values) const override;

	H5CgnsZone* zone() const override;

	void setCellCounts(const std::vector<int>& cellCounts);

private:
	std::string m_groupName;
	std::vector<int> m_cellCounts;
	H5CgnsPolyDataSolution* m_solution;
};

} // namespace iRICLib

#endif // H5CGNSPOLYDATASOLUTION_GROUPREADER_H
