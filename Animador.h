#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

class Animador
{
public:
	Animador(const sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animador();

	void Update(int row, float deltaTime, bool faceRight);


public:
	sf::IntRect uvRect;

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

