#pragma once
#include "SDL.h"
#include <string>

class TexturasSDL
{
public:
	TexturasSDL();
	~TexturasSDL();
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect);
	SDL_Surface* loadFile(string file);
private: 
	bool load(SDL_Renderer* pRenderer, string const& nombArch);
	SDL_Texture* pTextura;
};

