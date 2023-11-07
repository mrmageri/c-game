#ifndef MOVEABLERECTANGLE
#define MOVEABLERECTANGLE
#include <SFML/Graphics.hpp>
class MoveableRectangle : public sf::RectangleShape{
public:
	MoveableRectangle(sf::RenderWindow* window);
	MoveableRectangle(float x ,float y, float w, float h,sf::RenderWindow* window);

	~MoveableRectangle() = default;

	void ProcessEvent(sf::Event& event);

	void ProcessLogic();
private:
	sf::RenderWindow* window;
	float speedx = 3.0f;
	float speedy = 3.0f;
};
#endif // !BouncCircle 