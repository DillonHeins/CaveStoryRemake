#include <SDL.h>
#include <SDL_image.h>

#include "Graphics.h"
#include "Globals.h"

/*
	Graphics class
	Holds all info dealing with graphics of game
*/

Graphics::Graphics() {
	// initialize and create window and renderer
	SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "CaveStory");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filePath) {
	// count checks how many exist with that key
	// if not loaded into map yet then load
	if (this->_spriteSheets.count(filePath) == 0) {
		this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
	SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
	// Draw renderer to screen
	SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
	return this->_renderer;
}