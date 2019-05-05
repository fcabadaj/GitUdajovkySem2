#pragma once
#include "structures/heap_monitor.h"
#include "UzemnyCelok.h"
#include "VyssiUzemnyCelok.h"
#include <string>
#include "DataKolo.h"
#include <iostream>

using namespace std;

class Obec :
	public UzemnyCelok
{

private:
	string nazovOkresu_;
	string nazovKraja_;

public:
	Obec(string nazov, string nOkresu, string nKraja, int kodObce, DataKolo *dataKolo1, DataKolo *dataKolo2);
	~Obec();
	string getNazovOkresu() const { return nazovOkresu_; };
	string getNazovKraja() const { return nazovKraja_; };
	void vypisSa(int kolo);

	bool patriDoVUC(VyssiUzemnyCelok &vuc) const;
};

