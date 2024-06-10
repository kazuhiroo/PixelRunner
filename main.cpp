#include "Hero.h"
#include "Bonus.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <sstream>
#include <cstdlib>
#include <iostream>

#define HEIGHT 768
#define WIDTH 1366
#define LIMIT 1200
#define HALF 0.5, 0.5

//creating basic game objects
Hero create_hero() {

    sf::Texture hero_texture;
    hero_texture.loadFromFile("resources/character1.png");

    Hero hero(hero_texture, sf::Vector2f(200.0, 200.0), 9);
    hero.setScale(2, 2);

    hero.add_animation_frame(sf::IntRect(213, 0, 23, 37)); // 1 frame of animation
    hero.add_animation_frame(sf::IntRect(263, 0, 23, 37)); // 2 frame
    hero.add_animation_frame(sf::IntRect(313, 0, 23, 37)); // 3 frame
    hero.add_animation_frame(sf::IntRect(363, 0, 23, 37)); // 4 frame

    return hero;
}

Enemy create_enemy(const sf::Vector2f &position, sf::Texture &enemy_texture) {
   
    Enemy enemy(enemy_texture, position, 5);
    enemy.setScale(2, 2);

    enemy.add_animation_frame(sf::IntRect(213, 0, 23, 37)); // 1 frame of animation
    enemy.add_animation_frame(sf::IntRect(263, 0, 23, 37)); // 2 frame
    enemy.add_animation_frame(sf::IntRect(313, 0, 23, 37)); // 3 frame
    enemy.add_animation_frame(sf::IntRect(363, 0, 23, 37)); // 4 frame

    return enemy;
}

GraphicalObject create_sky() {
    sf::Texture sky_texture;
    sky_texture.loadFromFile("resources/sky.png");
    GraphicalObject sky(sky_texture, sf::Vector2f(0.0, 0.0), sf::IntRect(0, 0, WIDTH, HEIGHT));
    sky.setScale(1, 2.5);

    return sky;
}

//creating sets 
Set create_starting_set() {
    Set set;
    sf::Texture ground_platform_texture;
    sf::Texture coin_texture;
    sf::Texture star_texture;
    ground_platform_texture.loadFromFile("resources/ground_platform.png");
    coin_texture.loadFromFile("resources/coin.png");
    star_texture.loadFromFile("resources/star.png");

    set.add_platform(ground_platform_texture, sf::Vector2f(50.0, 600.0), sf::Vector2f(HALF));

    return set;
}

Set create_set_1() {
    Set set;
    sf::Texture platform_texture;
    sf::Texture coin_texture;
    sf::Texture star_texture;
    sf::Vector2f enemy_position(WIDTH+650,330.0-70);
    sf::Texture enemy_texture;

    enemy_texture.loadFromFile("resources/enemy.png");
    platform_texture.loadFromFile("resources/platform.png");
    coin_texture.loadFromFile("resources/coin.png");
    star_texture.loadFromFile("resources/star.png");
    
    Enemy enemy = create_enemy(enemy_position, enemy_texture);

    set.add_enemy(enemy, enemy_texture);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Bonus* coin = new Coin(coin_texture, sf::Vector2f(WIDTH + i*210 +j*50, 550 - i*90));
            set.add_bonus(coin);
        }
    }


    set.add_platform(platform_texture, sf::Vector2f(WIDTH, 600.0), sf::Vector2f(HALF));
    set.add_platform(platform_texture, sf::Vector2f(WIDTH + 200.0, 510.0), sf::Vector2f(HALF));
    set.add_platform(platform_texture, sf::Vector2f(WIDTH + 400.0, 420.0), sf::Vector2f(HALF));
    set.add_platform(platform_texture, sf::Vector2f(WIDTH + 600.0, 330.0), sf::Vector2f(HALF));

    return set;
}

Set create_set_2() {
    Set set;
    sf::Texture platform_texture;
    sf::Texture small_platform_texture;
    sf::Texture coin_texture;
    sf::Texture star_texture;

    platform_texture.loadFromFile("resources/platform.png");
    small_platform_texture.loadFromFile("resources/small_platform.png");
    coin_texture.loadFromFile("resources/coin.png");
    star_texture.loadFromFile("resources/star.png");

    for (int i = 0; i < 2; i++) {
        Bonus* coin = new Coin(coin_texture, sf::Vector2f(WIDTH+260+ i * 500, 500));
        set.add_bonus(coin);
    }


    set.add_platform(platform_texture, sf::Vector2f(WIDTH, 600), sf::Vector2f(HALF));
    set.add_platform(small_platform_texture, sf::Vector2f(WIDTH + 250, 550), sf::Vector2f(HALF));
    set.add_platform(platform_texture, sf::Vector2f(WIDTH + 500, 600), sf::Vector2f(HALF));
    set.add_platform(small_platform_texture, sf::Vector2f(WIDTH + 750, 550), sf::Vector2f(HALF));



    return set;
}

