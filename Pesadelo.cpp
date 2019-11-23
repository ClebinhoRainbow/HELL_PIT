#include "Pesadelo.h"

Pesadelo::Pesadelo(sf::Vector2f posicao) :
	Obstaculo(posicao, 7),
	id(0)
{
	animador = nullptr;
	speed = 150.0f;
	//this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	velocity = sf::Vector2f(speed, 0.0f);

	corpo.setSize(sf::Vector2f(48.0f, 32.0f));
	corpo.setPosition(10.0f, 300.0f);
	corpo.setOrigin(corpo.getSize() / 2.0f);
	corpo.setScale(2.0f, 1.95f);
}

Pesadelo::~Pesadelo()
{
}

void Pesadelo::Update(float deltaTime)
{
	velocity.x = 0.0f;
	/*verificat se chegou no final*/
	//testar valores
	if (corpo.getPosition().x < -100.0f)
	{
		velocity.x += speed;
	}
	/*verificat se colidiu com final da plat*/
	else if (corpo.getPosition().x > 2000.0f)
	{
		velocity.x -= speed;
	}
	else if (faceRight)
		velocity.x += speed;
	else
		velocity.x -= speed;

	velocity.y += 981.0f * deltaTime;

	if (velocity.x >= 0)
		faceRight = false;
	else
		faceRight = true;


	animador->Update(row, deltaTime, faceRight);
	corpo.setTextureRect(animador->uvRect);
	corpo.move(velocity * deltaTime);
}

void Pesadelo::Draw(sf::RenderWindow& window)
{
	window.draw(corpo);
}

void Pesadelo::setAnimador()
{
	animador = new Animador(corpo.getTexture(), sf::Vector2u(4, 1), 0.1f);
}
