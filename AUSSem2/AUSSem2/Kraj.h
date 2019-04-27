#pragma once
#include "VyssiUzemnyCelok.h"
#include "structures/heap_monitor.h"

class Kraj :
	public VyssiUzemnyCelok
{

private:
	int kodKraja_;

public:
	Kraj(string nazov, int pocZapVol, int pocVydOb, double perUcVol, int pocOdovOb, Array<Kandidat*> *zoznamKand, int kodKraja);
	~Kraj();
};

