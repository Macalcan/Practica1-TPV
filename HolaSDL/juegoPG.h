#pragma once
#include "SDL.h"
#include "GlobosPG.h"
#include <vector>

const int dim = 7; //dimension del array de los globos

const int ancho = 550; //dimensiones de la ventana del juego
const int alto = 600;
class juegoPG
{
public:
	juegoPG();
	void run();
	~juegoPG();
private:
	bool explotados[dim];
	bool initSDL();
	void closeSDL();
	bool initGlobos();
	void freeGlobos();
	void render()const;
	void onClick(int &pmx, int &pmy);
	void update();
	void handle_event();
	int puntos;
	bool error, gameOver, exit;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;

	GlobosPG* globos[dim]; //array de los globos
	TexturasSDL* ptexture;
	int numG; //numero de globos
};

