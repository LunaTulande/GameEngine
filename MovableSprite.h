#ifndef MOVABLESPRITE_H
#define MOVABLESPRITE_H

#include "Sprite.h"
#include <SDL.h>
#include <string>

namespace engine {
	class MovableSprite : public Sprite {
	private:
		MovableSprite(const MovableSprite&) = delete;
		const MovableSprite& operator=(const MovableSprite&) = delete;
	protected:
		MovableSprite(Window *win, std::string filePath, int x, int y, float speed);
		int posiX, posiY;
		float dirX, dirY, speed;
	public:
		static MovableSprite* getInstance(Window *win, std::string filePath, int x, int y, float speed);
		~MovableSprite();
		virtual void initialPosition();
		int getInitPositionX() const;
		int getInitPositionY() const;
		void setDirection(float dirx, float diry);
		void move(float delta);
	};
}
#endif