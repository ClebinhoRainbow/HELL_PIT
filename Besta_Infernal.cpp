#include "Besta_Infernal.h"

Besta_Infernal::Besta_Infernal(sf::Vector2f posicao) :
	Inimigo(sf::Vector2u(6, 2), 0.1f, 140.0f, 0, posicao)
{
	corpo.setSize(sf::Vector2f(45.0f, 20.0f));
	corpo.setScale(1.7f, 2.0f);
}

Besta_Infernal::~Besta_Infernal()
{
}

void Besta_Infernal::Update(float deltaTime, sf::Vector2f posicaoJog)
{
	velocity.x = 0;

	if ((getPosition().x < posicaoJog.x) && (abs(getPosition().x - posicaoJog.x) < 200.0f))
		velocity.x += speed;
	else if ((getPosition().x > posicaoJog.x) && (abs(getPosition().x - posicaoJog.x) < 200.0f))
		velocity.x -= speed;

	if (velocity.x >= 0)
		faceRight = true;
	else
		faceRight = false;


	animador->Update(row, deltaTime, faceRight);
	corpo.setTextureRect(animador->uvRect);
	corpo.move(velocity * deltaTime);
}

