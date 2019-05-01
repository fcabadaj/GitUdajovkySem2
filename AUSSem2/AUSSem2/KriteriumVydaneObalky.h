#pragma once
#include "Kriterium.h"
class KriteriumVydaneObalky :
	public Kriterium<int,UzemnyCelok>
{

private:
	int kolo_;

public:
	KriteriumVydaneObalky(int kolo);
	~KriteriumVydaneObalky();
	int evaluate(const UzemnyCelok& uc) const override;
	void setKolo(int kolo) { kolo_ = kolo; };
};



KriteriumVydaneObalky::KriteriumVydaneObalky(int kolo):
	kolo_(kolo)
{
}


KriteriumVydaneObalky::~KriteriumVydaneObalky()
{
}

inline int KriteriumVydaneObalky::evaluate(const UzemnyCelok & uc) const
{
	return uc.pocetVydanychObalok(kolo_);
}
