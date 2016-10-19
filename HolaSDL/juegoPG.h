#pragma once
#include "SDL.h"
class juegoPG
{
public:
	juegoPG();
	void run();
	~juegoPG();
private:
	bool initSDL();
	void closeSDL();
	bool initGlobos();
	void freeGlobos();
	void render();
	void onClick(int& pmx, int& pmy);
	void update();
	bool handle_event();
	int puntos;
	bool error, gameOver;
};

