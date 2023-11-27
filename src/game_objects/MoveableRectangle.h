#ifndef MOVEABLERECTANGLE
#define MOVEABLERECTANGLE

#include "SFML/Graphics.hpp"
#include <iostream>

enum COLLISION_DIRECTION {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};


class MoveableRectangle : public sf::RectangleShape {
public:
    MoveableRectangle(sf::RenderWindow *window);

    MoveableRectangle(float x, float y, float w, float h, sf::RenderWindow *window, sf::Color color = sf::Color::White);

    virtual ~MoveableRectangle() = default;

    virtual void ProcessEvent(sf::Event&) = 0;

    virtual void ProcessLogic(sf::RectangleShape &rectangleshape) = 0;

protected:
    virtual void ProcessMovement(sf::RectangleShape &rectangleshape) = 0;

    sf::RenderWindow *window;
    float speedx = 0;
    float speedy = 0;
    sf::Texture texture;
    sf::Texture textureRight;
    sf::Texture textureLeft;
};

#endif // !MoveableRectangle