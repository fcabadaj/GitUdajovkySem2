#pragma once
#include "VyssiUzemnyCelok.h"
#include "structures/heap_monitor.h"

class Okres :
	public VyssiUzemnyCelok
{

private:
	string nazovKraja_;

public:
	Okres(string nazov, DataKolo *dataKolo1, DataKolo *dataKolo2, int kodOkresu, string nazovKraja);
	~Okres();
	void vypisSa(int kolo);
};

