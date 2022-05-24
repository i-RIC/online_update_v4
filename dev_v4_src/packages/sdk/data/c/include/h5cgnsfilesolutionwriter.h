#ifndef H5CGNSFILESOLUTIONWRITER_H
#define H5CGNSFILESOLUTIONWRITER_H

#include "iriclib_global.h"

#include <string>

namespace iRICLib {

class H5CgnsFile;

class H5CgnsFileSolutionWriter
{
public:
	enum Mode {
		Standard,
		Separate,
	};

	H5CgnsFileSolutionWriter(Mode mode, H5CgnsFile* file);
	~H5CgnsFileSolutionWriter();

	int writeSolStart();
	int writeTime(double time);
	int writeIteration(int iteration);

	int writeBaseIterativeData(const std::string& name, int value);
	int writeBaseIterativeData(const std::string& name, double value);
	int writeBaseIterativeData(const std::string& name, const std::string value);

	H5CgnsFile* targetFile() const;

	int flush();
	int close();

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsfilesolutionwriter_impl.h"
#endif // _DEBUG

#endif // H5CGNSFILESOLUTIONWRITER_H
