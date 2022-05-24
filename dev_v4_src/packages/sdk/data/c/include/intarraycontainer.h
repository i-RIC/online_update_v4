#ifndef INTARRAYCONTAINER_H
#define INTARRAYCONTAINER_H

#include "iriclib_global.h"

#include <vector>

class IRICLIBDLL IntArrayContainer
{
public:
	IntArrayContainer(int size);
	~IntArrayContainer();

	int size() const;
	int value(int index) const;
	void setValue(int index, int v);
	int* pointer();

private:
	std::vector<int>* m_value;
};

#endif // INTARRAYCONTAINER_H
