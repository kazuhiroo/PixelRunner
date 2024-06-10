#include "Hero.h"
#include "Bonus.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

#define HEIGHT 768
#define WIDTH 1366
#define LIMIT 1200
#define HALF 0.5, 0.5


enum GameMode {
    menu,
    game_on,
    game_over
};

//creating basic game objects
Hero create_hero() {

    sf::Texture hero_texture;
    hero_texture.loadFromFile("resources/character2.png");

    Hero hero(hero_texture, sf::Vector2f(220.0, 150.0), 9);
    hero.setScale(2, 2);

    hero.add_animation_frame(sf::IntRect(205, 0, 30, 37)); // 1 frame of animation
    hero.add_animation_frame(sf::IntRect(255, 0, 30, 37)); // 2 frame
    hero.add_animation_frame(sf::IntRect(305, 0, 30, 37)); // 3 frame
    hero.add_animation_frame(sf::IntRect(355, 0, 30, 37)); // 4 frame

    return hero;
}

Enemy create_enemy(const sf::Vector2f &position, sf::Texture &enemy_texture) {
   
    Enemy enemy(enemy_texture, position, 2);
    enemy.setScale(2, 2);

    enemy.add_animation_frame(sf::IntRect(5, 0, 26, 34)); // 1 frame of animation
    enemy.add_animation_frame(sf::IntRect(55, 0, 26, 34)); // 2 frame
    enemy.add_animation_frame(sf::IntRect(105, 0, 26, 34)); // 3 frame
    enemy.add_animation_frame(sf::IntRect(157, 0, 26, 34)); // 4 frame


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
    sf::Vector2f enemy_position(WIDTH+650,330.0-65);
    sf::Texture enemy_texture;

    enemy_texture.loadFromFile("resources/enemy1.png");
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
    sf::Vector2f enemy_position(WIDTH + 100, 600.0 - 65);
    sf::Texture enemy_texture;

    enemy_texture.loadFromFile("resources/enemy1.png");
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

    enemy_texture.loadFromFile("resources/enemy1.png");
    ground_platform_texture.loadFromFile("resources/ground_platform.png");
    medium_platform_texture.loadFromFile("resources/medium_platform.png");
    long_platform_texture.loadFromFile("resources/long_platform.png");
    platform_texture.loadFromFile("resources/platform.png");
    coin_texture.loadFromFile("resources/coin.png");
    star_texture.loadFromFile("resources/star.png");

    for (int i = 0; i < 3; i++) {
        sf::Vector2f enemy_position(WIDTH+350 +i*200, 500-65 -i*100);
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
    sf::Texture enemy_texture;

    enemy_texture.loadFromFile("resources/enemy1.png");
    platform_texture.loadFromFile("resources/platform.png");
    small_platform_texture.loadFromFile("resources/small_platform.png");
    medium_platform_texture.loadFromFile("resources/medium_platform.png");
    coin_texture.loadFromFile("resources/coin.png");
   
    sf::Vector2f enemy_position(WIDTH + 100, 550.0 - 65);

    Enemy enemy = create_enemy(enemy_position, enemy_texture);

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

        if (spawned < 7) {
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

void set_update(sf::Time& elapsed_time, sf::Time &progress_time, std::vector<Set>& sets, Hero &hero, float &velocity_progress) {
    progress_time += elapsed_time;


    if (progress_time.asSeconds() >= 10.0) {
        progress_time = sf::Time::Zero;
        velocity_progress -= 1.0;
    }
    set_init(sets);
    



    for (auto& set : sets) {
        float o_velocity = set.objects_velocity + velocity_progress;

        for (auto& platform : set.platforms) {
            platform.move(o_velocity * elapsed_time.asSeconds(), 0.0);
        }
        for (auto& enemy : set.enemies) {
            enemy.update(elapsed_time, o_velocity);
            enemy.move(o_velocity * elapsed_time.asSeconds(), 0.0);
        }
        for (auto it = set.bonuses.begin(); it != set.bonuses.end();) {
            (*it)->move(o_velocity * elapsed_time.asSeconds(), 0.0);
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
    if (end) return;

    for (auto& set : sets) {
        for (auto enemy_it = set.enemies.begin(); enemy_it != set.enemies.end();) {
            auto& enemy = *enemy_it;
            bool enemy_erased = false;

            // Sprawdzenie kolizji miêdzy strza³ami bohatera a wrogiem
            for (auto arrow_it = hero.arrows.begin(); arrow_it != hero.arrows.end();) {
                if (enemy.getGlobalBounds().intersects((*arrow_it)->getGlobalBounds())) {
                    delete* arrow_it;
                    arrow_it = hero.arrows.erase(arrow_it);
                    enemy_it = set.enemies.erase(enemy_it);
                    enemy_erased = true;
                    break;
                }
                else {
                    ++arrow_it;
                }
            }

            if (enemy_erased) continue;

            // Sprawdzenie kolizji miêdzy bohaterem a wrogiem
            if (hero.getGlobalBounds().intersects(enemy.getGlobalBounds())) {
                if (hero.get_attitude() == State::passive) {
                    hero.rotate(-90);
                    end = true;
                    return;
                }
                else if (hero.get_attitude() == State::attacking) {
                    enemy_it = set.enemies.erase(enemy_it);
                    continue;
                }
            }

            ++enemy_it;
        }

        // Sprawdzenie kolizji miêdzy strza³ami wrogów a bohaterem
        for (auto& enemy : set.enemies) {
            for (auto arrow_it = enemy.arrows.begin(); arrow_it != enemy.arrows.end();) {
                if (hero.getGlobalBounds().intersects((*arrow_it)->getGlobalBounds())) {
                    if (hero.get_attitude() == State::attacking) {
                        hero.eq++;
                    }
                    else {
                        hero.rotate(-90);
                        end = true;
                    }
                    delete* arrow_it;
                    arrow_it = enemy.arrows.erase(arrow_it);
                    break;
                }
                else {
                    ++arrow_it;
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

sf::Text string_text(sf::Font& font, std::string name, float x, float y, float size) {
    sf::Text text;

    text.setFont(font);
    text.setString(name);
    text.setCharacterSize(size);
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
    text.setPosition(sf::Vector2f(x,y));

    return text;
}

sf::Text arrow_amount(Hero& hero, sf::Font& font) {
    sf::Text text;
    std::stringstream string_arrows;
    string_arrows << "x" << hero.eq;

    text.setFont(font);
    text.setString(string_arrows.str());
    text.setCharacterSize(30.f);
    text.setPosition(sf::Vector2f(0.9 * WIDTH, 0.05 * HEIGHT));

    return text;
}

//menu
void show_menu(sf::RenderWindow& window, sf::Font& font, GameMode& gameState, std::string best, std::string last) {
    sf::Text title = string_text(font, "PixelRunner", WIDTH*0.4, HEIGHT*0.3, 100);
    sf::Text play_option = string_text(font, "Press Space or W to Play", WIDTH * 0.4- 40, HEIGHT*0.3+ 100.0, 40);
    sf::Text exit_option = string_text(font, "Press Esc to Exit", WIDTH * 0.4- 150, HEIGHT*0.3 + 150.0, 40);
    sf::Text best_text = string_text(font, "Best Run: " + best, WIDTH * 0.5, HEIGHT * 0.3 + 250.0, 40);
    sf::Text last_text = string_text(font, "Last Run: " + last, WIDTH * 0.5, HEIGHT * 0.3 + 300.0, 40);

    
    window.draw(title);
    window.draw(play_option);
    window.draw(exit_option);
    window.draw(best_text);
    window.draw(last_text);
}

void save_run(int score, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << score;
        file.close();
    }
    else {
        std::cerr << "Error opening file for writing: " << filename << "\n";
    }
}

std::string load_run(const std::string& filename) {
    std::ifstream file(filename);
    std::string run;
    if (file.is_open()) {
        std::getline(file, run);
        file.close();
    }
    else {
        std::cerr << "Error opening file for reading: " << filename << "\n";
    }
    return run;
}

std::string load_best_run() {
    return load_run("bestrun.txt");
}

std::string load_last_run() {
    return load_run("lastrun.txt");
}

//main
int main() {
    // Game variables
    srand(static_cast<unsigned int>(time(0)));
    bool end = false;
    bool pause = false;
    float velocity_progress = 0;
    sf::Clock clock;
    sf::Time game_time = clock.restart();
    sf::Time end_time = clock.restart();
    sf::Time progress_time;
    sf::Font font;
    font.loadFromFile("resources/PixelEmulator-xq08.ttf");

    sf::Text score;
    sf::Text aa_text;
    sf::Texture arrow_texture;
    arrow_texture.loadFromFile("resources/arrow.png");

    std::string string_best_run = load_best_run();
    std::string string_last_run = load_last_run();

    // Create the window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "PixelRunner");
    window.setFramerateLimit(60);

    // Create sky object
    GraphicalObject sky = create_sky();

    // Create sets objects
    std::vector<Set> sets;
    Set starting_set = create_starting_set();
    sets.emplace_back(starting_set);

    // Create hero
    Hero hero = create_hero();

    // Create info object
    GraphicalObject arrow(arrow_texture, sf::Vector2f(0.85 * WIDTH, 0.05 * HEIGHT));
    arrow.setScale(2.5, 2.5);
    arrow.rotate(45);

    // Game state
    GameMode game_state = menu;

    // Game loop
    while (window.isOpen()) {
        sf::Time elapsed_time = clock.restart();
        score = load_score(hero, font);
        aa_text = arrow_amount(hero, font);
        over_borderline(hero, window, end);


        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (game_state == game_on && sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
                    pause = !pause;
                }
                if (game_state == menu && (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
                    game_state = game_on;
                    end = false; // reset end state
                    progress_time = sf::Time::Zero; // reset progress time
                    end_time = sf::Time::Zero;
                    velocity_progress = 0; // reset velocity multiplier
                }
                if (game_state == menu && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                }
            }
        }


        if (game_state == game_on) {
            if (!pause) {
                // Platform methods
                set_update(elapsed_time, progress_time, sets, hero, velocity_progress);
                spawn_set(sets);
                clear_set(sets);

                // Hero methods
                hero.movement(elapsed_time);
                hero.update(elapsed_time, sets);
                if (!end) {
                    hero.gain_score(game_time);
                }
                fight(hero, sets, end);
            }

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




            //render in game
            hero.render_arrows(window);
            window.draw(score);
            window.draw(aa_text);
            window.draw(arrow);
            window.draw(hero);

            if (pause) {
                window.draw(string_text(font, "PAUSE", WIDTH / 2, HEIGHT / 2, 100));
            }
            if (end) {
                hero.lost();
                end_time += elapsed_time;
                window.draw(string_text(font, "GAME OVER", WIDTH / 2, HEIGHT / 2, 100));
                if (end_time.asSeconds() >= 2) {
                    end = false;
                    game_state = menu;
                    // saving score
                    int current_run = hero.score;
                    int best_run = std::stoi(load_best_run());

                    save_run(current_run, "lastrun.txt");

                    if (current_run > best_run) {
                        save_run(current_run, "bestrun.txt");
                    }

                    string_best_run = load_best_run();
                    string_last_run = load_last_run();

                    // resetting
                    hero.reset();
                    sets.clear();
                    sets.emplace_back(create_starting_set());
                    std::cout << "SCORE:\n" << hero.score << "\nCOINS COLLECTED:\n" << hero.collected;
                }
                
            }

            window.display();
        }
        else if (game_state == menu && !end) {
            hero.animate(elapsed_time);
            window.clear();
            window.draw(sky);
            window.draw(hero);
            show_menu(window, font, game_state, string_best_run, string_last_run);
            window.display();
        }
    }

    
    return 0;
}
