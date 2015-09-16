#include "Paddle.h"
#include "sfwdraw.h"

// Definitions
void drawPlayer(Paddle p)
{

	sfw::drawLine(p.x, p.y, p.x, p.y + p.width);
}

void movePlayer(Paddle &p)
{
	if (sfw::getKey(p.up))   p.y -= p.speed * sfw::getDeltaTime();
	if (sfw::getKey(p.down)) p.y += p.speed * sfw::getDeltaTime();
}