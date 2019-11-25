#include "Machado_Infernal.h"

Machado_Infernal::Machado_Infernal(sf::Vector2f posicao) :
	Obstaculo(posicao, 5),
	id(0)
{
	corpo.setSize(sf::Vector2f(48.0f, 32.0f));
	corpo.setPosition(posicao);
	corpo.setOrigin(sf::Vector2f(20.0f, 50.0f) / 2.0f);
	corpo.setScale(1.0f, 1.0f);
}

Machado_Infernal::~Machado_Infernal()
{

}
void Machado_Infernal::Update(float deltaTime)
{
	velocity.y = 0;

	if (corpo.getPosition().y > 180.0f)
		corpo.setPosition(corpo.getPosition().x, -400.0f);

	velocity.y += 130.0f;
	getCorpo().rotate(-3.0f);

	corpo.move(velocity * deltaTime);
}
