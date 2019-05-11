#pragma once
#include "structures/heap_monitor.h"
#include "Obec.h"
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include "Okres.h"
#include "Kraj.h"
#include "Kriterium.h"
#include "structures/table/unsorted_sequence_table.h"
#include "structures/table/sorted_sequence_table.h"

using namespace std;
using namespace structures;

class DataManazer
{

private:
	SortedSequenceTable<int,Kandidat*> *zoznamKandidatov1Kolo_;
	SortedSequenceTable<int, Kandidat*> *zoznamKandidatov2Kolo_;
	SortedSequenceTable<int, Obec*> *vysledkyObci_;
	SortedSequenceTable<int, Okres*> *vysledkyOkresov_;
	SortedSequenceTable<int, Kraj*> *vysledkyKrajov_;
	
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
	void zoradenieUzemnychJednotiek();
	void vypisanieVysledkovKandidata();
	void test();
	template<typename K, typename T, typename T2>
	void usporiadajTabulku(UnsortedSequenceTable<K, T*> &table, Kriterium<T2, T> &kriterium, bool desc);
	
};

template<typename K, typename T, typename T2>
inline void DataManazer::usporiadajTabulku(UnsortedSequenceTable<K, T*> &tab, Kriterium<T2, T> &krit, bool desc)
{
	//vseobecna definicia quick sortu
	QuickSort<K, T> *qs = new QuickSort<K, T>();

	//volanie prerobenej metody sort
	qs->sorth(tab, krit, desc);

	delete qs;
}
