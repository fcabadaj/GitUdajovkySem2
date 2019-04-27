#pragma once
#include "DataManazer.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Obec.h"
#include "structures/table/treap.h"
#include "KriteriumNazov.h"

using namespace std;
using namespace structures;

int main()
{
	initHeapMonitor();
	DataManazer *dataMng = new DataManazer();

	KriteriumNazov *kn = new KriteriumNazov();

	Obec *obec = new Obec("jebo", 132, 123, 1, 12, new Array<Kandidat*>(10), "hakunamatata", "wuhuhu", 65465);
	Obec *obec2 = new Obec("egojebo", 132, 123, 1, 12, new Array<Kandidat*>(10), "hakunamatata", "wuhuhu", 65465);
	Obec *obec3 = new Obec("aljbgfnajldkajebo", 132, 123, 1, 12, new Array<Kandidat*>(10), "hakunamatata", "wuhuhu", 65465);
	cout << kn->evaluate(*obec) << endl;
	cout << kn->evaluate(*obec2) << endl;
	cout << kn->evaluate(*obec3) << endl;
	system("PAUSE");

	//dataMng->nacitajData();
	
	system("PAUSE");

	delete dataMng;

	return 0;
}