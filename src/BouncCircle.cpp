#include <SFML/Graphics.hpp>
#include"BouncCircle.h"

BouncCircle::BouncCircle(float r, float speedX, float speedY) : sf::CircleShape(r), speedX(speedX), speedY(speedY){}


void BouncCircle::Process() {
    if (getPosition().y + getRadius() > 540u) {
        setPosition(getPosition().x, 540.0 - getRadius());
        acceleration = 0.0;
        isHitGround = true;
        //move({ speedX, speedY -= (acceleration * startTime.getElapsedTime().asSeconds()) / 10 });
    }
   else {
        if (!isHitGround)
        { 
            move({ speedX, speedY += (acceleration * startTime.getElapsedTime().asSeconds()) / 10 }); 
        }
        else {
            move({ speedX, 0 });
            if (getFillColor().r == 255) {
                changeToOpposite = true;
            }
            else if (getFillColor().r == 0) {
                changeToOpposite = false;
            }
            setFillColor(sf::Color(getFillColor().r + (changeToOpposite ? 5 : -5), getFillColor().g, getFillColor().b));
            setRadius(getRadius() + (changeToOpposite ? 1 : -1));
        }
    }
}