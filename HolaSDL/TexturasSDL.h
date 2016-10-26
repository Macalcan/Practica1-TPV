#pragma once
#include "SDL.h"
class TexturasSDL
{
public:
	TexturasSDL();
	~TexturasSDL();
private: 
	bool load(SDL_Renderer* pRenderer, string const& nombArch, SDL_Color const& colKey);
	SDL_Surface* loadFile(string file);
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect);
	SDL_Texture* pTextura;
	const int TEXTURE_WIDTH = 100;   //texture dimension
	const int TEXTURE_HEIGHT = 100;  //texture dimension

};

