#ifndef H5CGNSPARTICLEGROUPIMAGESOLUTION_H
#define H5CGNSPARTICLEGROUPIMAGESOLUTION_H

#include "iriclib_global.h"
#include "h5util.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsZone;

class IRICLIBDLL H5CgnsParticleGroupImageSolution
{
public:
	H5CgnsParticleGroupImageSolution(const std::string& name, hid_t groupId, H5CgnsZone* zone);
	~H5CgnsParticleGroupImageSolution();

	std::string name() const;

	int readGroupNames(std::vector<std::string>* names) const;
	int count(const std::string& groupName, int* count);
	int readCoordinatesX(const std::string& groupName, std::vector<double>* values) const;
	int readCoordinatesY(const std::string& groupName, std::vector<double>* values) const;
	int readSize(const std::string& groupName, std::vector<double>* values) const;
	int readAngle(const std::string& groupName, std::vector<double>* values) const;

	void writeBegin(const std::string& groupName);
	int writeEnd();
	void writePos2d(double x, double y, double size, double angle);

	H5CgnsZone* zone() const;

	class GroupReader;
	GroupReader groupReader(const std::string& name);

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsparticlegroupsolution_impl.h"
#endif // _DEBUG

#endif // H5CGNSPARTICLEGROUPIMAGESOLUTION_H
