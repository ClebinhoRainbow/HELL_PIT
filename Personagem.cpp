#include "Personagem.h"

Personagem::Personagem(sf::Vector2u imageCount, float speed, const int id, float switchTime) :
	Entidade_Concreta(id)
{
	this->speed = speed;
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	animador = nullptr;
	faceRight = true;

	row = 0;
}


Personagem::~Personagem()
{
}

void Personagem::setAnimador()
{
	animador = new Animador(corpo.getTexture(), imageCount, switchTime);
}
