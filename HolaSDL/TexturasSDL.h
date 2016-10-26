#pragma once
#include "SDL.h"
class TexturasSDL
{
public:
	TexturasSDL();
	~TexturasSDL();
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect);
private: 
	bool load(SDL_Renderer* pRenderer, SDL_Texture* & pTexture);
	SDL_Texture* pTextura;
	const int TEXTURE_WIDTH = 100;   //texture dimension
	const int TEXTURE_HEIGHT = 100;  //texture dimension

};

