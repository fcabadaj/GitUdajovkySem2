#pragma once
#include "VyssiUzemnyCelok.h"
#include "structures/heap_monitor.h"

class Okres :
	public VyssiUzemnyCelok
{

private:
	string nazovKraja_;
	int kodOkresu_;

public:
	Okres(string nazov, int pocZapVol, int pocVydOb, double perUcVol, int pocOdovOb, int kodOkresu, string nazovKraja);
	~Okres();
};

