#include "juegoPG.h"
#include "TexturasSDL.h"
#include <iostream>
using namespace std;

juegoPG::juegoPG()
{
	const int ancho = 640;   //dimensiones de la ventana
	const int alto = 480; 
	globos.size(1) const;
	SDL_Window * pWindow = nullptr;
	SDL_Renderer * pRenderer = nullptr;
	
}
//--------------------------------------------------------------------------------//
bool juegoPG::initSDL() {

	
	bool carga = true; //si carga es false no se puede cargar la ventana inicializando SDL

	
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "¡SDL no se ha podido iniciar! \nSDL_Error: " << SDL_GetError() << '\n';
		carga = false;
	}
	else {
		pWindow = SDL_CreateWindow("SDL Balloon", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, ancho, alto, SDL_WINDOW_SHOWN);
		if (pWindow == nullptr){
			cout << "¡La ventana no se ha podido crear! \nSDL_Error: " << SDL_GetError() << '\n';
			carga = false;
		}
		else {
			//Toma la superficie de la ventana:
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //De momento la ventana sera negra pero despues tendra un fondo
			if (pRenderer == nullptr){
				cout << "¡No se ha podido crear el renderer! \nSDL_Error: " << SDL_GetError() << '\n';
				carga = false;
			}
		}
	}

	return carga;
}
//--------------------------------------------------------------------------------//
bool juegoPG::initGlobos() {
	bool addTecture = true;

	TexturasSDL t;
	t.loadFile("globoN.png"); //comrpobar que no se tenga que poner la ruta


}
//--------------------------------------------------------------------------------//
void juegoPG::closeSDL() {}
//--------------------------------------------------------------------------------//
void juegoPG::freeGlobos() {}
//--------------------------------------------------------------------------------//
void juegoPG::render() {}
//--------------------------------------------------------------------------------//
void juegoPG::onClick(int &pmx, int &pmy){}
//--------------------------------------------------------------------------------//
void juegoPG::update() {}
//--------------------------------------------------------------------------------//
bool juegoPG::handle_event() {
	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) onExit();
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				cout << "CLICK";
				onClick(e.button.x, e.button.y);
			}
			// else if(...)    
		}
		// else if(...)  
	}
	//return !running;
}//no esta completado
//--------------------------------------------------------------------------------//
void juegoPG::run()
{
	if (!error){
		Uint32 MSxUpdate = 500;  
		cout << "PLAY \n";
		Uint32 lastUpdate = SDL_GetTicks();
		render();
		handle_event();
		while (!exit && !gameOver) {
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate) {//while(elapsed >= MSxUpdate)
				update();
				lastUpdate = SDL_GetTicks();
			}
			render();
			handle_event();
		}
		if (exit) cout << "EXIT \n";
		else cout << "Has obtenido " << puntos << "puntos\n";
		SDL_Delay(1000); //cin.get();
	}
}
//--------------------------------------------------------------------------------//
juegoPG::~juegoPG()
{
	closeSDL();
	freeGlobos();
	SDL_Window * pWindow = nullptr;
	SDL_Renderer * pRenderer = nullptr;
}
