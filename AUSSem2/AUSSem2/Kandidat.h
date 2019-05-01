#pragma once
#include <string>
#include "structures/heap_monitor.h"
#include "UzemnyCelok.h"

class UzemnyCelok;

using namespace std;

class Kandidat
{

private:
	int poradoveCislo_;
	string meno_;
	string priezvisko_;
	int pocetHlasov_;

public:
	Kandidat(int pCislo, string meno, string priezvisko, int pocetHlasov = 0);
	~Kandidat();
	int getPoradoveCislo() const { return poradoveCislo_; } ;
	int getPocetOdovzdanychHlasov() const { return pocetHlasov_; };
	string getMeno() const { return meno_; };
	string getPriezvisko() const { return priezvisko_; };
	int pocetZiskanychHlasov(int kolo, UzemnyCelok *uc) const;
};

