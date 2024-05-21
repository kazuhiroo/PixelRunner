#include "Hero.h"

Hero::Hero(sf::Texture t, sf::Vector2f p): AnimatedObject(t,p){
	this->setTexture(texture);
	this->setPosition(position);
}

Hero::~Hero() {

}