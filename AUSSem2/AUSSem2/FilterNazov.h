#pragma once
#include "Filterfi1.h"
#include <string>

class FilterNazov :
	public Filterfi1<string, UzemnyCelok>
{
public:
	FilterNazov(std::string alpha);
	~FilterNazov();
	
};

FilterNazov::FilterNazov(std::string alpha) :
	Filterfi1(alpha)
{
}

FilterNazov::~FilterNazov()
{
}
