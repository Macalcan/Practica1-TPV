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
	bool getVisible();
	bool update();
	~GlobosPG();
private: 
	int puntos;
	bool explotado;
	int alto;
	int ancho;
	//bool visible;
	int x;
	int y;
	int inflado;
	bool visible;
	SDL_Rect balloon;
};

