#include "MoveableRectangle.h"

MoveableRectangle::MoveableRectangle(sf::RenderWindow* window) : window(window) {}

MoveableRectangle::MoveableRectangle(float x, float y, float w, float h, sf::RenderWindow* window, sf::Color color) : sf::RectangleShape({w, h}), window(window) {
	setPosition(x, y);
	setFillColor(color);
}