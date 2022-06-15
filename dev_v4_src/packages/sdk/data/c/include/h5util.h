#ifndef H5UTIL_H
#define H5UTIL_H

#include "iriclib_global.h"

#include <hdf5.h>

#include <set>
#include <string>
#include <vector>

namespace iRICLib {

class IRICLIBDLL H5Util
{
public:
	enum class DataArrayValueType {
		Char,
		Int,
		RealSingle,
		RealDouble
	};
	static std::string indexArrayLabel();
	static std::string indexArrayType();
	static std::string dataArrayLabel();
	static std::string userDefinedDataLabel();
	static std::string userDefinedDataType();

	static int getGroupNames(hid_t groupId, std::vector<std::string>* names);
	static int getGroupNames(hid_t groupId, std::set<std::string>* names);
	static int getGroupNamesWithLabel(hid_t groupId, const std::string& label, std::vector<std::string>* names);
	static int getGroupNamesWithLabel(hid_t groupId, const std::string& label, std::set<std::string>* names);
	static int getDatasetNames(hid_t groupId, std::vector<std::string>* names);
	static int getDatasetNames(hid_t groupId, std::set<std::string>* names);

	static int createGroup(hid_t groupId, const std::string& name, hid_t* newGroup);
	static int createGroup(hid_t groupId, const std::string& name, const std::string& label, const std::string& type, hid_t* newGroup);
	static int createUserDefinedDataGroup(hid_t groupId, const std::string& name, hid_t* newGroup);
	static int openGroup(hid_t groupId, const std::string& name, const std::string& label, hid_t* childGroup, bool noErrorLog = false);
	static int openOrCreateGroup(hid_t groupId, const std::string& name, const std::string& label, const std::string& type, hid_t* childGroup, const std::set<std::string>& names);
	static int openOrCreateUserDefinedDataGroup(hid_t groupId, const std::string& name, hid_t* childGroup, const std::set<std::string>& names);

	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const int& value, hid_t* newGroup = nullptr);
	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const float& value, hid_t* newGroup = nullptr);
	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const double& value, hid_t* newGroup = nullptr);

	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const std::string& value, hid_t* newGroup = nullptr);
	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const std::vector<char>& value, hid_t* newGroup = nullptr);
	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const std::vector<int>& value, hid_t* newGroup = nullptr);
	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const std::vector<float>& value, hid_t* newGroup = nullptr);
	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const std::vector<double>& value, hid_t* newGroup = nullptr);
	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const std::vector<char>& value, const std::vector<hsize_t>& dims, hid_t* newGroup = nullptr);
	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const std::vector<int>& value, const std::vector<hsize_t>& dims, hid_t* newGroup = nullptr);
	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const std::vector<float>& value, const std::vector<hsize_t>& dims, hid_t* newGroup = nullptr);
	static int createGroupWithValue(hid_t groupId, const std::string& name, const std::string& label, const std::vector<double>& value, const std::vector<hsize_t>& dims, hid_t* newGroup = nullptr);

	static int createDataArray(hid_t groupId, const std::string& name, const std::string& value);
	static int createDataArray(hid_t groupId, const std::string& name, const std::vector<char>& value);
	static int createDataArray(hid_t groupId, const std::string& name, const std::vector<int>& value);
	static int createDataArray(hid_t groupId, const std::string& name, const std::vector<float>& value);
	static int createDataArray(hid_t groupId, const std::string& name, const std::vector<double>& value);
	static int createDataArray(hid_t groupId, const std::string& name, const std::vector<char>& value, const std::vector<hsize_t>& dims);
	static int createDataArray(hid_t groupId, const std::string& name, const std::vector<int>& value, const std::vector<hsize_t>& dims);
	static int createDataArray(hid_t groupId, const std::string& name, const std::vector<float>& value, const std::vector<hsize_t>& dims);
	static int createDataArray(hid_t groupId, const std::string& name, const std::vector<double>& value, const std::vector<hsize_t>& dims);
	static int updateOrCreateDataArray(hid_t groupId, const std::string& name, const std::string& value, std::set<std::string>* names = nullptr);
	static int updateOrCreateDataArray(hid_t groupId, const std::string& name, const std::vector<char>& value, std::set<std::string>* names = nullptr);
	static int updateOrCreateDataArray(hid_t groupId, const std::string& name, const std::vector<int>& value, std::set<std::string>* names = nullptr);
	static int updateOrCreateDataArray(hid_t groupId, const std::string& name, const std::vector<float>& value, std::set<std::string>* names = nullptr);
	static int updateOrCreateDataArray(hid_t groupId, const std::string& name, const std::vector<double>& value, std::set<std::string>* names = nullptr);
	static int updateOrCreateDataArray(hid_t groupId, const std::string& name, const std::vector<std::string>& value, std::set<std::string>* names = nullptr);
	static int updateOrCreateDataArray(hid_t groupId, const std::string& name, const std::vector<char>& value, const std::vector<hsize_t>& dims, std::set<std::string>* names = nullptr);
	static int updateOrCreateDataArray(hid_t groupId, const std::string& name, const std::vector<int>& value, const std::vector<hsize_t>& dims, std::set<std::string>* names = nullptr);
	static int updateOrCreateDataArray(hid_t groupId, const std::string& name, const std::vector<float>& value, const std::vector<hsize_t>& dims, std::set<std::string>* names = nullptr);
	static int updateOrCreateDataArray(hid_t groupId, const std::string& name, const std::vector<double>& value, const std::vector<hsize_t>& dims, std::set<std::string>* names = nullptr);

	static int readGroupValueDimensions(hid_t groupId, std::vector<hsize_t>* dims);
	static int readGroupValueLength(hid_t groupId, int* length);
	static int readGroupValue(hid_t groupId, std::string* value);
	static int readGroupValue(hid_t groupId, std::vector<char>* values);
	static int readGroupValue(hid_t groupId, std::vector<int>* values);
	static int readGroupValue(hid_t groupId, std::vector<float>* values);
	static int readGroupValue(hid_t groupId, std::vector<double>* values);
	static int readGroupValue(hid_t groupId, std::vector<std::string>* values);

	static int readDataArrayValueType(hid_t groupId, const std::string& name, DataArrayValueType* type);
	static int readDataArrayLength(hid_t groupId, const std::string& name, int* length);
	static int readDataArrayValue(hid_t groupId, const std::string& name, std::string* value);
	static int readDataArrayValue(hid_t groupId, const std::string& name, std::vector<char>* values);
	static int readDataArrayValue(hid_t groupId, const std::string& name, std::vector<int>* values);
	static int readDataArrayValue(hid_t groupId, const std::string& name, std::vector<float>* values);
	static int readDataArrayValue(hid_t groupId, const std::string& name, std::vector<double>* values);
	static int readDataArrayValue(hid_t groupId, const std::string& name, std::vector<std::string>* values);

	static int updateGroupValue(hid_t groupId, const int& value);
	static int updateGroupValue(hid_t groupId, const float& value);
	static int updateGroupValue(hid_t groupId, const double& value);

	static int readAttribute(hid_t groupId, const std::string& name, std::string* value);

	static int writeAttribute(hid_t groupId, const std::string& name, const std::string& value);
	static int writeAttribute(hid_t groupId, const std::string& name, const int& value);
	static int writeAttribute(hid_t groupId, const std::string& name, const float& value);
	static int writeAttribute(hid_t groupId, const std::string& name, const double& value);

	static int readData(hid_t groupId, const std::string& name, std::vector<int>* value);
	static int readData(hid_t groupId, const std::string& name, std::vector<float>* value);
	static int readData(hid_t groupId, const std::string& name, std::vector<double>* value);

	static int writeData(hid_t groupId, const std::string& name, const std::string& value);

	static int writeData(hid_t groupId, const std::string& name, const int& value);
	static int writeData(hid_t groupId, const std::string& name, const float& value);
	static int writeData(hid_t groupId, const std::string& name, const double& value);
	static int writeData(hid_t groupId, const std::string& name, const std::vector<int>& value);
	static int writeData(hid_t groupId, const std::string& name, const std::vector<float>& value);
	static int writeData(hid_t groupId, const std::string& name, const std::vector<double>& value);
	static int writeData(hid_t groupId, const std::string& name, const std::vector<int>& value, const std::vector<hsize_t>& dims);
	static int writeData(hid_t groupId, const std::string& name, const std::vector<float>& value, const std::vector<hsize_t>& dims);
	static int writeData(hid_t groupId, const std::string& name, const std::vector<double>& value, const std::vector<hsize_t>& dims);

	static int deleteData(hid_t groupId, const std::string& name);
	static int deleteDataIfExists(hid_t groupId, const std::string& name);
	static int deleteAllChildren(hid_t groupId);

	static int copyGroup(hid_t srcGroupId, hid_t tgtGroupId, bool recursive = false);

private:
	H5Util();
};

} // namespace iRICLib

#endif // H5UTIL_H
