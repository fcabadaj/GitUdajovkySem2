#pragma once
#include "VyssiUzemnyCelok.h"
#include "structures/heap_monitor.h"

class Kraj :
	public VyssiUzemnyCelok
{

private:

public:
	Kraj(string nazov, DataKolo *dataKolo1, DataKolo *dataKolo2, int kodKraja);
	~Kraj(); 
	void vypisSa(int kolo);
};

