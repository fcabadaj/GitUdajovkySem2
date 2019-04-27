#include "UzemnyCelok.h"
#include "structures/heap_monitor.h"


UzemnyCelok::UzemnyCelok(string nazov, int pocZapVol, int pocVydOb, double perUcVol, int pocOdovOb, Array<Kandidat*> *zoznamKand):
	nazov_(nazov),
	pocetZapVolicov_(pocZapVol),
	pocetVydObalok_(pocVydOb),
	percUcastVolicov_(perUcVol),
	pocetOdovzdanychObalok_(pocOdovOb),
	zoznamKandidatov_(zoznamKand)
{
}


UzemnyCelok::~UzemnyCelok()
{
	for (unsigned int i = 0; i < zoznamKandidatov_->size(); i++)
	{
		delete zoznamKandidatov_->operator[](i);
	}
	delete zoznamKandidatov_;
	zoznamKandidatov_ = nullptr;
}
