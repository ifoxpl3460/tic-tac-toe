#include "Tile.h"

void Setup (Tile * tiles);
void HandleInput (sf::Event * evnt, Tile * tiles, int* t);
void ActiveTiles (Tile* tiles, int* t);

int main () {
	// sfml stuff
	sf::RenderWindow* win = new sf::RenderWindow (sf::VideoMode (301, 301), "tic-tac-toe");
	sf::Event* evnt = new sf::Event;

	// temporary tab
	Tile* tiles = new Tile[9];

	int t = 0;

	Setup (tiles);

	// main loop
	while (win->isOpen ()) {

		while (win->pollEvent (*evnt)) {
			if (evnt->type == sf::Event::Closed) win->close ();
			HandleInput (evnt, tiles, &t);
		}
		win->clear ();

		ActiveTiles (tiles, &t);

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

void Setup (Tile * tiles) {
	int n = 1, m = 1;
	// setting up position for each tile
	for (int i = 1; i < 10; i++) {
		tiles[i - 1].SetPosition (n, m);
		n += 100;
		if (i % 3 == 0) {
			n = 1;
			m += 100;
		}
	}
}


// Temp
void ActiveTiles (Tile * tiles, int * t) {
	if (*t == 0){
		tiles[0].Active ();
	}
	if (*t == 1) {
		tiles[1].Active ();
	}
	if (*t == 2) {
		tiles[2].Active ();
	}
	if (*t == 3) {
		tiles[3].Active ();
	}
	if (*t == 4) {
		tiles[4].Active ();
	}
	if (*t == 5) {
		tiles[5].Active ();
	}
	if (*t == 6) {
		tiles[6].Active ();
	}
	if (*t == 7) {
		tiles[7].Active ();
	}
	if (*t == 8) {
		tiles[8].Active ();
	}
}

// Temp
void HandleInput (sf::Event* evnt, Tile * tiles, int * t) {

	if (evnt->type == sf::Event::EventType::KeyPressed) {
		if (*t != 0) {
			if (evnt->key.code == sf::Keyboard::Left) {
				*t -= 1;
			}
		}

		if (*t != 8) {
			if (evnt->key.code == sf::Keyboard::Right) {
				*t += 1;
			}
		}

		if (*t != 0 && *t != 1 && *t != 2) {
			if (evnt->key.code == sf::Keyboard::Up) {
				*t -= 3;
			}
		}

		if (*t != 6 && *t != 7 && *t != 8) {
			if (evnt->key.code == sf::Keyboard::Down) {
				*t += 3;
			}

		}
	}
}