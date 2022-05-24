#ifndef H5CGNSZONE_H
#define H5CGNSZONE_H

#include "iriclib_global.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsBase;
class H5CgnsFlowSolution;
class H5CgnsGridAttributes;
class H5CgnsGridCoordinates;
class H5CgnsParticleGroupSolution;
class H5CgnsParticleSolution;
class H5CgnsPolyDataSolution;
class H5CgnsZoneBc;

class IRICLIBDLL H5CgnsZone
{
public:
	static std::string label();

	enum class Type {
		Structured,
		Unstructured
	};
	enum class SolutionPosition {
		Null,
		Node,
		Cell,
		IFace,
		JFace,
		KFace
	};

	H5CgnsZone(const std::string& name, hid_t groupId, H5CgnsBase* base);	// for reading
	H5CgnsZone(const std::string& name, Type type, const std::vector<int>& size, hid_t groupId, H5CgnsBase* base);	// for creating
	~H5CgnsZone();

	hid_t groupId() const;
	std::string name() const;
	Type type() const;
	std::vector<int> size() const;

	int nodeCount() const;
	int cellCount() const;
	int iFaceCount() const;
	int jFaceCount() const;
	int kFaceCount() const;

	int nodeDims(std::vector<hsize_t>* dims) const;
	int cellDims(std::vector<hsize_t>* dims) const;
	int iFaceDims(std::vector<hsize_t>* dims) const;
	int jFaceDims(std::vector<hsize_t>* dims) const;
	int kFaceDims(std::vector<hsize_t>* dims) const;

	H5CgnsBase* base() const;

	int solutionId() const;
	int setSolutionId(int solId);

	int getSolutionExists(bool* exists) const;

	H5CgnsGridCoordinates* gridCoordinates() const;
	H5CgnsGridAttributes* gridAttributes() const;
	H5CgnsZoneBc* zoneBc() const;

	int readTriangleElementsSize(int* size) const;
	int readTriangleElementsValueCount(int* size) const;
	int readTriangleElements(std::vector<int>* indices) const;
	int writeTriangleElements(const std::vector<int>& indices) const;

	bool gridCoordinatesForSolutionExists() const;
	H5CgnsGridCoordinates* gridCoordinatesForSolution();
	bool solutionExists(SolutionPosition pos) const;
	H5CgnsFlowSolution* solution(SolutionPosition pos);
	bool nodeSolutionExists() const;
	H5CgnsFlowSolution* nodeSolution();
	bool cellSolutionExists() const;
	H5CgnsFlowSolution* cellSolution();
	bool iFaceSolutionExists() const;
	H5CgnsFlowSolution* iFaceSolution();
	bool jFaceSolutionExists() const;
	H5CgnsFlowSolution* jFaceSolution();
	bool kFaceSolutionExists() const;
	H5CgnsFlowSolution* kFaceSolution();
	bool particleGroupSolutionExists() const;
	H5CgnsParticleGroupSolution* particleGroupSolution();
	bool particleSolutionExists() const;
	H5CgnsParticleSolution* particleSolution();
	bool polyDataSolutionExists() const;
	H5CgnsPolyDataSolution* polyDataSolution();

	int copyGridTo(H5CgnsZone* target);
	int flush();
	void clearSolutionGroups();
	int deleteAllResults();

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnszone_impl.h"
#endif // _DEBUG

#endif // H5CGNSZONE_H
