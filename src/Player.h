#ifndef PLAYER
#define PLAYER

#include <SFML/Graphics.hpp>
#include <iostream>
#include"MoveableRectangle.h"

const std::string PLAYER_FRONT = "../../resources/player/playerFront.png";
const std::string PLAYER_BACK = "../../resources/player/playerBack.png";
const std::string PLAYER_RIGHT = "../../resources/player/playerRight.png";
const std::string PLAYER_LEFT = "../../resources/player/playerLeft.png";


class Player : public MoveableRectangle {
public:
	Player(sf::RenderWindow* window);
	Player(float x, float y, float w, float h, sf::RenderWindow* window, sf::Color color = sf::Color::White);

	virtual ~Player() = default;

	virtual void ProcessEvent(sf::Event& event) final;
	virtual void ProcessLogic(sf::RectangleShape& rectangleshape) final;

protected:
	virtual void ProcessMovement(sf::RectangleShape& rectangleshape) final;
};
#endif // !BouncCircle 