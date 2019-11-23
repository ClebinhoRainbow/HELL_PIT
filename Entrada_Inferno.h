#pragma once

#include "Fase.h"

class Entrada_Inferno :
	public Fase
{
public:
	Entrada_Inferno(GerenciadorGrafico& gerGrafico, int n_jogadores);
	~Entrada_Inferno();

	void InicializarTexturas(GerenciadorGrafico& gg);
	void InicializarListas();
};

