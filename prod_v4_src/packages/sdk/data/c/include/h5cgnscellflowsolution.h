#ifndef H5CGNSCELLFLOWSOLUTION_H
#define H5CGNSCELLFLOWSOLUTION_H

#include "iriclib_global.h"

#include "h5cgnsflowsolution.h"

namespace iRICLib {

class H5CgnsCellFlowSolution : public H5CgnsFlowSolution
{
public:
	H5CgnsCellFlowSolution(const std::string& name, hid_t groupId, H5CgnsZone* zone);

private:
	int dataDims(std::vector<hsize_t>* dims) const override;
};

} // namespace iRICLib

#endif // H5CGNSCELLFLOWSOLUTION_H
