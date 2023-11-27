#ifndef BOUNCCIRCLE
#define BOUNCCIRCLE
#include "SFML/Graphics.hpp"
class BouncCircle : public sf::CircleShape {
public:
    BouncCircle() = delete;
    BouncCircle(float r, float speedX, float speedY);

    void Process();

    ~BouncCircle() = default;

private:
    bool changeToOpposite = false;
    bool isHitGround = false;
    sf::Clock startTime;
    float speedX;
    float speedY;
    float acceleration = 9.8;
};
#endif // !BouncCircle 
