#pragma once
#include "Kriterium.h"
class KriteriumOdovzdaneObalky :
	public Kriterium<int, UzemnyCelok>
{

private:
	int kolo_;

public:
	KriteriumOdovzdaneObalky(int kolo);
	~KriteriumOdovzdaneObalky();
	int evaluate(const UzemnyCelok& uc) const override;
	void setKolo(int kolo) { kolo_ = kolo; };
};

KriteriumOdovzdaneObalky::KriteriumOdovzdaneObalky(int kolo):
	kolo_(kolo)
{
}

KriteriumOdovzdaneObalky::~KriteriumOdovzdaneObalky()
{
}

inline int KriteriumOdovzdaneObalky::evaluate(const UzemnyCelok & uc) const
{
	return uc.pocetOdovzdanychObalok(kolo_);
}
