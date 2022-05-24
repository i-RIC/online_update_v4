#ifndef IRIC_OUTPUTERROR_H
#define IRIC_OUTPUTERROR_H

#include <string>

namespace iRICLib {

void _iric_output_zonenotexists_error(int fid, int gid, const std::string& fname);

} // namespace iRICLib

#endif // IRIC_OUTPUTERROR_H
