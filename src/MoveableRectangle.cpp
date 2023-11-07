#include"MoveableRectangle.h"

MoveableRectangle::MoveableRectangle(sf::RenderWindow* window) : window(window){}

MoveableRectangle::MoveableRectangle(float x, float y, float w, float h, sf::RenderWindow* window, sf::Color color) : sf::RectangleShape({ w, h }), window(window) {
	setPosition(x, y); 
	setFillColor(color);
	//setOutlineColor(sf::Color::Magenta); setOutlineThickness(10.0f);
}

void MoveableRectangle::ProcessEvent(sf::Event& event) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (speedy > -5.0f) {
			speedy -= 1.0f;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (speedy < 5.0f) speedy += 1.0f;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (speedx < 5.0f) speedx += 1.0f;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (speedx > -5.0f) speedx -= 1.0f;

	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		speedx = 0;
	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		speedy = 0;
	}
}

void MoveableRectangle::ProcessLogic(sf::RectangleShape& rectangleshape) {
	ProcessMovement(rectangleshape);

}

void MoveableRectangle::ProcessMovement(sf::RectangleShape& rectangleshape) {
	if (getPosition().x + speedx <= 0u || getPosition().x + speedx + getSize().x >= window->getSize().x) {
		speedx = 0;
	}
	if (getPosition().y + speedy <= 0u || getPosition().y + speedy + getSize().y >= window->getSize().y) {
		speedy = 0;
	}
	
	if (speedx < 0) {
		if (getGlobalBounds().intersects(rectangleshape.getGlobalBounds())) {
			setPosition(rectangleshape.getPosition().x + rectangleshape.getSize().x, getPosition().y);
			speedx = 0;
		}
	}else if (speedx > 0) {
		if (getGlobalBounds().intersects(rectangleshape.getGlobalBounds())) {
			setPosition(rectangleshape.getPosition().x - getSize().x, getPosition().y);
			speedx = 0;
		}
	}else if (speedy < 0) {
		if (getGlobalBounds().intersects(rectangleshape.getGlobalBounds())) {
			setPosition(getPosition().x, rectangleshape.getPosition().y + rectangleshape.getSize().y);
			speedy = 0;
		}
	} else if (speedy > 0) {
		if (getGlobalBounds().intersects(rectangleshape.getGlobalBounds())) {
			setPosition(getPosition().x, rectangleshape.getPosition().y - getSize().y);
			speedy = 0;
		}
	}
	move({ speedx, speedy });
}