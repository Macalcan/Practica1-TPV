#include "juegoPG.h"
#include <iostream>
using namespace std;

juegoPG::juegoPG()
{
	initSDL() {}
	initGlobos() {}
}
//--------------------------------------------------------------------------------//
bool juegoPG::initSDL() {}
//--------------------------------------------------------------------------------//
bool juegoPG::initGlobos() {}
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
}
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
	//--------------------------------------------------------------------------------//
	closeSDL() {}
	//--------------------------------------------------------------------------------//
	freeGlobos() {}
	//--------------------------------------------------------------------------------//
}
