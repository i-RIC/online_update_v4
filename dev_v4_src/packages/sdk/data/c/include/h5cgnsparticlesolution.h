#ifndef H5CGNSPARTICLESOLUTION_H
#define H5CGNSPARTICLESOLUTION_H

#include "iriclib_global.h"
#include "h5cgnssolutioni.h"
#include "h5util.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsZone;

class IRICLIBDLL H5CgnsParticleSolution : public H5CgnsSolutionI
{
public:
	H5CgnsParticleSolution(const std::string& name, hid_t groupId, H5CgnsZone* zone);
	~H5CgnsParticleSolution();

	std::string name() const;

	int count(int* count);
	int readValueNames(std::vector<std::string>* names) const override;
	int readValueNames(std::set<std::string>* names) const override;

	int readCoordinatesX(std::vector<double>* values) const;
	int readCoordinatesY(std::vector<double>* values) const;
	int readCoordinatesZ(std::vector<double>* values) const;
	int readValueType(const std::string& name, H5Util::DataArrayValueType *type) const override;
	int readValue(const std::string& name, std::vector<double>* values) const override;
	int readValue(const std::string& name, std::vector<int>* values) const override;
	int readValueAsDouble(const std::string& name, std::vector<double>* values) const override;

	int writeCoordinatesX(const std::vector<double>& coords) const;
	int writeCoordinatesY(const std::vector<double>& coords) const;
	int writeCoordinatesZ(const std::vector<double>& coords) const;
	int writeValue(const std::string& name, const std::vector<double>& values) const;
	int writeValue(const std::string& name, const std::vector<int>& values) const;

	H5CgnsZone* zone() const override;

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsparticlesolution_impl.h"
#endif // _DEBUG

#endif // H5CGNSPARTICLESOLUTION_H
