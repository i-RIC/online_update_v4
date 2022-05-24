#ifndef H5CGNSFILESOLUTIONWRITER_IMPL_H
#define H5CGNSFILESOLUTIONWRITER_IMPL_H

#include "../h5cgnsfilesolutionwriter.h"

namespace iRICLib {

class H5CgnsFileSolutionWriter::Impl
{
public:
	Impl(H5CgnsFileSolutionWriter* writer);
	~Impl();

	int writeSolStart();
	int writeTime(double time);
	int writeIteration(int iteration);

	int writeBaseIterativeData(const std::string& name, int value);
	int writeBaseIterativeData(const std::string& name, double value);
	int writeBaseIterativeData(const std::string& name, const std::string value);

	Mode m_mode;

	H5CgnsFile* m_file;
	H5CgnsFile* m_targetFile;

	int m_solutionId;

private:
	int writeSolStartStandard();
	int writeSolStartSeparate();

	int writeTimeStandard(double time);
	int writeTimeSeparate(double time);

	int writeIterationStandard(int iteration);
	int writeIterationSeparate(int iteration);

	H5CgnsFileSolutionWriter* m_writer;
};

} // namespace iRICLib

#endif // H5CGNSFILESOLUTIONWRITER_IMPL_H
