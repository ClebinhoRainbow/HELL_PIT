#pragma once

#include <SFML/Graphics.hpp>
#include "Personagem.h"

class Inimigo : public Personagem
{
protected:
	sf::Vector2f velocity;
	
	unsigned int row;
	float speed;
	bool faceRight;
	
public:
	Inimigo(sf::Vector2u imageCount, float switchTime, float speed, const int id);
	~Inimigo();

	virtual void Update(float deltaTime, sf::Vector2f posicaoJog) = 0;
	void Draw(sf::RenderWindow& window);
};