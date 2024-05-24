#include "Platform.h"

Platform::Platform(const sf::Texture &t, sf::Vector2f p) : GraphicalObject(t, p) {
	this->setTexture(texture);
	this->setPosition(position);
}

Platform::~Platform() {

}


void Platform::movement(sf::Time& elapsed_time) {

	position.x -= vertical_velocity * elapsed_time.asSeconds();
	this->setPosition(position);
}