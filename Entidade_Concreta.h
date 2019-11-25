#pragma once

#include "Entidade.h"
#include "Gerenciador_de_Colisoes.h"

class Entidade_Concreta :
	public Entidade
{
protected:
	sf::Vector2f velocity;

public:
	Entidade_Concreta(const int id);
	~Entidade_Concreta();

	void onCollision(sf::Vector2f direction);
	Gerenciador_de_Colisoes getCollider() { return Gerenciador_de_Colisoes(corpo); }
};

