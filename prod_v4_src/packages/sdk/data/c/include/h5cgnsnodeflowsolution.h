#ifndef H5CGNSNODEFLOWSOLUTION_H
#define H5CGNSNODEFLOWSOLUTION_H

#include "iriclib_global.h"

#include "h5cgnsflowsolution.h"

namespace iRICLib {

class H5CgnsNodeFlowSolution : public H5CgnsFlowSolution
{
public:
	H5CgnsNodeFlowSolution(const std::string& name, hid_t groupId, H5CgnsZone* zone);

private:
	int dataDims(std::vector<hsize_t>* dims) const override;
};

} // namespace iRICLib

#endif // H5CGNSNODEFLOWSOLUTION_H
