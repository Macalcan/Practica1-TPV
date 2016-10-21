#pragma once
#include "SDL.h"
class TexturasSDL
{
public:
	TexturasSDL();
	~TexturasSDL();
private: 
	bool load(SDL_Renderer* pRenderer);
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect);

};

