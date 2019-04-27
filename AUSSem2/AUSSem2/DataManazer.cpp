#include "DataManazer.h"
#include "structures/heap_monitor.h"

DataManazer::DataManazer():
zoznamKandidatov1Kolo_(new Treap<int,Kandidat*>),
zoznamKandidatov2Kolo_(new Treap<int, Kandidat*>),
vysledkyObci1Kolo_(new Treap<int,Obec*>),
vysledkyObci2Kolo_(new Treap<int, Obec*>),
vysledkyOkresov1Kolo_(new Treap<int,Okres*>),
vysledkyOkresov2Kolo_(new Treap<int, Okres*>),
vysledkyKrajov1Kolo_(new Treap<int, Kraj*>),
vysledkyKrajov2Kolo_(new Treap<int, Kraj*>)
{
}

DataManazer::~DataManazer()
{ 
	for (TableItem<int, Kandidat*>* kandidat : *zoznamKandidatov1Kolo_) {
		delete kandidat->accessData();
	}
	delete zoznamKandidatov1Kolo_;

	for (TableItem<int, Kandidat*>* kandidat : *zoznamKandidatov2Kolo_) {
		delete kandidat->accessData();
	}
	delete zoznamKandidatov2Kolo_;

	for (TableItem<int, Obec*>* obec : *vysledkyObci1Kolo_) {
		delete obec->accessData();
	}
	delete vysledkyObci1Kolo_;

	for (TableItem<int, Obec*>* obec : *vysledkyObci2Kolo_) {
		delete obec->accessData();
	}
	delete vysledkyObci2Kolo_;

	for (TableItem<int, Okres*>* okres : *vysledkyOkresov1Kolo_) {
		delete okres->accessData();
	}
	delete vysledkyOkresov1Kolo_;

	for (TableItem<int, Okres*>* okres : *vysledkyOkresov2Kolo_) {
		delete okres->accessData();
	}
	delete vysledkyOkresov2Kolo_;

	for (TableItem<int, Kraj*>* kraj : *vysledkyKrajov1Kolo_) {
		delete kraj->accessData();
	}
	delete vysledkyKrajov1Kolo_;

	for (TableItem<int, Kraj*>* kraj : *vysledkyKrajov2Kolo_) {
		delete kraj->accessData();
	}
	delete vysledkyKrajov2Kolo_;

}

void DataManazer::nacitajData()
{
	nacitajKandidatov();
	nacitajObce();
	nacitajOkresy();
	nacitajKraje();
}

