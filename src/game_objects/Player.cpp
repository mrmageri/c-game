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

void Player::ProcessEvent(sf::Event &) {}

void Player::ProcessKeyboard() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && can_jump) {
        jumped = true;
    } else {
        jumped = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && canMoveRight) {
        speedx = 5.0f;
        setTexture(&textureRight);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && canMoveLeft) {
        speedx = -5.0f;
        setTexture(&textureLeft);
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
        !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        speedx = 0;
        setTexture(&texture);
    }
}

void Player::ProcessLogic(const std::vector<sf::RectangleShape *> &rectangleshape) {
    sf::FloatRect player_boundingBox = this->getGlobalBounds();
    std::vector<sf::RectangleShape *> collision_shapes;
    for (int i = 0; i < rectangleshape.size(); ++i) {
        auto collision = intersectOfRectangles(*this, *rectangleshape[i], {speedx, speedy});
        if (collision != NONE) {
            collision_shapes.push_back(rectangleshape[i]);
        }
    }
    if (!collision_shapes.empty()) {
        ProcessMovementManyCubes(collision_shapes);
        return;
    }
    speedy = std::min(8.0f, speedy + 0.2f);

    std::cout << speedx << ' ' << speedy << '\n';
    move(speedx, speedy);
}

COLLISION_DIRECTION intersectOfRectangles(const MoveableRectangle &lhs, const sf::RectangleShape &rhs,
                                          const sf::Vector2<float> &lhs_speed) {
    static int counter = 0;
    if (lhs.getPosition().y + lhs.getSize().y >= rhs.getPosition().y &&
        lhs.getPosition().y < rhs.getPosition().y &&
        lhs.getPosition().x + lhs.getSize().x >= rhs.getPosition().x &&
        lhs.getPosition().x < rhs.getPosition().x + rhs.getSize().x) {
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

void Player::ProcessMovementManyCubes(const std::vector<sf::RectangleShape*>& shapes) {
    can_jump = false;
    for (const auto& cube : shapes) {
        auto rectangleshape = *cube;
        if (getPosition().x + speedx <= 0u || getPosition().x + speedx + getSize().x >= window->getSize().x) {
            speedx = 0;
        }
        if (getPosition().y + speedy <= 0u || getPosition().y + speedy + getSize().y >= window->getSize().y) {
            speedy = 0;
        }


        COLLISION_DIRECTION direction = intersectOfRectangles(*this, rectangleshape, {speedx, speedy});

        if (direction == UP) {
            setPosition(getPosition().x, rectangleshape.getPosition().y - getSize().y);
            speedy = 0;
            can_jump = true;
        }
        if (direction == DOWN) {
            setPosition(getPosition().x, rectangleshape.getPosition().y + rectangleshape.getSize().y);
            speedy = 0;
        }
        if (direction == LEFT) {
            setPosition(rectangleshape.getPosition().x - getSize().x, getPosition().y);
            speedx = 0;
        }
        if (direction == RIGHT) {
            setPosition(rectangleshape.getPosition().x + rectangleshape.getSize().x, getPosition().y);
            speedx = 0;
        }
    }
    if (can_jump && jumped) speedy = -6.;
    speedy = std::min(0.f, speedy + 0.5f);
    move({speedx, speedy});
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
            speedy = std::min(8.0f, speedy + 0.2f);

        }
    } else {
        if (jumped) {
            speedy = -6.f;
        }
    }

    if (direction == UP) {
        setPosition(getPosition().x, rectangleshape.getPosition().y - getSize().y);
        if (!jumped) speedy = 0;
        jumped = false;
    }
    if (direction == DOWN) {
        setPosition(getPosition().x, rectangleshape.getPosition().y + rectangleshape.getSize().y);
        speedy = 0;
    }
    if (direction == LEFT) {
        setPosition(rectangleshape.getPosition().x - getSize().x, getPosition().y);
        speedx = 0;
    }
    if (direction == RIGHT) {
        setPosition(rectangleshape.getPosition().x + rectangleshape.getSize().x, getPosition().y);
        speedx = 0;
    }
    move({speedx, speedy});
}


