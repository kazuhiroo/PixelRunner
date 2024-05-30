#pragma once
#include "AnimatedObject.h"
#include "Platform.h"
#include "Enemy.h"

enum class State {
	stable,
	in_air,

	attacking,
	passive,
	//???????????????
	normal,
	immune,
	flying
	
};

struct Set {
    //struct for gamesets
    std::vector<Platform> platforms;
	std::vector<sf::Texture> platform_textures;
	//bonuses
		/*
		std::vector...
		*/
	//enemies
	std::vector<Enemy> enemies;
	sf::Texture enemy_texture;
	
	float objects_velocity = -150.0;

	void add_platform(sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& scale = { 1.0f, 1.0f }) {
		
		platform_textures.push_back(texture);
		platforms.emplace_back(texture, position);
		platforms.back().setScale(scale);
	}


	void init() {
		for (size_t i = 0; i < platforms.size(); i++)
			platforms[i].setTexture(platform_textures[i]);
	}
    void update(sf::Time& elapsed_time) {
		init();
        for (auto& platform : platforms) {
            platform.move(objects_velocity*elapsed_time.asSeconds(), 0.0);
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

	const float jump_height = 110.0;
	const float horizontal_velocity = 600.0;
	const float forward_velocity = 150.0;
	const float back_velocity = -200.0;
	const float state_velocity = 50;
	const float g = 981.0;

	//state
	State state = State::stable;
	State attitude = State::passive;

public:
	//
	unsigned int score;
	unsigned int multiplier;
	unsigned int collected;
	/*State bonus_active;*/
	//contructors
	Hero(sf::Texture t, sf::Vector2f p, int af);
	~Hero();

	//movement methods
	void movement(sf::Time &elapsed_time);
	void gravity(sf::Time &elapsed_time);
	void attack(sf::Time& elapsed_time);
	void collision(std::vector<Set> &sets);
	//
	void gain_score(sf::Time& game_time);
	//info methods
	State get_attitude(); 
	//update
	void update(sf::Time &elapsed_time, std::vector<Set> &sets);

};
