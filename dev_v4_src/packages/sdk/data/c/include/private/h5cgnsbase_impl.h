#ifndef H5CGNSBASE_IMPL_H
#define H5CGNSBASE_IMPL_H

#include "../h5cgnsbase.h"
#include "../h5cgnszone.h"

#include <map>
#include <set>

namespace iRICLib {

class H5CgnsBase::Impl
{
public:
	Impl(H5CgnsBase* base);
	~Impl();

	void openOrCreateCcGroup();
	void openCcGroup();
	void createCcGroup();

	void openOrCreateGccTop();
	void openGccTop();
	void createGccTop();

	void openOrCreateGeoDataTop();
	void openGeoDataTop();
	void createGeoDataTop();

	void openOrCreateSolverInformation();
	void openSolverInformation();
	void createSolverInformation();

	void loadNames();
	void clearNames();

	H5CgnsBaseIterativeData* createBaseIterativeData();

	void loadZones();
	H5CgnsZone* createZone(const std::string& name, H5CgnsZone::Type type, const std::vector<int>& size);

	int m_dimension;
	std::string m_name;
	hid_t m_groupId;

	std::vector<H5CgnsZone*> m_zones;
	std::map<std::string, H5CgnsZone*> m_zoneMap;
	H5CgnsGridComplexConditionTop* m_gccTop;
	H5CgnsConditionGroup* m_ccGroup;
	H5CgnsBaseIterativeData* m_biterData;
	H5CgnsGeographicDataTop* m_geoDataTop;
	H5CgnsSolverInformation* m_solverInformation;
	H5CgnsFile* m_file;

	std::set<std::string> m_names;

private:
	H5CgnsBase* m_base;
};

} // namespace iRICLib

#endif // H5CGNSBASE_IMPL_H
