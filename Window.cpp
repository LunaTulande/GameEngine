#include "Window.h"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <algorithm>
#include <string>

namespace engine {
	Window* Window::getInstance(std::string title, int x, int y, int w, int h) {
		return new Window(title, x, y, w, h);
	}

	Window::Window(std::string title, int x, int y, int w, int h) {
		win = SDL_CreateWindow(title.c_str(), x, y, w, h, 0);
		if (win == NULL)
			throw std::runtime_error(std::string("Error:") + SDL_GetError());
		ren = SDL_CreateRenderer(win, -1, 0);
		if (ren == NULL)
			throw std::runtime_error(std::string("Error:") + SDL_GetError());
		winWidth = w;
		winHeight = h;

		//black background by default
		background = false;
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
		SDL_Rect winBackground = { x,y,w,h };
		SDL_RenderFillRect(ren, &winBackground);
	}

	Window::~Window() {
		if (background)
			SDL_DestroyTexture(backgr);
		if (sprites.size() > 0)
			removeAllSprites();
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
	}

	SDL_Renderer* Window::getRen() {
		return ren;
	}

	int Window::getWidth() const {
		return winWidth;
	}

	int Window::getHeight() const {
		return winHeight;
	}

	void Window::addSprite(Sprite *s) {
		sprites.push_back(s);
	}

	std::vector<Sprite*> Window::getSprites() {
		return sprites;
	}

	void Window::setBackground(std::string filePath) {
		background = true;
		backgr = IMG_LoadTexture(ren, filePath.c_str());
	}
	
	bool Window::hasBackground() {
		return background;
	}
	
	void Window::showBackground() {
		SDL_RenderCopy(ren, backgr, NULL, NULL);
	}

	void Window::removeSprite(Sprite *s) {
		auto iterator = find(sprites.begin(), sprites.end(), s);
		if (iterator != sprites.end())
			sprites.erase(iterator);
	}
	
	void Window::removeAllSprites() {
		for (int i = sprites.size() - 1; i >= 0; i--) {
			sprites.erase(std::remove(sprites.begin(), sprites.end(), sprites[i]), sprites.end());
		}
	}
}