#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <map>
#include <string>
#include <vector>

#include "Sprite.h"
#include "Globals.h"

class Graphics;

/*
	AnimatedSprite class
	Holds logic for animating sprites
*/

class AnimatedSprite : public Sprite {
public:
	AnimatedSprite();
	AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height,
			float posX, float posY, float timeToUpdate); // timeToUpdate ==> how long until need to go onto next frame in animation

	/*
		void playAnimation ==>
		Plays the animation provided if it is not already playing.
		once == false -> loop
	*/
	void playAnimation(std::string animation, bool once = false);

	/*
		void update ==>
		Updates the animated sprite (timer)
	*/
	void update(int elapsedTime);

	/*
		void draw ==>
		Draws the sprite to the screen
	*/
	void draw(Graphics &graphics, int x, int y);

	/*
		void setupAnimations ==>
		A required function that sets up all animations for a sprite
	*/
	virtual void setupAnimations();

private:
	// Vector of rectangles is each of the different sub-sprites (locations on spritesheet)
	std::map<std::string, std::has_move_constructor<SDL_Rect>> _animations;
	// Offsets to access different locations
	std::map <std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;
};

#endif