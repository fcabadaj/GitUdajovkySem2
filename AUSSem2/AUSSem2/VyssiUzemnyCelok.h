#pragma once
#include "UzemnyCelok.h"
#include "structures/heap_monitor.h"

class VyssiUzemnyCelok :
	public UzemnyCelok
{

public:
	VyssiUzemnyCelok(string nazov, int kod, DataKolo *dataKolo1, DataKolo *dataKolo2);
	virtual ~VyssiUzemnyCelok();
};

