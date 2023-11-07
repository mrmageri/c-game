#include <SFML/Graphics.hpp>

const int MAX_FPS = 60;
const uint32_t WIDTH = 1920u;
const uint32_t HEIGHT = 1080u;

int main() {
    auto window = sf::RenderWindow{{WIDTH, HEIGHT}, "C++ Game"};
    window.setFramerateLimit(MAX_FPS);

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();

        window.display();
    }
    return 0;
}