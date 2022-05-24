#ifndef H5CGNSPARTICLEGROUPSOLUTION_H
#define H5CGNSPARTICLEGROUPSOLUTION_H

#include "iriclib_global.h"
#include "h5util.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsZone;

class IRICLIBDLL H5CgnsParticleGroupSolution
{
public:
	H5CgnsParticleGroupSolution(const std::string& name, hid_t groupId, H5CgnsZone* zone);
	~H5CgnsParticleGroupSolution();

	std::string name() const;

	int readGroupNames(std::vector<std::string>* names) const;
	int count(const std::string& groupName, int* count);
	int readValueNames(const std::string& groupName, std::vector<std::string>* names) const;
	int readValueNames(const std::string& groupName, std::set<std::string>* names) const;
	int readCoordinatesX(const std::string& groupName, std::vector<double>* values) const;
	int readCoordinatesY(const std::string& groupName, std::vector<double>* values) const;
	int readCoordinatesZ(const std::string& groupName, std::vector<double>* values) const;
	int readValueType(const std::string& groupName, const std::string& valueName, H5Util::DataArrayValueType *type) const;
	int readValue(const std::string& groupName, const std::string& valueName, std::vector<int>* values) const;
	int readValue(const std::string& groupName, const std::string& valueName, std::vector<double>* values) const;
	int readValueAsDouble(const std::string& groupName, const std::string& valueName, std::vector<double>* values) const;

	void writeBegin(const std::string& groupName);
	int writeEnd();
	void writePos2d(double x, double y);
	void writePos3d(double x, double y, double z);
	void writeValue(const std::string& name, int value);
	void writeValue(const std::string& name, double value);

	H5CgnsZone* zone() const;

	class GroupReader;
	GroupReader groupReader(const std::string& name);

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsparticlesolution_impl.h"
#endif // _DEBUG

#endif // H5CGNSPARTICLEGROUPSOLUTION_H
