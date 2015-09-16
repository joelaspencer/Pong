#include <iostream>
#include "sfwdraw.h"
#include "Paddle.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 400;


/*
	Collision:
		Comparing the space occupied by every two possible pairs of objects.
			How do we represent the space that an object occupies?
				Geometry
					Rectangles, Circles, Planes, Rays
				
			calculate Minimum Translation Vector (MTV) (x,y)
---------------------------				
	Resolve Collision:
		


*/


int main()
{
	
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello window!");

	// Player 1 name entry
	char P1name[20];
	std::cout << "Player 1 enter your name" << std::endl;
	std::cin >> P1name; 
	std::cout << P1name << " controls: W/S" << std::endl;

	//Player 2 name entry
	char P2name[20];
	std::cout << "Player 2 enter your name" << std::endl;
	std::cin >> P2name;
	std::cout << P2name << " Controls: P/;" << std::endl;

	std::cout << "Press G to Start"   << std::endl;

	float xplayer = SCREEN_WIDTH - 20, yplayer = SCREEN_HEIGHT/2;
	float xplayer2 = SCREEN_WIDTH - 780, yplayer2 = SCREEN_HEIGHT / 2;
	float speed = 600, width = 60;
	
	// struct instantiation
	Paddle player1 = { SCREEN_WIDTH - 20, SCREEN_HEIGHT / 2, 60, 600, 'p',';' };
	Paddle player2 = { SCREEN_WIDTH - 780,  SCREEN_HEIGHT / 2, 60, 600, 'w','s' };

	float xball = SCREEN_WIDTH/2, yball=SCREEN_HEIGHT/2, xSpeed = 0, ySpeed = -0, radius = 12;

	

	// P1 Score
	int P1score = 0;

	// P2 Score
	int P2score = 0;

	while (sfw::stepContext())
	{
		
		if(sfw::getKey('g')) xSpeed = 200, ySpeed = -200;
		
		// Movement of the ball
		xball += xSpeed * sfw::getDeltaTime();
		yball += ySpeed * sfw::getDeltaTime();

		//How do I know if the ball is off the edge of the screen?
		if (yball > SCREEN_HEIGHT)
		{
			ySpeed *= -1;
			yball = SCREEN_HEIGHT;
		}
		if (yball < 0)
		{
			ySpeed *= -1;
			yball = 0;
		}
		if (xball > SCREEN_WIDTH)
		{
			xball = SCREEN_HEIGHT / 2, yball = SCREEN_WIDTH / 2, xSpeed = 225, ySpeed = 225;
			P1score++;
			std::cout << "Player 1's score is:" << P1score << std::endl;
		}
		if (xball < 0)
		{
			xball = SCREEN_HEIGHT / 2, yball = SCREEN_WIDTH / 2, xSpeed = 225, ySpeed = 225;
			P2score++;
			std::cout << "Player 2's score is:" << P2score << std::endl;
		}
		if (P1score == 5)
		{
			P1score = 0, P2score = 0;
			std::cout << "Player 1 wins!!" << std::endl;
			xSpeed = 0, ySpeed = 0;
			yball = SCREEN_HEIGHT / 2, xball = SCREEN_WIDTH / 2;
		}
		if (P2score == 5)
		{
			P2score = 0, P1score = 0;
			std::cout << "Player 2 wins!!" << std::endl;
			xSpeed = 0, ySpeed = 0;
			yball = SCREEN_HEIGHT / 2, xball = SCREEN_WIDTH / 2;
		}
		// col with player 1
		if (yball > player1.y  && (xball > player1.x-12) && yball + 12 < player1.y + 60) xSpeed *= -1.01, ySpeed *= -1.01;	
		if (player1.y < 0)
		{
			//std::cout << "AT SCREEN HEIGHT\n";
			player1.y = 0;
		}
		if (player1.y > SCREEN_HEIGHT - 60)
		{
			player1.y = SCREEN_HEIGHT - 60;
		}


		// col with player 2
		if (yball > player2.y && xball - 12 < player2.x && yball - 12 < player2.y + 60) xSpeed *= -1.01, ySpeed *= -1.01;
		if (player2.y < 0)
		{
			player2.y = 0;
		}
		if (player2.y > SCREEN_HEIGHT - 60)
		{
			player2.y = SCREEN_HEIGHT - 60;
		}
		// Drawing of the ball
		sfw::drawCircle(xball, yball, radius);

		// Movement of paddle		
		// Player 1 controls 
		movePlayer(player1);

		// Player 2 controls
		//if (sfw::getKey('w')) yplayer2 -= speed * sfw::getDeltaTime();
		//if (sfw::getKey('s')) yplayer2 += speed * sfw::getDeltaTime();
		movePlayer(player2);
		// Drawing of paddle
		// drawing player 1
		drawPlayer(player1);
		//sfw::drawLine(xplayer,  yplayer,  xplayer,  yplayer+width);
		//std::cout << "Player 2's Position - " << yplayer2 << "," << yplayer2 << std::endl;

		// drawing player 2
		//sfw::drawLine(xplayer2, yplayer2, xplayer2, yplayer2+width);
		drawPlayer(player2);
	}

	sfw::termContext();

	return 0;
}