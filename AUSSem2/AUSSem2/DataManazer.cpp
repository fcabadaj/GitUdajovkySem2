#include "DataManazer.h"
#include "structures/heap_monitor.h"
#include "KriteriumHlasyOdovzdane.h"
#include "KriteriumHlasyZiskane.h"
#include "KriteriumMeno.h"
#include "KriteriumNazov.h"
#include "KriteriumOdovzdaneObalky.h"
#include "KriteriumPrislusnostObce.h"
#include "KriteriumUcast.h"
#include "KriteriumVolici.h"
#include "KriteriumVydaneObalky.h"
#include "FilterMeno.h"
#include "FilterNazov.h"
#include "FilterPrislusnostObce.h"
#include "FilterUcast.h"
#include "FilterVolici.h"
#include "structures/table/sorting/quick_sort.h"
#include "structures/table/unsorted_sequence_table.h"

using namespace std;
using namespace structures;

DataManazer::DataManazer():
zoznamKandidatov1Kolo_(new Treap<int,Kandidat*>),
zoznamKandidatov2Kolo_(new Treap<int, Kandidat*>),
vysledkyObci_(new Treap<int,Obec*>),
vysledkyOkresov_(new Treap<int,Okres*>),
vysledkyKrajov_(new Treap<int, Kraj*>)
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

	for (TableItem<int, Obec*>* obec : *vysledkyObci_) {
		delete obec->accessData();
	}
	delete vysledkyObci_;

	for (TableItem<int, Okres*>* okres : *vysledkyOkresov_) {
		delete okres->accessData();
	}
	delete vysledkyOkresov_;

	for (TableItem<int, Kraj*>* kraj : *vysledkyKrajov_) {
		delete kraj->accessData();
	}
	delete vysledkyKrajov_;
}

void DataManazer::nacitajData()
{
	nacitajKandidatov();
	nacitajObce();
	nacitajOkresy();
	nacitajKraje();

	cout << "======================================================= \n";
	cout << "Udaje boli uspesne nacitane!! \n";
}

