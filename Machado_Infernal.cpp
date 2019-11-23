#include "Machado_Infernal.h"

Machado_Infernal::Machado_Infernal(sf::Vector2f posicao) :
	Obstaculo(posicao, 5),
	id(0)
{
	velocity.x = 100.0f;
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
	
	if (corpo.getPosition().y > 200.0f)
		corpo.setPosition(corpo.getPosition().x, -400.0f);

	velocity.y += 981.0f * deltaTime;

	corpo.move(velocity * deltaTime);
}
