#include "Entidade_Concreta.h"

Entidade_Concreta::Entidade_Concreta(const int id) :
	Entidade(id)
{
	velocity = sf::Vector2f(0.0f, 0.0f);
}

Entidade_Concreta::~Entidade_Concreta()
{
}

// Método para fazer com que os objetos
void Entidade_Concreta::onCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//collision on the right
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//collision on the bottom
		velocity.y = 0.0f;
	}
	else if (direction.y > 0.0f)
	{
		//collision on the top
		velocity.y = 0.0f;
	}
}