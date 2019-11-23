#pragma once

#include "Fase.h"

class Profundezas_do_Inferno :
	public Fase
{
public:
	Profundezas_do_Inferno(GerenciadorGrafico& gerGrafico, int n_jogadores);
	~Profundezas_do_Inferno();

	void InicializarTexturas(GerenciadorGrafico& gg);
	void InicializarListas();
};

