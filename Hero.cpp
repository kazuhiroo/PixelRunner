#include "Hero.h"


Hero::Hero(sf::Texture t, sf::Vector2f p, int af): AnimatedObject(t,p,af){
	this->setTexture(texture);
	this->setPosition(position);

    score = 0;
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
    //std::cout <<jump_velocity <<"\n";

    //jump
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (state == State::stable) {
            jump_velocity = -sqrt(2 * g * jump_height);
            state = State::in_air;

            position.y -= jump_velocity * elapsed_time.asSeconds();
        }
    }

    //left-right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        position.x += back_velocity * elapsed_time.asSeconds();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        position.x += forward_velocity * elapsed_time.asSeconds();
    }

    //down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        position.y += horizontal_velocity * elapsed_time.asSeconds();
        
    }

    if (state == State::stable) {
        position.x -= state_velocity * elapsed_time.asSeconds();
    }

    //setting new position
    this->setPosition(position);
}

void Hero::collision(std::vector<Set> &sets) {
    bool detected = false;

    for (auto& set : sets) {
        for (auto& e : set.platforms) {
            if (this->getPosition().y + this->getGlobalBounds().height >= e.getPosition().y &&
                this->getPosition().y + this->getGlobalBounds().height <= e.getPosition().y + e.getGlobalBounds().height / 2 &&
                this->getPosition().x + this->getGlobalBounds().width > e.getPosition().x &&
                this->getPosition().x < e.getPosition().x + e.getGlobalBounds().width &&
                jump_velocity >= 0) {

               // std::cout << "Collision detected at platform: " << e.getPosition().x << ", " << e.getPosition().y << "\n";
                detected = true;
                state = State::stable;
                break;
            }
            else {
                state = State::in_air;
            }
        }
        if (detected) {
            break;
        }
    }
    
}

//attacking
void Hero::attack(sf::Time &elapsed_time) {
   
    this->attack_time += elapsed_time;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && attitude == State::passive && attack_time.asSeconds() >= 2.0) {
        std::cout << "you are attacking\n";
        this->attitude = State::attacking;
        this->attack_time = sf::Time::Zero;
    }
}

//udpate method
void Hero::update(sf::Time& elapsed_time, std::vector<Set>& sets) {

    if (attack_time.asSeconds() >= 1.0 && attitude == State::attacking) {
        std::cout << "you are passive\n";
        this->attitude = State::passive;
    }

    this->animate(elapsed_time);
    this->collision(sets);
    this->attack(elapsed_time);

}

State Hero::get_attitude(){
    return attitude;
}