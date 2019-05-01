#pragma once
#include "Kriterium.h"
class KriteriumHlasyZiskane :
	public Kriterium<int, Kandidat>
{
private:
	int kolo_;
	UzemnyCelok *uc_;
public:
	KriteriumHlasyZiskane(int kolo, UzemnyCelok *uc);
	~KriteriumHlasyZiskane();
	int evaluate(const Kandidat& kand) const override;
	void setKolo(int kolo) { kolo_ = kolo; };
	void setUc(UzemnyCelok * uc) { uc_ = uc; };
};

KriteriumHlasyZiskane::KriteriumHlasyZiskane(int kolo, UzemnyCelok *uc):
	kolo_(kolo),
	uc_(uc)
{
}

KriteriumHlasyZiskane::~KriteriumHlasyZiskane()
{
}

inline int KriteriumHlasyZiskane::evaluate(const Kandidat & kand) const
{
	int pocetHlasov = kand.pocetZiskanychHlasov(kolo_, uc_);
	if (pocetHlasov == -1)
		return 0;
	else
		return pocetHlasov;
}	
