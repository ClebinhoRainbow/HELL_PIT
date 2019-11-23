#include "Menu.h"

Menu::Menu(const int nMItens, const int id) :
	Entidade(id),
	nMaxItens(nMItens),
	escolheu(0)
{
	menu = new sf::Text[nMaxItens];
	
	corpo.setPosition(sf::Vector2f(0.0f, 0.0f));
	corpo.setSize(sf::Vector2f(WIDTH, HEIGHT));

	if (!font.loadFromFile("arial.ttf"))
	{
		//handle error
	}

	selectedItemIndex = 0;
}


Menu::~Menu()
{
}

void Menu::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < nMaxItens; i++)
	{
		window.draw(menu[i]);
	}
}


void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < nMaxItens)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
