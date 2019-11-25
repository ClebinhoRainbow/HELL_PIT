#include "Inimigo.h"

Inimigo::Inimigo(sf::Vector2u imageCount, float switchTime, float speed, const int id, sf::Vector2f posicao) : 
	Personagem(imageCount, speed, id, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;

	corpo.setPosition(posicao);
	corpo.setOrigin(corpo.getSize() / 2.0f);
}


Inimigo::~Inimigo()
{
}

void Inimigo::Draw(sf::RenderWindow& window)
{
	window.draw(corpo);
}