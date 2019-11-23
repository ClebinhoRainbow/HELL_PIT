#include "Inimigo.h"

Inimigo::Inimigo(sf::Vector2u imageCount, float switchTime, float speed, const int id) : 
	Personagem(imageCount, speed, id, switchTime)
{
	this->speed = speed;
	//this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	corpo.setSize(sf::Vector2f(96.0f, 64.0f));
	corpo.setPosition(206.0f, 206.0f);
	corpo.setOrigin(corpo.getSize() / 2.0f);
}


Inimigo::~Inimigo()
{
}

void Inimigo::Draw(sf::RenderWindow& window)
{
	window.draw(corpo);
}