#include "DataKolo.h"

DataKolo::DataKolo(int pocetZVol, int pocetVydOb, double perUcastVol, int pocOdovOb, Array<Kandidat*> *zoznamKand) :
	pocetZapVolicov_(pocetZVol),
	pocetVydObalok_(pocetVydOb),
	percUcastVolicov_(perUcastVol),
	pocetOdovzdanychObalok_(pocetVydOb),
	zoznamKandidatov_(zoznamKand)
{
}

void DataKolo::vypisSa()
{
	int pocetHlasov = 0;

	for (unsigned int i = 0; i < zoznamKandidatov_->size(); i++)
	{
		pocetHlasov += zoznamKandidatov_->operator[](i)->getPocetOdovzdanychHlasov();
	}
	cout << "======================================================= \n";
	cout << "Pocet zapisanych volicov: " << pocetZapVolicov_ << " Vydane obalky: " << pocetVydObalok_ << " Ucast: " << percUcastVolicov_ << " Odovzdane obalky: " << pocetOdovzdanychObalok_ << " Platne hlasy: " << pocetHlasov << endl;
}

DataKolo::~DataKolo()
{
	for (unsigned int i = 0; i < zoznamKandidatov_->size(); i++)
	{
		delete zoznamKandidatov_->operator[](i);
	}
	delete zoznamKandidatov_;
	zoznamKandidatov_ = nullptr;
}
