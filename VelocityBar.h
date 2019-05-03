#pragma once
#include "Slider.cpp"

class VelocityBar {
public:
	sf::Texture texture_;
	sf::Sprite bar_;
	Slider slider_;
	double width_ = 100, height_ = 100, pos_x_, pos_y_; // Bar rectangle

	VelocityBar(const char* texturefilename, sf::RenderWindow& window);
	void GetAdjustingInfo(double winhorsize, double winvertsize);
	void Adjust(sf::RenderWindow&);
	void SetActive(sf::Event&);
};