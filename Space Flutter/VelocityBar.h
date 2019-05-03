#pragma once
#include "MovSprite.cpp"

class VelocityBar {
public:
	sf::Texture texture_;
	sf::Sprite bar_;
	MovSprite slider_;
	double width_, height_, pos_x_, pos_y_;

	void AdjustSprite(sf::Sprite&, double winhorsize, double winvertsize);
	void Adjust(sf::RenderWindow&);

	VelocityBar(const char* texturefilename, sf::RenderWindow& window);
	void SetActive(sf::Event&, sf::RenderWindow& window);
};