#pragma once

#include "Inimigo.h"

class Demonio_Caveira :
	public Inimigo
{
public:
	Demonio_Caveira(sf::Vector2f posicao);
	~Demonio_Caveira();

	void Update(float deltaTime, sf::Vector2f posicaoJog);
};

