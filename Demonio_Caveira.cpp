#include "Demonio_Caveira.h"

Demonio_Caveira::Demonio_Caveira(sf::Vector2f posicao) :
	Inimigo(sf::Vector2u(8, 1), 0.1f, 140.0f, 2)
{
}

Demonio_Caveira::~Demonio_Caveira()
{
}

void Demonio_Caveira::Update(float deltaTime, sf::Vector2f posicaoJog)
{
	velocity.y += 981.0f * deltaTime;
}
