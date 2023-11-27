#ifndef MAP
#define MAP

#include<vector>
#include "SFML/Graphics.hpp"
#include "Square.h"
#include "../game_objects/Player.h"

enum class CellType {
    SQUARE,
    EMPTY,
    PLAYER
};

class Map {
public:
    Map();

    ~Map() = default;

    void LoadMap(const std::vector<std::vector<CellType>> &cells, Player &player);

    void Draw(sf::RenderWindow &window);

    unsigned int getWidth();

    unsigned int getHieght();

    const std::vector<sf::RectangleShape*>& getMap() const;

private:
    std::vector<std::vector<CellType>> cells;
    std::vector<sf::RectangleShape*> squares;
};

#endif