void DataManazer::nacitajObce()
{
	ifstream subor;
	ifstream subor2;
	ifstream suborKand;
	ifstream suborKand2;
	
	string myString;
	string myString2;
	stringstream zaznam;
	stringstream zaznam2;
	

	string	nazovObce;
	string	nazovOkresu;
	string	nazovKraja;
	int		kodObce;
	int		pocetZapVolicov;
	int		pocetVydObalok;
	double	percUcastVolicov;
	int		pocetOdovzdanychObalok;

	string menoKand;
	string priezviskoKand;
	int pocetPlatnychHlasov;
	int poradoveCislo;

	string	nazovObce2;
	string	nazovOkresu2;
	string	nazovKraja2;
	int		kodObce2;
	int		pocetZapVolicov2;
	int		pocetVydObalok2;
	double	percUcastVolicov2;
	int		pocetOdovzdanychObalok2;

	string menoKand2;
	string priezviskoKand2;
	int pocetPlatnychHlasov2;
	int poradoveCislo2;

	subor.open("excel/suhrnneVysledkyObce1Kolo.csv");
	suborKand.open("excel/pocetAPodielhlasovZaObce1Kolo.csv");
	subor2.open("excel/suhrnneVysledkyObce2Kolo.csv");
	suborKand2.open("excel/pocetAPodielhlasovZaObce2Kolo.csv");
	setlocale(LC_ALL, "");
	
	for (unsigned int i = 0; i < 4; i++)
	{
		getline(suborKand, myString);
	}

	for (unsigned int i = 0; i < 4; i++)
	{
		getline(suborKand2, myString);
	}

	for (unsigned int i = 0; i < 5; i++)
	{
		getline(subor2, myString);
	}

	for (unsigned int i = 0; i < 5; i++)
	{
		getline(subor, myString);
	}

	while (getline(subor, myString))
	{	
		Array<Kandidat*> *zoznamKandidatov1Kolo = new Array<Kandidat*>(15);
		Array<Kandidat*> *zoznamKandidatov2Kolo = new Array<Kandidat*>(2);
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
		replace(myString.begin(), myString.end(), ',', '.');
		percUcastVolicov = stod(myString);

		//pocet odovzdanych obalok
		getline(zaznam, myString, ';');
		myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
		pocetOdovzdanychObalok = stoi(myString);


		getline(zaznam, myString, ';');
		getline(zaznam, myString, ';');
		getline(zaznam, myString, ';');
		getline(zaznam, myString, ';');

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

		getline(subor2, myString2);

		odstranDiakritiku(myString2);
		//cout << myString << endl;
		zaznam2 = stringstream(myString2);

		//Kod kraja
		getline(zaznam2, myString2, ';');

		//Nazov kraja
		getline(zaznam2, myString2, ';');
		nazovKraja2 = myString2;

		//preskoc kod uzemneho obvodu
		getline(zaznam2, myString2, ';');

		//preskoc nazov uzemneho obvodu
		getline(zaznam2, myString2, ';');

		//preskoc kod okresu
		getline(zaznam2, myString2, ';');

		//nazov okresu
		getline(zaznam2, myString2, ';');
		nazovOkresu2 = myString2;

		//kod obce
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		kodObce2 = stoi(myString2);

		// nazov obce
		getline(zaznam2, myString2, ';');
		nazovObce2 = myString2;

		//preskoc pocet okrskov
		getline(zaznam2, myString2, ';');

		//pocet zapisanych volicov
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		pocetZapVolicov2 = stoi(myString2);

		//pocet vydanych obalok
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		pocetVydObalok2 = stoi(myString2);

		//ucast
		getline(zaznam2, myString2, ';');
		replace(myString2.begin(), myString2.end(), ',', '.');
		percUcastVolicov2 = stod(myString2);

		//pocet odovzdanych obalok
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		pocetOdovzdanychObalok2 = stoi(myString2);

		//ignorun dalsie zaznamy
		getline(zaznam2, myString2, ';');
		getline(zaznam2, myString2, ';');
		getline(zaznam2, myString2, ';');
		getline(zaznam2, myString2, ';');

			
		for (unsigned int i = 0; i < zoznamKandidatov2Kolo->size(); i++)
		{
			getline(suborKand2, myString2);
			odstranDiakritiku(myString2);
			//cout << myString << endl;

			zaznam2 = stringstream(myString2);

			//preskoc kod kraja
			getline(zaznam2, myString2, ';');
			//presko nazov Kraja
			getline(zaznam2, myString2, ';');
			//presko kod uzemia
			getline(zaznam2, myString2, ';');
			//presko nazov uzemia
			getline(zaznam2, myString2, ';');
			//presko kod okresu
			getline(zaznam2, myString2, ';');
			//presko nazov okresu
			getline(zaznam2, myString2, ';');
			//presko kod obce
			getline(zaznam2, myString2, ';');
			//presko nazov obce
			getline(zaznam2, myString2, ';');

			//poradie na hlas. listku
			getline(zaznam2, myString2, ';');
			myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
			poradoveCislo2 = stoi(myString2);

			//meno 
			getline(zaznam2, myString2, ';');
			menoKand2 = myString2;

			//priezvisko
			getline(zaznam2, myString2, ';');
			priezviskoKand2 = myString2;

			//pocet platnych hlasov
			getline(zaznam2, myString2, ';');
			myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
			pocetPlatnychHlasov2 = stoi(myString2);

			//preskoc ostatne
			getline(zaznam2, myString2, ';');

			zoznamKandidatov2Kolo->operator[](i) = new Kandidat(poradoveCislo2, menoKand2, priezviskoKand2, pocetPlatnychHlasov2);
		}
							
		DataKolo *dataKolo2 = new DataKolo(pocetZapVolicov2, pocetVydObalok2, percUcastVolicov2, pocetOdovzdanychObalok2, zoznamKandidatov2Kolo);
		DataKolo *dataKolo1 = new DataKolo(pocetZapVolicov, pocetVydObalok, percUcastVolicov, pocetOdovzdanychObalok, zoznamKandidatov1Kolo);
		Obec *obec = new Obec(nazovObce, nazovOkresu, nazovKraja, kodObce, dataKolo1, dataKolo2);
		vysledkyObci_->insert(kodObce, obec);
	}

	subor.close();
	suborKand.close();
	subor2.close();
	suborKand2.close();
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
	int counter = 0;
	ifstream subor;
	ifstream suborKand;
	
	string myString;
	stringstream zaznam;	

	string	nazovOkresu;
	string	nazovKraja;
	int		kodOkresu;
	int		pocetZapVolicov;
	int		pocetVydObalok;
	double	percUcastVolicov;
	int		pocetOdovzdanychObalok;
	
	string menoKand;
	string priezviskoKand;
	int pocetPlatnychHlasov;
	int poradoveCislo;


	ifstream subor2;
	ifstream suborKand2;

	string myString2;
	stringstream zaznam2;

	string	nazovOkresu2;
	string	nazovKraja2;
	int		kodOkresu2;
	int		pocetZapVolicov2;
	int		pocetVydObalok2;
	double	percUcastVolicov2;
	int		pocetOdovzdanychObalok2;

	string menoKand2;
	string priezviskoKand2;
	int pocetPlatnychHlasov2;
	int poradoveCislo2;

	subor.open("excel/suhrnneVysledkyOkresy1Kolo.csv");
	suborKand2.open("excel/pocetAPodielhlasovZaOkresy2Kolo.csv");
	subor2.open("excel/suhrnneVysledkyOkresy2Kolo.csv");
	suborKand.open("excel/pocetAPodielhlasovZaOkresy1Kolo.csv");

	setlocale(LC_ALL, "");

	for (unsigned int i = 0; i < 8; i++)
	{
		getline(suborKand, myString);
	}

	for (unsigned int i = 0; i < 8; i++)
	{
		getline(suborKand2, myString);
	}

	for (unsigned int i = 0; i < 4; i++)
	{
		getline(subor2, myString);
	}

	for (unsigned int i = 0; i < 4; i++)
	{
		getline(subor, myString);
	}

	while (getline(subor, myString))
	{
		Array<Kandidat*> *zoznamKandidatov2Kolo = new Array<Kandidat*>(2);
		Array<Kandidat*> *zoznamKandidatov1Kolo = new Array<Kandidat*>(15);

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
		replace(myString.begin(), myString.end(), ',', '.');
		percUcastVolicov = stod(myString);

		//pocet odovzdanych obalok
		getline(zaznam, myString, ';');
		myString.erase(remove_if(myString.begin(), myString.end(), isspace), myString.end());
		pocetOdovzdanychObalok = stoi(myString);

		//ignorun dalsie zaznamy
		getline(zaznam, myString, ';');
		getline(zaznam, myString, ';');
		getline(zaznam, myString, ';');			
			
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

		getline(subor2, myString2);
		odstranDiakritiku(myString2);
		//cout << myString << endl;
		zaznam2 = stringstream(myString2);

		//Kod kraja
		getline(zaznam2, myString2, ';');

		//Nazov kraja
		getline(zaznam2, myString2, ';');
		nazovKraja2 = myString2;

		//preskoc kod uzemneho obvodu
		getline(zaznam2, myString2, ';');

		//preskoc nazov uzemneho obvodu
		getline(zaznam2, myString2, ';');

		//kod okresu
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		kodOkresu2 = stoi(myString2);

		//nazov okresu
		getline(zaznam2, myString2, ';');
		nazovOkresu2 = myString2;

		//preskoc pocet okrskov
		getline(zaznam2, myString2, ';');

		//pocet zapisanych volicov
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		pocetZapVolicov2 = stoi(myString2);

		//pocet vydanych obalok
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		pocetVydObalok2 = stoi(myString2);

		//ucast
		getline(zaznam2, myString2, ';');
		replace(myString2.begin(), myString2.end(), ',', '.');
		percUcastVolicov2 = stod(myString2);

		//pocet odovzdanych obalok
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		pocetOdovzdanychObalok2 = stoi(myString2);

		//ignorun dalsie zaznamy
		getline(zaznam2, myString2, ';');
		getline(zaznam2, myString2, ';');
		getline(zaznam2, myString2, ';');


		for (unsigned int i = 0; i < zoznamKandidatov2Kolo->size(); i++)
		{
			getline(suborKand2, myString2);
			odstranDiakritiku(myString2);
			//cout << myString << endl;

			zaznam2 = stringstream(myString2);

			//preskoc kod kraja
			getline(zaznam2, myString2, ';');
			//presko nazov Kraja
			getline(zaznam2, myString2, ';');
			//presko kod uzemia
			getline(zaznam2, myString2, ';');
			//presko nazov uzemia
			getline(zaznam2, myString2, ';');
			//presko kod okresu
			getline(zaznam2, myString2, ';');
			//presko nazov okresu
			getline(zaznam2, myString2, ';');

			//poradie na hlas. listku
			getline(zaznam2, myString2, ';');
			myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
			poradoveCislo2 = stoi(myString2);

			//meno 
			getline(zaznam2, myString2, ';');
			menoKand2 = myString2;

			//priezvisko
			getline(zaznam2, myString2, ';');
			priezviskoKand2 = myString2;

			//pocet platnych hlasov
			getline(zaznam2, myString2, ';');
			myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
			pocetPlatnychHlasov2 = stoi(myString2);

			//preskoc ostatne
			getline(zaznam2, myString2, ';');
			getline(zaznam2, myString2, ';');
			getline(zaznam2, myString2, ';');
			getline(zaznam2, myString2, ';');
			getline(zaznam2, myString2, ';');
			getline(zaznam2, myString2, ';');
			
			zoznamKandidatov2Kolo->operator[](i) = new Kandidat(poradoveCislo2, menoKand2, priezviskoKand2, pocetPlatnychHlasov2);
		}

		DataKolo *dataKolo1 = new DataKolo(pocetZapVolicov, pocetVydObalok, percUcastVolicov, pocetOdovzdanychObalok, zoznamKandidatov1Kolo);
		DataKolo *dataKolo2 = new DataKolo(pocetZapVolicov2, pocetVydObalok2, percUcastVolicov2, pocetOdovzdanychObalok2, zoznamKandidatov2Kolo);

		Okres *okres = new Okres(nazovOkresu, dataKolo1, dataKolo2, kodOkresu, nazovKraja);
		vysledkyOkresov_->insert(kodOkresu, okres);
	}
	
	subor.close();
	subor2.close();
	suborKand.close();
	suborKand2.close();
}

