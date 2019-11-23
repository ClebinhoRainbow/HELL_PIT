#pragma once

#include "Entidade.h"

class Entidade_Concreta :
	public Entidade
{
protected:
	sf::Vector2f velocity;

public:
	Entidade_Concreta(const int id);
	~Entidade_Concreta();

	void onCollision(sf::Vector2f direction);
};

