#include <SDL.h>
#include <algorithm>
#include "Game.h"
#include "Graphics.h"
#include "Input.h"

/*
	Game class
	Holds all information for main game loop
*/

namespace {
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
	Graphics graphics;
	Input input;
	SDL_Event event;
	this->_player = Sprite(graphics, "content/sprites/MyChar.png", 0, 0, 16, 16, 100, 100);

	int LAST_UPDATE_TIME = SDL_GetTicks();

	// Start the game loop
	while (true) {
		input.beginNewFrame();
		
		// checks if an event is fired
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				// if not repeating register keydown
				if (event.key.repeat == 0) {
					input.keyDownEvent(event);
				}
			} else if (event.type == SDL_KEYUP) {
				input.keyUpEvent(event);
			} else if (event.type == SDL_QUIT) {
				// if event is quit then end game loop
				return;
			}
		}

		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
			return;
		}

		// Current time should not change until recaptured, not required but good idea
		const int CURRENT_TIME_MS = SDL_GetTicks();
		// How long current frame took
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		// Reset for beginning of next loop
		LAST_UPDATE_TIME = CURRENT_TIME_MS;

		this->draw(graphics);
	}
}

void Game::draw(Graphics &graphics) {
	graphics.clear();

	this->_player.draw(graphics, 100, 100);

	graphics.flip();
}

void Game::update(float elapsedTime) {

}