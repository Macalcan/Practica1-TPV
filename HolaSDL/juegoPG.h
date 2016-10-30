#pragma once
#include "SDL.h"
#include "GlobosPG.h"
#include <vector>
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
	void onClick(int &pmx, int &pmy);
	void update();
	bool handle_event();
	int puntos;
	bool error, gameOver;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	vector <GlobosPG*> globos;//¿vector de punteros?
	const int ancho;   
	const int alto;
	int numG; //numero de globos
};

