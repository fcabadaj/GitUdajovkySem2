#pragma once
#include "Filter.h"

template <typename T, typename O>
class FilterFi2 :
	public Filter<T,O>
{
private:
	T alpha_;
	T beta_;
public:
	FilterFi2(T alpha, T beta);
	virtual ~FilterFi2();
	bool evaluate(const O& o, const Kriterium<T, O>& c) override;
	void setAlpha(T alpha) { alpha_ = alpha; };
	void setBeta(T beta) { beta_ = beta; };
};

template <typename T, typename O>
FilterFi2<T,O>::FilterFi2(T alpha, T beta) :
	alpha_(alpha),
	beta_(beta)
{
}

template <typename T, typename O>
FilterFi2<T,O>::~FilterFi2()
{
}

template<typename T, typename O>
inline bool FilterFi2<T, O>::evaluate(const O & o, const Kriterium<T, O>& c)
{
	T result = c.evaluate(o); 
	return result >= alpha_ && result <= beta_;
}
