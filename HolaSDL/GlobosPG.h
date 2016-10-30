#pragma once
#include "SDL.h"
#include "TexturasSDL.h"

class GlobosPG
{
public:
	GlobosPG(TexturasSDL* img, int &px, int &py);
	bool onClick(int &pmx, int &pmy);
	int getPuntos();
	bool update();
	~GlobosPG();
private: 
	
	void draw(SDL_Renderer* pRenderer) const;
	
	int puntos;
	bool explotado;
	int alto;
	int ancho;
	//bool visible;
	int x;
	int y;
	int inflado;
	SDL_Rect balloon;
};

