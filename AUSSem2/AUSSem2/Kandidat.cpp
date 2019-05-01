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

int Kandidat::pocetZiskanychHlasov(int kolo, UzemnyCelok * uc) const
{
	int hlasySpolu = 0;

	switch (kolo)
	{
	case 1:
		return uc->getDataPreKolo1()->getKandidatov()->operator[](poradoveCislo_ - 1)->getPocetOdovzdanychHlasov();
		break;
	case 2:
		hlasySpolu = uc->getDataPreKolo2()->getKandidatov()->operator[](poradoveCislo_ - 1)->getPocetOdovzdanychHlasov();
		if (hlasySpolu == 0)
			return -1;
		else
			return hlasySpolu;
		break;
	case 3:
		hlasySpolu += uc->getDataPreKolo1()->getKandidatov()->operator[](poradoveCislo_ - 1)->getPocetOdovzdanychHlasov();
		hlasySpolu += uc->getDataPreKolo2()->getKandidatov()->operator[](poradoveCislo_ - 1)->getPocetOdovzdanychHlasov();

		if (hlasySpolu == 0)
			return -1;
		else
			return hlasySpolu;

		break;
	}
}