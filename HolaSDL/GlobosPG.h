#pragma once
#include "SDL.h"
class GlobosPG
{
public:
	GlobosPG();
	~GlobosPG();
private: 
	void draw(SDL_Renderer* pRenderer);
	void onClick(int &pmx, int &pmy);
	bool update();
};

