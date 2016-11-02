#pragma once
#include "SDL.h"
#include "GlobosPG.h"
#include <vector>

const int dim = 1;
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
	void render()const;
	void onClick(int &pmx, int &pmy);
	void update();
	bool handle_event();
	int puntos;
	bool error, gameOver;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	
	GlobosPG* globos [dim]; //array de los globos
	TexturasSDL* ptexture;
	const int ancho;   
	const int alto;
	int numG; //numero de globos
};

