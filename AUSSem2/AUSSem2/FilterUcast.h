#pragma once
#include "FilterFi2.h"
class FilterUcast :
	public FilterFi2<double, UzemnyCelok>
{
public:
	FilterUcast(double alpha, double beta);
	~FilterUcast();
};



FilterUcast::FilterUcast(double alpha, double beta):
	FilterFi2(alpha, beta)
{
}


FilterUcast::~FilterUcast()
{
}
