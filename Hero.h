#pragma once
#include "AnimatedObject.h"
#include "Platform.h"

enum class State {
	stable,
	in_air,
	slide,
	attacking,
	passive
};

struct Set {
    //struct for gamesets
    std::vector<Platform> platforms;
	std::vector<sf::Texture> platform_textures;
	//enemies
	//bonuses

	void add_platform(sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& scale = { 0.5f, 0.3f }) {
		
		platform_textures.push_back(texture);
		platforms.emplace_back(texture, position);
		platforms.back().setScale(scale);
	}


	void init() {
		for (int i = 0; i < platforms.size(); i++)
			platforms[i].setTexture(platform_textures[i]);
	}


    void update(sf::Time& elapsed_time) {
		init();
        for (auto& platform : platforms) {
            platform.movement(elapsed_time);
        }
    }
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
	const float vertical_velocity = 150.0;
	const float state_velocity = 100;
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
	void attack(sf::Time& elapsed_time);
	//collision
	void collision(std::vector<Set> &sets);


	//update
	void update(sf::Time &elapsed_time, std::vector<Set> &sets);

};
