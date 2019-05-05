#include "Obec.h"
#include "structures/heap_monitor.h"

Obec::Obec(string nazov,string nOkresu, string nKraja, int kodObce, DataKolo *dataKolo1, DataKolo *dataKolo2):
	UzemnyCelok(nazov, kodObce, dataKolo1, dataKolo2),
	nazovOkresu_(nOkresu),
	nazovKraja_(nKraja)
{
}

Obec::~Obec()
{
}

void Obec::vypisSa(int kolo)
{
	cout << "======================================================= \n";
	cout << "Nazov obce: " << nazov_ << " Nazov okresu: " << nazovOkresu_ << " Nazov Kraja: " << nazovKraja_ << endl;
	if (kolo == 1)
	{
		dataPre1Kolo_->vypisSa();
	}
	else if (kolo == 2)
	{
		dataPre2Kolo_->vypisSa();
	}
}

bool Obec::patriDoVUC(VyssiUzemnyCelok &vuc) const
{
	return vuc.getNazov() == nazovKraja_ || vuc.getNazov() == nazovOkresu_;
}
