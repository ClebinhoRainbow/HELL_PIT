#include "Demonio_Caveira.h"

Demonio_Caveira::Demonio_Caveira(sf::Vector2f posicao) :
	Inimigo(sf::Vector2u(8, 1), 0.1f, 140.0f, 2, posicao)
{
	corpo.setSize(sf::Vector2f(64.0f, 64.0f));
	corpo.setScale(1.0f, 1.0f);
}

Demonio_Caveira::~Demonio_Caveira()
{
}

void Demonio_Caveira::Update(float deltaTime, sf::Vector2f posicaoJog)
{
	velocity.y = 0.0f;
	velocity.x = 0.0f;

	// if para definir se o Chefão vai seguir o jogador ou não em x
	if (fabs(posicaoJog.x - getPosition().x) < 500.0f)
	{
		if (posicaoJog.x - getPosition().x > 100)
			velocity.x += 50.0f;
		else
			velocity.x -= 50.0f;
	}

	// if para definir se o Chefão vai seguir o jogador ou não em y
	if (getPosition().y - posicaoJog.y > 100)
		velocity.y -= 50.0f;
	else if (getPosition().y - posicaoJog.y < 0)
		velocity.y += 50.0f;

	if (velocity.x >= 0)
		faceRight = true;
	else
		faceRight = false;

	// Atualiza a animação e move o Chefão
	animador->Update(row, deltaTime, faceRight);
	corpo.setTextureRect(animador->uvRect);
	corpo.move(velocity * deltaTime);
}
