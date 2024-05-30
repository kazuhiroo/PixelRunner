#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Hero.h"

class Bonus: public sf::Sprite
{
protected:
	sf::Texture texture;
	sf::Vector2f position;
public:
	Bonus(sf::Texture &t, sf::Vector2f &p);
	~Bonus();

	virtual void interaction(Hero& hero) = 0;

};

class Coin: public Bonus
{
private:
	unsigned int value;
public:
	Coin(sf::Texture& t, sf::Vector2f& p);
	~Coin();

	void interaction(Hero& hero) override;
};

class Star : public Bonus
{
public:
	Star(sf::Texture& t, sf::Vector2f& p);
	~Star();

	void interaction(Hero& hero) override;
};