#include "Tile.h"

Tile::Tile () {
	active = 0;
	size = sf::Vector2f (100.f, 100.f);
	tile->setSize (size);
	tile->setFillColor (sf::Color::White);
	tile->setOutlineThickness (1.f);
	tile->setOutlineColor (sf::Color::Red);
}

void Tile::SetPosition (float x, float y) {
	tile->setPosition (x, y);
}