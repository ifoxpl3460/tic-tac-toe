#include "Tile.h"
#include <iostream>

void Setup (Tile*);
void RenderTiles (Tile*, sf::RenderWindow*);
void HandleInput (sf::Event*, Tile*, int*, sf::RenderWindow*);
void ActiveTiles (Tile*, int*);

int main () {
	int pos = 0;

	// sfml stuff
	sf::RenderWindow* win = new sf::RenderWindow (sf::VideoMode (302, 302), "tic-tac-toe");
	sf::Event* evnt = new sf::Event;

	// temporary tab (vector?)
	Tile* tiles = new Tile[9];

	Setup (tiles);

	// main loop
	while (win->isOpen ()) {
		while (win->pollEvent (*evnt)) HandleInput (evnt, tiles, &pos, win);

		win->clear ();
		ActiveTiles (tiles, &pos);
		RenderTiles (tiles, win);		
		win->display ();
	}
	return 0;
}

void RenderTiles (Tile * tiles, sf::RenderWindow * win) {
	for (int i = 0; i < 9; i++) {
		if (tiles[i].active == 1) {
			tiles[i].tile->setFillColor (sf::Color::Green);
		}
		else tiles[i].tile->setFillColor (sf::Color::White);
		win->draw (*tiles[i].tile);
	}
}

void Setup (Tile* tiles) {
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

// activating tiles
void ActiveTiles (Tile* tiles, int* t) {
	for (int i = 0; i < 9; i++) {
		if (*t == i) {
			tiles[i].active = 1;
		}
	}
}

// handling user input
void HandleInput (sf::Event* evnt, Tile* tiles, int* t, sf::RenderWindow* win) {

	int k = *t;

	// closing program
	if (evnt->type == sf::Event::Closed) win->close ();

	// controls
	if (evnt->type == sf::Event::EventType::KeyPressed) {
		switch (evnt->key.code) {
		case sf::Keyboard::Left:
			if (*t != 0) {
				*t -= 1;
				tiles[k].active = 0;
			}
			break;
		case sf::Keyboard::Right:
			if (*t != 8) {
				*t += 1;
				tiles[k].active = 0;
			}
		break;
		case sf::Keyboard::Up:
			if (*t != 0 && *t != 1 && *t != 2) {
				*t -= 3;
				tiles[k].active = 0;
			}
		break;
		case sf::Keyboard::Down:
			if (*t != 6 && *t != 7 && *t != 8) {
				*t += 3;
				tiles[k].active = 0;
			}
			break;	
		}	
	}
}
