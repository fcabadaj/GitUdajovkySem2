#pragma once
#include "structures/heap_monitor.h"
#include <string>

using namespace std;

class UzemnyCelok
{
protected:
	string nazov_;
	int pocetZapVolicov_;
	int pocetVydObalok_;
	double percUcastVolicov_;
	int pocetOdovzdanychObalok_;

public:
	UzemnyCelok(string nazov, int pocZapVol, int pocVydOb, double perUcVol, int pocOdovOb);
	virtual ~UzemnyCelok();
	string getNazov() { return nazov_; };
	
};

