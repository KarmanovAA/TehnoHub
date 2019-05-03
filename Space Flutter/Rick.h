#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Rick {
private:
	sf::Clock clock_;
	sf::Texture texture_;
	sf::Sprite sprite_;
	const int ssz_x = 640;
	const int ssz_y = 360;
	int frame_ = 0;
	const double delay_[18] = { 0.1, 0.1, 0.1, 0.1, 0.5, 0.1, 0.1, 0.1, 0.1,
									0.5, 0.5, 0.5, 0.5, 0.5, 0.2, 0.2, 0.2, 0.5 };
	sf::Music track_;
public:
	Rick();
	void ChangeCurFrame(sf::RenderWindow& window);
	void Execute(/*sf::RenderWindow& window*/);
};