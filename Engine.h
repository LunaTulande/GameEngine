#ifndef ENGINE_H
#define ENGINE_H

#define MAX_FPS 500

#include "Window.h"
#include <SDL.h>
#include <string>

namespace engine {
	class Engine {
	private:
		Window *win;
		const Uint8 *keyState;
		float delta;
		int framesPerSecond, prevTime, currentTime;
		Engine(const Engine&) = delete;
		const Engine& operator=(const Engine&) = delete;
	protected:
		Engine(std::string title, int x, int y, int w, int h);
	public:
		static Engine* getInstance(std::string title, int x, int y, int w, int h);
		~Engine();
		Window* getWindow();
		void setFPS(int fps);
		int getFPS();
		void run();
		void actionableCollision(Sprite* sprite);
		void restartGame();
		void conditionRestartGame(void (*fp)());
		void(*funcPointer)();
		void removeSprite(Sprite *s);
		void removeAllSprites();
	};
}
#endif