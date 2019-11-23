#pragma once

#include "Jogador.h"

class Dante :
	public Jogador
{
public:
	Dante(sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Dante();
};

