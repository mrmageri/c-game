#include "Square.h"

Square::Square() : sf::RectangleShape({size,size}) {
    if (!texture.loadFromFile(SQUARE_SPR)) {
        throw std::runtime_error("No sprite found!");
    }
    setTexture(&texture);
}

	
