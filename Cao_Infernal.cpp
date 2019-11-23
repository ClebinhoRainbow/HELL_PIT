#include "Cao_Infernal.h"

Cao_Infernal::Cao_Infernal(sf::Vector2f posicao) :
	Inimigo(sf::Vector2u(5, 1), 0.1f, 140.0f, 1)
{
}

Cao_Infernal::~Cao_Infernal()
{
}

void Cao_Infernal::Update(float deltaTime, sf::Vector2f posicaoJog)
{
	velocity.x = 0.0f;

	if ((getPosition().x < posicaoJog.x) && (abs(getPosition().x - posicaoJog.x) < 500.0f))
		velocity.x += speed;
	else if ((getPosition().x > posicaoJog.x) && (abs(getPosition().x - posicaoJog.x) < 500.0f))
		velocity.x -= speed;

	velocity.y += 981.0f * deltaTime;

	if (velocity.x >= 0)
		faceRight = false;
	else
		faceRight = true;


	animador->Update(row, deltaTime, faceRight);
	corpo.setTextureRect(animador->uvRect);
	corpo.move(velocity * deltaTime);
}
