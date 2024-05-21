#pragma once
#include "include.h"
class AnimatedObject: public sf::Sprite
{
private:
	//animation
	std::vector<sf::IntRect> frames;
	int animated_frame = 0;
	int animated_fps;
	sf::Time object_time;

	//variables for initializing
	sf::Texture texture;
	sf::Vector2f position;

public:
	//constructors
	AnimatedObject(sf::Texture t, sf::Vector2f p, int af);
	~AnimatedObject();
	
	//animation methods
	void add_animation_frame(sf::IntRect frame);
	void animate(sf::Time& time_elapsed);

};

