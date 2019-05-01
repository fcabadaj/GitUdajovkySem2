#pragma once
#include "structures/array/array.h"
#include "Kandidat.h"
#include  <iostream>

using namespace structures;
class Kandidat;

class DataKolo
{

private:
	int pocetZapVolicov_;
	int pocetVydObalok_;
	double percUcastVolicov_;
	int pocetOdovzdanychObalok_;
	Array<Kandidat*> *zoznamKandidatov_;
public:
	DataKolo(int pocetZVol, int pocetVydOb, double perUcastVol, int pocOdovOb, Array<Kandidat*> *zoznamKand);
	int getPocetZapVolicov() { return pocetZapVolicov_; };
	int getPocetVydObalok() { return pocetVydObalok_; };
	double getPercUcastVolicov() { return percUcastVolicov_; };
	int getPocetOdovzObalok() { return pocetOdovzdanychObalok_; };
	Array<Kandidat*>* getKandidatov() { return zoznamKandidatov_; };
	void vypisSa();
	~DataKolo();
};

