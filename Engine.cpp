#include "Engine.h"
#include "Sprite.h"
#include <SDL.h>
#include <string>

namespace engine {
	Engine* Engine::getInstance(std::string title, int x, int y, int w, int h) {
		return new Engine(title, x, y, w, h);
	}

	Engine::Engine(std::string title, int x, int y, int w, int h) {
		win = Window::getInstance(title, x, y, w, h);
		framesPerSecond = 60; //default
		delta = 0.0f;
		prevTime = 0; currentTime = 0;
	}

	Engine::~Engine() {
		delete win;
	}

	Window* Engine::getWindow() {
		return win;
	}

	void Engine::setFPS(int fps) {
		if (fps >= MAX_FPS)
			framesPerSecond = MAX_FPS;
		else
			framesPerSecond = fps;
	}

	int Engine::getFPS() {
		return framesPerSecond;
	}

	void Engine::run() {
		currentTime = SDL_GetTicks();
		bool isRunning = true;
		while (isRunning) {
			prevTime = currentTime;
			currentTime = SDL_GetTicks();
			delta = (currentTime - prevTime) / 1000.0f;
			if (currentTime - prevTime < 1000.0f / framesPerSecond) { //Sleep the remaining frame time
				SDL_Delay((1000.0f / framesPerSecond) - (currentTime - prevTime)); }

			SDL_PumpEvents();
			keyState = SDL_GetKeyboardState(NULL);
			//close window
			if (keyState[SDL_SCANCODE_ESCAPE] || keyState[SDL_SCANCODE_END]) {
				isRunning = false;
				break;
			}
			//keyDown and collision detection
			for (Sprite *s : win->getSprites()) {
				s->setKeyState(keyState);
				s->update(delta);
				if (s->getCanCollide()) { actionableCollision(s); }
			}

			//restartGame if required
			conditionRestartGame(funcPointer);

			SDL_RenderClear(win->getRen());
			if (win->hasBackground())
				win->showBackground();
			for (Sprite *s : win->getSprites())
				s->draw();
			SDL_RenderPresent(win->getRen());
		}
	}

	void Engine::actionableCollision(Sprite *sprite) {
		Sprite* currentSprite = sprite;
		for (int j = 0; j < win->getSprites().size(); j++) {
			if (win->getSprites()[j] != sprite) {
				currentSprite->collisionResponse(win->getSprites()[j]);
			}
		}
	}

	void Engine::restartGame() {
		for (Sprite *s : win->getSprites()) {
			s->initialPosition();
		}
	}

	void Engine::conditionRestartGame(void(*funcPointer)()) {
		funcPointer();
	}
	
	void Engine::removeSprite(Sprite *s) {
		win->removeSprite(s);
	}

	void Engine::removeAllSprites() {
		win->removeAllSprites();
	}
}