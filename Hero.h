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
    sf::Texture platform_texture;


    //setting texture method
    void set_texture() {
        if (!platform_texture.loadFromFile("platform.png")) {
            std::cerr << "Error loading platform.png\n";
        }
    }

    void update(sf::Time& elapsed_time) {
        for (auto& e : platforms) {
            e.setTexture(platform_texture);
            e.movement(elapsed_time);
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
