#include "GraphicalObject.h"

//constructors
GraphicalObject::GraphicalObject(sf::Texture t, sf::Vector2f p) : texture(t), position(p) {
	this->setTexture(texture);
	this->setPosition(position);
}

GraphicalObject::~GraphicalObject() {

}