#include "Gerenciador_de_Colisoes.h"
#include "Jogador.h"

Gerenciador_de_Colisoes::Gerenciador_de_Colisoes()
{
}


Gerenciador_de_Colisoes::~Gerenciador_de_Colisoes()
{
}

void Gerenciador_de_Colisoes::checarColisoes(ListaEntidades lEn, ListaInimigos lIn, ListaObstaculos lOb,
	ListaPlataformas lPlat, vector<Jogador*> jogadores)
{
	sf::Vector2f direcao;
	bool jaColidiu = false;


	for (int i = 0; i < lPlat.pegarTamanho(); i++)
	{
		for (unsigned int k = 0; k < jogadores.size(); k++)
		{
			if (checkCollision(lPlat.pegarPlataforma(i)->getCorpo(), jogadores[k]->getCorpo(), direcao, 1.0f))
				jogadores[k]->onCollision(direcao);
		}
		for (int j = 0; j < lIn.pegarTamanho(); j++)
		{
			if (checkCollision(lPlat.pegarPlataforma(i)->getCorpo(), lIn.pegarInimigo(j)->getCorpo(), direcao, 1.0f))
				lIn.pegarInimigo(j)->onCollision(direcao);
		}
		for (int j = 0; j < lOb.pegarTamanho(); j++)
		{
			if (checkCollision(lPlat.pegarPlataforma(i)->getCorpo(), lOb.pegarObstaculo(j)->getCorpo(), direcao, 1.0f))
				lOb.pegarObstaculo(j)->onCollision(direcao);
		}
	}
	for (int j = 0; j < lIn.pegarTamanho(); j++)
	{
		for (unsigned int k = 0; k < jogadores.size(); k++)
		{
			if ((checkCollision(lIn.pegarInimigo(j)->getCorpo(), jogadores[k]->getCorpo(), direcao, 1.0f)) &&
				(jogadores[k]->Atacando()))
			{
				lEn.removerEntidade(lIn.pegarInimigo(j)->retornarId(), j);
				lIn.removerInimigo(j);
				j--;
				break;
			}
			else if ((checkCollision(lIn.pegarInimigo(j)->getCorpo(), jogadores[k]->getCorpo(), direcao, 1.0f)) &&
				!(jogadores[k]->Atacando()))
			{
				jogadores[k]->onCollision(direcao);
				jogadores[k]->reduzirVida();
				if (jogadores[k]->Morreu())
				{
					lEn.removerEntidade(jogadores[k]->retornarId(), k);
					jogadores.erase(jogadores.begin() + j);
					k--;
				}
			}
		}
	}
	for (int j = 0; j < lOb.pegarTamanho(); j++)
	{
		for (unsigned int k = 0; k < jogadores.size(); k++)
		{
			jaColidiu = false;
			if (lOb.pegarObstaculo(j)->retornarId() == 5)
			{
				if (checkCollision(lOb.pegarObstaculo(j)->getCorpo(), jogadores[k]->getCorpo(), direcao, 1.0f))
				{
					while (!(jogadores[k]->Morreu()))
						jogadores[k]->reduzirVida();
					lEn.removerEntidade(jogadores[k]->retornarId(), k);
					jogadores.erase(jogadores.begin() + j);
					k--;
				}
			}
			else if (lOb.pegarObstaculo(j)->retornarId() == 6)
			{
				if (checkCollision(lOb.pegarObstaculo(j)->getCorpo(), jogadores[k]->getCorpo(), direcao, 0.0f))
					jogadores[k]->reduzirVida();
			}
			else
			{
				if (checkCollision(lOb.pegarObstaculo(j)->getCorpo(), jogadores[k]->getCorpo(), direcao, 1.0f))
				{
					if (jaColidiu)
					{
						while (!(jogadores[k]->Morreu()))
							jogadores[k]->reduzirVida();
						lEn.removerEntidade(jogadores[k]->retornarId(), k);
						jogadores.erase(jogadores.begin() + j);
						k--;
					}
					else
						jaColidiu = true;
				}

			}

		}

	}
}
			
bool Gerenciador_de_Colisoes::checkCollision(sf::RectangleShape& corpo1, sf::RectangleShape& corpo2,
	sf::Vector2f direcao, float push)
{
	sf::Vector2f corpo2Posicao = pegarPosicao(corpo2);
	sf::Vector2f corpo2MetadeTamanho = pegarMetadeTamanho(corpo2);
	sf::Vector2f corpo1Posicao = pegarPosicao(corpo1);
	sf::Vector2f corpo1MetadeTamanho = pegarMetadeTamanho(corpo1);

	float deltaX = corpo2Posicao.x - corpo1Posicao.x;
	float deltaY = corpo2Posicao.y - corpo1Posicao.y;

	float intersectX = abs(deltaX) - (corpo2MetadeTamanho.x + corpo1MetadeTamanho.x);
	float intersectY = abs(deltaY) - (corpo2MetadeTamanho.y + corpo1MetadeTamanho.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = min(max(push, 0.0f), 1.0f);

		if (intersectX > intersectY)
		{
			if (deltaX > 0.0f)
			{
				Mover(corpo1, intersectX * (1.0f - push), 0.0f);
				Mover(corpo2, -intersectX * push, 0.0f);

				direcao.x = 1.0f;
				direcao.y = 0.0f;
			}
			else
			{
				Mover(corpo1, -intersectX * (1.0f - push), 0.0f);
				Mover(corpo2, intersectX * push, 0.0f);

				direcao.x = -1.0f;
				direcao.y = 0.0f;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Mover(corpo1, 0.0f, intersectY * (1.0f - push));
				Mover(corpo2 ,0.0f, -intersectY * push);

				direcao.x = 0.0f;
				direcao.y = 1.0f;
			}
			else
			{
				Mover(corpo1, 0.0f, -intersectY * (1.0f - push));
				Mover(corpo2, 0.0f, intersectY * push);

				direcao.x = 0.0f;
				direcao.y = -1.0f;
			}
		}

		return true;
	}

	return false;
}