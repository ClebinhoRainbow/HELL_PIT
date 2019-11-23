#pragma once

#include "Jogador.h"

class Ghierila :
	public Jogador
{
public:
	Ghierila(sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Ghierila();
};

