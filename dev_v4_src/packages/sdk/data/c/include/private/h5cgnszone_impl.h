#ifndef H5CGNSZONE_IMPL_H
#define H5CGNSZONE_IMPL_H

#include "../h5cgnszone.h"

#include <set>

namespace iRICLib {

class H5CgnsZone::Impl
{
public:
	Impl(H5CgnsZone* zone);
	~Impl();

	void readSizeAndType();
	void writeSizeAndType();

	void loadNames();
	void loadFlowSolutionPointerNames();

	int getSolutionExists(bool* exists) const;

	H5CgnsGridCoordinates* openOrCreateGridCoordinates();
	H5CgnsGridCoordinates* createGridCoordinates();

	H5CgnsGridAttributes* openOrCreateGridAttributes();
	H5CgnsGridAttributes* createGridAttributes();

	H5CgnsZoneBc* openOrCreateZoneBc();
	H5CgnsZoneBc* createZoneBc();

	void createZoneIterativeDataIfNotExists();
	void createZoneIterativeData();

	H5CgnsGridCoordinates* openGridCoordinatesForSolution();
	H5CgnsGridCoordinates* createGridCoordinatesForSolution();

	H5CgnsFlowSolution* openNodeSolution();
	H5CgnsFlowSolution* createNodeSolution();

	H5CgnsFlowSolution* openCellSolution();
	H5CgnsFlowSolution* createCellSolution();

	H5CgnsFlowSolution* openIFaceSolution();
	H5CgnsFlowSolution* createIFaceSolution();

	H5CgnsFlowSolution* openJFaceSolution();
	H5CgnsFlowSolution* createJFaceSolution();

	H5CgnsFlowSolution* openKFaceSolution();
	H5CgnsFlowSolution* createKFaceSolution();

	H5CgnsParticleGroupSolution* openParticleGroupSolution();
	H5CgnsParticleGroupSolution* createParticleGroupSolution();

	H5CgnsParticleSolution* openParticleSolution();
	H5CgnsParticleSolution* createParticleSolution();

	H5CgnsPolyDataSolution* openPolyDataSolution();
	H5CgnsPolyDataSolution* createPolyDataSolution();

	int writeZoneIterativeData();

	std::string m_name;
	Type m_type;
	std::vector<int> m_size;
	int m_solutionId;

	hid_t m_groupId;

	H5CgnsGridCoordinates* m_gridCoordinates;
	H5CgnsGridAttributes* m_gridAttributes;
	H5CgnsZoneBc* m_zoneBc;

	H5CgnsGridCoordinates* m_gridCoordinatesForSolution;
	H5CgnsFlowSolution* m_nodeSolution;
	H5CgnsFlowSolution* m_cellSolution;
	H5CgnsFlowSolution* m_iFaceSolution;
	H5CgnsFlowSolution* m_jFaceSolution;
	H5CgnsFlowSolution* m_kFaceSolution;
	H5CgnsParticleGroupSolution* m_particleGroupSolution;
	H5CgnsParticleSolution* m_particleSolution;
	H5CgnsPolyDataSolution* m_polyDataSolution;

	std::set<std::string> m_names;
	std::set<std::string> m_flowSolutionPointerNames;

	H5CgnsBase* m_base;

private:
	int openSolutionGroup(const std::string& name, hid_t* gId);
	int createSolutionGroup(const std::string& name, const std::string& gridLocation, hid_t* gId);
	std::string getSolutionName(const std::string& pointersName, const std::string& prefix, int solId);

	H5CgnsZone* m_zone;
};

} // namespace iRICLib

#endif // H5CGNSZONE_IMPL_H
