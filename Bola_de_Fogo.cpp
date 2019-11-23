#include "Bola_de_Fogo.h"

Bola_de_Fogo::Bola_de_Fogo(sf::Color color, float speed) :
	Entidade_Concreta(8)
{
	bullet.setFillColor(color);
	bullet.setSize(sf::Vector2f(5.0f, 5.0f));

	this->speed = speed;
}


Bola_de_Fogo::~Bola_de_Fogo()
{
}


void Bola_de_Fogo::Update(float deltaTime)
{
	velocity.x = 0.0f;

	velocity.x += speed;

	bullet.move(velocity * deltaTime);
}
