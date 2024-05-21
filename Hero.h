#pragma once
#include "AnimatedObject.h"

enum class Action {
	stable,
	in_air
};


class Hero: public AnimatedObject
{
private:

	//movement variables
	float jump_height = 100.0;
	float velocity_jump = 0;

	const float velocity_vertical = 200.0;
	const float g = 981.0;

	//state
	Action state = Action::stable;

public:
	//contructors
	Hero(sf::Texture t, sf::Vector2f p, int af);
	~Hero();
};

