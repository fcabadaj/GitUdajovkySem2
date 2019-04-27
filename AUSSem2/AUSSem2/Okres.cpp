#include "Okres.h"
#include "structures/heap_monitor.h"


Okres::Okres(string nazov, int pocZapVol, int pocVydOb, double perUcVol, int pocOdovOb, Array<Kandidat*> *zoznamKand, int kodOkresu, string nazovKraja):
	VyssiUzemnyCelok(nazov, pocZapVol, pocVydOb, perUcVol, pocOdovOb, zoznamKand),
	kodOkresu_(kodOkresu),
	nazovKraja_(nazovKraja)
{
}


Okres::~Okres()
{
}
