#include "Sprite.h"
#include "Window.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>

namespace engine {
	Sprite* Sprite::getInstance(Window *win, std::string filePath, int x, int y) {
		return new Sprite(win, filePath, x, y); }

	Sprite::Sprite(Window *win, std::string filePath, int x, int y) {
		SDL_Surface *surface = IMG_Load(filePath.c_str());
		if (surface == NULL)
			throw std::runtime_error(std::string("Error:") + SDL_GetError());
		else {
			texture = SDL_CreateTextureFromSurface(win->getRen(), surface);
			if (texture == NULL)
				throw std::runtime_error(std::string("Error:") + SDL_GetError());
		}
		rect.x = x;
		rect.y = y;
		rect.w = surface->w;
		rect.h = surface->h;
		SDL_FreeSurface(surface);

		visible = true;
		canCollide = false;
		this->win = win;
		win->addSprite(this);
	}

	Sprite::~Sprite() {
		SDL_DestroyTexture(texture);
	}

	void Sprite::draw() {
		if(visible)
			SDL_RenderCopy(win->getRen(), texture, NULL, &rect);
	}

	SDL_Rect Sprite::getRect() {
		return rect;
	}

	int Sprite::getPositionX() const {
		return rect.x;
	}

	int Sprite::getPositionY() const {
		return rect.y;
	}

	int Sprite::getWidth() const {
		return rect.w;
	}

	int Sprite::getHeight() const {
		return rect.h;
	}

	bool Sprite::getVisible() const {
		return visible;
	}

	void Sprite::setVisible(bool state) {
		visible = state;
	}

	bool Sprite::getCanCollide() const {
		return canCollide;
	}

	void Sprite::setCanCollide(bool can) {
		canCollide = can;
	}

	bool Sprite::keyDown(char* keyName) {
		return (keyState[SDL_GetScancodeFromName(keyName)]);
	}

	void Sprite::setKeyState(const Uint8* keyState) {
		this->keyState = keyState;
	}

	bool Sprite::checkCollision(Sprite *s) { 
		if (rect.x + rect.w > s->getRect().x && rect.x < s->getRect().x + s->getRect().w &&
			rect.y + rect.h > s->getRect().y && rect.y < s->getRect().y + s->getRect().h)
			return true;
		return false;
	}
}