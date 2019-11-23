#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Entidade
{
protected:
	sf::RectangleShape corpo;
	const int id;

public:
	Entidade(const int ID);
	~Entidade();

	void imprimir_se(sf::RenderWindow& janela) { janela.draw(corpo); }

	const int retornarId() { return id; }

	sf::RectangleShape& getCorpo() { return corpo; }
};
