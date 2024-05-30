#pragma once
#include "GraphicalObject.h"

class Platform: public GraphicalObject
{
private:
	float vertical_velocity = 150.0;

public:
	Platform(sf::Texture& t, sf::Vector2f p);
	~Platform();

};

