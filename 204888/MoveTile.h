#pragma once

#include "Tile.h"
#include <SFML/Graphics.hpp>

enum Direction
{
	Left,
	Right,
	Up,
	Down,
};


void move(Direction d);
