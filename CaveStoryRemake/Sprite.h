#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <string>

class Graphics;

/*
	Sprite class
	Holds all information for individual sprites
*/

class Sprite {
public:
	Sprite();
	Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
			float posX, float posY);
	virtual ~Sprite();
	// going to be overriding this in animated sprite
	virtual void update();
	void draw(Graphics &graphics, int x, int y);
protected:
	// Where on the spritesheet to get the sprite from
	SDL_Rect _sourceRect;
	// Sprite sheet responsible for this particular sprite
	SDL_Texture* _spriteSheet;

private:
	float _x, _y;
};

#endif