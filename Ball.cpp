#include "Ball.h"
#include "MovableSprite.h"
#include "Window.h"
#include "Paddle.h"
#include "Brick.h"

using namespace engine;

namespace game {
	Ball * Ball::getInstance(engine::Window * win, std::string filePath, int x, int y, float speed) {
		return new Ball(win, filePath, x, y, speed); }

	Ball::Ball(engine::Window *win, std::string filePath, int x, int y, float speed) : 
	 MovableSprite(win, filePath, x, y, speed) {
		brickCount = 0;
		setCanCollide(true);
	}

	Ball::~Ball() { }

	void Ball::initialPosition() {
		MovableSprite::initialPosition();
		dirX = 0.0f; dirY = 0.0f;
		brickCount = 0;
	}

	void Ball::update(float delta) {
		if (keyDown("Space")) {
			setDirection(1, -1); }
		move(delta);
		checkLimits();
	}

	void Ball::checkLimits() {
		if (rect.x < 0) {
			setDirection(dirX*-1, dirY); }
		if (rect.x >= (win->getWidth() - rect.w)) {
			setDirection(dirX*-1, dirY); }
		if (rect.y < 0) {
			setDirection(dirX, dirY*-1); }
	}

	bool Ball::hitBottom() {
		if (rect.y >= (win->getHeight() - rect.h)) {
			return true; }
		return false;
	}

	int Ball::getBrickCount() {
		return brickCount; }

	void Ball::collisionResponse(Sprite *other) { //mirar
		Paddle *p = dynamic_cast<Paddle*>(other);
		if (p != nullptr && checkCollision(other)) {
			setDirection(dirX, dirY*-1);
		}

		Brick *b = dynamic_cast<Brick*>(other);
		if (b != nullptr && b->getVisible() && checkCollision(other)) {
			setDirection(dirX, dirY*-1);
			if (rect.x < b->getPositionX() && rect.x + rect.w < b->getPositionX() + b->getWidth()
				|| rect.x > b->getPositionX() && rect.x + rect.w > b->getPositionX() + b->getWidth()) {
				setDirection(dirX*-1, dirY);
			}
			b->setVisible(false);
			brickCount++;
		}
	}
}