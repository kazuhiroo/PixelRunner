#include "Enemy.h"


//contructor
Enemy::Enemy(sf::Texture t, sf::Vector2f p, int af) : AnimatedObject(t, p, af) {
	this->setTexture(texture);
	this->setPosition(position);
}

Enemy::~Enemy() {

}



//void Enemy::shooting(sf::Time& elapsed_time) {
//	shoot_time += elapsed_time;
//	if (shoot_time.asSeconds() >= 1.0) {
//		sf::Texture arrow_texture;
//		arrow_texture.loadFromFile("arrow.png");
//		sf::Vector2f arrow_position;
//		arrow_position.x = this->getPosition().x;
//		arrow_position.y = this->getPosition().y;
//
//		auto arrow = std::make_unique<Arrow>(arrow_texture, arrow_position);
//		arrows.push_back(std::move(arrow));
//		shoot_time = sf::Time::Zero;
//	}
//
//	for (auto& arrow : arrows) {
//		arrow->movement(elapsed_time);
//	}
//
//}
//
//void Enemy::render_arrows(sf::RenderWindow &window){
//
//		for (const auto& arrow : arrows) {
//			window.draw(*arrow);
//		}
//}
//
//
//void Enemy::clear_arrows() {
//	for (auto it = arrows.begin(); it != arrows.end();) {
//		if ((*it)->getPosition().x + (*it)->getGlobalBounds().width < 0) {
//			it = arrows.erase(it);
//		}
//		else {
//			it++;
//		}
//	}
//}
//
//
//void Enemy::update(sf::Time &elapsed_time) {
//	
//	//this->clear_arrows();
//	//this->shooting(elapsed_time);
//}