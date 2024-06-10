#pragma once
#include "AnimatedObject.h"
#include "Platform.h"
#include "Enemy.h"
#include "Bonus.h"


enum class State {
	stable,
	in_air,

	attacking,
	shooting,
	passive,
	
};

class Bonus;

struct Set {
	std::vector<Platform> platforms;
	std::vector<sf::Texture> platform_textures;
	std::vector<Bonus*> bonuses;
	std::vector<Enemy> enemies;
	sf::Texture enemy_texture;

	float objects_velocity = -200.0;

	void add_platform(sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& scale = { 1.0f, 1.0f }) {
		platform_textures.push_back(texture);
		platforms.emplace_back(texture, position);
		platforms.back().setScale(scale);
	}

	void add_bonus(Bonus* bonus) {
		bonuses.push_back(bonus);
	}

	void add_enemy(Enemy &enemy, sf::Texture &e_texture) {
		enemies.push_back(enemy);
		enemy_texture = e_texture;
	}
};

class Hero : public AnimatedObject
{
private:
	//attacking 
	sf::Time attack_time;

	//movement variables
	float jump_velocity = 0;
	float jump_height = 115.0;
	float horizontal_velocity = 600.0;
	float forward_velocity = 200.0;
	float back_velocity = -300.0;
	float state_velocity = 50;
	const float g = 981.0;

	sf::Texture attack_texture;
	
	//state
	State state = State::stable;
	State attitude = State::passive;

	
public:
	//
	std::vector<Arrow*> arrows;

	unsigned int eq = 5;
	unsigned int score;
	unsigned int multiplier;
	unsigned int collected;
	
	//contructors
	Hero(sf::Texture t, sf::Vector2f p, int af);
	~Hero();

	//movement methods
	void movement(sf::Time& elapsed_time);
	void gravity(sf::Time& elapsed_time);
	void collision(std::vector<Set>& sets);
	//attack
	void attack(sf::Time& elapsed_time);
	void shooting(sf::Time& elapsed_time);
	void render_arrows(sf::RenderWindow& window);
	void clear_arrows();
	//game info
	void lost();
	void gain_score(sf::Time& game_time);
	//info methods
	State get_attitude();
	//update
	void update(sf::Time& elapsed_time, std::vector<Set>& sets);
	void reset();
};