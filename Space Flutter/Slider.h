#pragma once
#include "MovSprite.cpp"

#define MAX_VELOCITY 1000;

class Slider : public MovSprite {
public:
	sf::Text text;
	sf::Font font;
	double velocity = MAX_VELOCITY;
	void SetActive(sf::Event& event, sf::IntRect restrictions);
	Slider();
	Slider(sf::Texture& t, sf::IntRect r);
};