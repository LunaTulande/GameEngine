#include "MovableSprite.h"
#include "Sprite.h"
#include "Window.h"
#include <string>

namespace engine {
	MovableSprite* MovableSprite::getInstance(Window *win, std::string filePath, int x, int y, float speed) {
		return new MovableSprite(win, filePath, x, y, speed); }

	MovableSprite::MovableSprite(Window *win, std::string filePath, int x, int y, float speed) : Sprite(win, filePath, x, y) {
		this->speed = speed;
		posiX = x; posiY = y;
	}

	MovableSprite::~MovableSprite() { }

	void MovableSprite::initialPosition() {
		rect.x = posiX;
		rect.y = posiY;
	}

	int MovableSprite::getInitPositionX() const {
		return posiX;
	}

	int MovableSprite::getInitPositionY() const {
		return posiY;
	}

	void MovableSprite::setDirection(float dirx, float diry) {
		float length = sqrt(dirx * dirx + diry * diry);
		this->dirX = speed * (dirx / length);
		this->dirY = speed * (diry / length);
	}

	void MovableSprite::move(float delta) {
		rect.x += (int) dirX * delta;
		rect.y += (int) dirY * delta;
	}
}