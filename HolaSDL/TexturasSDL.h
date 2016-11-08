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
	bool load(SDL_Renderer* pRenderer, string const& nombArch);
	SDL_Texture* getTextura();
private:
	int alto;
	int ancho;
	SDL_Surface* loadFile(string file);
	SDL_Texture* pTextura;
};

