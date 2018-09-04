#ifndef PADDLE_H
#define PADDLE_H

#include "MovableSprite.h"
#include <string>

namespace game {
	class Paddle : public engine::MovableSprite {
	private:
		bool active;
		void checkLimits();
		Paddle(const Paddle&) = delete;
		const Paddle& operator=(const Paddle&) = delete;
	protected:
		Paddle(engine::Window *win, std::string filePath, int x, int y, float speed);
	public:
		static Paddle* getInstance(engine::Window *win, std::string filePath, int x, int y, float speed);
		~Paddle();
		void initialPosition();
		void update(float delta);
		void move(float delta);
	};
}
#endif