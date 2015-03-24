#pragma once
#include "Feature.h"
class DebrisPile :
	public Feature
{
public:
	DebrisPile();
	~DebrisPile();

	void setVolume(double);
	double getVolume();

private:

	double volume;

};

