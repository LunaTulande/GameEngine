#include "Brick.h"
#include "Sprite.h"
#include "Window.h"

using namespace engine;

namespace game {
	Brick* Brick::getInstance(engine::Window * win, std::string filePath, int x, int y) {
		return new Brick(win, filePath, x, y); }

	Brick::Brick(engine::Window * win, std::string filePath, int x, int y) :
		Sprite(win, filePath, x, y) {
	}

	Brick::~Brick() { }

	void Brick::initialPosition() {
		Sprite::setVisible(true);
	}
}