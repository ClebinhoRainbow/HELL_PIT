#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f position) :
	Entidade_Concreta(9)
{
	corpo.setSize(sf::Vector2f(50.0f, 50.0f));
	corpo.setOrigin(corpo.getSize() / 2.0f);
	corpo.setPosition(position);
	corpo.setScale(1.3f, 1.0f);
}


Plataforma::~Plataforma()
{
}
