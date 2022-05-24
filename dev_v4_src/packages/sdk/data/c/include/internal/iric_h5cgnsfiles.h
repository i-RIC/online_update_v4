#ifndef IRIC_H5CGNSFILES_H
#define IRIC_H5CGNSFILES_H

namespace iRICLib {

class H5CgnsFile;

int _iric_lastFileId(int* fid);
int _iric_h5cgnsfiles_register(H5CgnsFile* file, int* fid);
int _iric_h5cgnsfiles_unregister(int fid);
int _iric_h5cgnsfiles_get(int fid, H5CgnsFile** file);

} // namespace iRICLib

#endif // IRIC_H5CGNSFILES_H
