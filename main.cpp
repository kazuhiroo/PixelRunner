#include "Classes.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

struct Set {
    //struct for gamesets
    std::vector<Platform> platforms;
    sf::Texture platform_texture;

    void set_texture() {
        if (!platform_texture.loadFromFile("platform.png")) {
            std::cerr << "Error loading platform.png\n";
        }
    }
};


Set create_set_1() {
    Set set;
    set.set_texture();

    Platform platform1(set.platform_texture, sf::Vector2f(100.0, 600.0));
    platform1.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform1);

    Platform platform2(set.platform_texture, sf::Vector2f(300.0, 550.0));
    platform2.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform2);

    Platform platform3(set.platform_texture, sf::Vector2f(500.0, 500.0));
    platform3.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform3);

    Platform platform4(set.platform_texture, sf::Vector2f(700.0, 450.0));
    platform4.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform4);


    return set;
}




int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(1366, 768), "My window");
    window.setFramerateLimit(60);

    //time
    sf::Clock clock;

    //create sky object
    sf::Texture sky_texture;
    if (!sky_texture.loadFromFile("sky.png")) {
        std::cerr << "Error loading sky.png\n";
    }
    GraphicalObject sky(sky_texture, sf::Vector2f(0.0, 0.0), sf::IntRect(0, 0, 1366, 768));
    sky.setScale(1, 2.5);

    Set set_1 = create_set_1();


    //Create hero object
    sf::Texture hero_texture;
    if (!hero_texture.loadFromFile("character.png")) {
        std::cerr << "Error loading character.png\n";
    }
    Hero hero(hero_texture, sf::Vector2f(100.0, 200.0), 9);
    hero.setScale(2, 2);

    hero.add_animation_frame(sf::IntRect(213, 0, 23, 37)); // 1 frame of animation
    hero.add_animation_frame(sf::IntRect(263, 0, 23, 37)); // 2 frame
    hero.add_animation_frame(sf::IntRect(313, 0, 23, 37)); // 3 frame
    hero.add_animation_frame(sf::IntRect(363, 0, 23, 37)); // 4 frame

    //game loop
    while (window.isOpen()) {
        // Restart the clock to get elapsed time since the last restart
        sf::Time elapsed_time = clock.restart();

        //polling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //hero methods
        hero.update(elapsed_time, set_1.platforms);

        //platform methods
        for (auto& e : set.platforms) {
            e.setTexture(set.platform_texture);
            e.movement(elapsed_time);
        }

        //render
        window.clear();
        window.draw(sky);
        for (const auto& e : set_1.platforms) {
            window.draw(e);
        }
        window.draw(hero);
        window.display();
    }

    return 0;
}
