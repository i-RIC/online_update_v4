#ifndef H5CGNSBASE_H
#define H5CGNSBASE_H

#include "iriclib_global.h"

#include "h5cgnszone.h"

#include <hdf5.h>

#include <string>
#include <vector>

namespace iRICLib {

class H5CgnsBaseIterativeData;
class H5CgnsConditionGroup;
class H5CgnsFile;
class H5CgnsGeographicDataTop;
class H5CgnsGridComplexConditionTop;
class H5CgnsSolverInformation;
class H5CgnsZone;

class IRICLIBDLL H5CgnsBase
{
public:
	static std::string label();

	H5CgnsBase(int dimension, const std::string& name, hid_t groupId, H5CgnsFile* file);
	~H5CgnsBase();

	int dimension() const;
	std::string name() const;
	H5CgnsConditionGroup* ccGroup() const;
	H5CgnsGridComplexConditionTop* gccTop() const;
	H5CgnsBaseIterativeData* biterData();
	H5CgnsGeographicDataTop* geoDataTop() const;
	H5CgnsSolverInformation* solverInformation() const;

	int writeErrorCode(int errorCode);
	int readErrorCode(int* errorCode);

	int zoneNum() const;
	H5CgnsZone* zoneById(int zid);
	std::vector<std::string> zoneNames() const;
	H5CgnsZone* defaultZone();
	H5CgnsZone* zone(const std::string& name);
	bool zoneExists(const std::string& name);

	H5CgnsZone* createDefaultZone(H5CgnsZone::Type type, const std::vector<int>& size);
	H5CgnsZone* createZone(const std::string& name, H5CgnsZone::Type type, const std::vector<int>& size);
	std::string nextDefaultName();

	int setSolutionId(int solutionId);
	int copyGridsTo(H5CgnsBase* target);
	int flush();

	H5CgnsFile* file() const;

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsbase_impl.h"
#endif // _DEBUG

#endif // H5CGNSBASE_H
