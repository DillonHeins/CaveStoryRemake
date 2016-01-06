#include "Sprite.h"
#include "Graphics.h"
#include "Globals.h"

Sprite::Sprite() {}

Sprite::Sprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
		float posX, float posY) :_x(posX), _y(posY) {
	this->_sourceRect.x = sourceX;
	this->_sourceRect.y = sourceY;
	this->_sourceRect.w = width;
	this->_sourceRect.h = height;

	// Load surface from image if not already loaded and then store texture in spritesheet
	this->_spriteSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(), graphics.loadImage(filePath));

	if (this->_spriteSheet == NULL) {
		printf("\nError: Unable to load image\n");
	}
}

Sprite::~Sprite() {}

void Sprite::draw(Graphics &graphics, int x, int y) {
	// Where on the screen we will be drawing
	SDL_Rect destinationRectangle = { x, y, this->_sourceRect.w * globals::SPRITE_SCALE,
			this->_sourceRect.h * globals::SPRITE_SCALE };
	// What will be doing the drawing
	graphics.blitSurface(this->_spriteSheet, &this->_sourceRect, &destinationRectangle);
}

void Sprite::update() {}