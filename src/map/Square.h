#ifndef SQUARE_H
#define SQUARE_H

#include "SFML/Graphics.hpp"
const float size = 64;

#if defined(_WIN64)
const std::string SQUARE_SPR = "../../../../resources/square/squareSprite.png";
#else
const std::string SQUARE_SPR = "../../resources/square/squareSprite.png";
#endif

class Square : public sf::RectangleShape {
public:
	Square();
	~Square() = default;
private:
	sf::Texture texture;
};


#endif // !Square