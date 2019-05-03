#include "Slider.h"
#include <string>

Slider::Slider() {
	width_ = 100;
	height_ = 100;
	if (!font.loadFromFile("font.otf"))
	{
		std::cerr << "Unable to open a font file" << std::endl;
	}
	text.setFont(font);
	text.setString("1000.0");
	text.setCharacterSize(height_ / 4);
	text.setFillColor(sf::Color::Yellow);
}

Slider::Slider(sf::Texture& Tex, sf::IntRect Rec) {
	this->setTexture(Tex);
	this->setTextureRect(Rec);
	width_ = Rec.width;
	height_ = Rec.height;
	this->setOrigin(width_ / 2, height_ / 2);
}

void Slider::SetActive(sf::Event& event, sf::IntRect restr) {
	double x = event.mouseMove.x;
	double y = event.mouseMove.y;
	double boundleft = getPosition().x - width_ / 2;
	double boundright = getPosition().x + width_ / 2;
	double boundtop = getPosition().y - height_ / 2;
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
		IsWithinBoundaries(PressedX_, PressedY_, boundleft, boundright, boundtop, boundbottom) &&
		y >= restr.top && y <= (restr.top + restr.height))
	{
		PressedX_ = x;
		PressedY_ = y;
		setPosition(restr.left, y);
		velocity = (restr.top + restr.height - y) / restr.height;
		velocity *= MAX_VELOCITY;
		text.setString(std::to_string(static_cast<int>(velocity)));
		text.setPosition(getPosition().x + width_, getPosition().y - height_ / 4);
	}
}
//
//
//int main() {
//	sf::Texture tex;
//	tex.loadFromFile("VelBar.png");
//	sf::RenderWindow window(sf::VideoMode(1920, 1080), "my");
//	Slider sl(tex, sf::IntRect(0,0,100,100));
//	sl.setPosition(500, 0);
//	std::cout << "x: " << sl.text.getPosition().x << "y: " << sl.text.getPosition().y << std::endl;
//	while (window.isOpen()) {
//		sf::Event event;
//		//sl.SetActive(event, window);
//		while (window.pollEvent(event)) {
//			sl.SetActive(event , sf::IntRect(500, 0, 0, 1000));
//			window.clear();
//			//std::cout << "x: " << sl.text.getPosition().x << "y: " << sl.text.getPosition().y << std::endl;
//			std::cout << "string: " << static_cast<std::string>(sl.text.getString()) << std::endl;
//			window.draw(sl);
//			window.draw(sl.text);
//			window.display();
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//	}
//	return 0;
//}