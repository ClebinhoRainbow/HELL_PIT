#pragma once

#include <SFML/Graphics.hpp>

#include "Entidade_Concreta.h"
#include "Animador.h"

class Personagem :
	public Entidade_Concreta
{
protected:
	Animador* animador;

	sf::Vector2u imageCount;

	unsigned int row;

	float switchTime;
	float speed;

	bool faceRight;

public:
	Personagem(sf::Vector2u imageCount, float speed, const int id, float switchTime);
	virtual ~Personagem();

	sf::Vector2f getPosition() { return corpo.getPosition(); }

	void setAnimador();
};


