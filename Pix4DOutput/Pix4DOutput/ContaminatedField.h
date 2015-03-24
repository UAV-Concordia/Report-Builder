#pragma once
#include "Feature.h"
class ContaminatedField :
	public Feature
{
public:
	ContaminatedField();
	~ContaminatedField();

	void setArea(double);
	double getArea();

private:

	double area;

};

