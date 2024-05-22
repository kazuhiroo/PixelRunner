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
	float jump_velocity = 0;

	const float vertical_velocity = 200.0;
	const float g = 981.0;

	//state
	Action state = Action::stable;

public:
	//contructors
	Hero(sf::Texture t, sf::Vector2f p, int af);
	~Hero();

	//movement methods
	void movement(sf::Time &elapsed_time);
	void gravity(sf::Time &elapsed_time);

};

