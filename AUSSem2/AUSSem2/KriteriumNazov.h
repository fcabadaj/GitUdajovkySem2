#pragma once
#include "Kriterium.h"

using namespace std;

class KriteriumNazov :
	public Kriterium<string, UzemnyCelok>
{
public:
	KriteriumNazov();
	~KriteriumNazov();
	string evaluate(const UzemnyCelok& uc) const override;
};

KriteriumNazov::KriteriumNazov()
{
}

KriteriumNazov::~KriteriumNazov()
{
}

inline string KriteriumNazov::evaluate(const UzemnyCelok & uc) const
{
	 return uc.getNazov(); 
}
