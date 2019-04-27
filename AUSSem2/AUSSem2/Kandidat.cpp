#include "Kandidat.h"
#include "structures/heap_monitor.h"

Kandidat::Kandidat(int pCislo, string meno, string priezvisko, int pocetHlasov):
	poradoveCislo_(pCislo),
	meno_(meno),
	priezvisko_(priezvisko),
	pocetHlasov_(pocetHlasov)
{
}


Kandidat::~Kandidat()
{
}
