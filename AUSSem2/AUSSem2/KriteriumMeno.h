#pragma once
#include "Kriterium.h"
class KriteriumMeno :
	public Kriterium<string, Kandidat>
{
public:
	KriteriumMeno();
	~KriteriumMeno();
	string evaluate(const Kandidat& kand) const override;
};



KriteriumMeno::KriteriumMeno()
{
}


KriteriumMeno::~KriteriumMeno()
{
}

inline string KriteriumMeno::evaluate(const Kandidat & kand) const
{
	string celeMeno = kand.getMeno() + kand.getPriezvisko();
	return celeMeno;
}
