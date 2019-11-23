#pragma once

#include "Inimigo.h"

class Cao_Infernal :
	public Inimigo
{
public:
	Cao_Infernal(sf::Vector2f posicao);
	~Cao_Infernal();

	void Update(float deltaTime, sf::Vector2f posicaoJog);
};

