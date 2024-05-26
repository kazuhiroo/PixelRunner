#include "Sets.h"


void Set::set_texture() {
    if (!platform_texture.loadFromFile("platform.png")) {
        std::cerr << "Error loading platform.png\n";
    }
}

void Set::update(sf::Time& elapsed_time) {
    for (auto& e : platforms) {
        e.setTexture(platform_texture);
        e.movement(elapsed_time);
    }
}