#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Hero.h"

class Hero;

class Bonus : public sf::Sprite
{
protected:
	sf::Texture texture;
public:
	Bonus(sf::Texture& t,const sf::Vector2f& p);
	~Bonus();

	virtual bool interaction(Hero& hero) = 0;

};

class Coin : public Bonus
{
private:
	unsigned int value;
public:
	Coin(sf::Texture& t, const sf::Vector2f& p);
	~Coin();

	bool interaction(Hero& hero) override;
};

class Star : public Bonus
{
private:
	unsigned int value;
public:
	Star(sf::Texture& t, const sf::Vector2f& p);
	~Star();

	bool interaction(Hero& hero) override;
};