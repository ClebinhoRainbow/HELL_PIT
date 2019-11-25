#pragma once

#include "Entidade.h"
#include "ListaEntidades.h"
#include "ListaObstaculos.h"
#include "ListaInimigos.h"
#include "ListaPlataformas.h"
#include "Dante.h"
#include "Ghierila.h"
#include "Besta_Infernal.h"
#include "Cao_Infernal.h"
#include "Pesadelo.h"
#include "Espinhos_Infernais.h"
#include "Machado_Infernal.h"
#include "MenuPause.h"
#include "GerenciadorGrafico.h"

class Fase :
	public Entidade
{
protected:
	ListaEntidades lEntidades;
	ListaInimigos lInimigos;
	ListaObstaculos lObstaculos;
	ListaPlataformas lPlataformas;

	MenuPause menuPause;

	vector<Jogador*> jogadores;

	int n_jogadores;
	int saiuDaFase;
	float deltaTime;
	sf::Clock clock;

public:
	Fase(int n_jog, const int id);
	~Fase();

	void executar(sf::RenderWindow& janela, sf::View& view);
	void checarJanelaAberta(sf::RenderWindow& janela, sf::View& view);
	void executarMenuPause(sf::RenderWindow& janela, sf::View& view);
	void checarColisoes();
	void limparFase();
	void atualizarEntidades(float deltaTime);
	void desenharEntidades(sf::RenderWindow& janela);
	
	virtual void InicializarTexturas(GerenciadorGrafico& gg) = 0;
	virtual void InicializarListas() = 0;
};

