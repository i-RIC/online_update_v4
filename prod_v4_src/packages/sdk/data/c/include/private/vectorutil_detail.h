#ifndef VECTORUTIL_DETAIL_H
#define VECTORUTIL_DETAIL_H

#include "../vectorutil.h"

namespace iRICLib {

template <typename V>
void _vectorToPointerT(const std::vector<V>& vec, V* pointer)
{
	for (size_t i = 0; i < vec.size(); ++i) {
		*(pointer + i) = vec.at(i);
	}
}

template <typename V>
void _pointerToVectorT(V* pointer, std::vector<V>* vec)
{
	for (size_t i = 0; i < vec->size(); ++i) {
		(*vec)[i] = *(pointer + i);
	}
}

} // namespaec iRICLib

#endif // VECTORUTIL_DETAIL_H
