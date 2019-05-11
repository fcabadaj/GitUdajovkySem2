#pragma once
#include "structures/heap_monitor.h"
#include "DataManazer.h"

using namespace std;
using namespace structures;


void menu(int &c);

int main()
{
	initHeapMonitor();
	bool nacitane = false;

	DataManazer *dataMng = new DataManazer();

	cout << "Nacitavam data... \n";
	dataMng->nacitajData();
	nacitane = true;

	int choice = 155;

	menu(choice);

	while (choice != 0)
	{		
		switch (choice)
		{	
		case 0:
			
			return 0;
			break;

		case 1:
			dataMng->vypisInfOUzemnychJednotkach();
			break;
		case 2:
			dataMng->zoradenieUzemnychJednotiek();
			break;
		
		case 3:
			break;

		case 9:
			dataMng->test();
			break;

		case 10:
			if (!nacitane)
			{
				cout << "Nacitavam data... \n";
				dataMng->nacitajData();
				nacitane = true;
			}
			else
			{
				cout << "Data uz sa raz nacitali, nemozno ich nacitat znova kvoli vzniku duplicit! \n";
			}
			break;

		default:
			break;
		}
		menu(choice);
	}
	
	cout << "Vymazavam data... \n";
	delete dataMng;

	return 0;
}


void menu(int &c)
{
	cout << "======================================================= \n";
	cout << "stlac 0 - Ukoncenie programu \n";
	cout << "stlac 1 - Vypis informacie o Uzemnom celku \n";
	cout << "stlac 2 - Zoradenie uzemnych jednotiek \n";
	cout << "stlac 3 - Vypisanie vysledkov kandidata v uzemnej jednotke \n";
	cout << "stlac 9 - TEST \n";
	cout << "STLAC 10 - PRE NACITANIE UDAJOV ZO SUBOROV \n";
	cout << "======================================================= \n";
	cin >> c;
	system("CLS");
}