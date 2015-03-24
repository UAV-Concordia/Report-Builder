#pragma once
#include "Feature.h"

enum Condition { UNKNOWN, DAMAGED, NOTDAMAGED };

class Structure :
	public Feature
{
public:
	Structure();
	~Structure();

private:
	Condition condition;
};

