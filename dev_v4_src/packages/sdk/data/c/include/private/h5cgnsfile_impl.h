#ifndef H5CGNSFILE_IMPL_H
#define H5CGNSFILE_IMPL_H

#include "../h5cgnsfile.h"
#include "../h5cgnsfilesolutionwriter.h"
#include "../h5cgnszone.h"

#include <hdf5.h>

#include <map>
#include <vector>

namespace iRICLib {

class H5CgnsFile::Impl
{
public:
	Impl(H5CgnsFile* file);
	~Impl();

	int open();
	int close();

	void loadBases();
	H5CgnsBase* createBase(int dimension);
	static std::string baseName(int dimension);

	void loadZones();
	int getGridId(H5CgnsZone* zone, int* gridId);

	std::vector<H5CgnsBase*> m_bases;
	std::map<int, H5CgnsBase*> m_baseMap;
	H5CgnsBase* m_ccBase;

	std::vector<H5CgnsZone*> m_zones;

	hid_t m_fileId;
	Mode m_mode;
	std::string m_fileName;
	std::string m_resultFolder;

	H5CgnsFileSolutionReader* m_solutionReader;
	H5CgnsFileSolutionWriter* m_solutionWriter;
	H5CgnsFileSolutionWriter::Mode m_writerMode;

	H5CgnsFile* m_file;
};

} // namespace iRICLib

#endif // H5CGNSFILE_IMPL_H

