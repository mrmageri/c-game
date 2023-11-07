#include"MoveableRectangle.h"

MoveableRectangle::MoveableRectangle(sf::RenderWindow* window) : window(window){}

MoveableRectangle::MoveableRectangle(float x, float y, float w, float h, sf::RenderWindow* window) : sf::RectangleShape({ w, h }), window(window) {
	setPosition(x, y); setOutlineColor(sf::Color::Magenta); setOutlineThickness(10.0f);
}

void MoveableRectangle::ProcessEvent(sf::Event& event) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		speedy -= 0.1f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		speedy += 0.1f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		speedx += 0.1f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		speedx -= 0.1f;
	}
}

void MoveableRectangle::ProcessLogic() {
	if (getPosition().x + speedx <= 0u || getPosition().x + speedx + getSize().x >= window->getSize().x) {
		speedx = 0;
	}
	if (getPosition().y + speedy <= 0u || getPosition().y + speedy + getSize().y >= window->getSize().y) {
		speedy = 0;
	}
	move({speedx, speedy});
}