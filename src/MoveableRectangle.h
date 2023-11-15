#ifndef MOVEABLERECTANGLE
#define MOVEABLERECTANGLE
#include <SFML/Graphics.hpp>
#include <iostream>
class MoveableRectangle : public sf::RectangleShape{
public:
	MoveableRectangle(sf::RenderWindow* window);
	MoveableRectangle(float x ,float y, float w, float h,sf::RenderWindow* window, const std::string& path, sf::Color color = sf::Color::White);

	~MoveableRectangle() = default;

	void ProcessEvent(sf::Event& event);

	void ProcessLogic(sf::RectangleShape& rectangleshape);
private:
	void ProcessMovement(sf::RectangleShape& rectangleshape);

	sf::RenderWindow* window;
	float speedx = 0;
	float speedy = 0;
};
#endif // !BouncCircle 