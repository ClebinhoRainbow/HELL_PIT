#pragma once

#include <SFML/Graphics.hpp>
#include "Personagem.h"

class Jogador : public Personagem
{
protected:
	int vida;
	int atacando;
	unsigned int row;
	float speed;
	bool faceRight;

	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;

public:
	Jogador(sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, const int id);
	~Jogador();

	void Update(float deltaTime);
	void reduzirVida() { vida--; }

	bool Atacando();
	bool Morreu();
};
