#ifndef GAME_H
#define GAME_H

/*
	Game class
	Holds all information for main game loop
*/

#include "Player.h"
#include "Level.h"

class Graphics;

class Game {
public:
	Game();
	~Game();
private:
	void gameLoop();
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	Player _player;
	Level _level;
};

#endif