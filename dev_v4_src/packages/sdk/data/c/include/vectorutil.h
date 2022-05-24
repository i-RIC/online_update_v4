#ifndef VECTORUTIL_H
#define VECTORUTIL_H

#include <vector>

namespace iRICLib {

template <typename V>
void _vectorToPointerT(const std::vector<V>& vec, V* pointer);

template <typename V>
void _pointerToVectorT(V* pointer, std::vector<V>* vec);

} // namespaec iRICLib

#include "private/vectorutil_detail.h"

#endif // VECTORUTIL_H
