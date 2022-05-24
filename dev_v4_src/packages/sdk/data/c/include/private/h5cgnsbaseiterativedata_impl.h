#ifndef H5CGNSBASEITERATIVEDATA_IMPL_H
#define H5CGNSBASEITERATIVEDATA_IMPL_H

#include "../h5cgnsbaseiterativedata.h"

#include <map>

namespace iRICLib {

class H5CgnsBaseIterativeData::Impl
{
public:
	Impl(H5CgnsBaseIterativeData* data);

	int valueCount();
	int readAllValues();

	int readValues(const std::string& name, std::vector<double>* values);
	int readValues(const std::string& name, std::vector<int>* values);
	int readValues(const std::string& name, std::vector<std::string>* values);

	hid_t m_groupId;
	H5CgnsBase* m_base;

	std::map<std::string, std::vector<int> > m_intValues;
	std::map<std::string, std::vector<double> > m_realValues;
	std::map<std::string, std::vector<std::string> > m_stringValues;

private:
	H5CgnsBaseIterativeData* m_data;
};

} // namespace iRICLib

#endif // H5CGNSBASEITERATIVEDATA_IMPL_H
