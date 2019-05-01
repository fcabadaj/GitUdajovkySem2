#pragma once
#include "Kriterium.h"
class KriteriumHlasyOdovzdane :
	public Kriterium<int, UzemnyCelok>
{
private:
	int kolo_;
	Kandidat * kandidat_;

public:
	KriteriumHlasyOdovzdane(int kolo, Kandidat *kandidat);
	~KriteriumHlasyOdovzdane();
	int evaluate(const UzemnyCelok& uc) const override;
	void setKolo(int kolo) { kolo_ = kolo; };
	void setKandidat(Kandidat *kandi) { kandidat_ = kandi; };
};



KriteriumHlasyOdovzdane::KriteriumHlasyOdovzdane(int kolo, Kandidat *kandidat):
	kolo_(kolo),
	kandidat_(kandidat)
{
}


KriteriumHlasyOdovzdane::~KriteriumHlasyOdovzdane()
{
}

inline int KriteriumHlasyOdovzdane::evaluate(const UzemnyCelok & uc) const
{
	int pocetHlasov = uc.pocetOdovzdanychHlasov(kolo_, kandidat_);
	if (pocetHlasov == -1)
		return 0;
	else
		return pocetHlasov;
}
