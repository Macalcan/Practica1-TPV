#pragma once
#include "SDL.h"
#include <string>

class TexturasSDL
{
public:
	TexturasSDL();
	~TexturasSDL();
<<<<<<< HEAD
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect);
private: 
	bool load(SDL_Renderer* pRenderer, SDL_Texture* & pTexture);
=======
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect);//si es privado no se llama desde globos
private: 
	bool load(SDL_Renderer* pRenderer, string const& nombArch);
	SDL_Surface* loadFile(string file);
>>>>>>> TexturasSDL
	SDL_Texture* pTextura;
};