Set create_set_3() {
    Set set;
    sf::Texture small_platform_texture;
    sf::Texture long_platform_texture;
    sf::Texture coin_texture;
    sf::Texture star_texture;
    sf::Vector2f enemy_position(WIDTH + 100, 600.0-70);
    sf::Texture enemy_texture;

    enemy_texture.loadFromFile("resources/enemy.png");
    small_platform_texture.loadFromFile("resources/small_platform.png");
    long_platform_texture.loadFromFile("resources/long_platform.png");
    coin_texture.loadFromFile("resources/coin.png");
    star_texture.loadFromFile("resources/star.png");

    set.add_platform(long_platform_texture, sf::Vector2f(WIDTH, 600), sf::Vector2f(HALF));
    set.add_platform(small_platform_texture, sf::Vector2f(WIDTH + 200, 700), sf::Vector2f(HALF));
    set.add_platform(small_platform_texture, sf::Vector2f(WIDTH + 450, 600), sf::Vector2f(HALF));
    set.add_platform(small_platform_texture, sf::Vector2f(WIDTH + 650, 550), sf::Vector2f(HALF));


    Enemy enemy = create_enemy(enemy_position, enemy_texture);
    set.add_enemy(enemy, enemy_texture);

    Bonus* star = new Star(star_texture, sf::Vector2f(WIDTH + 200.0, 650.0));
    set.add_bonus(star);

    for (int i = 0; i < 3; i++) {
        Bonus* coin = new Coin(coin_texture, sf::Vector2f(WIDTH + 500.0 +i*50, 540.0-i*20));
        set.add_bonus(coin);
    }
    
    

    return set;
}

Set create_set_4() {
    Set set;
    sf::Texture ground_platform_texture;
    sf::Texture medium_platform_texture;
    sf::Texture long_platform_texture;
    sf::Texture platform_texture;
    sf::Texture coin_texture;
    sf::Texture star_texture;
    sf::Texture enemy_texture;

    enemy_texture.loadFromFile("resources/enemy.png");
    ground_platform_texture.loadFromFile("resources/ground_platform.png");
    medium_platform_texture.loadFromFile("resources/medium_platform.png");
    long_platform_texture.loadFromFile("resources/long_platform.png");
    platform_texture.loadFromFile("resources/platform.png");
    coin_texture.loadFromFile("resources/coin.png");
    star_texture.loadFromFile("resources/star.png");

    for (int i = 0; i < 3; i++) {
        sf::Vector2f enemy_position(WIDTH+350 +i*200, 500-70-i*100);
        Enemy enemy = create_enemy(enemy_position, enemy_texture);
        set.add_enemy(enemy,enemy_texture);
    }

    for (int i = 0; i < 9; i++) {
        sf::Vector2f bonus_position(WIDTH+805+i*23 ,250);
        Bonus* bonus;
        if (i == 8) {
            bonus = new Star(star_texture, bonus_position);
        }
        else {
            bonus = new Coin(coin_texture, bonus_position);
        }
        
        set.add_bonus(bonus);
    }
    

    set.add_platform(platform_texture, sf::Vector2f(WIDTH + 300.0, 500), sf::Vector2f(HALF));
    set.add_platform(platform_texture, sf::Vector2f(WIDTH + 500.0, 400), sf::Vector2f(HALF));
    set.add_platform(long_platform_texture, sf::Vector2f(WIDTH + 700.0, 300), sf::Vector2f(HALF));
    set.add_platform(ground_platform_texture, sf::Vector2f(WIDTH, 600), sf::Vector2f(HALF));


    return set;
}

