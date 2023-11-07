#include <SFML/Graphics.hpp>
#include"BouncCircle.h"

int main()
{
    std::srand(std::time(nullptr));
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "C++Game" };
    window.setFramerateLimit(60);


    std::vector<BouncCircle> circles;
    sf::CircleShape circle(50.0);
    circle.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    circle.setPosition(circle.getPosition().x - 2 * circle.getRadius(), circle.getPosition().y);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    circle.setPosition(circle.getPosition().x + 2 * circle.getRadius(), circle.getPosition().y);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    circle.setPosition(circle.getPosition().x, circle.getPosition().y + 2 * circle.getRadius());
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    circle.setPosition(circle.getPosition().x, circle.getPosition().y - 2 * circle.getRadius());
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tilde)) {
                    circles.emplace_back(BouncCircle(25.0, 3, 3));
                    circles.back().setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
                    circles.back().setFillColor(sf::Color(std::rand() % 256, std::rand() % 256, std::rand() % 256));
                }
            }
        }
        window.clear();
        for (auto& elem : circles) {
            elem.Process();
            window.draw(elem);
        }
        window.draw(circle);
        window.display();
    }
}