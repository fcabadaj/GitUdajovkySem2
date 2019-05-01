#pragma once
#include "Filter.h"

template <typename T, typename O>
class Filterfi1 :
	public Filter<T,O>
{
private:
	T alpha_;
public:
	Filterfi1(T alpha);
	virtual ~Filterfi1();
	bool evaluate(const O& o, const Kriterium<T, O>& c) override;
	void setAlpha(T alpha) { alpha_ = alpha; };
};

template <typename T, typename O>
Filterfi1<T,O>::Filterfi1(T alpha) :
	alpha_(alpha)
{
}

template <typename T, typename O>
Filterfi1<T,O>::~Filterfi1()
{
}

template<typename T, typename O>
inline bool Filterfi1<T, O>::evaluate(const O & o, const Kriterium<T, O>& c)
{
	return c.evaluate(o) == alpha_;
}