void DataManazer::nacitajKraje()
{
	int counter = 0;
	ifstream subor;
	ifstream suborKand;	
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

	ifstream subor2;
	ifstream suborKand2;
	string myString2;
	stringstream zaznam2;

	string	nazovKraja2;
	int		kodKraja2;
	int		pocetZapVolicov2;
	int		pocetVydObalok2;
	double	percUcastVolicov2;
	int		pocetOdovzdanychObalok2;

	string menoKand2;
	string priezviskoKand2;
	int pocetPlatnychHlasov2;
	int poradoveCislo2;

	subor.open("excel/suhrnneVysledkyKraje1Kolo.csv");
	suborKand.open("excel/pocetAPodielhlasovZaKraje1Kolo.csv");
	subor2.open("excel/suhrnneVysledkyKraje2Kolo.csv");
	suborKand2.open("excel/pocetAPodielhlasovZaKraje2Kolo.csv");
	setlocale(LC_ALL, "");

	for (unsigned int i = 0; i < 5; i++)
	{
		getline(subor, myString);
	}

	for (unsigned int i = 0; i < 5; i++)
	{
		getline(subor2, myString);
	}

	for (unsigned int i = 0; i < 8; i++)
	{
		getline(suborKand, myString);
	}

	for (unsigned int i = 0; i < 8; i++)
	{
		getline(suborKand2, myString);
	}

	while (getline(subor, myString))
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
		replace(myString.begin(), myString.end(), ',', '.');
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


		//druhe kolo
		getline(subor2, myString2);
		odstranDiakritiku(myString2);
		//cout << myString << endl;
		zaznam2 = stringstream(myString2);

		//Kod kraja
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		kodKraja2 = stoi(myString2);

		//Nazov kraja
		getline(zaznam2, myString2, ';');
		nazovKraja2 = myString2;

		//preskoc pocet okrskov
		getline(zaznam2, myString2, ';');

		//pocet zapisanych volicov
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		pocetZapVolicov2 = stoi(myString2);

		//pocet vydanych obalok
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		pocetVydObalok2 = stoi(myString2);

		//ucast
		getline(zaznam2, myString2, ';');
		replace(myString2.begin(), myString2.end(), ',', '.');
		percUcastVolicov2 = stod(myString2);

		//pocet odovzdanych obalok
		getline(zaznam2, myString2, ';');
		myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
		pocetOdovzdanychObalok2 = stoi(myString2);

		//ignorun dalsie zaznamy
		getline(zaznam2, myString2, ';');
		getline(zaznam2, myString2, ';');
		getline(zaznam2, myString2, ';');

		Array<Kandidat*> *zoznamKandidatov2Kolo = new Array<Kandidat*>(2);
		for (unsigned int i = 0; i < zoznamKandidatov2Kolo->size(); i++)
		{
			getline(suborKand2, myString2);
			odstranDiakritiku(myString2);
			//cout << myString << endl;

			zaznam2 = stringstream(myString2);

			//preskoc kod kraja
			getline(zaznam2, myString2, ';');

			//presko nazov Kraja
			getline(zaznam2, myString2, ';');

			//poradie na hlas. listku
			getline(zaznam2, myString2, ';');
			myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
			poradoveCislo2 = stoi(myString2);

			//meno 
			getline(zaznam2, myString2, ';');
			menoKand2 = myString2;

			//priezvisko
			getline(zaznam2, myString2, ';');
			priezviskoKand2 = myString2;

			//pocet platnych hlasov
			getline(zaznam2, myString2, ';');
			myString2.erase(remove_if(myString2.begin(), myString2.end(), isspace), myString2.end());
			pocetPlatnychHlasov2 = stoi(myString2);

			//preskoc ostatne
			getline(zaznam2, myString2, ';');
			getline(zaznam2, myString2, ';');
			getline(zaznam2, myString2, ';');
			getline(zaznam2, myString2, ';');
			getline(zaznam2, myString2, ';');
			getline(zaznam2, myString2, ';');

			zoznamKandidatov2Kolo->operator[](i) = new Kandidat(poradoveCislo2, menoKand2, priezviskoKand2, pocetPlatnychHlasov2);
		}

		DataKolo *dataKolo1 = new DataKolo(pocetZapVolicov, pocetVydObalok, percUcastVolicov, pocetOdovzdanychObalok, zoznamKandidatov1Kolo);
		DataKolo *dataKolo2 = new DataKolo(pocetZapVolicov2, pocetVydObalok2, percUcastVolicov2, pocetOdovzdanychObalok2, zoznamKandidatov2Kolo);

		Kraj *kraj = new Kraj(nazovKraja, dataKolo1, dataKolo2, kodKraja);
		vysledkyKrajov_->insert(kodKraja, kraj);
	}

	subor.close();
	suborKand.close();
	suborKand2.close();
	subor2.close();
}

