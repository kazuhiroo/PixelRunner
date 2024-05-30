#include "Bonus.h"

Bonus::Bonus(sf::Texture& t, sf::Vector2f& p) : texture(t), position(p) {
	this->setTexture(texture);
	this->setPosition(position);
}

Bonus::~Bonus() {

}


//Coin

Coin::Coin(sf::Texture& t, sf::Vector2f& p) : Bonus(t, p) {
	this->setTexture(texture);
	this->setPosition(position);

	value = 1;
}

Coin::~Coin() {
	std::cout << "Coin collected!";
}

void Coin::interaction(Hero& hero) {
	if (hero.getGlobalBounds().intersects(this->getGlobalBounds())) {
		hero.score += value;
	}
}

//Star

Star::Star(sf::Texture& t, sf::Vector2f& p) : Bonus(t, p) {
	this->setTexture(texture);
	this->setPosition(position);
}


Star::~Star() {
	std::cout << "Star picked up!";
}


void Star::interaction(Hero& hero) {

}