#include <SFML/Graphics.hpp>

// tile class
class Tile {
private:
	sf::Vector2f size;
	
public:
	bool active = 0;
	sf::RectangleShape tile;
	Tile () {
		size = sf::Vector2f (100.f, 100.f);
		tile.setSize (size);
		tile.setFillColor (sf::Color::White);
		tile.setOutlineThickness (1.f);
		tile.setOutlineColor (sf::Color::Red);
	}
	void SetPosition (float x, float y) {
		tile.setPosition (x, y);
	}
	void Active () {
		active = !active;
	}
};

int main () {
	// sfml stuff
	sf::RenderWindow* win = new sf::RenderWindow (sf::VideoMode (301, 301), "tic-tac-toe");
	sf::Event* evnt = new sf::Event;

	// temporary tab
	Tile tiles[9];

	tiles[0].active = 1;

	int n = 1, m = 1;

	// setting up position for each tile
	for (int i = 1; i < 10; i++) {
		tiles[i-1].SetPosition (n, m);
		n += 100;
		if (i % 3 == 0) {
			n = 1;
			m += 100;		
		}
	}

	// main loop
	while (win->isOpen ()) {

		while (win->pollEvent (*evnt)) {
			if (evnt->type == sf::Event::Closed) win->close ();
		}
		win->clear ();

		for (int i = 0; i < 9; i++) {
			if (tiles[i].active == 1) {
				tiles[i].tile.setFillColor (sf::Color::Green);
			}
			win->draw (tiles[i].tile);
		}	
		win->display ();
	}
	return 0;
}