#include "Besta_Infernal.h"

Besta_Infernal::Besta_Infernal(sf::Vector2f posicao) :
	Inimigo(sf::Vector2u(6, 2), 0.1f, 140.0f, 0)
{
}

Besta_Infernal::~Besta_Infernal()
{
}

void Besta_Infernal::Update(float deltaTime, sf::Vector2f posicaoJog)
{
	velocity.y += 981.0f * deltaTime;
}

