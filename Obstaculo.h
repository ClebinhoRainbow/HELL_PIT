#pragma once

#include "Entidade_Concreta.h"

class Obstaculo :
	public Entidade_Concreta
{
protected:
public:
	Obstaculo(sf::Vector2f posicao, const int id);
	~Obstaculo();

	virtual void Update(float deltaTime) = 0;
	virtual void setAnimador() = 0;
};

