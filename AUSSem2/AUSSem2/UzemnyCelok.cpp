#include "UzemnyCelok.h"
#include "structures/heap_monitor.h"


UzemnyCelok::UzemnyCelok(string nazov, int pocZapVol, int pocVydOb, double perUcVol, int pocOdovOb):
	nazov_(nazov),
	pocetZapVolicov_(pocZapVol),
	pocetVydObalok_(pocVydOb),
	percUcastVolicov_(perUcVol),
	pocetOdovzdanychObalok_(pocOdovOb)
{
}


UzemnyCelok::~UzemnyCelok()
{
}
