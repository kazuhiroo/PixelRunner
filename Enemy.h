#pragma once
#include "AnimatedObject.h"
#include "Arrow.h"

class Enemy: public AnimatedObject
{
private:
	//variables for an attack
	//std::vector<std::unique_ptr<Arrow>> arrows;
	//sf::Time shoot_time;

public:
	//constructor
	Enemy(sf::Texture t, sf::Vector2f p, int af);
	~Enemy();

	//attack method for enemy
	void shooting(sf::Time& elapsed_time);

	//rendering
	void render_arrows(sf::RenderWindow& window);
	void clear_arrows();

	//update
	void update(sf::Time& elapsed_time);
};

