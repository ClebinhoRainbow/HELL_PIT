#pragma once

#include "Menu.h"

class MenuPause :
	public Menu
{
private:
public:
	MenuPause();
	~MenuPause();

	void setPosicao();
	int executar(sf::RenderWindow& janela);
};

