#pragma once
#include <string>
#include "structures/heap_monitor.h"

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
};

