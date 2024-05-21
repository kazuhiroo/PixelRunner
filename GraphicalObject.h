#pragma once
#include "include.h"

class GraphicalObject: public sf::Sprite
{
private:

	//variables for initializing
	sf::Texture texture;
	sf::Vector2f position;
	sf::IntRect frame;
public:
	//constructors
	GraphicalObject(sf::Texture t, sf::Vector2f p);
	GraphicalObject(sf::Texture t, sf::Vector2f p, sf::IntRect f);
	~GraphicalObject();

	void repeat(sf::IntRect frame);
};

