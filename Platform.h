#pragma once
#include "GraphicalObject.h"

class Platform: public GraphicalObject
{
private:
	float vertical_velocity;

public:
	Platform(sf::Texture t, sf::Vector2f p);
	~Platform();
};

