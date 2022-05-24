#ifndef H5CGNSBASEITERATIVEDATA_H
#define H5CGNSBASEITERATIVEDATA_H

#include "iriclib_global.h"

#include "h5util.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsBase;

class IRICLIBDLL H5CgnsBaseIterativeData
{
public:
	static std::string label();
	static std::string groupName();

	H5CgnsBaseIterativeData(hid_t groupId, H5CgnsBase* base);
	~H5CgnsBaseIterativeData();

	int writeData(const std::string& name, double value, int* count = nullptr);
	int writeData(const std::string& name, int value, int* count = nullptr);
	int writeData(const std::string& name, const std::string& value, int* count = nullptr);
	int writeData(const std::string& name, const std::vector<double>& values);
	int writeData(const std::string& name, std::vector<int>& values);
	int writeData(const std::string& name, std::vector<std::string>& values);
	int writeTime(double time, int* count);
	int writeIteration(int iteration, int* count);

	int clearData();
	int flush();

	int getResultNames(std::vector<std::string>* names);
	int getResultNames(std::set<std::string>* names);
	int readValueType(const std::string& name, H5Util::DataArrayValueType* type);

	int readTime(std::vector<double>* values);
	int readTime(int solutionId, double* value);
	int readIteration(std::vector<int>* values);
	int readIteration(int solutionId, int* value);
	int readValues(const std::string& name, std::vector<double>* values);
	int readValue(int solutionId, const std::string& name, double* value);
	int readValues(const std::string& name, std::vector<int>* values);
	int readValue(int solutionId, const std::string& name, int* value);
	int readValues(const std::string& name, std::vector<std::string>* values);
	int readValue(int solutionId, const std::string& name, std::string* value);

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsbaseiterativedata_impl.h"
#endif // _DEBUG

#endif // H5CGNSBASEITERATIVEDATA_H
