#pragma once
#include "Kriterium.h"
class KriteriumVolici :
	public Kriterium<int, UzemnyCelok>
{

private:
	int kolo_;
public:
	KriteriumVolici(int kolo);
	~KriteriumVolici();
	void setKolo(int kolo) { kolo_ = kolo; };
	int evaluate(const UzemnyCelok& uc) const override;
};

KriteriumVolici::KriteriumVolici(int kolo):
	kolo_(kolo)
{
}

KriteriumVolici::~KriteriumVolici()
{
}

inline int KriteriumVolici::evaluate(const UzemnyCelok & uc) const
{
	return uc.pocetZapisanychVolicov(kolo_);
}