void DataManazer::nacitajObce()
{
	ifstream subor;
	int counter = 0;
	string myString;
	stringstream zaznam;
	

	string	nazovObce;
	string	nazovOkresu;
	string	nazovKraja;
	int		kodObce;
	int		pocetZapVolicov;
	int		pocetVydObalok;
	double	percUcastVolicov;
	int		pocetOdovzdanychObalok;

	ifstream suborKand;
	string menoKand;
	string priezviskoKand;
	int pocetPlatnychHlasov;
	int poradoveCislo;

	subor.open("excel/suhrnneVysledkyObce1Kolo.csv");
	suborKand.open("excel/pocetAPodielhlasovZaObce1Kolo.csv");
	setlocale(LC_ALL, "");
	
	for (unsigned int i = 0; i < 4; i++)
	{
		getline(suborKand, myString);
	}

	while (getline(subor, myString))
	{
		counter++;
		if (counter > 5)
		{
			odstranDiakritiku(myString);
			//cout << myString << endl;
			zaznam = stringstream(myString);
			
			//Kod kraja
			getline(zaznam, myString, ';');

			//Nazov kraja
			getline(zaznam, myString, ';');
			nazovKraja = myString;

			//preskoc kod uzemneho obvodu
			getline(zaznam, myString, ';');
			
			//preskoc nazov uzemneho obvodu
			getline(zaznam, myString, ';');

			//preskoc kod okresu
			getline(zaznam, myString, ';');

			//nazov okresu
			getline(zaznam, myString, ';');
			nazovOkresu = myString;

			//kod obce
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			kodObce = stoi(myString);

			// nazov obce
			getline(zaznam, myString, ';');
			nazovObce = myString;	

			//preskoc pocet okrskov
			getline(zaznam, myString, ';');

			//pocet zapisanych volicov
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetZapVolicov = stoi(myString);

			//pocet vydanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetVydObalok = stoi(myString);

			//ucast
			getline(zaznam, myString, ';');
			percUcastVolicov = stod(myString);

			//pocet odovzdanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetOdovzdanychObalok = stoi(myString);


			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');

			Array<Kandidat*> *zoznamKandidatov1Kolo = new Array<Kandidat*>(15);
			for (unsigned int i = 0; i < zoznamKandidatov1Kolo->size(); i++)
			{	
				getline(suborKand, myString);
				odstranDiakritiku(myString);
				//cout << myString << endl;

				zaznam = stringstream(myString);

				//preskoc kod kraja
				getline(zaznam, myString, ';');
				//presko nazov Kraja
				getline(zaznam, myString, ';');
				//presko kod uzemia
				getline(zaznam, myString, ';');
				//presko nazov uzemia
				getline(zaznam, myString, ';');
				//presko kod okresu
				getline(zaznam, myString, ';');
				//presko nazov okresu
				getline(zaznam, myString, ';');
				//presko kod obce
				getline(zaznam, myString, ';');
				//presko nazov obce
				getline(zaznam, myString, ';');

				//poradie na hlas. listku
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				poradoveCislo = stoi(myString);

				//meno 
				getline(zaznam, myString, ';');
				menoKand = myString;

				//priezvisko
				getline(zaznam, myString, ';');
				priezviskoKand = myString;

				//pocet platnych hlasov
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				pocetPlatnychHlasov = stoi(myString);

				//preskoc ostatne
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');

				zoznamKandidatov1Kolo->operator[](i) = new Kandidat(poradoveCislo, menoKand, priezviskoKand, pocetPlatnychHlasov);
			}
			
			Obec *obec = new Obec(nazovObce, pocetZapVolicov, pocetVydObalok, percUcastVolicov, pocetOdovzdanychObalok, zoznamKandidatov1Kolo, nazovOkresu, nazovKraja, kodObce);

			vysledkyObci1Kolo_->insert(kodObce,obec);
		}
	}

	subor.close();
	suborKand.close();

	subor.open("excel/suhrnneVysledkyObce2Kolo.csv");
	suborKand.open("excel/pocetAPodielhlasovZaObce1Kolo.csv");

	for (unsigned int i = 0; i < 4; i++)
	{
		getline(suborKand, myString);
	}

	counter = 0;
	while (getline(subor, myString))
	{
		counter++;
		if (counter > 5)
		{
			odstranDiakritiku(myString);
			//cout << myString << endl;
			zaznam = stringstream(myString);

			//Kod kraja
			getline(zaznam, myString, ';');

			//Nazov kraja
			getline(zaznam, myString, ';');
			nazovKraja = myString;

			//preskoc kod uzemneho obvodu
			getline(zaznam, myString, ';');

			//preskoc nazov uzemneho obvodu
			getline(zaznam, myString, ';');

			//preskoc kod okresu
			getline(zaznam, myString, ';');

			//nazov okresu
			getline(zaznam, myString, ';');
			nazovOkresu = myString;

			//kod obce
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			kodObce = stoi(myString);

			// nazov obce
			getline(zaznam, myString, ';');
			nazovObce = myString;

			//preskoc pocet okrskov
			getline(zaznam, myString, ';');

			//pocet zapisanych volicov
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetZapVolicov = stoi(myString);

			//pocet vydanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetVydObalok = stoi(myString);

			//ucast
			getline(zaznam, myString, ';');
			percUcastVolicov = stod(myString);

			//pocet odovzdanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetOdovzdanychObalok = stoi(myString);

			//ignorun dalsie zaznamy
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');

			Array<Kandidat*> *zoznamKandidatov2Kolo = new Array<Kandidat*>(2);
			for (unsigned int i = 0; i < zoznamKandidatov2Kolo->size(); i++)
			{
				getline(suborKand, myString);
				odstranDiakritiku(myString);
				//cout << myString << endl;

				zaznam = stringstream(myString);

				//preskoc kod kraja
				getline(zaznam, myString, ';');
				//presko nazov Kraja
				getline(zaznam, myString, ';');
				//presko kod uzemia
				getline(zaznam, myString, ';');
				//presko nazov uzemia
				getline(zaznam, myString, ';');
				//presko kod okresu
				getline(zaznam, myString, ';');
				//presko nazov okresu
				getline(zaznam, myString, ';');
				//presko kod obce
				getline(zaznam, myString, ';');
				//presko nazov obce
				getline(zaznam, myString, ';');

				//poradie na hlas. listku
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				poradoveCislo = stoi(myString);

				//meno 
				getline(zaznam, myString, ';');
				menoKand = myString;

				//priezvisko
				getline(zaznam, myString, ';');
				priezviskoKand = myString;

				//pocet platnych hlasov
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				pocetPlatnychHlasov = stoi(myString);

				//preskoc ostatne
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');

				zoznamKandidatov2Kolo->operator[](i) = new Kandidat(poradoveCislo, menoKand, priezviskoKand, pocetPlatnychHlasov);
			}			

			Obec *obec = new Obec(nazovObce, pocetZapVolicov, pocetVydObalok, percUcastVolicov, pocetOdovzdanychObalok, zoznamKandidatov2Kolo, nazovOkresu, nazovKraja, kodObce);

			vysledkyObci2Kolo_->insert(kodObce, obec);
		}
	}

	subor.close();
	suborKand.close();
}

