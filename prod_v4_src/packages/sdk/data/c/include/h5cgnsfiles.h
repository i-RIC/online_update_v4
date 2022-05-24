#ifndef H5CGNSFILES_H
#define H5CGNSFILES_H

#include <vector>

namespace iRICLib {

class H5CgnsFile;

class H5CgnsFiles
{
public:
	H5CgnsFiles();
	~H5CgnsFiles();

	H5CgnsFile* operator[] (int index);
	H5CgnsFile* at(int index) const;
	int size() const;

	int registerFile(H5CgnsFile* file);
	int unregisterFile(int index);

	void clear();

	H5CgnsFiles& operator=(const std::vector<H5CgnsFile*>& files);

private:
	std::vector<H5CgnsFile*> m_files;
};

} // namespace iRICLib

#endif // H5CGNSFILES_H
