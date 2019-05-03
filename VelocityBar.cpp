#include "VelocityBar.h"



VelocityBar::VelocityBar(const char* texturefilename, sf::RenderWindow& window) {
	if (!texture_.loadFromFile(texturefilename))
		std::cerr << "Unable to open a texture file" << std::endl;	
	slider_ = Slider(texture_, sf::IntRect(0, 0, 100, 100));
	bar_ = sf::Sprite(texture_, sf::IntRect(0, 100, 100, 1000));
	Adjust(window);
	if (!slider_.font.loadFromFile("font.otf"))
		std::cerr << "Unable to open a font file" << std::endl;
	slider_.text.setFont(slider_.font);
	slider_.text.setString("1000");
	slider_.text.setCharacterSize(width_ / 4);
	slider_.text.setFillColor(sf::Color::Yellow);
	slider_.text.setPosition(slider_.getPosition().x + width_, slider_.getPosition().y - width_/4);

}

void VelocityBar::GetAdjustingInfo(double winhorsize, double winvertsize) {
	width_ = winhorsize / 20;
	height_ = winvertsize * 0.5;
	pos_x_ = width_;
	pos_y_ = winvertsize / 4;
}

void VelocityBar::Adjust(sf::RenderWindow& window) {
	GetAdjustingInfo(window.getSize().x, window.getSize().y);
	bar_.setPosition(pos_x_, pos_y_);
	bar_.setScale(width_ / 100, height_ / 1000);
	slider_.setPosition(pos_x_ + width_/2, pos_y_);
	slider_.setScale(width_ / 100, width_ / 100);
}

void VelocityBar::SetActive(sf::Event& event) {
	slider_.SetActive(event, sf::IntRect(3*width_/2, pos_y_, 0, height_));
}



int main() {

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "my");	
	VelocityBar vb("VelBar.png", window);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			vb.SetActive(event);
			window.clear();
			window.draw(vb.bar_);
			window.draw(vb.slider_);
			window.draw(vb.slider_.text);
			window.display();
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	return 0;
} 
