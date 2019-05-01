#pragma once
#include "Filterfi1.h"
class FilterPrislusnostObce :
	public Filterfi1<bool, Obec>
{
public:
	FilterPrislusnostObce(bool alpha);
	~FilterPrislusnostObce();
};

FilterPrislusnostObce::FilterPrislusnostObce(bool alpha):
	Filterfi1(alpha)
{
}

FilterPrislusnostObce::~FilterPrislusnostObce()
{
}
