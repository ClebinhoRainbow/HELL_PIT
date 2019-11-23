#pragma once

#include <SFML/Graphics.hpp>

#include "Entidade_Concreta.h"

class Plataforma : 
	public Entidade_Concreta
{
public:
	Plataforma(sf::Vector2f position);
	~Plataforma();
};