void DataManazer::odstranDiakritiku(string & s)
{
	replace(s.begin(), s.end(), '‰', 'a');
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
	replace(s.begin(), s.end(), ',', '.');
}

void DataManazer::vypisInfOUzemnychJednotkach()
{
	system("CLS");
	int i = 0;
	int x = 0;
	int kolo = 0;

	string nazovObce = "";

	int voliciOd = 0;
	int voliciDo = 0;

	double ucastOd = 0.0;
	double ucastDo = 0.0;

	FilterNazov * filNaz = new FilterNazov(nazovObce);
	FilterVolici * filVol = new FilterVolici(voliciOd, voliciDo);
	FilterUcast * filUcast = new FilterUcast(ucastOd, ucastDo);

	KriteriumNazov * kritNaz = new KriteriumNazov();
	KriteriumVolici * kritVol = new KriteriumVolici(1);
	KriteriumUcast * kritUcast = new KriteriumUcast(1);

	cout << "======================================================= \n";
	cout << "stlac 0 - PRE NAVRAT DO HLAVNEHO MENU \n";
	cout << "stlac 1 - Filter Nazov \n";
	cout << "stlac 2 - Filter Volici \n";
	cout << "stlac 3 - Filter Ucast \n";
	cout << "======================================================= \n";

	cin >> i;

	switch (i)
	{
	case 1:

		zobrazMenuInfOUzJedn();
		cin >> x;

		switch (x)
		{
		case 1:
			cout << "======================================================= \n";
			cout << " Zadaj nazov obce \n";
			getline(cin >> ws, nazovObce);
			filNaz->setAlpha(nazovObce);
			
			kolo = vyberKolo();

			for each (TableItem<int, Obec*> *obec in *vysledkyObci_)
			{
				if (filNaz->evaluate(*obec->accessData(), *kritNaz))
				{					
					obec->accessData()->vypisSa(kolo);
				}
			}

			break;
		case 2:
			cout << "======================================================= \n";
			cout << " Zadaj nazov okresu \n";
			getline(cin >> ws, nazovObce);
			filNaz->setAlpha(nazovObce);

			kolo = vyberKolo();

			for each (TableItem<int, Okres*> *okres in *vysledkyOkresov_)
			{
				if (filNaz->evaluate(*okres->accessData(), *kritNaz))
				{
					okres->accessData()->vypisSa(kolo);
				}
			}

			break;
		case 3:
			cout << "======================================================= \n";
			cout << " Zadaj nazov kraja \n";
			getline(cin >> ws, nazovObce);
			filNaz->setAlpha(nazovObce);

			kolo = vyberKolo();

			for each (TableItem<int, Kraj*> *kraj in *vysledkyKrajov_)
			{
				if (filNaz->evaluate(*kraj->accessData(), *kritNaz))
				{
					kraj->accessData()->vypisSa(kolo);
				}
			}

			break;
		default:
			break;
		}

		break;
	case 2:

		zobrazMenuInfOUzJedn();
		cin >> x;

		switch (x)
		{
		case 1:
			cout << "======================================================= \n";
			cout << " Zadaj pocet volicov pre obec OD: \n";
			cin >> voliciOd;
			filVol->setAlpha(voliciOd);

			cout << " Zadaj pocet volicov pre obec DO: \n";
			cin >> voliciDo;
			filVol->setBeta(voliciDo);

			kolo = vyberKolo();

			for each (TableItem<int, Obec*> *obec in *vysledkyObci_)
			{
				if (filVol->evaluate(*obec->accessData(), *kritVol))
				{
					obec->accessData()->vypisSa(kolo);
				}
			}

			break;
		case 2:
			cout << "======================================================= \n";
			cout << " Zadaj pocet volicov pre okres OD: \n";
			cin >> voliciOd;
			filVol->setAlpha(voliciOd);

			cout << " Zadaj pocet volicov pre okres DO: \n";
			cin >> voliciDo;
			filVol->setBeta(voliciDo);

			kolo = vyberKolo();

			for each (TableItem<int, Okres*> *okres in *vysledkyOkresov_)
			{
				if (filVol->evaluate(*okres->accessData(), *kritVol))
				{
					okres->accessData()->vypisSa(kolo);
				}
			}

			break;
		case 3:
			cout << "======================================================= \n";
			cout << " Zadaj pocet volicov pre kraj OD: \n";
			cin >> voliciOd;
			filVol->setAlpha(voliciOd);

			cout << " Zadaj pocet volicov pre kraj DO: \n";
			cin >> voliciDo;
			filVol->setBeta(voliciDo);

			kolo = vyberKolo();

			for each (TableItem<int, Kraj*> *kraj in *vysledkyKrajov_)
			{
				if (filVol->evaluate(*kraj->accessData(), *kritVol))
				{
					kraj->accessData()->vypisSa(kolo);
				}
			}

			break;
		default:
			break;
		}

		filNaz->setAlpha(nazovObce);
		
		break;
	case 3:
		zobrazMenuInfOUzJedn();
		cin >> x;

		switch (x)
		{
		case 1:
			cout << "======================================================= \n";
			cout << " Zadaj ucast volicov pre obec OD: \n";
			cin >> voliciOd;
			filUcast->setAlpha(voliciOd);

			cout << " Zadaj ucast volicov pre obec DO: \n";
			cin >> voliciDo;
			filUcast->setBeta(voliciDo);

			kolo = vyberKolo();

			for each (TableItem<int, Obec*> *obec in *vysledkyObci_)
			{
				if (filUcast->evaluate(*obec->accessData(), *kritUcast))
				{
					obec->accessData()->vypisSa(kolo);
				}
			}


			break;
		case 2:
			cout << "======================================================= \n";
			cout << " Zadaj ucast volicov pre okres OD: \n";
			cin >> voliciOd;
			filUcast->setAlpha(voliciOd);

			cout << " Zadaj ucast volicov pre okres DO: \n";
			cin >> voliciDo;
			filUcast->setBeta(voliciDo);

			kolo = vyberKolo();

			for each (TableItem<int, Okres*> *okres in *vysledkyOkresov_)
			{
				if (filUcast->evaluate(*okres->accessData(), *kritUcast))
				{
					okres->accessData()->vypisSa(kolo);
				}
			}

			break;
		case 3:
			cout << "======================================================= \n";
			cout << " Zadaj ucast volicov pre kraj OD: \n";
			cin >> voliciOd;
			filUcast->setAlpha(voliciOd);

			cout << " Zadaj ucast volicov pre kraj DO: \n";
			cin >> voliciDo;
			filUcast->setBeta(voliciDo);

			kolo = vyberKolo();

			for each (TableItem<int, Kraj*> *kraj in *vysledkyKrajov_)
			{
				if (filUcast->evaluate(*kraj->accessData(), *kritUcast))
				{
					kraj->accessData()->vypisSa(kolo);
				}
			}

			break;
		}
		break;
	case 0:
		break;
	}

	delete filNaz;
	delete filVol;
	delete filUcast;
	delete kritNaz;
	delete kritVol;
	delete kritUcast;
}

