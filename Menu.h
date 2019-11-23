#pragma once

#include <iostream>
using namespace std;

#include "Entidade.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#define WIDTH 960
#define HEIGHT 540

class Menu :
	public Entidade
{
protected:
	int escolheu;
	int selectedItemIndex;
	
	const int nMaxItens;

	sf::Font font;
	sf::Text* menu;

public:
	Menu(const int nMItens, const int id);
	~Menu();

	void Draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

	int getPressedItem() { return selectedItemIndex; }

	virtual void setPosicao() = 0;
	virtual int executar(sf::RenderWindow& janela) = 0;
};

