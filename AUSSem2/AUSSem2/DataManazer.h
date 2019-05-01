#pragma once
#include "structures/heap_monitor.h"
#include "Obec.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "structures/list/array_list.h"
#include <sstream>
#include "structures/table/treap.h"
#include "Okres.h"
#include "Kraj.h"

using namespace std;
using namespace structures;

class DataManazer
{

private:
	Treap<int,Kandidat*> *zoznamKandidatov1Kolo_;
	Treap<int, Kandidat*> *zoznamKandidatov2Kolo_;
	Treap<int, Obec*> *vysledkyObci_;
	Treap<int, Okres*> *vysledkyOkresov_;
	Treap<int, Kraj*> *vysledkyKrajov_;

	void nacitajObce();
	void nacitajKandidatov();
	void nacitajOkresy();
	void nacitajKraje();

	void odstranDiakritiku(string & s);	
	void zobrazMenuInfOUzJedn();
	int vyberKolo();

public:
	DataManazer();
	~DataManazer();
	void nacitajData();
	void vypisInfOUzemnychJednotkach();
	
	
};

