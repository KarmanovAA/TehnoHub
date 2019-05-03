#include "VelocityBar.h"

VelocityBar::VelocityBar(const char* texturefilename, sf::RenderWindow& window) {
	if (!texture_.loadFromFile(texturefilename))
		std::cerr << "Unable to open a texture file" << std::endl;			//
	MovSprite slider_(texture_ ,sf::IntRect(0, 0, 100, 100));			//	Загрузили текстуру 
	sf::Sprite bar_(texture_, sf::IntRect(0, 100, 100, 1000));				//	и вырезали спрайты
	Adjust(window);
	std::cout << "slder pos x: "<< slider_.getPosition().x << std::endl;
	std::cout << "slder pos y: " << slider_.getPosition().y << std::endl;
	std::cout << "slder scale x: " << slider_.getScale().x << std::endl;
	std::cout << "slder scale y: " << slider_.getScale().y << std::endl;
	std::cout << "slder origin x: " << slider_.getOrigin().x << std::endl;
}

void VelocityBar::AdjustSprite(sf::Sprite& sprite, double winhorsize, double winvertsize) {
	width_ = winhorsize / 10;
	height_ = winvertsize * 0.75; 
	pos_x_ = width_;
	pos_y_ = winvertsize / 8;
	sprite.setPosition(pos_x_, pos_y_);
	sprite.setScale(width_ / 100  , height_ / 100);
}

void VelocityBar::Adjust(sf::RenderWindow& window) {
	AdjustSprite(bar_, window.getSize().x, window.getSize().y);
	bar_.setScale(1, 0.1);										//Выравниваем под размер окна
	AdjustSprite(slider_, window.getSize().x, window.getSize().y);
	slider_.setPosition(pos_x_ + width_ / 2, pos_y_);
}

void VelocityBar::SetActive(sf::Event& event, sf::RenderWindow& window) {

}


int main() {

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "my");	
	VelocityBar vb("VelBar.png", window);
	while (window.isOpen()) {
		sf::Event event;
	//	vb.SetActive(event, window);
		while (window.pollEvent(event)) {
			//vb.SetActive(event, window);
			window.clear();
			window.draw(vb.bar_);
			window.draw(vb.slider_);
			window.display();
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
	return 0;
} 


//Разобраться со скейлом
// Ориджином
// Нормально настроить adjust
// исправить отрисовку