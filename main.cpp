#include "include.h"

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(1366, 768), "My window");

    sf::Clock clock;
    sf::Texture sky_texture;
    sky_texture.loadFromFile("sky.png");

    GraphicalObject sky(sky_texture, sf::Vector2f(0.0,0.0), sf::IntRect(0,0,1366, 100));

    //game loop
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }











        window.clear();

        window.draw(sky);

        window.display();


        sf::Time elapsed = clock.restart(); // Restart the clock to get elapsed time since the last restart
        //std::cout << elapsed.asSeconds() << "\n"; // Print elapsed time in seconds
    }


    return 0;
}