void DataManazer::nacitajKandidatov()
{
	ifstream subor;
	int counter = 0;
	string myString;
	stringstream zaznam;
	int poradoveCislo;
	string meno;
	string priezvisko;

	subor.open("excel/zoznamKandidatov1Kolo.csv");	
	setlocale(LC_ALL, "");

	while (getline(subor, myString))
	{
		counter++;
		if (counter > 4)
		{
			odstranDiakritiku(myString);
			//cout << myString << endl;
			zaznam = stringstream(myString);

			getline(zaznam, myString, ';');
			poradoveCislo = stoi(myString);

			getline(zaznam, myString, ';');
			meno = myString;

			getline(zaznam, myString, ';');
			priezvisko = myString;

			Kandidat *kandidat = new Kandidat(poradoveCislo, meno, priezvisko);
			zoznamKandidatov1Kolo_->insert(poradoveCislo,kandidat);
		}		
	}

	subor.close();

	subor.open("excel/zoznamKandidatov2Kolo.csv");
	counter = 0;

	while (getline(subor, myString))
	{
		counter++;
		if (counter > 4)
		{
			odstranDiakritiku(myString);
			//cout << myString << endl;
			zaznam = stringstream(myString);

			getline(zaznam, myString, ';');
			poradoveCislo = stoi(myString);

			getline(zaznam, myString, ';');
			meno = myString;

			getline(zaznam, myString, ';');
			priezvisko = myString;

			Kandidat *kandidat = new Kandidat(poradoveCislo, meno, priezvisko);
			zoznamKandidatov2Kolo_->insert(poradoveCislo, kandidat);
		}
	}

	subor.close();
}

