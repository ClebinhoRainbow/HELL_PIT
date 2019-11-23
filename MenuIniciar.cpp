#include "MenuIniciar.h"

MenuIniciar::MenuIniciar() :
	Menu(3, 12)
{
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Fase 1");
	menu[0].setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / (nMaxItens + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Fase 2");
	menu[1].setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / (nMaxItens + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Sair");
	menu[2].setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / (nMaxItens + 1) * 3));
}

MenuIniciar::~MenuIniciar()
{
}

void MenuIniciar::setPosicao()
{
	menu[0].setPosition(getCorpo().getPosition().x + 430.0f, getCorpo().getPosition().y + 100.0f);
	menu[1].setPosition(getCorpo().getPosition().x + 430.0f, getCorpo().getPosition().y + 250.0f);
	menu[2].setPosition(getCorpo().getPosition().x + 440.0f, getCorpo().getPosition().y + 400.0f);
}

int MenuIniciar::executar(sf::RenderWindow& janela)
{
	escolheu = 0;

	setPosicao();

	while (!escolheu)
	{
		sf::Event evnt;

		while (janela.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::KeyReleased:
				switch (evnt.key.code)
				{
				case sf::Keyboard::Up:
					MoveUp();
					break;
				case sf::Keyboard::Down:
					MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (getPressedItem())
					{
					case 0:
						escolheu = 1;
						break;
					case 1:
						escolheu = 2;
						break;
					case 2:
						escolheu = 3;
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				escolheu = 4;
				break;
			}
		}

		janela.clear();

		imprimir_se(janela);
		Draw(janela);

		janela.display();
	}

	return escolheu;
}
