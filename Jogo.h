#pragma once

#include <iostream>
using namespace std;

#include "MenuIniciar.h"
#include "GerenciadorGrafico.h"
#include "Entrada_Inferno.h"
#include "Profundezas_do_Inferno.h"


class Jogo
{
private:
	GerenciadorGrafico gerenciadorgrafico;

	MenuIniciar menuIniciar;

	Entrada_Inferno* fase1;
	Profundezas_do_Inferno* fase2;

	sf::RenderWindow janela;
	sf::View view;

public:
	Jogo();
	~Jogo();

	void executar();
};

