#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "MoveableRectangle.h"
#include "Player.h"
#include "Map.h"

const int MAX_FPS = 60;
const uint32_t WIDTH = 1920u;
const uint32_t HEIGHT = 1080u;

int main() {
    auto window = sf::RenderWindow{{WIDTH, HEIGHT}, "C++ Game"};
    window.setFramerateLimit(MAX_FPS);

    //Player player(500, 0, 72, 100, &window);

    //sf::RectangleShape rectangle({400, 400});
   // rectangle.setPosition(500, 500);

    Map map;

    map.LoadMap({
        {CellType::SQUARE, CellType::EMPTY, CellType::SQUARE},
        {CellType::EMPTY,CellType::SQUARE,CellType::EMPTY},
        {CellType::SQUARE, CellType::EMPTY, CellType::SQUARE}
        });

    while (window.isOpen()) {
        for (auto event = sf::Event{}; window.pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
//            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
//            }
        }

        //player.ProcessKeyboard();
        window.clear(sf::Color(67, 100, 199));
        map.Draw(window);
        //player.ProcessLogic(rectangle);
        //window.draw(player);
        //window.draw(rectangle);
        window.display();
    }
    return 0;
}