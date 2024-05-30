#pragma once
#include "GraphicalObject.h"

class Arrow: public GraphicalObject
{
private:
	//variables
	const float vertical_velocity = -500.0;
public:
	//constructors
	Arrow(sf::Texture t, sf::Vector2f p);
	~Arrow();

	//movement
	void movement(sf::Time& elapsed_time);
};

