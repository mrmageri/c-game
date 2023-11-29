#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include <iostream>
#include "MoveableRectangle.h"

#if defined(_WIN64)
const std::string PLAYER_FRONT = "../../../../resources/player/playerFront.png";
const std::string PLAYER_BACK = "../../../../resources/player/playerBack.png";
const std::string PLAYER_RIGHT = "../../../../resources/player/playerRight.png";
const std::string PLAYER_LEFT = "../../../../resources/player/playerLeft.png";
#else
const std::string PLAYER_FRONT = "../../resources/player/playerFront.png";
const std::string PLAYER_BACK = "../../resources/player/playerBack.png";
const std::string PLAYER_RIGHT = "../../resources/player/playerRight.png";
const std::string PLAYER_LEFT = "../../resources/player/playerLeft.png";
#endif


class Player : public MoveableRectangle {
public:
    Player(sf::RenderWindow *window);

    Player(float x, float y, float w, float h, sf::RenderWindow *window, sf::Color color = sf::Color::White);

    virtual ~Player() = default;

    virtual void ProcessEvent(sf::Event&) final;

    void ProcessKeyboard();

    virtual void ProcessLogic(const std::vector<sf::RectangleShape*> &rectangleshape) final;

protected:
    virtual void ProcessMovement(sf::RectangleShape &rectangleshape) final;
private:
    bool jumped = false;
};

#endif // !Player_H