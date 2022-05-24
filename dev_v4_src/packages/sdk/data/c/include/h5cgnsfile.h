#ifndef H5CGNSFILE_H
#define H5CGNSFILE_H

#include "h5cgnsfilesolutionwriter.h"
#include "iriclib_global.h"

#include <string>

namespace iRICLib {

class H5CgnsBase;
class H5CgnsFileSolutionReader;
class H5CgnsFileSolutionWriter;
class H5CgnsZone;

class IRICLIBDLL H5CgnsFile
{
public:
	enum class Mode {
		Create,
		OpenModify,
		OpenReadOnly
	};

	H5CgnsFile(const std::string& fileName, Mode mode, const std::string& resultFolder = "result");
	~H5CgnsFile();

	int open();
	int close();

	Mode mode() const;
	std::string fileName() const;
	std::string tmpFileName() const; // temporary file used to read result while running
	std::string resultFolder() const;

	int baseNum() const;

	H5CgnsBase* base();
	H5CgnsBase* base(int dim);
	H5CgnsBase* baseById(int bid);

	H5CgnsBase* ccBase() const;

	bool baseExists(int dim) const;

	int zoneNum() const;

	H5CgnsZone* zoneById(int zid);

	int writeTime(double time);
	int writeIteration(int iteration);

	int setSolutionId(int solutionId);

	int copyGridsTo(H5CgnsFile* target);
	int flush();

	int getGridId(H5CgnsZone* zone, int* gridId);
	int lastGridId(int* id);

	H5CgnsFileSolutionReader* solutionReader();
	H5CgnsFileSolutionWriter* solutionWriter();

	void setWriterMode(H5CgnsFileSolutionWriter::Mode mode);

private:
	class Impl;
	Impl* impl;

public:
	friend class H5CgnsBase;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsfile_impl.h"
#endif // _DEBUG

#endif // H5CGNSFILE_H
