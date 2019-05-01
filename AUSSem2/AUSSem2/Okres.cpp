#include "Okres.h"
#include "structures/heap_monitor.h"


Okres::Okres(string nazov,DataKolo *dataKolo1, DataKolo *dataKolo2, int kodOkresu, string nazovKraja):
	VyssiUzemnyCelok(nazov, kodOkresu,dataKolo1, dataKolo2),
	nazovKraja_(nazovKraja)
{
}

Okres::~Okres()
{
}

void Okres::vypisSa(int kolo)
{
	cout << "======================================================= \n";

	cout << "Nazov okresu " << nazov_ << " Nazov kraja: " << nazovKraja_ << endl;
	if (kolo == 1)
	{
		dataPre1Kolo_->vypisSa();
	}
	else if (kolo == 2)
	{
		dataPre2Kolo_->vypisSa();
	}
}
