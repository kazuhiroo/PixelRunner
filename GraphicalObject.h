#pragma once
#include "include.h"

class GraphicalObject: public sf::Sprite
{
private:

	sf::Texture texture;
	sf::Vector2f position;

public:
	GraphicalObject(sf::Texture t, sf::Vector2f p);
	~GraphicalObject();

};

