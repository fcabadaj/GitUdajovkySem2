#pragma once
#include "structures/heap_monitor.h"
#include <string>
#include "structures/array/array.h"
#include "DataKolo.h"

using namespace std;
using namespace structures;

class Kandidat;
class DataKolo;

class UzemnyCelok
{
protected:
	string nazov_;
	int kod_;
	DataKolo *dataPre1Kolo_;
	DataKolo *dataPre2Kolo_;	

public:
	UzemnyCelok(string nazov,int kod, DataKolo *dataKolo1, DataKolo *dataKolo2);
	virtual ~UzemnyCelok();
	string getNazov() const { return nazov_; };
	int pocetZapisanychVolicov(int kolo) const;
	int pocetVydanychObalok(int kolo) const;
	double ucastVolicovVKole(int kolo) const;
	int pocetOdovzdanychObalok(int kolo) const;
	int pocetOdovzdanychHlasov(int kolo, Kandidat *kandidat) const;
	DataKolo* getDataPreKolo1() { return dataPre1Kolo_; };
	DataKolo* getDataPreKolo2() { return dataPre2Kolo_; };
};

