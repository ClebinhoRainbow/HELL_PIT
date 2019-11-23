#include "Jogo.h"

int main()
{
	Jogo objetoJogo;
	objetoJogo.executar();
}

/*int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "meu pinto");

	Menu menu((float)window.getSize().x, (float)window.getSize().y);


	while (window.isOpen())
	{
		sf::Event evnt;

		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::KeyReleased:
				switch (evnt.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::Return:
					switch (menu.getPressedItem())
					{
					case 0:
						cout << "Play button has been pressed" << endl;
						break;
					case 1:
						cout << "Options button has been pressed" << endl;
						break;
					case 2:
						cout << "Exit button has been pressed" << endl;
						window.close();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear();

		menu.draw(window);

		window.display();

	}
	return 0;
}*/
/*#include <SFML/Graphics.hpp>
//#include <iostream>
//using namespace std;
#include "Jogador.h"
#include "Plataforma.h"
#include <vector>
#include "Inimigo.h"



static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{

	sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Window", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	//sf::RectangleShape player(sf::Vector2f(80.0f, 91.0f)); //tamanho de cada boneco
	//player.setFillColor(sf::Color::Red);
	//player.setOrigin(50.0,50.0);
	sf::Texture playerTexture;
	sf::Texture enemyTexture;
	sf::Texture backgroundTexture;
	//playerTexture.loadFromFile("tux_from_linux.png");
	//playerTexture.loadFromFile("../super-mario-png.png"); //por algum motivo precisa daquele "../"
	backgroundTexture.loadFromFile("background.png");
	playerTexture.loadFromFile("cop3.png"); //3
	enemyTexture.loadFromFile("crab-idle-2.png");
	//player.setTexture(&playerTexture);
	//player.setPosition(206.0f, 206.0f);

	/*sf::Vector2u textureSize = playerTexture.getSize();
	textureSize.x /= 3;
	textureSize.y /= 9;

	player.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * 8,
			textureSize.x, textureSize.y));*/

	/*Jogador player(&playerTexture, sf::Vector2u(8, 5), 0.3f, 130.0f, 200.0f);
	Inimigo enemy(&enemyTexture, sf::Vector2u(1, 1), 0.3f, 50.0f); //eles nao pulam ainda

	//bullet.setShooter(&player);

	vector<Plataforma> platforms;

	//platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
	//platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	platforms.push_back(Plataforma(nullptr, sf::Vector2f(10000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));
	//Platform platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	//Platform platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));
	//Platform platform3(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f));

	float deltaTime = 0.0002f;
	sf::Clock clock;

	bool goRight = true;
	int i = 0;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;

		if (i == 5000)
		{
			goRight = false;
		}
		else if (i == 10000)
		{
			goRight = true;
			i = 0;
		}

		sf::Event evnt;

		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
				/*case sf::Event::Resized:
					cout << "New window width: " << evnt.size.width << " New window height: "
					<< evnt.size.height << endl;
					break;
				case sf::Event::TextEntered:
					if(evnt.text.unicode < 128)
					{
						printf("%c ", evnt.text.unicode);
					}
					break;*/

			/*}

			/*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
			{
				player.move(-1.0,0.0);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				player.move(1.0,0.0);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
			{
				player.move(0.0,-1.0);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				player.move(0.0,1.0);
			}*/

			/*if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
			}*/


		/*}

		player.Update(deltaTime);
		enemy.Update(goRight, deltaTime);
		i++;
		//player.setTextureRect(animation.uvRect);

		sf::Vector2f direction;

		/*for (int i = 0; i < platforms.size(); i++)
		{
			Platform& platform = platforms[i];
		}*/

/*
		for (Plataforma& platform : platforms)
		{
			if (platform.getCollider().checkCollision(player.getCollider(), direction, 1.0f))
				player.onCollision(direction);
			if (platform.getCollider().checkCollision(enemy.getCollider(), direction, 1.0f))
				enemy.onCollision(direction);
			if (enemy.getCollider().checkCollision(player.getCollider(), direction, 1.0f))
				player.onCollision(direction);
		}


		//platform1.getCollider().checkCollision(player.getCollider(), 0.0f); // se fosse 0.5f, seria 50% mais dificil de mover
		//platform2.getCollider().checkCollision(player.getCollider(), 1.0f); // já que é 1.0f, ela nao move


		view.setCenter(player.getPosition());

		sf::Sprite background(backgroundTexture);


		window.clear(sf::Color::Blue);
		window.draw(background);
		window.setView(view);
		player.Draw(window);
		enemy.Draw(window);

		for (Plataforma& platform : platforms)
			platform.Draw(window);
		window.display();

	}
	return 0;
}*//*float deltaTime = 0.0002f;
	sf::Clock clock;

	bool goRight = true;
	int i = 0;

	while (janela.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;

		if (i == 5000)
		{
			goRight = false;
		}
		else if (i == 10000)
		{
			goRight = true;
			i = 0;
		}

		sf::Event evnt;
		while (janela.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				janela.close();
				break;
			}
		}

		jogador1.Update(deltaTime);
		inimigo1.Update(goRight, deltaTime);
		i++;

		sf::Vector2f direction;

		for (Plataforma& platform : platforms)
		{
			if (platform.getCollider().checkCollision(jogador1.getCollider(), direction, 1.0f))
				jogador1.onCollision(direction);
			if (platform.getCollider().checkCollision(inimigo1.getCollider(), direction, 1.0f))
				inimigo1.onCollision(direction);
		}
		if (inimigo1.getCollider().checkCollision(jogador1.getCollider(), direction, 1.0f))
			jogador1.onCollision(direction);

		view.setCenter(jogador1.getPosition());

		janela.clear(sf::Color::Blue);
		//janela->draw(background);
		janela.setView(view);
		jogador1.Draw(janela);
		inimigo1.Draw(janela);

		for (Plataforma& platform : platforms)
			platform.Draw(janela);
		janela.display();

	}*/