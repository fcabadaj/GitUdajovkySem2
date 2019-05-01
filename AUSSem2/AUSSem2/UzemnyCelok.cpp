#include "UzemnyCelok.h"
#include "structures/heap_monitor.h"


UzemnyCelok::UzemnyCelok(string nazov,int kod, DataKolo *dataKolo1, DataKolo *dataKolo2):
	nazov_(nazov),
	kod_(kod),
	dataPre1Kolo_(dataKolo1),
	dataPre2Kolo_(dataKolo2)
{
}


UzemnyCelok::~UzemnyCelok()
{
	delete dataPre1Kolo_;
	delete dataPre2Kolo_;
}

int UzemnyCelok::pocetZapisanychVolicov(int kolo) const
{
	if (kolo == 1)
		return dataPre1Kolo_->getPocetZapVolicov();
	else
		return dataPre2Kolo_->getPocetZapVolicov();
}

int UzemnyCelok::pocetVydanychObalok(int kolo) const
{
	switch (kolo)
	{
	case 1:
		return dataPre1Kolo_->getPocetVydObalok();
		break;
	case 2:
		return dataPre2Kolo_->getPocetVydObalok();
		break;
	case 3:
		return dataPre1Kolo_->getPocetVydObalok() + dataPre2Kolo_->getPocetVydObalok();
		break;
	}
}

double UzemnyCelok::ucastVolicovVKole(int kolo) const
{
	if (kolo == 1)
		return dataPre1Kolo_->getPercUcastVolicov();
	else
		return dataPre2Kolo_->getPercUcastVolicov();
}

int UzemnyCelok::pocetOdovzdanychObalok(int kolo) const
{
	switch (kolo)
	{
	case 1:
		return dataPre1Kolo_->getPocetOdovzObalok();
		break;
	case 2:
		return dataPre2Kolo_->getPocetOdovzObalok();
		break;
	case 3:
		return dataPre1Kolo_->getPocetOdovzObalok() + dataPre2Kolo_->getPocetVydObalok();
		break;
	}
}

int UzemnyCelok::pocetOdovzdanychHlasov(int kolo, Kandidat *kandidat) const
{
	int hlasySpolu = 0;

	switch (kolo)
	{
	case 1:
		
		for (unsigned int i = 0; i < dataPre1Kolo_->getKandidatov()->size(); i++)
		{
			if (kandidat->getPoradoveCislo() == dataPre1Kolo_->getKandidatov()->operator[](i)->getPoradoveCislo())
				return dataPre1Kolo_->getKandidatov()->operator[](i)->getPocetOdovzdanychHlasov();
		}

		return -1;
		break;
	case 2:
		
		for (unsigned int i = 0; i < dataPre2Kolo_->getKandidatov()->size(); i++)
		{
			if (kandidat->getPoradoveCislo() == dataPre2Kolo_->getKandidatov()->operator[](i)->getPoradoveCislo())
				return dataPre2Kolo_->getKandidatov()->operator[](i)->getPocetOdovzdanychHlasov();
		}

		return -1;

		break;
	case 3:
		
		for (unsigned int i = 0; i < dataPre1Kolo_->getKandidatov()->size(); i++)
		{
			if (kandidat->getPoradoveCislo() == dataPre1Kolo_->getKandidatov()->operator[](i)->getPoradoveCislo())
				hlasySpolu += dataPre1Kolo_->getKandidatov()->operator[](i)->getPocetOdovzdanychHlasov();
		}

		for (unsigned int i = 0; i < dataPre2Kolo_->getKandidatov()->size(); i++)
		{
			if (kandidat->getPoradoveCislo() == dataPre1Kolo_->getKandidatov()->operator[](i)->getPoradoveCislo())
				hlasySpolu += dataPre2Kolo_->getKandidatov()->operator[](i)->getPocetOdovzdanychHlasov();
		}

		if (hlasySpolu == 0)
			return -1;
		else
			return hlasySpolu;

		break;
	}
}

