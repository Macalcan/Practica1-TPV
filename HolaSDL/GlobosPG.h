#pragma once
#include "SDL.h"
#include "TexturasSDL.h"

class GlobosPG
{
public:
	GlobosPG(TexturasSDL* img, int &px, int &py);
	~GlobosPG();
private: 
	void draw(SDL_Renderer* pRenderer);
	bool onClick(int &pmx, int &pmy);
	bool update();
	int puntos;
	bool explotado;
	int alto;
	int ancho;
	bool visible;
	int x;
	int y;
	int hinchado;
};

