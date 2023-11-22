#include "Player.h"

Player::Player(sf::RenderWindow *window) : MoveableRectangle(window) {}

Player::Player(float x, float y, float w, float h, sf::RenderWindow *window, sf::Color color) : MoveableRectangle(x, y,
                                                                                                                  w, h,
                                                                                                                  window,
                                                                                                                  color) {
    if (!texture.loadFromFile(PLAYER_FRONT)) {
        throw std::runtime_error("No player sprite found!");
    }
    if (!textureRight.loadFromFile(PLAYER_RIGHT)) {
        throw std::runtime_error("No player sprite found!");
    }
    if (!textureLeft.loadFromFile(PLAYER_LEFT)) {
        throw std::runtime_error("No player sprite found!");
    }
    setTexture(&texture);
};


void Player::ProcessEvent(sf::Event &event) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        if (!jumped) {
            speedy = -10.f;
        }
        jumped = true;
    }
    /* if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
         if (speedy < 5.0f) speedy += 1.0f;

     }  */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        speedx = 5.0f;
        setTexture(&textureRight);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        speedx = -5.0f;
        setTexture(&textureLeft);
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        speedx = 0;
        setTexture(&texture);
    }
    /*if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        speedy = 0;
    }*/
}

void Player::ProcessLogic(sf::RectangleShape &rectangleshape) {
    ProcessMovement(rectangleshape);
}

COLLISION_DIRECTION intersectOfRectangles(const MoveableRectangle &lhs, const sf::RectangleShape &rhs,
                                          const sf::Vector2<float> &lhs_speed) {
    static int counter = 0;
    if (lhs.getPosition().y + lhs.getSize().y > rhs.getPosition().y &&
        lhs.getPosition().y < rhs.getPosition().y &&
        lhs.getPosition().x + lhs.getSize().x > rhs.getPosition().x &&
        lhs.getPosition().x < rhs.getPosition().x + rhs.getSize().x && lhs_speed.y > 0) {
        std::cout << "TOP collision (" << ++counter << ")\n";
        return UP;
    } else if (lhs.getPosition().y < rhs.getPosition().y + rhs.getSize().y &&
               lhs.getPosition().y + lhs.getSize().y > rhs.getPosition().y + rhs.getSize().y &&
               lhs.getPosition().x + lhs.getSize().x > rhs.getPosition().x &&
               lhs.getPosition().x < rhs.getPosition().x + rhs.getSize().x && lhs_speed.y < 0) {
        std::cout << "BOTTOM collision (" << ++counter << ")\n";
        return DOWN;
    } else if (lhs.getPosition().x + lhs.getSize().x >= rhs.getPosition().x &&
               lhs.getPosition().x < rhs.getPosition().x &&
               lhs.getPosition().y + lhs.getSize().y > rhs.getPosition().y &&
               lhs.getPosition().y < rhs.getPosition().y + rhs.getSize().y && lhs_speed.x > 0
            ) {
        std::cout << "LEFT collision (" << ++counter << ")\n";
        return LEFT;
    } else if (lhs.getPosition().x <= rhs.getPosition().x + rhs.getSize().x &&
               lhs.getPosition().x + lhs.getSize().x > rhs.getPosition().x &&
               lhs.getPosition().y + lhs.getSize().y > rhs.getPosition().y &&
               lhs.getPosition().y < rhs.getPosition().y + rhs.getSize().y && lhs_speed.x < 0
            ) {
        std::cout << "RIGHT collision (" << ++counter << ")\n";
        return RIGHT;
    }
    return NONE;
}


void Player::ProcessMovement(sf::RectangleShape &rectangleshape) {
    if (getPosition().x + speedx <= 0u || getPosition().x + speedx + getSize().x >= window->getSize().x) {
        speedx = 0;
    }
    if (getPosition().y + speedy <= 0u || getPosition().y + speedy + getSize().y >= window->getSize().y) {
        speedy = 0;
    }
    COLLISION_DIRECTION direction = intersectOfRectangles(*this, rectangleshape, {speedx, speedy});
    if (direction != UP) {
        if (getPosition().y + getSize().y != rectangleshape.getPosition().y ||
            (getPosition().x >= rectangleshape.getPosition().x + rectangleshape.getSize().x ||
             getPosition().x + getSize().x <= rectangleshape.getPosition().x)) {
            if (jumped) { 
                speedy = std::min(speedy + 1.f, 7.f); 
            }
            else {
                speedy += 1.f;
            }
        } else {
            if (!jumped) {
                speedy = 0;
            }
        }
    }
    switch (direction) {
        case UP:
            setPosition(getPosition().x, rectangleshape.getPosition().y - getSize().y);
            speedy = 0;
            jumped = false;
            break;
        case DOWN:
            setPosition(getPosition().x, rectangleshape.getPosition().y + rectangleshape.getSize().y);
            speedy = 0;
            break;
        case LEFT:
            setPosition(rectangleshape.getPosition().x - getSize().x, getPosition().y);
            speedx = 0;
            break;
        case RIGHT:
            setPosition(rectangleshape.getPosition().x + rectangleshape.getSize().x, getPosition().y);
            speedx = 0;
            break;
        case NONE:
            break;
    }
    move({speedx, speedy});
}

