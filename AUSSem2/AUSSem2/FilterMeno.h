#pragma once
#include "Filterfi1.h"

using namespace std;

class FilterMeno :
	public Filterfi1<string, Kandidat>
{
public:
	FilterMeno(string alpha);
	~FilterMeno();
};

FilterMeno::FilterMeno(string alpha):
	Filterfi1(alpha)
{
}

FilterMeno::~FilterMeno()
{
}
