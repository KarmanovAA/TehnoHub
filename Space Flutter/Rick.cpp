
#include "Rick.h"


Rick::Rick() {
	if (!track_.openFromFile("NGGYU.ogg"))
		std::cerr << "Unable to open a music file" << std::endl;
	track_.setLoop(true);
	if (!texture_.loadFromFile("Rick.jpg"))
		std::cerr << "Unable to open a texture file" << std::endl;
	sprite_.setTexture(texture_);
}
void Rick::ChangeCurFrame(sf::RenderWindow& window) {
	window.clear(sf::Color::Black); 
	sprite_.setTextureRect(sf::IntRect(frame_*ssz_x, 0, 640, 360)); 
	window.draw(sprite_); 
	window.display();
}

void Rick::Execute(/*sf::RenderWindow& window*/) {
	sf::Event event;
	sf::RenderWindow window_(sf::VideoMode(640, 360), "You`ve been RickRolled");
	window_.setPosition({0,0});
	window_.setSize({1920, 1080});
	track_.play();
	ChangeCurFrame(window_);
	clock_.restart();

	while (window_.isOpen()) {
		if (clock_.getElapsedTime().asSeconds() >= delay_[frame_]) {
			++frame_;
			ChangeCurFrame(window_);
			clock_.restart();
			if (frame_ == 18)
				frame_ = 0;
		}

		while (window_.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window_.close();
	}
}

int main() {
	Rick r;
	r.Execute();
	return 0;
} 