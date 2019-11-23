#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class GerenciadorGrafico
{
private:
	sf::Texture playerTexture;
	sf::Texture player2Texture;
	sf::Texture caoTexture;
	sf::Texture bestaTexture;
	sf::Texture backgroundTexture;
	sf::Texture background2Texture;
	sf::Texture floorTexture;
	sf::Texture floor2Texture;
	sf::Texture bolaDeFogoTexture;
	sf::Texture espinhosTexture;
	sf::Texture demonioTexture;
	sf::Texture pesadeloTexture;
	sf::Texture machadoTexture;
	sf::Texture backgroundMenuTexture;

public:
	GerenciadorGrafico();
	~GerenciadorGrafico();

	void setCaoTexture(sf::RectangleShape& corpo) { corpo.setTexture(&caoTexture); }
	void setBestaTexture(sf::RectangleShape& corpo) { corpo.setTexture(&bestaTexture); }
	void setBackgroundTexture(sf::RectangleShape& corpo) { corpo.setTexture(&backgroundTexture); }
	void set2BackgroundTexture(sf::RectangleShape& corpo) { corpo.setTexture(&background2Texture); }
	void setMenuBackgroundTexture(sf::RectangleShape& corpo) { corpo.setTexture(&backgroundMenuTexture); }
	void setEspinhosTexture(sf::RectangleShape& corpo) { corpo.setTexture(&espinhosTexture); }
	void setPlayerTexture(sf::RectangleShape& corpo) { corpo.setTexture(&playerTexture); }
	void setPlayer2Texture(sf::RectangleShape& corpo) { corpo.setTexture(&player2Texture); }
	void setBoladeFogoTexture(sf::RectangleShape& corpo) { corpo.setTexture(&bolaDeFogoTexture); }
	void setFloorTexture(sf::RectangleShape& corpo) { corpo.setTexture(&floorTexture); }
	void set2FloorTexture(sf::RectangleShape& corpo) { corpo.setTexture(&floor2Texture); }
	void setPesadeloTexture(sf::RectangleShape& corpo) { corpo.setTexture(&pesadeloTexture); }
	void setDemonioTexture(sf::RectangleShape& corpo) { corpo.setTexture(&demonioTexture); }
	void setMachadoTexture(sf::RectangleShape& corpo) { corpo.setTexture(&machadoTexture); }
};
