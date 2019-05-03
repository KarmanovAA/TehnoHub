#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


class MovSprite: public sf::Sprite
{
public:
	MovSprite() : width_(0), height_(0){}
	MovSprite(sf::Texture&, sf::IntRect);
	MovSprite(sf::Texture&);
	void SetActive(sf::Event& event);
	void Rescale(float widfactor, float heightfactor);
	
	
	sf::Sprite sprite_;
	double width_ , height_ ;
private:
	double PressedX_ = -1;
	double PressedY_ = -1;
	bool MouseStatus_ = false;
};