void DataManazer::nacitajOkresy()
{
	ifstream subor;
	int counter = 0;
	string myString;
	stringstream zaznam;

	string	nazovOkresu;
	string	nazovKraja;
	int		kodOkresu;
	int		pocetZapVolicov;
	int		pocetVydObalok;
	double	percUcastVolicov;
	int		pocetOdovzdanychObalok;

	ifstream suborKand;
	string menoKand;
	string priezviskoKand;
	int pocetPlatnychHlasov;
	int poradoveCislo;

	subor.open("excel/suhrnneVysledkyOkresy1Kolo.csv");
	subor.open("excel/pocetAPodielhlasovZaOkresy2Kolo.csv");
	setlocale(LC_ALL, "");

	for (unsigned int i = 0; i < 8; i++)
	{
		getline(suborKand, myString);
	}

	while (getline(subor, myString))
	{
		counter++;
		if (counter > 4)
		{
			odstranDiakritiku(myString);
			//cout << myString << endl;
			zaznam = stringstream(myString);

			//Kod kraja
			getline(zaznam, myString, ';');

			//Nazov kraja
			getline(zaznam, myString, ';');
			nazovKraja = myString;

			//preskoc kod uzemneho obvodu
			getline(zaznam, myString, ';');

			//preskoc nazov uzemneho obvodu
			getline(zaznam, myString, ';');

			//kod okresu
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			kodOkresu = stoi(myString);

			//nazov okresu
			getline(zaznam, myString, ';');
			nazovOkresu = myString;
			
			//preskoc pocet okrskov
			getline(zaznam, myString, ';');

			//pocet zapisanych volicov
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetZapVolicov = stoi(myString);

			//pocet vydanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetVydObalok = stoi(myString);

			//ucast
			getline(zaznam, myString, ';');
			percUcastVolicov = stod(myString);

			//pocet odovzdanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetOdovzdanychObalok = stoi(myString);

			//ignorun dalsie zaznamy
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');

			Array<Kandidat*> *zoznamKandidatov1Kolo = new Array<Kandidat*>(15);
			
			for (unsigned int i = 0; i < zoznamKandidatov1Kolo->size(); i++)
			{
				getline(suborKand, myString);
				odstranDiakritiku(myString);
				//cout << myString << endl;

				zaznam = stringstream(myString);

				//preskoc kod kraja
				getline(zaznam, myString, ';');
				//presko nazov Kraja
				getline(zaznam, myString, ';');
				//presko kod uzemia
				getline(zaznam, myString, ';');
				//presko nazov uzemia
				getline(zaznam, myString, ';');
				//presko kod okresu
				getline(zaznam, myString, ';');
				//presko nazov okresu
				getline(zaznam, myString, ';');

				//poradie na hlas. listku
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				poradoveCislo = stoi(myString);

				//meno 
				getline(zaznam, myString, ';');
				menoKand = myString;

				//priezvisko
				getline(zaznam, myString, ';');
				priezviskoKand = myString;

				//pocet platnych hlasov
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				pocetPlatnychHlasov = stoi(myString);

				//preskoc ostatne
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');


				zoznamKandidatov1Kolo->operator[](i) = new Kandidat(poradoveCislo, menoKand, priezviskoKand, pocetPlatnychHlasov);
			}

			Okres *okres = new Okres(nazovOkresu, pocetOdovzdanychObalok, pocetVydObalok, percUcastVolicov, pocetOdovzdanychObalok, zoznamKandidatov1Kolo, kodOkresu, nazovKraja);

			vysledkyOkresov1Kolo_->insert(kodOkresu,okres);
			
		}
		
	}

	subor.close();
	subor.open("excel/suhrnneVysledkyOkresy2Kolo.csv");
	subor.open("excel/pocetAPodielhlasovZaOkresy2Kolo.csv");

	for (unsigned int i = 0; i < 7; i++)
	{
		getline(suborKand, myString);
	}

	counter = 0;
	while (getline(subor, myString))
	{
		counter++;
		if (counter > 4)
		{
			odstranDiakritiku(myString);
			//cout << myString << endl;
			zaznam = stringstream(myString);

			//Kod kraja
			getline(zaznam, myString, ';');

			//Nazov kraja
			getline(zaznam, myString, ';');
			nazovKraja = myString;

			//preskoc kod uzemneho obvodu
			getline(zaznam, myString, ';');

			//preskoc nazov uzemneho obvodu
			getline(zaznam, myString, ';');

			//kod okresu
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			kodOkresu = stoi(myString);

			//nazov okresu
			getline(zaznam, myString, ';');
			nazovOkresu = myString;

			//preskoc pocet okrskov
			getline(zaznam, myString, ';');

			//pocet zapisanych volicov
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetZapVolicov = stoi(myString);

			//pocet vydanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetVydObalok = stoi(myString);

			//ucast
			getline(zaznam, myString, ';');
			percUcastVolicov = stod(myString);

			//pocet odovzdanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetOdovzdanychObalok = stoi(myString);

			//ignorun dalsie zaznamy
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');

			Array<Kandidat*> *zoznamKandidatov2Kolo = new Array<Kandidat*>(2);
			for (unsigned int i = 0; i < zoznamKandidatov2Kolo->size(); i++)
			{
				getline(suborKand, myString);
				odstranDiakritiku(myString);
				//cout << myString << endl;

				zaznam = stringstream(myString);

				//preskoc kod kraja
				getline(zaznam, myString, ';');
				//presko nazov Kraja
				getline(zaznam, myString, ';');
				//presko kod uzemia
				getline(zaznam, myString, ';');
				//presko nazov uzemia
				getline(zaznam, myString, ';');
				//presko kod okresu
				getline(zaznam, myString, ';');
				//presko nazov okresu
				getline(zaznam, myString, ';');

				//poradie na hlas. listku
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				poradoveCislo = stoi(myString);

				//meno 
				getline(zaznam, myString, ';');
				menoKand = myString;

				//priezvisko
				getline(zaznam, myString, ';');
				priezviskoKand = myString;

				//pocet platnych hlasov
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				pocetPlatnychHlasov = stoi(myString);

				//preskoc ostatne
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');


				zoznamKandidatov2Kolo->operator[](i) = new Kandidat(poradoveCislo, menoKand, priezviskoKand, pocetPlatnychHlasov);
			}			

			Okres *okres = new Okres(nazovOkresu, pocetOdovzdanychObalok, pocetVydObalok, percUcastVolicov, pocetOdovzdanychObalok, zoznamKandidatov2Kolo, kodOkresu, nazovKraja);

			vysledkyOkresov2Kolo_->insert(kodOkresu, okres);
		}
	}

	subor.close();
}

