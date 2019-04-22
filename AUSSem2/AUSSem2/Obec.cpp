#include "Obec.h"
#include "structures/heap_monitor.h"


Obec::Obec(string nazov, int pZapVol, int pVydOb, int perUcVol, int pocOdoObal, string nOkresu, string nKraja, int kodObce):
	UzemnyCelok(nazov, pZapVol,pVydOb,perUcVol,pocOdoObal),
	nazovOkresu_(nOkresu),
	nazovKraja_(nKraja),
	kodObce_(kodObce)
{
}


Obec::~Obec()
{
}
