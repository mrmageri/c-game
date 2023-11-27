#ifndef SQUARE_H
#define SQUARE_H

#include <SFML/Graphics.hpp>
const float size = 64;

class Square : public sf::RectangleShape {
public:
	Square();
	~Square() = default;
private:
};


#endif // !Square