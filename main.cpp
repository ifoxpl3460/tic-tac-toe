#include <SFML/Graphics.hpp>

// tile class
class Tile {
private:
	sf::Vector2f size;
public:
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
};

int main () {
	// sfml stuff
	sf::RenderWindow* win = new sf::RenderWindow (sf::VideoMode (301, 301), "tic-tac-toe");
	sf::Event* evnt = new sf::Event;

	// temporary tab
	Tile tiles[9];

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
			win->draw (tiles[i].tile);
		}	
		win->display ();
	}
	return 0;
}