#ifndef PLAYER_H
#define PLAYER_H

#include "AnimatedSprite.h"

class Graphics;

class Player : public AnimatedSprite {
public:
	Player();
	Player(Graphics &graphics, float x, float y);
	void draw(Graphics &graphics);
	void update(float elapsedTime);

	/*
		void moveLeft ==>
		Moves the player left by -dx
	*/
	void moveLeft();

	/*
		void moveRight ==>
		Moves the player right by dx
	*/
	void moveRight();

	/*
		void stopMoving ==>
		Stops moving the player (idle animation)
	*/
	void stopMoving();

	virtual void animationDone(std::string currentAnimation);
	virtual void setupAnimations();
private:
	// delta x and y
	float _dx, _dy;

	Direction _facing;
};

#endif