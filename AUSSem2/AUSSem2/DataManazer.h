#pragma once
#include "structures/heap_monitor.h"
#include "Obec.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include "structures/list/array_list.h"
#include "Kandidat.h"
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
	Treap<int, Obec*> *vysledkyObci1Kolo_;
	Treap<int, Obec*> *vysledkyObci2Kolo_;
	Treap<int, Okres*> *vysledkyOkresov1Kolo_;
	Treap<int, Okres*> *vysledkyOkresov2Kolo_;
	Treap<int, Kraj*> *vysledkyKrajov1Kolo_;
	Treap<int, Kraj*> *vysledkyKrajov2Kolo_;

	void nacitajObce();
	void nacitajKandidatov();
	void nacitajOkresy();
	void nacitajKraje();

	string odstranDiakritiku(string s);	

public:
	DataManazer();
	~DataManazer();
	void nacitajData();
	
};

