#ifndef H5CGNSJFACEFLOWSOLUTION_H
#define H5CGNSJFACEFLOWSOLUTION_H

#include "iriclib_global.h"

#include "h5cgnsflowsolution.h"

namespace iRICLib {

class H5CgnsJFaceFlowSolution : public H5CgnsFlowSolution
{
public:
	H5CgnsJFaceFlowSolution(const std::string& name, hid_t groupId, H5CgnsZone* zone);

private:
	int dataDims(std::vector<hsize_t>* dims) const override;
};

} // namespace iRICLib

#endif // H5CGNSJFACEFLOWSOLUTION_H
