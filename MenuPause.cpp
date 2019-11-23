#include "MenuPause.h"

MenuPause::MenuPause() :
	Menu(2, 13)
{
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Continuar");
	menu[0].setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / (nMaxItens + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Sair");
	menu[1].setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / (nMaxItens + 1) * 2));
}

MenuPause::~MenuPause()
{
}

void MenuPause::setPosicao()
{
	menu[0].setPosition(getCorpo().getPosition().x + 420.0f, getCorpo().getPosition().y + 120.0f);
	menu[1].setPosition(getCorpo().getPosition().x + 445.0f, getCorpo().getPosition().y + 300.0f);
}
int MenuPause::executar(sf::RenderWindow& janela)
{
	escolheu = 0;

	setPosicao();

	while (!escolheu && janela.isOpen())
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
					}
					break;
				}
				break;
			case sf::Event::Closed:
				janela.close();
				break;
			}
		}

		janela.clear();

		janela.draw(corpo);
		Draw(janela);

		janela.display();
	}

	return escolheu;
}
