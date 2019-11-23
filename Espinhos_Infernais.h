#pragma once

#include "Obstaculo.h"

class Espinhos_Infernais :
	public Obstaculo
{
private:
	const int id;
public:
	Espinhos_Infernais(sf::Vector2f posicao);
	~Espinhos_Infernais();

	void Update(float deltaTime) {}
	void setAnimador() {}
	const int retornarId() const { return id; }
};