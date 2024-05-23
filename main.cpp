#include "Classes.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

struct Set {
    //struct for gamesets
};




int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(1366, 768), "My window");
    window.setFramerateLimit(60);

    //time
    sf::Clock clock;

    //create sky object
    sf::Texture sky_texture;
    sky_texture.loadFromFile("sky.png");
    GraphicalObject sky(sky_texture, sf::Vector2f(0.0,0.0), sf::IntRect(0,0,1366, 768));
    sky.setScale(1,2.5);

    //create prototype platforms
    std::vector<Platform> platforms;

    sf::Texture platform_texture;
    platform_texture.loadFromFile("platform.png");
    Platform platform1(platform_texture, sf::Vector2f(150.0,300.0));
    platform1.setScale(0.5, 0.3);
    platforms.emplace_back(platform1);

    Platform platform2(platform_texture, sf::Vector2f(100.0, 600.0));
    platform2.setScale(0.5, 0.3);
    platforms.emplace_back(platform2);



    Platform platform3(platform_texture, sf::Vector2f(200.0, 500.0));
    platform3.setScale(0.5, 0.3);
    platforms.emplace_back(platform3);


    Platform platform4(platform_texture, sf::Vector2f(400.0, 400.0));
    platform4.setScale(0.5, 0.3);
    platforms.emplace_back(platform4);


    //Create hero object
    sf::Texture hero_texture;
    hero_texture.loadFromFile("character.png");
    Hero hero(hero_texture,sf::Vector2f(100.0, 200.0),9);
    hero.setScale(2, 2);

    hero.add_animation_frame(sf::IntRect(200, 0, 37, 37)); // 1 frame of animation
    hero.add_animation_frame(sf::IntRect(250, 0, 37, 37)); // 2 frame
    hero.add_animation_frame(sf::IntRect(300, 0, 37, 37)); // 3 frame
    hero.add_animation_frame(sf::IntRect(350, 0, 37, 37)); // 4 frame


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
        hero.collision(platforms);
        hero.animate(elapsed_time);
        hero.movement(elapsed_time);
      


        //render
        window.clear();

        window.draw(sky);
        for (auto& e : platforms) {
            window.draw(e);
        }
        
        window.draw(hero);
        window.display();


       
        //std::cout << elapsed.asSeconds() << "\n"; // Print elapsed time in seconds
    }


    return 0;
}
