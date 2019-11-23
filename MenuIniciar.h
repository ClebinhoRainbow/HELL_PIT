#pragma once

#include "Menu.h"

class MenuIniciar :
	public Menu
{
private:
public:
	MenuIniciar();
	~MenuIniciar();

	void setPosicao();
	int executar(sf::RenderWindow& janela);
};

