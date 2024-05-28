#include "Hero.h"
#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

//creating sets methods
Set create_starting_set() {
    Set set;

    //will add a set for starting game


    return set;
}

Set create_set_1() {
    Set set;
    sf::Texture platform_texture;
    platform_texture.loadFromFile("platform.png");

    set.add_platform(platform_texture, sf::Vector2f(200.0, 600.0), sf::Vector2f(0.5f, 0.3f));
    set.add_platform(platform_texture, sf::Vector2f(400.0, 550.0), sf::Vector2f(0.5f, 0.3f));
    set.add_platform(platform_texture, sf::Vector2f(600.0, 500.0), sf::Vector2f(0.5f, 0.3f));
    set.add_platform(platform_texture, sf::Vector2f(800.0, 450.0), sf::Vector2f(0.5f, 0.3f));
    return set;


}


Set create_set_2() {
    Set set;
    sf::Texture big_platform_texture;
    sf::Texture small_platform_texture;

    big_platform_texture.loadFromFile("platform.png");
    small_platform_texture.loadFromFile("platform_small.png");

    set.add_platform(big_platform_texture, sf::Vector2f(1366, 600), sf::Vector2f(0.5f, 0.3f));
    set.add_platform(small_platform_texture, sf::Vector2f(1366+200, 550), sf::Vector2f(0.5f, 0.3f));
    return set;


}



//spawn - clear mechanism
void spawn_set(std::vector<Set>& sets, sf::Texture &platform_texture) {
    int set_choice;

    Set& last_set = sets.back();
    Platform& last_platform = last_set.platforms.back();

    if (last_platform.getPosition().x + last_platform.getGlobalBounds().width <= 1350) {
        set_choice = rand() % 2;
        Set set;
        switch (set_choice)
        {
        case 0:
            set = create_set_2();
            sets.emplace_back(set);
            break;
        case 1:
            set = create_set_2();
            sets.emplace_back(set);
            break;
        default:
            break;
        }
    }


}

void clear_set(std::vector<Set>& sets) {

    Set& first_set = sets.front();
    Platform& last_platform = first_set.platforms.back();

    if (last_platform.getPosition().x +
        last_platform.getGlobalBounds().width <= 0) {
        sets.erase(sets.begin());
    }
}

//main
int main() {
    //create the window
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
    //plat

    sf::Texture platform_texture;
    if (!platform_texture.loadFromFile("platform.png")) {
        std::cerr << "Error loading p.png\n";
    }

    //create sets objects
    std::vector<Set> sets;

    Set starting_set = create_set_1();
    sets.emplace_back(starting_set);
    
    //create enemy (just for trying if it works)
    sf::Texture enemy_texture;
    enemy_texture.loadFromFile("enemy.png");
    Enemy enemy(enemy_texture, sf::Vector2f(window.getSize().x/2,window.getSize().y/2), 9);
    enemy.setScale(2, 2);


    enemy.add_animation_frame(sf::IntRect(213, 0, 23, 37)); // 1 frame of animation
    enemy.add_animation_frame(sf::IntRect(263, 0, 23, 37)); // 2 frame
    enemy.add_animation_frame(sf::IntRect(313, 0, 23, 37)); // 3 frame
    enemy.add_animation_frame(sf::IntRect(363, 0, 23, 37)); // 4 frame
    
    

    //create hero object
    sf::Texture hero_texture;
    if (!hero_texture.loadFromFile("character.png")) {
        std::cerr << "Error loading character.png\n";
    }

    Hero hero(hero_texture, sf::Vector2f(1350.0, 200.0), 9);
    hero.setScale(2, 2);

    hero.add_animation_frame(sf::IntRect(213, 0, 23, 37)); // 1 frame of animation
    hero.add_animation_frame(sf::IntRect(263, 0, 23, 37)); // 2 frame
    hero.add_animation_frame(sf::IntRect(313, 0, 23, 37)); // 3 frame
    hero.add_animation_frame(sf::IntRect(363, 0, 23, 37)); // 4 frame

    //game loop
    while (window.isOpen()) {
        // restart the clock to get elapsed time since the last restart
        sf::Time elapsed_time = clock.restart();

        //polling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
                
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                }
            }
        }

  

        //platform methods
        for (auto& set : sets) {
            set.update(elapsed_time);
        }

        spawn_set(sets, platform_texture);
        clear_set(sets);

        //hero methods
        hero.movement(elapsed_time);
        hero.update(elapsed_time, sets);
        
        //render
        window.clear();
        window.draw(sky);


        for ( auto& set : sets) {
            for (const auto& platform : set.platforms) {
                window.draw(platform);
            }
        }
        //enemy.render_arrows(window);

        //window.draw(enemy);
        window.draw(hero);

        window.display();
    }

    return 0;
}
