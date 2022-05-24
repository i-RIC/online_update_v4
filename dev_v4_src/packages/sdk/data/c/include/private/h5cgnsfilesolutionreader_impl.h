#ifndef H5CGNSFILESOLUTIONREADER_IMPL_H
#define H5CGNSFILESOLUTIONREADER_IMPL_H

#include "../h5cgnsfilesolutionreader.h"

namespace iRICLib {

class H5CgnsFileSolutionReader::Impl
{
public:
	Impl(H5CgnsFileSolutionReader* reader);
	~Impl();

	int setSolutionId(int id);
	void detectMode();

	Mode m_mode;

	H5CgnsFile* m_file;
	H5CgnsFile* m_targetFile;

	int m_solutionId;

private:
	int setSolutionIdStandard(int id);
	int setSolutionIdSeparate(int id);

	H5CgnsFileSolutionReader* m_reader;
};

} // namespace iRICLib

#endif // H5CGNSFILESOLUTIONREADER_IMPL_H
