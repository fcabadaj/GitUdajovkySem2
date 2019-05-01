#include "Kraj.h"
#include "structures/heap_monitor.h"

Kraj::Kraj(string nazov, DataKolo *dataKolo1, DataKolo *dataKolo2, int kodKraja):
	VyssiUzemnyCelok(nazov, kodKraja, dataKolo1, dataKolo2)
{
}


Kraj::~Kraj()
{
}

void Kraj::vypisSa(int kolo)
{
	cout << "======================================================= \n";
	cout << "Nazov kraja: " << nazov_ << endl;
	if (kolo == 1)
	{
		dataPre1Kolo_->vypisSa();
	}
	else if (kolo == 2)
	{
		dataPre2Kolo_->vypisSa();
	}
}
