#ifndef IRIC_UTIL_H
#define IRIC_UTIL_H

#include <string>

namespace iRICLib {

class H5CgnsZone;

int _iric_get_zone(int fid, int gid, H5CgnsZone** zone, const std::string& f_name);
int _iric_get_zone_for_solread(int fid, int gid, int solid, H5CgnsZone** zone, const std::string& f_name);
int _iric_get_zone_for_solwrite(int fid, int gid, H5CgnsZone** zone, const std::string& f_name);

} // namespace iRICLib

#endif // IRIC_UTIL_H