Set create_set_5() {
    Set set;
    sf::Texture platform_texture;
    sf::Texture medium_platform_texture;
    sf::Texture small_platform_texture;
    sf::Texture coin_texture;


    platform_texture.loadFromFile("resources/platform.png");
    small_platform_texture.loadFromFile("resources/small_platform.png");
    medium_platform_texture.loadFromFile("resources/medium_platform.png");
    coin_texture.loadFromFile("resources/coin.png");
   
    Bonus* coin = new Coin(coin_texture, sf::Vector2f(WIDTH + 227, 410));
    set.add_bonus(coin);

    set.add_platform(medium_platform_texture, sf::Vector2f(WIDTH, 550), sf::Vector2f(HALF));
    set.add_platform(small_platform_texture, sf::Vector2f(WIDTH + 220, 460), sf::Vector2f(HALF));
    set.add_platform(platform_texture, sf::Vector2f(WIDTH + 400, 370), sf::Vector2f(HALF));

    return set;
}

Set create_set_break() {
    Set set;
    sf::Texture ground_platform_texture;
    sf::Texture coin_texture;
    sf::Texture star_texture;
    coin_texture.loadFromFile("resources/coin.png");
    ground_platform_texture.loadFromFile("resources/ground_platform.png");
    star_texture.loadFromFile("resources/star.png");

    for (int i = 1; i < 13; i++) {
            Bonus* coin = new Coin(coin_texture, sf::Vector2f(WIDTH + 100 * i, 550));
            set.add_bonus(coin);
    }

    set.add_platform(ground_platform_texture, sf::Vector2f(WIDTH, 600), sf::Vector2f(HALF));

    return set;
}

// initializing and updating sets
void spawn_set(std::vector<Set>& sets) {
    int set_choice;
    static int previous_choice;
    static int spawned = 0;
    Set& last_set = sets.back();
    Platform& last_platform = last_set.platforms.back();

    auto limit = last_platform.getPosition().x + last_platform.getGlobalBounds().width;

    if (limit <= LIMIT) {

        if (spawned < 2) {
            do {
                set_choice = rand() % 5;
            } while (set_choice == previous_choice);

            previous_choice = set_choice;

            Set set;
            switch (set_choice)
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
            default:
                break;
            }
            spawned++;
        }
        else {
            Set set = create_set_break();
            sets.emplace_back(set);
            spawned = 0;
        }
    }

}

void clear_set(std::vector<Set>& sets) {
    Set& first_set = sets.front();
    Platform& last_platform = first_set.platforms.back();

    if (last_platform.getPosition().x + last_platform.getGlobalBounds().width <= 0) {
        // Clean up bonuses
        for (auto bonus : first_set.bonuses) {
            delete bonus;
        }
        sets.erase(sets.begin());
    }
}

void set_init(std::vector<Set>& sets) {
    for (auto& set : sets) {
        for (size_t i = 0; i < set.platforms.size(); i++) {
           set.platforms[i].setTexture(set.platform_textures[i]);
        }
        for (auto& enemy : set.enemies) {
            enemy.setTexture(set.enemy_texture);
        }
    }
}

void set_update(sf::Time& elapsed_time, sf::Time progress_time, std::vector<Set>& sets, Hero &hero) {
    progress_time += elapsed_time;
    static int velocity_multiplier = 1;



    if (progress_time.asSeconds() >= 10.0) {
        progress_time = sf::Time::Zero;
        velocity_multiplier += 0.1;
    }
    set_init(sets);
    



    for (auto& set : sets) {
        float o_velocity = set.objects_velocity * velocity_multiplier;

        for (auto& platform : set.platforms) {
            platform.move(set.objects_velocity * velocity_multiplier * elapsed_time.asSeconds(), 0.0);
        }
        for (auto& enemy : set.enemies) {
            enemy.update(elapsed_time, o_velocity);
        }
        for (auto it = set.bonuses.begin(); it != set.bonuses.end();) {
            (*it)->move(set.objects_velocity * velocity_multiplier * elapsed_time.asSeconds(), 0.0);
            if ((*it)->interaction(hero)) {
                delete* it;
                it = set.bonuses.erase(it);
            }
            else {
                it++;
            }
        }
    }
}

//game functions
void over_borderline(Hero& hero, sf::RenderWindow& window, bool& end) {

    if (hero.getPosition().x + hero.getGlobalBounds().width <= 0 ||
        hero.getPosition().y >= window.getSize().y) {
        end = true;
    }
}

