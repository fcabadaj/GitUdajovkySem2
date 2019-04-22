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

public:
	Kandidat(int pCislo, string meno, string priezvisko);
	~Kandidat();
};

