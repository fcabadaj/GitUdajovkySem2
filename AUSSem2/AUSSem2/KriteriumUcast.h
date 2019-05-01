#pragma once
#include "Kriterium.h"
class KriteriumUcast :
	public Kriterium<double, UzemnyCelok>
{

private:
	int kolo_;
public:
	KriteriumUcast(int kolo);
	~KriteriumUcast();
	double evaluate(const UzemnyCelok& uc) const override;
	void setKolo(int kolo) { kolo_ = kolo; };
};

KriteriumUcast::KriteriumUcast(int kolo):
	kolo_(kolo)
{
}


KriteriumUcast::~KriteriumUcast()
{
}

inline double KriteriumUcast::evaluate(const UzemnyCelok & uc) const
{
	return uc.ucastVolicovVKole(kolo_);
}
