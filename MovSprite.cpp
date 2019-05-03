#include "MovSprite.h"

bool IsWithinBoundaries(double& x, double& y, double& boundleft,
							double& boundright, double& boundtop, double& boundbottom) 
{
	if (x>=boundleft && x <=boundright && y >= boundtop && y<= boundbottom)
		return true;
	return false;
}

MovSprite::MovSprite(sf::Texture& Tex, sf::IntRect Rec){
	this->setTexture(Tex);
	this->setTextureRect(Rec);
	width_ = Rec.width;
	height_ = Rec.height;
	this->setOrigin(width_ / 2, height_ / 2);
}

MovSprite::MovSprite(sf::Texture& Tex) {
	this->setTexture(Tex);
	width_ = Tex.getSize().x;
	height_ = Tex.getSize().y;
	this->setOrigin(width_ / 2, height_ / 2);
}

void MovSprite::Rescale(float widfactor, float heightfactor) {
	width_ *= widfactor;
	height_ *= heightfactor;
	setScale(widfactor, heightfactor);
}

void MovSprite::SetActive(sf::Event& event) {
	double x = event.mouseMove.x;
	double y = event.mouseMove.y;
	double boundleft = getPosition().x - width_ / 2;
	double boundright = getPosition().x + width_ / 2;
	double boundtop = getPosition().y  - height_ / 2;
	double boundbottom = getPosition().y + height_ / 2;

	if (event.type == sf::Event::MouseButtonPressed) {
		MouseStatus_ = true;
		PressedX_ = event.mouseButton.x;
		PressedY_ = event.mouseButton.y;
	}
	if (event.type == sf::Event::MouseButtonReleased)
		MouseStatus_ = false;
	
	if (MouseStatus_ && event.type == sf::Event::MouseMoved && //Зажата ЛКМ и мышь двигается
		IsWithinBoundaries(x, y, boundleft, boundright, boundtop, boundbottom) &&
		IsWithinBoundaries(PressedX_, PressedY_, boundleft, boundright, boundtop, boundbottom))
	{
		PressedX_ = x;
		PressedY_ = y;
		setPosition(x , y);
	}
}


//int main() {
//	sf::Texture tex;
//	tex.loadFromFile("VelBar.png");
//	sf::RenderWindow window(sf::VideoMode(1000, 1000), "my");
//	MovSprite sl(tex, sf::IntRect(0, 0, 100, 100));
//	while (window.isOpen()) {
//		sf::Event event;
//		//sl.SetActive(event, window);
//		while (window.pollEvent(event)) {
//			sl.SetActive(event);
//			window.clear();
//			window.draw(sl);
//			//window.draw(sl.text);
//			window.display();
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//	}
//	return 0;
//}