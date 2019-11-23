#pragma once

#include <SFML/Graphics.hpp>

#include "Jogador.h"
#include "ListaEntidades.h"
#include "ListaInimigos.h"
#include "ListaObstaculos.h"
#include "ListaPlataformas.h"

using namespace std;

class Gerenciador_de_Colisoes
{
public:
	Gerenciador_de_Colisoes();
	~Gerenciador_de_Colisoes();

	void Mover(sf::RectangleShape& corpo, float dx, float dy) { corpo.move(dx, dy); }

	void checarColisoes(ListaEntidades lEn, ListaInimigos lIn, ListaObstaculos lOb,
		ListaPlataformas lPlat, vector<Jogador*> jogadores);

	bool checkCollision(sf::RectangleShape& corpo1, sf::RectangleShape& corpo2, sf::Vector2f direcao, float push);
	sf::Vector2f pegarPosicao(sf::RectangleShape& corpo) const { return corpo.getPosition(); }
	sf::Vector2f pegarMetadeTamanho(sf::RectangleShape& corpo) const { return corpo.getSize() / 2.0f; }
};

