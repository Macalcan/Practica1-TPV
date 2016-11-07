#pragma once
#include "SDL.h"
#include <string>
using namespace std;

class TexturasSDL
{
public:
	TexturasSDL();
	~TexturasSDL();
	void draw(SDL_Renderer* pRenderer, SDL_Rect const& rect);
	SDL_Surface* loadFile(string file);
	SDL_Texture* getTextura();
private: 
	bool load(SDL_Renderer* pRenderer, string const& nombArch);
	SDL_Texture* pTextura;
};

