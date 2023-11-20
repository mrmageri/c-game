#ifndef MOVEABLERECTANGLE
#define MOVEABLERECTANGLE

#include <SFML/Graphics.hpp>
#include <iostream>

const std::string PLAYER_FRONT = "../../resources/player/playerFront.png";
const std::string PLAYER_BACK = "../../resources/player/playerBack.png";
const std::string PLAYER_RIGHT = "../../resources/player/playerRight.png";
const std::string PLAYER_LEFT = "../../resources/player/playerLeft.png";


class MoveableRectangle : public sf::RectangleShape{
public:
	MoveableRectangle(sf::RenderWindow* window);
	MoveableRectangle(float x ,float y, float w, float h,sf::RenderWindow* window, sf::Color color = sf::Color::White);

	~MoveableRectangle() = default;

	void ProcessEvent(sf::Event& event);

	void ProcessLogic(sf::RectangleShape& rectangleshape);
private:
	void ProcessMovement(sf::RectangleShape& rectangleshape);

	sf::RenderWindow* window;
	float speedx = 0;
	float speedy = 0;
	sf::Texture texture;
	sf::Texture textureRight;
	sf::Texture textureLeft;
};
#endif // !BouncCircle 