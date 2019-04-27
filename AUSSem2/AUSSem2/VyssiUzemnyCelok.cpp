#include "VyssiUzemnyCelok.h"
#include "structures/heap_monitor.h"

VyssiUzemnyCelok::VyssiUzemnyCelok(string nazov, int pocZapVol, int pocVydOb, double perUcVol, int pocOdovOb, Array<Kandidat*> *zoznamKand):
	UzemnyCelok(nazov, pocZapVol,pocVydOb,perUcVol,pocOdovOb, zoznamKand)
{
}


VyssiUzemnyCelok::~VyssiUzemnyCelok()
{
}
