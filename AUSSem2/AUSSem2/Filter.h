#pragma once
#include "Kriterium.h"

template <typename T, typename O>
class Filter
{
protected:
	virtual bool evaluate(const O& obj, const Kriterium<T, O>& krit);
public:
	Filter();
	virtual ~Filter();
};

template<typename T, typename O>
inline bool Filter<T, O>::evaluate(const O & obj, const Kriterium<T, O>& krit)
{
	return true;
}

template <typename T, typename O>
Filter<T,O>::Filter()
{
}

template <typename T, typename O>
Filter<T, O>::~Filter()
{
}
