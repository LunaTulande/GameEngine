#ifndef BALL_H
#define BALL_H

#include "MovableSprite.h"
#include <string>

namespace game {
	class Ball : public engine::MovableSprite {
	private:
		int brickCount;
		void checkLimits();
		Ball(const Ball&) = delete;
		const Ball& operator=(const Ball&) = delete;
	protected:
		Ball(engine::Window *win, std::string filePath, int x, int y, float speed);
	public:
		static Ball* getInstance(engine::Window *win, std::string filePath, int x, int y, float speed);
		~Ball();
		void initialPosition();
		void update(float delta);
		bool hitBottom();
		int getBrickCount();
		void collisionResponse(Sprite *other); //mirar
	};
}
#endif