// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include "SDL.h"  // Para utilizar SDL
#include <iostream>  // la consola: cin / cout
#include "juegoPG.h"
using namespace std; // Para cualificar automaticamente con std:: los identificadores de la librería estandar 

int main(int argc, char* args[]) {  // SDL require esta cabecera 
	
	system("chcp 1252");
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Check Memory Leaks
	/*bool error = false;

	juegoPG game;
	while (!error){
		game.run();
	}*/

	juegoPG game;
	game.run();

	/*
	SDL_Window * pWin = nullptr;        //The window we'll be rendering to
	SDL_Renderer * pRender = nullptr;   //The renderer by the window  
	SDL_Texture *pTexture = nullptr;    //The image we will load and show on the screen

	//Start up SDL and create resources
	init(pWin, pRender);

	loadTexture(pRender, pTexture);

	if (pWin == nullptr || pRender == nullptr || pTexture == nullptr) {
		cout << " Fatal Error\n Press Enter";  cin.ignore();   //system("pause");
	}
	else {
		bool exit = false;

		render(pRender, pTexture);  //  Show the texture
		exit = handle_events();	    //  
		while (!exit) {    // While application is running
			update();
			// SDL_Delay(2000);  //Wait two seconds
			render(pRender, pTexture);
			exit = handle_events();
		}
	}

	// free resources and close SDL
	SDL_DestroyTexture(pTexture);
	pTexture = nullptr;

	close(pWin, pRender);*/

	return 0;
}