void DataManazer::zoradenieUzemnychJednotiek()
{
	system("CLS");
	int i = 0;
	int kolo = 0;
	string nazovObce = "";
	int ucastOd = 0;
	int ucastDo = 0;
	int voliciOd = 0;
	int voliciDo = 0;
	string prislusnyVUC = "";
	VyssiUzemnyCelok *vuc = (*vysledkyKrajov_)[1];
	char c = ' ';

	FilterUcast *filterUcast = new FilterUcast(0, 0);
	FilterPrislusnostObce *filterPrislusnost = new FilterPrislusnostObce(false);
	FilterVolici *filterVolici = new FilterVolici(0, 0);
	KriteriumNazov *kNazov = new KriteriumNazov();
	KriteriumVolici *kVolici = new KriteriumVolici(1);
	KriteriumUcast *kUcast = new KriteriumUcast(1);
	KriteriumPrislusnostObce *kPrislusnost = new KriteriumPrislusnostObce(vuc);

	UnsortedSequenceTable<int, UzemnyCelok*> *unsortedTable = new UnsortedSequenceTable<int, UzemnyCelok*>();
	UnsortedSequenceTable<int, Obec*> *pomTab = new UnsortedSequenceTable<int, Obec*>();

	cout << "======================================================= \n";
	cout << "stlac 0 - PRE NAVRAT DO HLAVNEHO MENU \n";
	cout << "stlac 1 - Kriterium Nazov \n";
	cout << "stlac 2 - Kriterium Volici \n";
	cout << "stlac 3 - Kriterium Ucast \n";
	cout << "======================================================= \n";

	cin >> i;

	switch (i)
	{
	case 1:

		cout << "======================================================= \n";
		cout << "PRE FILTER UCAST \n";
		cout << " Zadaj ucast volicov pre obec OD: \n";
		cin >> ucastOd;
		filterUcast->setAlpha(ucastOd);

		cout << " Zadaj ucast volicov pre obec DO: \n";
		cin >> ucastDo;
		filterUcast->setBeta(ucastDo);

		cout << "======================================================= \n";
		cout << "PRE FILTER PRISLUSNOST OBCE \n";
		cout << "Zadaj nazov Vyssieho uzemneho celku \n";
		getline(cin >> ws, prislusnyVUC);

		kolo = vyberKolo();

		for (TableItem<int,Okres*> *okres : *vysledkyOkresov_)
		{
			if (okres->accessData()->getNazov() == prislusnyVUC)
			{
				vuc = okres->accessData();
			}
		}

		for (TableItem<int, Kraj*> *kraj : *vysledkyKrajov_)
		{
			if (kraj->accessData()->getNazov() == prislusnyVUC)
			{
				vuc = kraj->accessData();
			}
		}

		kPrislusnost->setVuc(vuc);
		filterPrislusnost->setAlpha(vuc);
		kUcast->setKolo(kolo);

		for (TableItem<int, Obec*> *obec : *vysledkyObci_)
		{
			if (filterPrislusnost->evaluate(*obec->accessData(), *kPrislusnost) && filterUcast->evaluate(*obec->accessData(), *kUcast))
			{
				unsortedTable->insert(obec->getKey(),obec->accessData());
			}
		}

		cout << "======================================================= \n";
		cout << "Chces zoradit vzostupne(ascending)? (y/n) \n";
		cin >> c;
		if (c == 'y')
			this->usporiadajTabulku(*unsortedTable, *kNazov, false);
		else
			this->usporiadajTabulku(*unsortedTable, *kNazov, true);

		for (TableItem<int, UzemnyCelok*> *item : *unsortedTable)
		{
			pomTab->insert(item->getKey(), dynamic_cast<Obec*>(item->accessData()));
		}

		for (TableItem<int, Obec*> *obec : *pomTab)
		{
			obec->accessData()->vypisSa(kolo);
		}

		break;
	case 2:

		cout << "======================================================= \n";
		cout << "PRE FILTER UCAST \n";
		cout << "Zadaj percentualnu ucast volicov pre obec OD: \n";
		cin >> ucastOd;
		filterUcast->setAlpha(ucastOd);

		cout << "Zadaj percentualnu ucast volicov pre obec DO: \n";
		cin >> ucastDo;
		filterUcast->setBeta(ucastDo);

		cout << "======================================================= \n";
		cout << "PRE FILTER PRISLUSNOST OBCE \n";
		cout << "Zadaj nazov Vyssieho uzemneho celku \n";
		getline(cin >> ws, prislusnyVUC);

		kolo = vyberKolo();

		for (TableItem<int, Okres*> *okres : *vysledkyOkresov_)
		{
			if (okres->accessData()->getNazov() == prislusnyVUC)
				vuc = okres->accessData();
		}

		for (TableItem<int, Kraj*> *kraj : *vysledkyKrajov_)
		{
			if (kraj->accessData()->getNazov() == prislusnyVUC)
				vuc = kraj->accessData();
		}

		kPrislusnost->setVuc(vuc);
		filterPrislusnost->setAlpha(vuc);
		kVolici->setKolo(kolo);

		for (TableItem<int, Obec*> *obec : *vysledkyObci_)
		{
			if (filterPrislusnost->evaluate(*obec->accessData(), *kPrislusnost) && filterUcast->evaluate(*obec->accessData(), *kUcast))
			{
				unsortedTable->insert(obec->getKey(), obec->accessData());
			}
		}

		cout << "======================================================= \n";
		cout << "Chces zoradit vzostupne(ascending)? (y/n) \n";
		cin >> c;
		if (c == 'y')
			this->usporiadajTabulku(*unsortedTable, *kVolici, false);
		else
			this->usporiadajTabulku(*unsortedTable, *kVolici, true);

		for (TableItem<int, UzemnyCelok*> *item : *unsortedTable)
		{
			pomTab->insert(item->getKey(), dynamic_cast<Obec*>(item->accessData()));
		}

		for (TableItem<int, Obec*> *obec : *pomTab)
		{
			obec->accessData()->vypisSa(kolo);
		}

		break;
	case 3:

		cout << "======================================================= \n";
		cout << "PRE FILTER UCAST \n";
		cout << "Zadaj percentualnu ucast volicov pre obec OD: \n";
		cin >> ucastOd;
		filterUcast->setAlpha(ucastOd);

		cout << "Zadaj percentualnu ucast volicov pre obec DO: \n";
		cin >> ucastDo;
		filterUcast->setBeta(ucastDo);

		cout << "======================================================= \n";
		cout << "PRE FILTER PRISLUSNOST OBCE \n";
		cout << "Zadaj nazov Vyssieho uzemneho celku \n";
		getline(cin >> ws, prislusnyVUC);

		kolo = vyberKolo();

		for (TableItem<int, Okres*> *okres : *vysledkyOkresov_)
		{
			if (okres->accessData()->getNazov() == prislusnyVUC)
				vuc = okres->accessData();
		}

		for (TableItem<int, Kraj*> *kraj : *vysledkyKrajov_)
		{
			if (kraj->accessData()->getNazov() == prislusnyVUC)
				vuc = kraj->accessData();
		}

		kPrislusnost->setVuc(vuc);
		filterPrislusnost->setAlpha(vuc);
		kVolici->setKolo(kolo);

		for (TableItem<int, Obec*> *obec : *vysledkyObci_)
		{
			if (filterPrislusnost->evaluate(*obec->accessData(), *kPrislusnost) && filterUcast->evaluate(*obec->accessData(), *kUcast))
			{
				unsortedTable->insert(obec->getKey(), obec->accessData());
			}
		}

		cout << "======================================================= \n";
		cout << "Chces zoradit vzostupne(ascending)? (y/n) \n";
		cin >> c;
		if (c == 'y')
			this->usporiadajTabulku(*unsortedTable, *kUcast, false);
		else
			this->usporiadajTabulku(*unsortedTable, *kUcast, true);

		for (TableItem<int, UzemnyCelok*> *item : *unsortedTable)
		{
			pomTab->insert(item->getKey(), dynamic_cast<Obec*>(item->accessData()));
		}

		for (TableItem<int, Obec*> *obec : *pomTab)
		{
			obec->accessData()->vypisSa(kolo);
		}

		break;
	default:
		break;
	}

	delete filterUcast;
	delete filterPrislusnost;
	delete filterVolici;
	delete kNazov;
	delete kVolici;
	delete kUcast;
	delete kPrislusnost;
	delete unsortedTable;
	delete pomTab;

}

