#pragma once


/*
	position
	width
	speed
	controls
*/

// The variables we use are the ones necessary to represent the object
struct Paddle
{
	float x;
	float y;
	float width;
	float speed;
	char up;
	char down;
};


void drawPlayer(Paddle p);
void movePlayer(Paddle &p);