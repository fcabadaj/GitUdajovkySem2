#pragma once
#include "structures/heap_monitor.h"
#include <string>
#include "structures/array/array.h"
#include "Kandidat.h"

using namespace std;
using namespace structures;

class UzemnyCelok
{
protected:
	string nazov_;
	int pocetZapVolicov_;
	int pocetVydObalok_;
	double percUcastVolicov_;
	int pocetOdovzdanychObalok_;
	Array<Kandidat*> *zoznamKandidatov_;

public:
	UzemnyCelok(string nazov, int pocZapVol, int pocVydOb, double perUcVol, int pocOdovOb, Array<Kandidat*> *zoznamKand);
	virtual ~UzemnyCelok();
	string getNazov() const { return nazov_; };
	
};

