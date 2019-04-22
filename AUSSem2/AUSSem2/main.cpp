#pragma once
#include "DataManazer.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Obec.h"
#include "structures/table/treap.h"

using namespace std;
using namespace structures;

int main()
{
	initHeapMonitor();
	DataManazer *dataMng = new DataManazer();

	dataMng->nacitajData();
	
	system("PAUSE");

	delete dataMng;

	return 0;
}