#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
#include <vector>
#include <string>

namespace engine {
	class Sprite;
	class Window {
	private:
		SDL_Window* win;
		int winWidth, winHeight;
		SDL_Renderer* ren;
		bool background;
		SDL_Texture* backgr;
		std::vector<Sprite*> sprites;
	protected:
		Window(std::string title, int x, int y, int w, int h);
	public:
		static Window* getInstance(std::string title, int x, int y, int w, int h);
		~Window();
		SDL_Renderer* getRen();
		int getWidth() const;
		int getHeight() const;
		void addSprite(Sprite* s);
		std::vector<Sprite*> getSprites();
		void setBackground(std::string filePath);
		bool hasBackground();
		void showBackground();
		void removeSprite(Sprite *s);
		void removeAllSprites();
	};
}
#endif