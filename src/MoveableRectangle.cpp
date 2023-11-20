#include "MoveableRectangle.h"

MoveableRectangle::MoveableRectangle(sf::RenderWindow* window) : window(window) {}

MoveableRectangle::MoveableRectangle(float x, float y, float w, float h, sf::RenderWindow* window, sf::Color color) {
	setPosition(x, y);
	setFillColor(color);
}