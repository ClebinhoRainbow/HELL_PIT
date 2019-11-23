#include "Jogador.h"

Jogador::Jogador(sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, const int id) :
	Personagem(imageCount, speed, id, switchTime),
	vida(3)
{
	atacando = 50;
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	canJump = true;

	corpo.setSize(sf::Vector2f(80.0f, 91.0f));
	corpo.setPosition(000.0f, 100.0f);
	corpo.setOrigin(corpo.getSize() / 2.0f);
}


Jogador::~Jogador()
{
}

void Jogador::Update(float deltaTime)
{
	velocity.x = 0.0f;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && canJump)
	{
		canJump = false;

		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

    velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0)
	{
		row = 0;
	}
	else
	{
		row = 1; //linha da img do personagem

		if (velocity.x >= 0)
			faceRight = true;
		else
			faceRight = false;
	}

	animador->Update(row, deltaTime, faceRight);
	corpo.setTextureRect(animador->uvRect);
	corpo.move(velocity * deltaTime);
}


bool Jogador::Atacando()
{
	if (atacando < 50)
		return true;
	
	return false;
}

bool Jogador::Morreu()
{
	if (vida == 0)
		return true;
	
	return false;
}

