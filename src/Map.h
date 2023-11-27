#ifndef MAP
#define MAP
#include<vector>
#include <SFML/Graphics.hpp>
#include "Square.h"

enum class CellType
{
	SQUARE,
	EMPTY
};

class Map {
public:
	Map();
	~Map() = default;

	void LoadMap(const std::vector<std::vector<CellType>>& cells);
	void Draw(sf::RenderWindow& window);
	unsigned int getWidth();
	unsigned int getHieght();
private:
	std::vector<std::vector<CellType>> cells;
	std::vector<Square> squares;
};

#endif