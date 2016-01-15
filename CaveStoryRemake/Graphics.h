#ifndef GRAPHICS_H
#define GRAPHICS_H

/*
	Graphics class
	Holds all information dealing with graphics for the game
*/

#include <SDL.h>

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
public:
	Graphics();
	~Graphics();
	
	/*
		SDL_Surface* loadImage ==>
		Loads an image into the _spriteSheets map if it doesn't already exist.
		As a result each image will only be loaded once.
		Will return the image from the map regardless of whether or not it was just
		loaded.
	*/
	SDL_Surface* loadImage(const std::string &filePath);

	/*
		void blitSurface ==>
		What draws images (SDL textures) to a certain part of the screen.
		Source is what we are drawing to screen, sourceRectangle is what part of source
		destinationRectangle is what part of screen
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

	/*
		void flip ==>
		Renders everything to the screen
	*/
	void flip();

	/*
		void clear ==>
		Clears the screen
	*/
	void clear();

	/*
		SDL_Renderer* getRenderer ==>
		Returns the renderer
	*/
	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window; // place to draw
	SDL_Renderer* _renderer; // thing that draws

	/* 
		Map is going to hold in memory in our graphics object every spritesheet
		we have loaded into game.
		Benefit if we are holding onto this the entire time graphics exists
		then we never have to load an image more than once.
	*/
	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif