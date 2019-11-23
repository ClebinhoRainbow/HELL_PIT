#pragma once

#include "Obstaculo.h"

class Machado_Infernal : public Obstaculo
{
private:
	const int id;
public:
	Machado_Infernal(sf::Vector2f posicao);
	~Machado_Infernal();

	const int retornarId() const { return id; }

	void setAnimador() {}
	void Update(float deltaTime);
};


