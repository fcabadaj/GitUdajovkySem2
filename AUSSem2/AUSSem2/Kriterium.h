#pragma once
#include <string>
#include "UzemnyCelok.h"

template <typename T, typename O>
class Kriterium
{

protected:
	virtual T evaluate(const O& obj);
public:
	Kriterium();
	virtual ~Kriterium();	
};

template<typename T, typename O>
inline T Kriterium<T, O>::evaluate(const O& obj)
{
	return T();
}

template <typename T, typename O>
Kriterium<T,O>::Kriterium()
{
}

template <typename T, typename O>
Kriterium<T,O>::~Kriterium()
{
}


