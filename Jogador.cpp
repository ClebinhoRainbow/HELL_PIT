#include "Jogador.h"

Jogador::Jogador(sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight, const int id) :
	Personagem(imageCount, speed, id, switchTime),
	vida(3)
{
	flag = 300;
	controlador = 0;
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	canJump = true;

	corpo.setSize(sf::Vector2f(22.5f, 40.0f));
	corpo.setPosition(000.0f, 457.5f);
	corpo.setOrigin(corpo.getSize() / 2.0f);
	corpo.setScale(4.7f, 2.0f);
}


Jogador::~Jogador()
{
}

void Jogador::Update(float deltaTime)
{
	velocity.x = 0.0f;

	if (getPosition().x > 3100.0f && getPosition().y < 500.0f && getPosition().y > 457.5f)
		corpo.setPosition(sf::Vector2f(getPosition().x, 157.5f));

	if (flag < 300) flag++;

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (canJump) && (flag == 300))
	{
		flag = 0;
		switchTime = 0.1f;
		row = 2;
	}
	else if (!canJump)
		row = 3;
	else if ((velocity.x == 0) && (flag == 300))
		row = 0;
	else if (flag == 300)
		row = 1; //linha da img do personagem

	if (((getPosition().y < 500.0f && getPosition().y > 457.5f) || (getPosition().y < 200.0f && getPosition().y > 157.5f)))
	{
		if (canJump)
			velocity.y = 0.0f;
		else if (velocity.y < 0.0f)
			velocity.y += 981.0f * deltaTime;
		else
		{
			canJump = true;
			velocity.y = 0.0f;
		}
	}
	else
		velocity.y += 981.0f * deltaTime;

	if (velocity.x > 0.0f)
		faceRight = true;
	else if (velocity.x < 0.0f)
		faceRight = false;

	animador->Update(row, deltaTime, faceRight);
	corpo.setTextureRect(animador->uvRect);
	corpo.move(velocity * deltaTime);
}


bool Jogador::Atacando()
{
	if (flag < 300)
		return true;
	
	return false;
}

bool Jogador::Morreu()
{
	if (vida == 0)
		return true;
	
	return false;
}

