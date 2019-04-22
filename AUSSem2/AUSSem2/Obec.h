#pragma once
#include "structures/heap_monitor.h"
#include "UzemnyCelok.h"
#include <string>

using namespace std;

class Obec :
	public UzemnyCelok
{

private:

	string nazovOkresu_;
	string nazovKraja_;
	int kodObce_;

public:
	Obec(string nazov, int pZapVol, int pVydOb, int perUcVol, int pocOdoObal, string nOkresu, string nKraja, int kodObce);
	~Obec();
};

