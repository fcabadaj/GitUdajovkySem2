#pragma once
#include "Kriterium.h"

using namespace std;

class KriteriumNazov :
	public Kriterium<string, UzemnyCelok>
{
public:
	KriteriumNazov();
	~KriteriumNazov();
	string evaluate(const UzemnyCelok& uc) override { return uc.getNazov(); };
};

KriteriumNazov::KriteriumNazov()
{
}

KriteriumNazov::~KriteriumNazov()
{
}
