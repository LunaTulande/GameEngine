#ifndef SPRITE_H
#define SPRITE_H

#include <SDL.h>
#include <string>

namespace engine {
	class Window;
	class Sprite {
	private:
		bool visible;
		bool canCollide;
		const Uint8 *keyState;
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
	protected:
		Sprite(Window *win, std::string filePath, int x, int y);
		Window *win;
		SDL_Rect rect;
		SDL_Texture *texture;
		bool checkCollision(Sprite *s);
	public:
		static Sprite* getInstance(Window *w, std::string filePath, int x, int y);
		virtual ~Sprite();
		virtual void draw();
		virtual void update(float delta) {}
		virtual void initialPosition() {}
		virtual void collisionResponse(Sprite* other) {} 
		int getPositionX() const;
		int getPositionY() const;
		int getWidth() const;
		int getHeight() const;
		SDL_Rect getRect();
		bool getVisible() const;
		void setVisible(bool state);
		bool getCanCollide() const;
		void setCanCollide(bool can);
		bool keyDown(char* keyName);
		void setKeyState(const Uint8* keyState); //friend??
		//Si la función en cuestión es designada "virtual", se llamará a la función de la clase
		//derivada (si existe). Si no es virtual, se llamará a la función de la clase base.
		//q se puede sobre escribir
	};
}
#endif