#include "Profundezas_do_Inferno.h"

Profundezas_do_Inferno::Profundezas_do_Inferno(GerenciadorGrafico& gerGrafico, int n_jogadores):
	Fase(n_jogadores, 11)
{
	gerGrafico.set2BackgroundTexture(corpo);
	InicializarListas();
	InicializarTexturas(gerGrafico);
}

Profundezas_do_Inferno::~Profundezas_do_Inferno()
{
}

void Profundezas_do_Inferno::InicializarListas()
{
	sf::Vector2f coordenadas = sf::Vector2f(-200.0f, 500.0f);

	int i;
	int n_InimCao = rand() % 6 + 10;
	int n_InimBesta = rand() % 6 + 10;
	int n_Machado = rand() % 6 + 10;
	int n_Pesadelo = rand() % 6 + 2;

	for (i = 0; i < 50; i++)
	{
		lPlataformas.incluirPlataforma(new Plataforma(coordenadas));
		lEntidades.incluirEntidade(lPlataformas.pegarPlataforma(i));
		coordenadas.x += 75.0f;
	}
	
	coordenadas = sf::Vector2f(-200.0f, 200.0f);
	
	for (i; i < 100; i++)
	{
		lPlataformas.incluirPlataforma(new Plataforma(coordenadas));
		lEntidades.incluirEntidade(lPlataformas.pegarPlataforma(i));
		coordenadas.x += 75.0f;
	}
	
	coordenadas = sf::Vector2f(2000.0f, 450.0f);

	for (i = 0; i < n_InimBesta; i++)
	{
		lInimigos.incluirInimigo(new Besta_Infernal(coordenadas));
		lEntidades.incluirEntidade(lInimigos.pegarInimigo(i));
		coordenadas.x -= 1900.0f / n_InimBesta;
	}
	
	coordenadas = sf::Vector2f(2000.0f, 150.0f);

	for (i; i < n_InimBesta + n_InimCao; i++)
	{
		lInimigos.incluirInimigo(new Cao_Infernal(coordenadas));
		lEntidades.incluirEntidade(lInimigos.pegarInimigo(i));
		coordenadas.x -= 1900.0f / n_InimCao;
	}

	coordenadas = sf::Vector2f(2000.0f, 484.0f);

	for (i = 0; i < n_Pesadelo; i++)
	{
		lObstaculos.incluirObstaculo(new Pesadelo(coordenadas));
		lEntidades.incluirEntidade(lObstaculos.pegarObstaculo(i));
		coordenadas.x -= 1900.0f / n_Pesadelo;
	}

	coordenadas = sf::Vector2f(2000.0f, 160.0f);

	for (i; i < n_Pesadelo + n_Machado; i++)
	{
		lObstaculos.incluirObstaculo(new Machado_Infernal(coordenadas));
		lEntidades.incluirEntidade(lObstaculos.pegarObstaculo(i));
		coordenadas.x -= 1900.0f / n_Machado;
	}
}

void Profundezas_do_Inferno::InicializarTexturas(GerenciadorGrafico& gg)
{
	int i;

	gg.setPlayerTexture(jogadores[0]->getCorpo());
	jogadores[0]->setAnimador();
	if (jogadores.size() > 1)
	{
		gg.setPlayer2Texture(jogadores[1]->getCorpo());
		jogadores[1]->setAnimador();
	}
	for (i = 0; i < lPlataformas.pegarTamanho(); i++)
		gg.set2FloorTexture(lPlataformas.pegarPlataforma(i)->getCorpo());
	for (i = 0; i < lInimigos.pegarTamanho(); i++)
	{
		if (lInimigos.pegarInimigo(i)->retornarId() == 0)
		{
			gg.setBestaTexture(lInimigos.pegarInimigo(i)->getCorpo());
			lInimigos.pegarInimigo(i)->setAnimador();
		}
		else if (lInimigos.pegarInimigo(i)->retornarId() == 1)
		{
			gg.setCaoTexture(lInimigos.pegarInimigo(i)->getCorpo());
			lInimigos.pegarInimigo(i)->setAnimador();
		}
		else
		{
			gg.setDemonioTexture(lInimigos.pegarInimigo(i)->getCorpo());
			lInimigos.pegarInimigo(i)->setAnimador();
		}
	}
	for (i = 0; i < lObstaculos.pegarTamanho(); i++)
	{
		if (lObstaculos.pegarObstaculo(i)->retornarId() == 5)
			gg.setMachadoTexture(lObstaculos.pegarObstaculo(i)->getCorpo());
		else
		{
			gg.setPesadeloTexture(lObstaculos.pegarObstaculo(i)->getCorpo());
			lObstaculos.pegarObstaculo(i)->setAnimador();
		}
	}
	gg.setMenuBackgroundTexture(menuPause.getCorpo());
}