#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "MoveableRectangle.h"

const int MAX_FPS = 60;
const uint32_t WIDTH = 1920u;
const uint32_t HEIGHT = 1080u;

int main() {
    auto window = sf::RenderWindow{{WIDTH, HEIGHT}, "C++ Game"};
    window.setFramerateLimit(MAX_FPS);

    MoveableRectangle player(500,0, 72, 100, &window, "E:/mrmageri-ñ++/c-game/resources/player/player1.png");


    sf::RectangleShape rectangle({400,400});
    rectangle.setPosition(500, 500);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
                player.ProcessEvent(event);
            }
        }
        window.clear();
        player.ProcessLogic(rectangle);
        window.draw(player);
        window.draw(rectangle);
        window.display();
    }
    return 0;
}