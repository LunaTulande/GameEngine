#include "Engine.h"
#include "Window.h"
#include "Sprite.h"
#include "MovableSprite.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include <algorithm>
#include <iostream>

using namespace std;
using namespace engine;
using namespace game;

Engine* myEngine;
Ball* ball;
int bricks = 88;
void endGame();

int main(int argc, char* argv[]) {
	try {
		myEngine = Engine::getInstance("Breakout", 250, 100, 800, 600);
		Window* myWin = myEngine->getWindow();

		myWin->setBackground("Images/background.png");

		Paddle* paddle = Paddle::getInstance(myWin, "Images/paddle.png", 336, 550, 300.0f);
		ball = Ball::getInstance(myWin, "Images/ball.png", 388, 527, 180.0f);
		
		//bricks
		int posiY = 45, spaceBetwBricks = 2;
		for (int row = 0; row < 8; row++) {
			int posiX = 40;
			Brick *tempBrick = NULL;
			for (int block = 0; block < 11; block++) {
				tempBrick = Brick::getInstance(myWin, "Images/block.png", posiX, posiY);
				posiX = tempBrick->getPositionX() + tempBrick->getWidth() + spaceBetwBricks;
			}
			posiY = tempBrick->getPositionY() + tempBrick->getHeight() + spaceBetwBricks;
		}

		myEngine->funcPointer = endGame;

		myEngine->run();

		myEngine->removeAllSprites();
		delete ball;
		delete paddle;
		delete myEngine;		
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
	}
	return 0;
}

void endGame() {	
	if (ball->hitBottom() || ball->getBrickCount() == bricks) {
		myEngine->restartGame();
	}
}