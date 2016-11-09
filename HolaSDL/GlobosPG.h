// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
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
	static const int PVIS = 70;
	static const int PDES = 30;
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

