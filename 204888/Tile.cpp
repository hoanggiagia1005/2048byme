#include "Tile.h"
sf::Vector2i genPosition() {
	sf::Vector2i p;
	while (1) {
		p.x = rand() % N;
		p.y = rand() % N;
		if (MAP[p.y][p.x] == 0)
			break;
	}
	return p;
}

int genNewTile() {
	if ((rand() % 2) == 0)
		return 2;
	else
		return 4;
}

void addNewTile() {
	sf::Vector2i p = genPosition();
	MAP[p.y][p.x] = genNewTile();
}