void DataManazer::test()
{
	KriteriumNazov *knazov = new KriteriumNazov();
	KriteriumUcast *kucast = new KriteriumUcast(1);
	UnsortedSequenceTable<int, UzemnyCelok*> *unsortedTable = new UnsortedSequenceTable<int, UzemnyCelok*>();

	for (TableItem<int, Obec*> *obec : *vysledkyObci_)
	{
		unsortedTable->insert(obec->getKey(), obec->accessData());
	}


	this->usporiadajTabulku(*unsortedTable, *knazov, false);

	for each (TableItem<int, UzemnyCelok*> *obec in *unsortedTable)
	{
		cout << obec->accessData()->getNazov() << endl;
	}

	delete knazov;
	delete kucast;
	delete unsortedTable;
}

void DataManazer::zobrazMenuInfOUzJedn()
{
	system("CLS");

	cout << "======================================================= \n";
	cout << "stlac 1 - Informacie o obciach \n";
	cout << "stlac 2 - Informacie o okresoch\n";
	cout << "stlac 3 - Informacie o krajoch\n";
	cout << "======================================================= \n";
}

int DataManazer::vyberKolo()
{
	int i = 0;
	system("CLS");
	cout << "======================================================= \n";
	cout << "Zadaj kolo pre ktore chces vypisat vysledky \n";
	cin >> i;
	return i;
}

