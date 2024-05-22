#include "Arrow.h"


Arrow::Arrow(sf::Texture t, sf::Vector2f p) : GraphicalObject(t, p) {
	this->setPosition(position);
	this->setTexture(texture);
}

Arrow::~Arrow() {

}

void Arrow::movement(sf::Time& elapsed_time) {

}