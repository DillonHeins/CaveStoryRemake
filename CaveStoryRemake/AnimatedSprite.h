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

protected:
	double _timeToUpdate;
	bool _currentAnimationOnce;
	std::string _currentAnimation;

	/*
		void addAnimation ==>
		Adds an animation to the map of animations for the sprite
	*/
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

	/*
		void resetAnimations ==>
		Resets all animations associated with this sprite
	*/
	void resetAnimations();

	/*
		void stopAnimation ==>
		Stops the current animation
	*/
	void stopAnimation();

	/*
		void setVisible ==>
		Changes the visibility of the aniamted sprite
	*/
	void setVisible(bool visible);

	/*
		void animationDone ==>
		Logic that happens when an animation ends
	*/
	virtual void animationDone(std::string currentAnimation);
	
private:
	// Vector of rectangles is each of the different sub-sprites (locations on spritesheet)
	std::map<std::string, std::vector<SDL_Rect>> _animations;
	// Offsets to access different locations
	std::map <std::string, Vector2> _offsets;

	int _frameIndex;
	double _timeElapsed;
	bool _visible;
};

#endif