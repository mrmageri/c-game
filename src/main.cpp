#include <SFML/Graphics.hpp>
#include "MoveableRectangle.h"

const int MAX_FPS = 60;
const uint32_t WIDTH = 1920u;
const uint32_t HEIGHT = 1080u;

int main() {
    auto window = sf::RenderWindow{{WIDTH, HEIGHT}, "C++ Game"};
    window.setFramerateLimit(MAX_FPS);

    MoveableRectangle rectangle(5,5,100,50, &window);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                rectangle.ProcessEvent(event);
            }
        }
        window.clear();
        rectangle.ProcessLogic();
        window.draw(rectangle);
        window.display();
    }
    return 0;
}