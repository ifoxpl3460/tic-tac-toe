#pragma once
#include <SFML/Graphics.hpp>
class Tile {
private:
	sf::Vector2f size;
public:
	bool active;
	sf::RectangleShape* tile = new sf::RectangleShape;
	Tile ();
	void Active ();
	void SetPosition (float, float);
};