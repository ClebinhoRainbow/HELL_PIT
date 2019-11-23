#include "Espinhos_Infernais.h"
Espinhos_Infernais::Espinhos_Infernais(sf::Vector2f posicao) :
	Obstaculo(posicao, 6),
	id(0)
{
	corpo.setSize(sf::Vector2f(48.0f, 32.0f));
	corpo.setPosition(posicao);
	corpo.setOrigin(sf::Vector2f(50.0f, 20.0f) / 2.0f);
	corpo.setScale(1.0f, 1.0f);
}

Espinhos_Infernais::~Espinhos_Infernais()
{
}