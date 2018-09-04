#ifndef BRICK_H
#define BRICK_H

#include "Sprite.h"
#include <string>

namespace game {
	class Brick : public engine::Sprite {
	private:
		Brick(const Brick&) = delete;
		const Brick& operator=(const Brick&) = delete;
	protected:
		Brick(engine::Window *win, std::string filePath, int x, int y);
	public:
		static Brick* getInstance(engine::Window *win, std::string filePath, int x, int y);
		~Brick();
		void initialPosition();
	};
}
#endif