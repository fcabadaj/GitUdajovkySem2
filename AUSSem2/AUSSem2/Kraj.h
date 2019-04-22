#pragma once
#include "VyssiUzemnyCelok.h"
#include "structures/heap_monitor.h"

class Kraj :
	public VyssiUzemnyCelok
{
public:
	Kraj(string nazov, int pocZapVol, int pocVydOb, double perUcVol, int pocOdovOb);
	~Kraj();
};

