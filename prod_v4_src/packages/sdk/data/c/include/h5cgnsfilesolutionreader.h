#ifndef H5CGNSFILESOLUTIONREADER_H
#define H5CGNSFILESOLUTIONREADER_H

#include "iriclib_global.h"

namespace iRICLib {

class H5CgnsFile;

class IRICLIBDLL H5CgnsFileSolutionReader
{
public:
	enum Mode {
		Standard,
		Separate,
	};

	H5CgnsFileSolutionReader(H5CgnsFile* file);
	~H5CgnsFileSolutionReader();

	Mode mode() const;

	int setSolutionId(int id);

	H5CgnsFile* targetFile() const;

private:
	class Impl;
	Impl* impl;
};

} // namespace iRICLib

#ifdef _DEBUG
	#include "private/h5cgnsfilesolutionreader_impl.h"
#endif // _DEBUG

#endif // H5CGNSFILESOLUTIONREADER_H
