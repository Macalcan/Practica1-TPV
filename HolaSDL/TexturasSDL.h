#pragma once
#include "SDL.h"
#include <string>

class TexturasSDL
{
public:
	TexturasSDL();
	~TexturasSDL();
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect);//si es privado no se llama desde globos
private: 
	bool load(SDL_Renderer* pRenderer, string const& nombArch);
	SDL_Surface* loadFile(string file);
	SDL_Texture* pTextura;
};

