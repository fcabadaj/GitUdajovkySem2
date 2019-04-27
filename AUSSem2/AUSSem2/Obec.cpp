#include "Obec.h"
#include "structures/heap_monitor.h"


Obec::Obec(string nazov, int pZapVol, int pVydOb, double perUcVol, int pocOdoObal, Array<Kandidat*> *zoznamKand, string nOkresu, string nKraja, int kodObce):
	UzemnyCelok(nazov, pZapVol,pVydOb,perUcVol,pocOdoObal, zoznamKand),
	nazovOkresu_(nOkresu),
	nazovKraja_(nKraja),
	kodObce_(kodObce)
{
}


Obec::~Obec()
{
}
