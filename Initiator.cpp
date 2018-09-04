#include "Initiator.h"
#include "Engine.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <stdexcept>

namespace engine {
	Initiator init;

	Initiator::Initiator() {
		if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
			throw std::runtime_error(std::string("Error:") + SDL_GetError());
	}

	Initiator::~Initiator() {
		IMG_Quit();
		SDL_Quit();
	}
}