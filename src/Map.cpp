#include "Map.h"

Map::Map() {}

void Map::LoadMap(const std::vector<std::vector<CellType>>& cells) {
	this->cells = cells;
	for (int i = 0; i < cells.size(); ++i) {
		for (int j = 0; j < cells[i].size(); ++j) {
			if (cells[i][j] == CellType::SQUARE) { squares.push_back(Square()); 
			squares.back().setPosition({j*size,i*size});
			}
		}
	}
}
void Map::Draw(sf::RenderWindow& window) {
	for (const auto& elem : squares) {
		window.draw(elem);
	}
}
unsigned int Map::getWidth() {
	return 0;
}

unsigned int Map::getHieght() {
	return 0;
}