#pragma once
#include "FilterFi2.h"

class FilterVolici :
	public FilterFi2<int, UzemnyCelok>
{

public:
	FilterVolici(int alpha, int beta);
	~FilterVolici();
};



FilterVolici::FilterVolici(int alpha, int beta) :
	FilterFi2(alpha, beta)
{
}


FilterVolici::~FilterVolici()
{
}
