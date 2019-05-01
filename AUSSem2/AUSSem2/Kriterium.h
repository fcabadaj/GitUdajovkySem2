#pragma once
#include <string>
#include "UzemnyCelok.h"
#include "Obec.h"
#include "VyssiUzemnyCelok.h"

template <typename T, typename O>
class Kriterium
{

public:
	Kriterium();
	virtual ~Kriterium();	
	virtual T evaluate(const O& obj) const;
};

template<typename T, typename O>
inline T Kriterium<T, O>::evaluate(const O& obj) const
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


