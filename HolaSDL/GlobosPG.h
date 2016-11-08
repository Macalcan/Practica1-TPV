#pragma once
#include "SDL.h"
#include "TexturasSDL.h"

class GlobosPG
{
public:
	GlobosPG(TexturasSDL* img, int &px, int &py);
	bool onClick(int &pmx, int &pmy);
	void draw(SDL_Renderer* pRenderer) const;
	int getPuntos();
	bool update();
	~GlobosPG();
private:

	bool daTrue;
	TexturasSDL* imagen;
	int puntos;
	bool explotado;
	int alto;
	int ancho;
	int x;
	int y;
	int inflado;
	bool invisible;
	SDL_Rect balloon;
};

