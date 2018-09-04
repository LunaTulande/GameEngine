#include "Paddle.h"
#include "MovableSprite.h"
#include "Window.h"

using namespace engine;

namespace game{
	Paddle* Paddle::getInstance(Window *win, std::string filePath, int x, int y, float speed) {
		return new Paddle(win, filePath, x, y, speed); }

	Paddle::Paddle(Window *win, std::string filePath, int x, int y, float speed) : 
	 MovableSprite(win, filePath, x, y, speed) {
		active = false;
	}

	Paddle::~Paddle() { }

	void Paddle::initialPosition() {
		MovableSprite::initialPosition();
		active = false;
	}

	void Paddle::update(float delta) {
		checkLimits();
		if (keyDown("Space")) {
			active = true;
		}
		if (keyDown("Left")) {
			setDirection(-1, 0);
			move(delta);
		}
		if (keyDown("Right")) {
			setDirection(1, 0);
			move(delta);
		}
	}

	void Paddle::move(float delta) {
		if (active)
			MovableSprite::move(delta);
	}

	void Paddle::checkLimits() {
		if (rect.x < 0) {
			rect.x = 0;
		}
		if (rect.x >= (win->getWidth() - rect.w)) {
			rect.x = (win->getWidth() - rect.w);
		}
	}
}