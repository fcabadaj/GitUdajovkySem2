#pragma once
#include "Kriterium.h"

class KriteriumPrislusnostObce :
	public Kriterium<bool, Obec>
{
private:
	VyssiUzemnyCelok *vuc_;

public:
	KriteriumPrislusnostObce(VyssiUzemnyCelok *vuc);
	~KriteriumPrislusnostObce();
	bool evaluate(const Obec& obec) const override;
	void setVuc(VyssiUzemnyCelok *vuc) { this->vuc_ = vuc; };
};



KriteriumPrislusnostObce::KriteriumPrislusnostObce(VyssiUzemnyCelok *vuc) :
	vuc_(vuc)
{
}


KriteriumPrislusnostObce::~KriteriumPrislusnostObce()
{
}

inline bool KriteriumPrislusnostObce::evaluate(const Obec& obec) const
{
	return obec.patriDoVUC(vuc_);
	//return obec.getNazovOkresu() == vuc_->getNazov() || obec.getNazovKraja() == vuc_->getNazov();
}
