#pragma once
#include "AnimatedObject.h"
#include "Platform.h"
#include "Arrow.h"

enum class State {
	stable,
	in_air,
	slide,
	attacking,
	passive
};


class Hero: public AnimatedObject
{
private:
	//attacking 
	sf::Time attack_time;

	//movement variables
	
	float jump_velocity = 0;

	const float jump_height = 100.0;
	const float horizontal_velocity = 800.0;
	const float vertical_velocity = 200.0;
	const float g = 981.0;

	//state
	State state = State::stable;
	State attitude = State::passive;

public:
	//contructors
	Hero(sf::Texture t, sf::Vector2f p, int af);
	~Hero();

	//movement methods
	void movement(sf::Time &elapsed_time);
	void gravity(sf::Time &elapsed_time);
	void attack();
	//collision
	void collision(std::vector<Platform> &platforms);


	//update
	void update(sf::Time &elapsed_time, std::vector<Platform> &platforms);

};

