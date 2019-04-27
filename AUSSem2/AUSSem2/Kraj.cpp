#include "Kraj.h"
#include "structures/heap_monitor.h"

Kraj::Kraj(string nazov, int pocZapVol, int pocVydOb, double perUcVol, int pocOdovOb, Array<Kandidat*> *zoznamKand, int kodKraja):
	VyssiUzemnyCelok(nazov, pocZapVol, pocVydOb, perUcVol, pocOdovOb, zoznamKand),
	kodKraja_(kodKraja)
{
}


Kraj::~Kraj()
{
}
