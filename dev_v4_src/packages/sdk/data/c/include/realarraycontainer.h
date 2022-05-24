#ifndef REALARRAYCONTAINER_H
#define REALARRAYCONTAINER_H

#include "iriclib_global.h"

#include <vector>

class IRICLIBDLL RealArrayContainer
{
public:
	RealArrayContainer(int size);
	~RealArrayContainer();

	int size() const;
	double value(int index) const;
	void setValue(int index, double v);
	double* pointer();

private:
	std::vector<double>* m_value;
};

#endif // REALARRAYCONTAINER_H
