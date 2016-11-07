#pragma once
#include "SDL.h"
#include "GlobosPG.h"
#include <vector>
using namespace std;
typedef uint32_t Uint32;

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
	bool error, gameOver, exit;
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	
	GlobosPG* globos [dim]; //array de los globos
	TexturasSDL* ptexture;
	int ancho;   
	int alto;
	int numG; //numero de globos
};

