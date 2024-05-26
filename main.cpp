#include "Classes.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


struct Set {
    //struct for gamesets
    std::vector<Platform> platforms;
    sf::Texture platform_texture;


    //setting texture method
    void set_texture() {
        if (!platform_texture.loadFromFile("platform.png")) {
            std::cerr << "Error loading platform.png\n";
        }
    }

    void update(sf::Time &elapsed_time) {
        for (auto& e : platforms) {
            e.setTexture(platform_texture);
            e.movement(elapsed_time);
        }
    }
};


Set create_set_1() {
    Set set;
    set.set_texture();

    Platform platform1(set.platform_texture, sf::Vector2f(1366.0, 600.0));
    platform1.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform1);

    Platform platform2(set.platform_texture, sf::Vector2f(1366+200.0, 550.0));
    platform2.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform2);

    Platform platform3(set.platform_texture, sf::Vector2f(1366+400.0, 500.0));
    platform3.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform3);

    Platform platform4(set.platform_texture, sf::Vector2f(1366+600.0, 450.0));
    platform4.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform4);


    return set;
}

Set create_set_2() {
    Set set;
    set.set_texture();

    Platform platform1(set.platform_texture, sf::Vector2f(1366.0, 600.0));
    platform1.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform1);

    Platform platform2(set.platform_texture, sf::Vector2f(1366 + 200.0, 550.0));
    platform2.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform2);

    Platform platform3(set.platform_texture, sf::Vector2f(1366 + 400.0, 500.0));
    platform3.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform3);

    Platform platform4(set.platform_texture, sf::Vector2f(1366 + 600.0, 450.0));
    platform4.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform4);


    return set;
}

Set create_set_3() {
    Set set;
    set.set_texture();

    Platform platform1(set.platform_texture, sf::Vector2f(1366.0, 600.0));
    platform1.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform1);

    Platform platform2(set.platform_texture, sf::Vector2f(1366 + 200.0, 550.0));
    platform2.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform2);

    Platform platform3(set.platform_texture, sf::Vector2f(1366 + 400.0, 500.0));
    platform3.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform3);

    Platform platform4(set.platform_texture, sf::Vector2f(1366 + 600.0, 450.0));
    platform4.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform4);


    return set;
}

Set create_set_4() {
    Set set;
    set.set_texture();

    Platform platform1(set.platform_texture, sf::Vector2f(1366.0, 600.0));
    platform1.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform1);

    Platform platform2(set.platform_texture, sf::Vector2f(1366 + 200.0, 550.0));
    platform2.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform2);

    Platform platform3(set.platform_texture, sf::Vector2f(1366 + 400.0, 500.0));
    platform3.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform3);

    Platform platform4(set.platform_texture, sf::Vector2f(1366 + 600.0, 450.0));
    platform4.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform4);


    return set;
}

Set create_set_5() {
    Set set;
    set.set_texture();

    Platform platform1(set.platform_texture, sf::Vector2f(1366.0, 600.0));
    platform1.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform1);

    Platform platform2(set.platform_texture, sf::Vector2f(1366 + 200.0, 550.0));
    platform2.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform2);

    Platform platform3(set.platform_texture, sf::Vector2f(1366 + 400.0, 500.0));
    platform3.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform3);

    Platform platform4(set.platform_texture, sf::Vector2f(1366 + 600.0, 450.0));
    platform4.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform4);


    return set;
}

Set create_set_6() {
    Set set;
    set.set_texture();

    Platform platform1(set.platform_texture, sf::Vector2f(1366.0, 600.0));
    platform1.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform1);

    Platform platform2(set.platform_texture, sf::Vector2f(1366 + 200.0, 550.0));
    platform2.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform2);

    Platform platform3(set.platform_texture, sf::Vector2f(1366 + 400.0, 500.0));
    platform3.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform3);

    Platform platform4(set.platform_texture, sf::Vector2f(1366 + 600.0, 450.0));
    platform4.setScale(0.5, 0.3);
    set.platforms.emplace_back(platform4);


    return set;
}

void spawn_set(std::vector<Set> &sets) {
    int set_choice;

    const Set& last_set = sets.back();
    const Platform& last_platform = last_set.platforms.back();



    if (last_platform.getPosition().x + last_platform.getGlobalBounds().width <= 1200) {
        set_choice = rand() % 6;
        Set set;
        switch(set_choice)
        {
        case 0:
            set = create_set_1();
            sets.emplace_back(set);
            break;
        case 1:
            set = create_set_2();
            sets.emplace_back(set);
            break;
        case 2:
            set = create_set_3();
            sets.emplace_back(set);
            break;
        case 3:
            set = create_set_4();
            sets.emplace_back(set);
            break;
        case 4:
            set = create_set_5();
            sets.emplace_back(set);
            break;
        case 5:
            set = create_set_6();
            sets.emplace_back(set);
            break;
        default:
            break;
        }
    }


}

void clear_set(std::vector<Set> sets) {
    
    Set& first_set = sets.front();
    Platform& last_platform = first_set.platforms.back();

    if (last_platform.getPosition().x +
        last_platform.getGlobalBounds().width <= 0) {
        sets.erase(sets.begin());
        }
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

    


    std::vector<Set> sets;

    Set set_1 = create_set_1();
    sets.emplace_back(set_1);

    Set set_2 = create_set_1();
    sets.emplace_back(set_2);
    
    Platform ground(set_1.platform_texture, sf::Vector2f(-200.0,550.0));
    ground.setScale(100.0,1.0);
    
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
        // restart the clock to get elapsed time since the last restart
        sf::Time elapsed_time = clock.restart();

        //polling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //hero methods
        hero.movement(elapsed_time);

        for (auto& set : sets) {
            hero.update(elapsed_time, set.platforms);
        }

        //platform methods
        for (auto& set : sets) {
            set.update(elapsed_time);
        }

        spawn_set(sets);
        clear_set(sets);


        //render
        window.clear();
        window.draw(sky);
        window.draw(ground);

        for (const auto& set : sets) {
            for (const auto& platform : set.platforms) {
                window.draw(platform);
            }
        }

        window.draw(hero);

        window.display();
    }

    return 0;
}
