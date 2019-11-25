#include "Gerenciador_de_Colisoes.h"
#include "Jogador.h"

Gerenciador_de_Colisoes::Gerenciador_de_Colisoes(sf::RectangleShape& corpo) :
	corpo(corpo)
{
}


Gerenciador_de_Colisoes::~Gerenciador_de_Colisoes()
{
}

			
bool Gerenciador_de_Colisoes::checkCollision(Gerenciador_de_Colisoes corpo2, sf::Vector2f& direcao, float push)
{
	sf::Vector2f corpo2Posicao = corpo2.pegarPosicao();
	sf::Vector2f corpo2MetadeTamanho = corpo2.pegarMetadeTamanho();
	sf::Vector2f corpo1Posicao = pegarPosicao();
	sf::Vector2f corpo1MetadeTamanho = pegarMetadeTamanho();

	float deltaX = corpo2Posicao.x - corpo1Posicao.x;
	float deltaY = corpo2Posicao.y - corpo1Posicao.y;

	float intersectX = abs(deltaX) - (corpo2MetadeTamanho.x + corpo1MetadeTamanho.x);
	float intersectY = abs(deltaY) - (corpo2MetadeTamanho.y + corpo1MetadeTamanho.y);

	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = min(max(push, 0.0f), 1.0f);
		
		if (push > 0.0f) 
		{
			if (intersectX > intersectY)
			{
				if (deltaX > 0.0f)
				{
					Mover(intersectX * (1.0f - push), 0.0f);
					corpo2.Mover(-intersectX * push, 0.0f);

					direcao.x = 1.0f;
					direcao.y = 0.0f;
				}
				else
				{
					Mover(-intersectX * (1.0f - push), 0.0f);
					corpo2.Mover(intersectX * push, 0.0f);

					direcao.x = -1.0f;
					direcao.y = 0.0f;
				}
			}
			else
			{
				if (deltaY > 0.0f)
				{
					Mover(0.0f, intersectY * (1.0f - push));
					corpo2.Mover(0.0f, -intersectY * push);

					direcao.x = 0.0f;
					direcao.y = 1.0f;
				}
				else
				{
					Mover(0.0f, -intersectY * (1.0f - push));
					corpo2.Mover(0.0f, intersectY * push);

					direcao.x = 0.0f;
					direcao.y = -1.0f;
				}
			}
		}
		return true;
	}

	return false;
}