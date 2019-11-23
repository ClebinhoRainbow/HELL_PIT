#pragma once

#include "Obstaculo.h"
#include "Animador.h"

class Pesadelo :
	public Obstaculo
{
private:
	Animador* animador;
	
	sf::Vector2f velocity;
	
	const int id;
	int row;

	bool faceRight;

	float speed;

public:
	Pesadelo(sf::Vector2f posicao);
	~Pesadelo();
	
	const int retornarId() const { return id; }

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void setAnimador();

	sf::Vector2f getPosition() { return corpo.getPosition(); }
};



