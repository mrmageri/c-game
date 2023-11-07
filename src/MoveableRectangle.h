#ifndef MOVEABLERECTANGLE
#define MOVEABLERECTANGLE
#include <SFML/Graphics.hpp>
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
};
#endif // !BouncCircle 