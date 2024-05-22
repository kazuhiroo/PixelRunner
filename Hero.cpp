#include "Hero.h"

Hero::Hero(sf::Texture t, sf::Vector2f p, int af): AnimatedObject(t,p,af){
	this->setTexture(texture);
	this->setPosition(position);
}

Hero::~Hero() {

}

//movement methods
void Hero::gravity(sf::Time& elapsed_time) {
    if (state == State::in_air) {
        jump_velocity += g * elapsed_time.asSeconds();

        position.y += jump_velocity * elapsed_time.asSeconds();
    }
    else if (state == State::stable) {
        jump_velocity = 0;
    }
}


void Hero::movement(sf::Time& elapsed_time) {
    //gravitation
    this->gravity(elapsed_time);
    std::cout <<jump_velocity <<"\n";

    //jump
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if (state == State::stable) {
            jump_velocity = -sqrt(2 * g * jump_height);
            state = State::in_air;

            position.y -= jump_velocity * elapsed_time.asSeconds();
        }
    }

    //moving left-right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        position.x -= vertical_velocity * elapsed_time.asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        position.x += vertical_velocity * elapsed_time.asSeconds();
    }

    //down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if (state == State::stable) {
            position.y += horizontal_velocity * elapsed_time.asSeconds();
        }
    }

    //setting new position
    this->setPosition(position);
}


void Hero::collision(std::vector<Platform>& platforms) {
    for (auto& e : platforms) {
        if (this->getPosition().y + this->getGlobalBounds().height >= e.getPosition().y &&
            this->getPosition().y + this->getGlobalBounds().height <= e.getPosition().y + e.getGlobalBounds().height &&
            this->getPosition().x + this->getGlobalBounds().width >= e.getPosition().x &&
            this->getPosition().x <= e.getPosition().x + e.getGlobalBounds().width &&
            jump_velocity >= 0) {
           
            state = State::stable;
            return;
        }
        else {
            state = State::in_air;
        }
    }
}



   
