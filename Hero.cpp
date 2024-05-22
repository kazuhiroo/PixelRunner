#include "Hero.h"

Hero::Hero(sf::Texture t, sf::Vector2f p, int af): AnimatedObject(t,p,af){
	this->setTexture(texture);
	this->setPosition(position);
}

Hero::~Hero() {

}

//movement methods
void Hero::gravity(sf::Time& elapsed_time) {
    if (state == Action::in_air) {
        jump_velocity += g * elapsed_time.asSeconds();

        position.y += jump_velocity * elapsed_time.asSeconds();
    }
    else if (state == Action::stable) {
        jump_velocity = 0;
    }
}


void Hero::movement(sf::Time& elapsed_time) {
    //gravitation
    this->gravity(elapsed_time);

    //jump
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (state == Action::stable) {
            jump_velocity = -sqrt(2 * g * jump_height);
            state = Action::in_air;

            position.y -= jump_velocity * elapsed_time.asSeconds();
        }
    }

    //moving left-right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        position.x -= vertical_velocity * elapsed_time.asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        position.x += vertical_velocity * elapsed_time.asSeconds();
    }


    this->setPosition(position);
}


void Hero::collision(std::vector<Platform>& platforms) {

}