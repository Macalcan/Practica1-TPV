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
	void onClick(int &pmx, int &pmy);
	bool update();
};