void DataManazer::nacitajKraje()
{
	ifstream subor;
	ifstream suborKand;
	int counter = 0;
	string myString;
	stringstream zaznam;

	string	nazovKraja;
	int		kodKraja;
	int		pocetZapVolicov;
	int		pocetVydObalok;
	double	percUcastVolicov;
	int		pocetOdovzdanychObalok;

	string menoKand;
	string priezviskoKand;
	int pocetPlatnychHlasov;
	int poradoveCislo;

	subor.open("excel/suhrnneVysledkyKraje1Kolo.csv");
	suborKand.open("excel/pocetAPodielhlasovZaKraje1Kolo.csv");
	setlocale(LC_ALL, "");

	for (unsigned int i = 0; i < 8; i++)
	{
		getline(suborKand, myString);
	}

	while (getline(subor, myString))
	{
		counter++;
		if (counter > 5)
		{
			odstranDiakritiku(myString);
			//cout << myString << endl;
			zaznam = stringstream(myString);

			//Kod kraja
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			kodKraja = stoi(myString);

			//Nazov kraja
			getline(zaznam, myString, ';');
			nazovKraja = myString;

			//preskoc pocet okrskov
			getline(zaznam, myString, ';');

			//pocet zapisanych volicov
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetZapVolicov = stoi(myString);

			//pocet vydanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetVydObalok = stoi(myString);

			//ucast
			getline(zaznam, myString, ';');
			percUcastVolicov = stod(myString);

			//pocet odovzdanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetOdovzdanychObalok = stoi(myString);

			//ignorun dalsie zaznamy
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');

			Array<Kandidat*> *zoznamKandidatov1Kolo = new Array<Kandidat*>(15);
			
			for (unsigned int i = 0; i < zoznamKandidatov1Kolo->size(); i++)
			{

				getline(suborKand, myString);
				odstranDiakritiku(myString);
				//cout << myString << endl;

				zaznam = stringstream(myString);

				//preskoc kod kraja
				getline(zaznam, myString, ';');

				//presko nazov Kraja
				getline(zaznam, myString, ';');

				//poradie na hlas. listku
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				poradoveCislo = stoi(myString);

				//meno 
				getline(zaznam, myString, ';');
				menoKand = myString;

				//priezvisko
				getline(zaznam, myString, ';');
				priezviskoKand = myString;

				//pocet platnych hlasov
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				pocetPlatnychHlasov = stoi(myString);

				//preskoc ostatne
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');

				zoznamKandidatov1Kolo->operator[](i) = new Kandidat(poradoveCislo, menoKand, priezviskoKand, pocetPlatnychHlasov);
			}
		

			Kraj *kraj = new Kraj(nazovKraja,pocetZapVolicov,pocetVydObalok,percUcastVolicov,pocetOdovzdanychObalok, zoznamKandidatov1Kolo, kodKraja);

			vysledkyKrajov1Kolo_->insert(kodKraja,kraj);

		}

	}

	subor.close();
	suborKand.close();

	subor.open("excel/suhrnneVysledkyKraje2Kolo.csv");
	suborKand.open("excel/pocetAPodielhlasovZaKraje2Kolo.csv");
	counter = 0;

	for (unsigned int i = 0; i < 8; i++)
	{
		getline(suborKand, myString);
	}

	while (getline(subor, myString))
	{
		counter++;
		if (counter > 5)
		{
			odstranDiakritiku(myString);
			//cout << myString << endl;
			zaznam = stringstream(myString);

			//Kod kraja
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			kodKraja = stoi(myString);

			//Nazov kraja
			getline(zaznam, myString, ';');
			nazovKraja = myString;

			//preskoc pocet okrskov
			getline(zaznam, myString, ';');

			//pocet zapisanych volicov
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetZapVolicov = stoi(myString);

			//pocet vydanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetVydObalok = stoi(myString);

			//ucast
			getline(zaznam, myString, ';');
			percUcastVolicov = stod(myString);

			//pocet odovzdanych obalok
			getline(zaznam, myString, ';');
			myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
			pocetOdovzdanychObalok = stoi(myString);

			//ignorun dalsie zaznamy
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');
			getline(zaznam, myString, ';');
						
			Array<Kandidat*> *zoznamKandidatov2Kolo = new Array<Kandidat*>(2);
			for (unsigned int i = 0; i < zoznamKandidatov2Kolo->size(); i++)
			{
				getline(suborKand, myString);
				odstranDiakritiku(myString);
				//cout << myString << endl;

				zaznam = stringstream(myString);

				//preskoc kod kraja
				getline(zaznam, myString, ';');

				//presko nazov Kraja
				getline(zaznam, myString, ';');

				//poradie na hlas. listku
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				poradoveCislo = stoi(myString);

				//meno 
				getline(zaznam, myString, ';');
				menoKand = myString;

				//priezvisko
				getline(zaznam, myString, ';');
				priezviskoKand = myString;

				//pocet platnych hlasov
				getline(zaznam, myString, ';');
				myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
				pocetPlatnychHlasov = stoi(myString);

				//preskoc ostatne
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');
				getline(zaznam, myString, ';');

				zoznamKandidatov2Kolo->operator[](i) = new Kandidat(poradoveCislo, menoKand, priezviskoKand, pocetPlatnychHlasov);
			}			

			Kraj *kraj = new Kraj(nazovKraja, pocetZapVolicov, pocetVydObalok, percUcastVolicov, pocetOdovzdanychObalok, zoznamKandidatov2Kolo, kodKraja);

			vysledkyKrajov2Kolo_->insert(kodKraja, kraj);
		}
	}

	suborKand.close();
	subor.close();
}

