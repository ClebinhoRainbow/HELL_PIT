#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
using namespace std;

class Gerenciador_de_Colisoes
{
private:
	sf::RectangleShape& corpo;
public:
	Gerenciador_de_Colisoes(sf::RectangleShape& corpo);
	~Gerenciador_de_Colisoes();

	void Mover(float dx, float dy) { corpo.move(dx, dy); }

	bool checkCollision(Gerenciador_de_Colisoes corpo2, sf::Vector2f& direcao, float push);
	sf::Vector2f pegarPosicao() const { return corpo.getPosition(); }
	sf::Vector2f pegarMetadeTamanho() const { return corpo.getSize() / 2.0f; }
};

