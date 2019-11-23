#include "Animador.h"

Animador::Animador(const sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = float(texture->getSize().x) / float(imageCount.x);
	uvRect.height = float(texture->getSize().y) / float(imageCount.y);
}

Animador::~Animador()
{

}

void Animador::Update(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x || currentImage.x >= 6) // >= é o limite da imagem no caso do cop3 row 1
		{
			currentImage.x = 0;
		}
	}


	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight)
	{
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else
	{
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}