void fight(Hero& hero, std::vector<Set>& sets, bool& end) {
    if (!end) {
        for (auto& set : sets) {
            for (auto it = set.enemies.begin(); it != set.enemies.end();) {
                if (hero.getGlobalBounds().intersects(it->getGlobalBounds())) {
                    if (hero.get_attitude() == State::passive) {
                        hero.rotate(-90);

                        end = true;
                        break;
                    }
                    else if (hero.get_attitude() == State::attacking) {
                        it = set.enemies.erase(it);
                        continue;
                    }
                }

                it++;
            }
            //arrows collision
            for (auto& enemy : set.enemies) {
                for (auto it = enemy.arrows.begin(); it != enemy.arrows.end();) {
                    if (hero.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
                        hero.rotate(-90);

                        delete* it;
                        it = enemy.arrows.erase(it);
                        end = true;
                        break;
                    }
                    else {
                        it++;
                    }
                }
            }
        }
    }
    
}


sf::Text load_score(Hero& hero, sf::Font &font) {
    sf::Text text;
    std::stringstream string_score;
    string_score << hero.score << " x" << hero.multiplier;

    text.setFont(font);
    text.setString(string_score.str());
    text.setCharacterSize(30.f);
    text.setPosition(sf::Vector2f(0.01*WIDTH, 0.01* HEIGHT));

    return text;
}

sf::Text string_text(sf::Font& font, std::string name) {
    sf::Text text;

    text.setFont(font);
    text.setString(name);
    text.setCharacterSize(100.f);
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / 2));

    return text;
}

sf::Text arrow_amount(sf::Font& font) {
    sf::Text text;
    std::stringstream string_arrows;
    //string_arrows << " x" << hero.get_arrows_size();

    text.setFont(font);
    text.setString(string_arrows.str());
    text.setCharacterSize(30.f);
    text.setPosition(sf::Vector2f(0.01 * WIDTH, 0.01 * HEIGHT));

    return text;
}
//main
int main() {
    //game variables
    srand(static_cast<unsigned int>(time(0)));
    bool end = false;
    bool pause = false;
    sf::Clock clock;
    sf::Time game_time = clock.restart();
    sf::Time progress_time;
    sf::Font font;
    font.loadFromFile("resources/PixelEmulator-xq08.ttf");
    sf::Text text;
    sf::Text score;
    sf::Texture arrow_texture;
    arrow_texture.loadFromFile("resources/arrow.png");


    //create the window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "PixelRunner");
    window.setFramerateLimit(60);

    //create sky object
    GraphicalObject sky = create_sky();

    //create sets objects
    std::vector<Set> sets;
    Set starting_set = create_starting_set();
    sets.emplace_back(starting_set);


    //create hero
    Hero hero = create_hero();

    //create info object
    GraphicalObject arrow(arrow_texture, sf::Vector2f(0.9*WIDTH, 0.05*HEIGHT));
    arrow.setScale(2, 2);
    arrow.rotate(45);

    //game loop
    while (window.isOpen()) {
        // restart the clock to get elapsed time since the last restart
        sf::Time elapsed_time = clock.restart();
        score = load_score(hero, font);
        //polling
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    pause = !pause;
                }
            }
        }


        if (!pause) {
            over_borderline(hero, window, end);
            
            //platform methods
            set_update(elapsed_time, progress_time, sets, hero);

            spawn_set(sets);
            clear_set(sets);

            //hero methods
            hero.movement(elapsed_time);
            hero.update(elapsed_time, sets);
            hero.gain_score(game_time);

            fight(hero, sets, end);

        }
     
        
        //render
        window.clear();
        window.draw(sky);
        

        for (auto& set : sets) {
            for (const auto& platform : set.platforms) {
                window.draw(platform);
            }
            for (const auto& bonus : set.bonuses) {
                window.draw(*bonus);
            }
            for (auto& enemy : set.enemies) {
                window.draw(enemy);
                enemy.render_arrows(window);
            }
        }

        window.draw(hero);

        if (pause) {
            window.draw(sf::Text(string_text(font, "PAUSE")));
        }
        else if (end) {
            hero.lost();
            static sf::Time end_time;
            end_time += elapsed_time;
            window.draw(sf::Text(string_text(font, "GAME OVER")));
            if (end_time.asSeconds() >= 2) {
                window.close();
            }
        }
       
        window.draw(score);
        window.draw(arrow);
        window.display();
    }

    std::cout << "SCORE:\n" << hero.score << "\nCOINS COLLECTED:\n" << hero.collected;

    return 0;
}