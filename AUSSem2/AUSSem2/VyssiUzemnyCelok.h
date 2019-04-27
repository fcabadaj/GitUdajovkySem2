#pragma once
#include "UzemnyCelok.h"
#include "structures/heap_monitor.h"

class VyssiUzemnyCelok :
	public UzemnyCelok
{

public:
	VyssiUzemnyCelok(string nazov, int pocZapVol, int pocVydOb, double perUcVol, int pocOdovOb, Array<Kandidat*> *zoznamKand);
	virtual ~VyssiUzemnyCelok();
};

