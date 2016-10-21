#pragma once
#include "SDL.h"
class GlobosPG
{
public:
	GlobosPG();
	void draw(SDL_Renderer* pRenderer);
	void onClick(int &pmx, int &pmy);
	bool update();
	~GlobosPG();
};

