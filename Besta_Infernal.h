#pragma once

#include "Inimigo.h"

class Besta_Infernal :
	public Inimigo
{
public:
	Besta_Infernal(sf::Vector2f posicao);
	~Besta_Infernal();
	
	void Update(float deltaTime, sf::Vector2f posicaoJog);
};

