#include "Fase.h"

Fase::Fase(int n_jog, const int id) :
	Entidade(id),
	n_jogadores(n_jog),
	deltaTime(0.0002f),
	saiuDaFase(0)
{
	corpo.setSize(sf::Vector2f(960.0f, 540.0f));
	corpo.setPosition(480.0f, 270.0f);
	
	jogadores.push_back(new Dante(sf::Vector2u(12, 4), 0.3f, 130.0f, 150.0f));
	lEntidades.incluirEntidade(jogadores[0]);
	if (n_jogadores == 2)
	{
		jogadores.push_back(new Ghierila(sf::Vector2u(12, 4), 0.3f, 130.0f, 200.0f));
		lEntidades.incluirEntidade(jogadores[1]);
	}
}

Fase::~Fase()
{
	limparFase();
}

void Fase::executar(sf::RenderWindow& janela, sf::View& view)
{
	
	while (true)
	{
		deltaTime = clock.restart().asSeconds();

		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;


		checarJanelaAberta(janela, view);
		view.setCenter(jogadores[0]->getCorpo().getPosition());
		atualizarEntidades(deltaTime);
		checarColisoes();
		desenharEntidades(janela);
		
		if (!(jogadores.size()) || saiuDaFase == 2) 
			break;
		corpo.setPosition(jogadores[0]->getPosition().x - 480.0f, jogadores[0]->getPosition().y - 270.0f);
		
		view.setCenter(corpo.getPosition().x + 480.0f, corpo.getPosition().y + 270.0f);
		janela.setView(view);
		janela.display();
		janela.clear();
	}
}

void Fase::checarJanelaAberta(sf::RenderWindow& janela, sf::View& view)
{
	sf::Event evnt;

	while (janela.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			janela.close();
			break;
		case sf::Event::KeyPressed:
			if (evnt.key.code == sf::Keyboard::Escape)
				executarMenuPause(janela, view);
			break;
		}
	}
}

void Fase::executarMenuPause(sf::RenderWindow& janela, sf::View& view)
{
	view.setCenter(sf::Vector2f(menuPause.getCorpo().getPosition().x + 480.0f, 
		menuPause.getCorpo().getPosition().y + 270.0f));
	janela.setView(view);
	saiuDaFase = menuPause.executar(janela);
}

void Fase::checarColisoes()
{
	sf::Vector2f direcao;
	bool jaColidiu = false;
	int i, j;
	unsigned int k;

	/*
	for (i = 0; i < lPlataformas.pegarTamanho(); i++)
	{
		for (k = 0; k < jogadores.size(); k++)
		{
			if (lPlataformas.pegarPlataforma(i)->getCollider().checkCollision(jogadores[k]->getCorpo(), direcao, 1.0f))
				jogadores[k]->onCollision(direcao);
		}
		for (j = 0; j < lInimigos.pegarTamanho(); j++)
		{
			if (lPlataformas.pegarPlataforma(i)->getCollider().checkCollision(lInimigos.pegarInimigo(j)->getCorpo(), direcao, 1.0f))
				lInimigos.pegarInimigo(j)->onCollision(direcao);
		}
		for (j = 0; j < lObstaculos.pegarTamanho(); j++)
		{
			if (lPlataformas.pegarPlataforma(i)->getCollider().checkCollision(lObstaculos.pegarObstaculo(j)->getCorpo(), direcao, 1.0f))
				lObstaculos.pegarObstaculo(j)->onCollision(direcao);
		}
	}*/
	for (j = 0; j < lInimigos.pegarTamanho(); j++)
	{
		for (k = 0; k < jogadores.size(); k++)
		{
			if (lInimigos.pegarInimigo(j)->getCollider().checkCollision(jogadores[k]->getCorpo(), direcao, 1.0f) &&
				(jogadores[k]->Atacando()))
			{
				lInimigos.removerInimigo(j);
				j--;
				break;
			}
			else if (lInimigos.pegarInimigo(j)->getCollider().checkCollision(jogadores[k]->getCorpo(), direcao, 1.0f) &&
				!(jogadores[k]->Atacando()))
			{
				jogadores[k]->onCollision(direcao);
				jogadores[k]->reduzirVida();
				if (jogadores[k]->Morreu())
				{
					jogadores.erase(jogadores.begin() + k);
					k--;
				}
			}
		}
	}
	for (j = 0; j < lObstaculos.pegarTamanho(); j++)
	{
		for (k = 0; k < jogadores.size(); k++)
		{
			jaColidiu = false;
			if (lObstaculos.pegarObstaculo(j)->retornarId() == 5)
			{
				if (lObstaculos.pegarObstaculo(j)->getCollider().checkCollision(jogadores[k]->getCorpo(), direcao, 1.0f))
				{
					while (!(jogadores[k]->Morreu()))
						jogadores[k]->reduzirVida();
					jogadores.erase(jogadores.begin() + k);
					k--;
				}
			}
			else if (lObstaculos.pegarObstaculo(j)->retornarId() == 6)
			{
				if (lObstaculos.pegarObstaculo(j)->getCollider().checkCollision(jogadores[k]->getCorpo(), direcao, 0.0f))
					jogadores[k]->reduzirVida();
			}
			else
			{
				if (lObstaculos.pegarObstaculo(j)->getCollider().checkCollision(jogadores[k]->getCorpo(), direcao, 1.0f))
				{
					if (jaColidiu)
					{
						while (!(jogadores[k]->Morreu()))
							jogadores[k]->reduzirVida();
						jogadores.erase(jogadores.begin() + k);
						k--;
					}
					else
						jaColidiu = true;
				}

			}

		}

	}
}

void Fase::limparFase()
{
	lEntidades.limparLista();
	lInimigos.excluirLista();
	lObstaculos.excluirSet();
	lPlataformas.excluirVector();
	jogadores.clear();
}

void Fase::atualizarEntidades(float deltaTime)
{
	int i;


	for (i = 0; i < jogadores.size(); i++)
		jogadores[i]->Update(deltaTime);
	for (i = 0; i < lInimigos.pegarTamanho(); i++)
	{
		if (jogadores.size() > 1)
		{
			if (abs(jogadores[0]->getPosition().x - lInimigos.pegarInimigo(i)->getPosition().x)
				< abs(jogadores[1]->getPosition().x - lInimigos.pegarInimigo(i)->getPosition().x))
				lInimigos.pegarInimigo(i)->Update(deltaTime, jogadores[0]->getPosition());
			else
				lInimigos.pegarInimigo(i)->Update(deltaTime, jogadores[1]->getPosition());
		}
		lInimigos.pegarInimigo(i)->Update(deltaTime, jogadores[0]->getPosition());
	}
	for (i = 0; i < lObstaculos.pegarTamanho(); i++)
		lObstaculos.pegarObstaculo(i)->Update(deltaTime);
}

void Fase::desenharEntidades(sf::RenderWindow& janela)
{
	imprimir_se(janela);
	lEntidades.percorrerLista(janela);
}

