#pragma once

#include <SFML/Graphics.hpp>

#include "Animador.h"
#include "Entidade_Concreta.h"

class Bola_de_Fogo :
	public Entidade_Concreta
{
public:
	Bola_de_Fogo(sf::Color color, float speed);
	~Bola_de_Fogo();

	void Update(float deltaTime);

	sf::Vector2f getPosition() { return bullet.getPosition(); }

private:
	sf::RectangleShape bullet;
	float speed;

	sf::Vector2f velocity;
};

