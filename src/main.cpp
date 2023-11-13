#include <SFML/Graphics.hpp>
#include "MoveableRectangle.h"

const int MAX_FPS = 60;
const uint32_t WIDTH = 1920u;
const uint32_t HEIGHT = 1080u;

int main() {
    auto window = sf::RenderWindow{{WIDTH, HEIGHT}, "C++ Game"};
    window.setFramerateLimit(MAX_FPS);

    MoveableRectangle player(5,5,100,50, &window);
    MoveableRectangle rectangle(500, 500, 400, 400, &window, sf::Color::Red);

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