void DataManazer::odstranDiakritiku(string & s)
{
	replace(s.begin(), s.end(), '·', 'a');
	replace(s.begin(), s.end(), '¡', 'A');
	replace(s.begin(), s.end(), 'Ë', 'c');
	replace(s.begin(), s.end(), '»', 'C');
	replace(s.begin(), s.end(), 'Ô', 'd');
	replace(s.begin(), s.end(), 'œ', 'D');
	replace(s.begin(), s.end(), 'È', 'e');
	replace(s.begin(), s.end(), '…', 'E');
	replace(s.begin(), s.end(), 'Ì', 'i');
	replace(s.begin(), s.end(), 'Õ', 'I');
	replace(s.begin(), s.end(), 'Â', 'l');
	replace(s.begin(), s.end(), 'æ', 'l');
	replace(s.begin(), s.end(), '≈', 'L');
	replace(s.begin(), s.end(), 'º', 'L');
	replace(s.begin(), s.end(), 'Ú', 'n');
	replace(s.begin(), s.end(), '“', 'N');
	replace(s.begin(), s.end(), 'Û', 'o');
	replace(s.begin(), s.end(), 'Ù', 'o');
	replace(s.begin(), s.end(), '”', 'O');
	replace(s.begin(), s.end(), 'ö', 's');
	replace(s.begin(), s.end(), 'ä', 'S');
	replace(s.begin(), s.end(), 'ù', 't');
	replace(s.begin(), s.end(), 'ç', 'T');
	replace(s.begin(), s.end(), '˙', 'u');
	replace(s.begin(), s.end(), '⁄', 'U');
	replace(s.begin(), s.end(), '˝', 'y');
	replace(s.begin(), s.end(), '›', 'Y');
	replace(s.begin(), s.end(), 'û', 'z');
	replace(s.begin(), s.end(), 'é', 'Z');
}