#ifndef H5CGNSPOLYDATASOLUTION_H
#define H5CGNSPOLYDATASOLUTION_H


#include "iriclib_global.h"
#include "h5util.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsZone;

class IRICLIBDLL H5CgnsPolyDataSolution
{
public:
	const static int POLYGON = 1;
	const static int POLYLINE = 2;

	H5CgnsPolyDataSolution(const std::string& name, hid_t groupId, H5CgnsZone* zone);
	~H5CgnsPolyDataSolution();

	std::string name() const;

	void writeBegin(const std::string& groupName);
	int writeEnd();
	void writePolygon(std::vector<double>& x, std::vector<double>& y);
	void writePolyline(std::vector<double>& x, std::vector<double>& y);
	void writeValue(const std::string& name, int value);
	void writeValue(const std::string& name, double value);

	int readGroupNames(std::vector<std::string>* names) const;
	int dataCount(const std::string& groupName, int* count);
	int coordinatesCount(const std::string& groupName, int* count);
	int readValueNames(const std::string& groupName, std::vector<std::string>* names) const;
	int readValueNames(const std::string& groupName, std::set<std::string>* names) const;
	int readCoordinatesX(const std::string& groupName, std::vector<double>* values) const;
	int readCoordinatesY(const std::string& groupName, std::vector<double>* values) const;
	int readTypes(const std::string& groupName, std::vector<int>* values) const;
	int readSizes(const std::string& groupName, std::vector<int>* values) const;
	int readValueType(const std::string& groupName, const std::string& valueName, H5Util::DataArrayValueType *type) const;
	int readValue(const std::string& groupName, const std::string& valueName, std::vector<int>* values) const;
	int readValue(const std::string& groupName, const std::string& valueName, std::vector<double>* values) const;
	int readValueAsDouble(const std::string& groupName, const std::string& valueName, std::vector<double>* values) const;

	H5CgnsZone* zone() const;

	class GroupReader;
	GroupReader groupReader(const std::string& name);

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnspolydatasolution_impl.h"
#endif // _DEBUG

#endif // H5CGNSPOLYDATASOLUTION_H
