﻿// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include "juegoPG.h"
#include "TexturasSDL.h"
#include <iostream>
#include "GlobosPG.h"
using namespace std;

juegoPG::juegoPG()
{
	srand(SDL_GetTicks());
	ptexture [0] = nullptr; //texturas de los globos
	ptexture [1] = nullptr;
	ptexture[2] = nullptr; //textura del fondo

	SDL_Window * pWindow = nullptr;
	SDL_Renderer * pRenderer = nullptr;

	error = false; //si hay un error se pondrá a true
	exit = false; //si se sale del juego se pondrá a true
	gameOver = false; //si se acaba el juego se pondrá a true
	puntos = 0; //puntos al comenzar el juego
	initSDL();
	initGlobos();
	initFondo();
	
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
//crea el fondo
bool juegoPG::initFondo(){
	ptexture[2] = new TexturasSDL;
	string file = { "..\\bmps\\sky.jpg" };
	ptexture[2]->load(pRenderer, file);
	return (ptexture[2] != nullptr);
}
bool juegoPG::initGlobos() {
	//declaras variables aleatorias x e y que indican la posicion de cada globo
	int x;
	int y;
	//inicializa las texturas de los globos
	for (int j = 0; j < 2; j++){
		ptexture [j] = new TexturasSDL;
	}
	
	//carga las texturas de los globos
	string nombre = { "..\\bmps\\globoN.png" };
	ptexture[0]->load(pRenderer, nombre);
	nombre = {"..\\bmps\\globoM.png"};
	ptexture[1]->load(pRenderer, nombre);

	for (int i = 0; i < dim; i++){//creamos un globo en cada vuelta en una posicion aleatoria en el rectangulo de la ventana
		x = rand() % 450;
		y = rand() % 450;
		globos[i] = new GlobosPG(ptexture[i%2], x, y); //cada globo tendrá la textura 0 o la textura 1
		explotados[i] = false; //aun no ha sido explotado
	}

	numG = dim; //numero total de globos al principio del juego
	return (ptexture[0] != nullptr && ptexture[1] != nullptr);
}

//--------------------------------------------------------------------------------//
void juegoPG::closeSDL() {
	SDL_DestroyRenderer(pRenderer);
	pRenderer = nullptr;

	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;

	SDL_Quit();
}
//--------------------------------------------------------------------------------//
void juegoPG::freeGlobos() {
	//destruye el array de los globos
	for (int i = 0; i < dim; i++)
		delete globos[i];
	//destruye las texturas de los globos
	delete(ptexture[0]);
	delete(ptexture[1]);

}
//--------------------------------------------------------------------------------//
//dibuja los globos que estan visibles, para ello deberia hacer probablemente un for recorriendo todos los globos y accediendo a su atributo visible,
//en caso de que el globo lo sea se dibuja con draw(pRenderer), pRenderer está declarado arriba pero no asginado
void juegoPG::render()const {

	SDL_RenderClear(pRenderer); //"limpia" el render donde vamos a dibujar el siguiente frame
	
	SDL_Rect rect; //rect para el fondo
	rect = {0, 0, ancho, alto};
	ptexture[2]->draw(pRenderer, rect); //dibuja el fondo

	for (int i = 0; i < dim; i++){ //dibuja los globos
		globos[i]->draw(pRenderer);
	}

	//Show the window
	SDL_RenderPresent(pRenderer);
}
//--------------------------------------------------------------------------------//
//comprueba si al hacer click ha explotado el globo a traves del metodo onClick de GlobosPG y si lo ha explotado saca los puntos del globo y los suma
//a los puntos conseguidos en total
void juegoPG::onClick(int &pmx, int &pmy){

	for (int i = 0; i < dim; i++){
		if (globos[i]->onClick(pmx, pmy) && !explotados[i]){
			puntos += globos[i]->getPuntos();
		}
	}
}
//--------------------------------------------------------------------------------//
//recorre todos los globos actualizandolos y comprobando si se han desinflado o explotado, y por lo tanto no son visibles
void juegoPG::update() {
	for (int i = 0; i < dim; i++) {
		if (globos[i]->update() && !explotados[i]) { //si se ha exlpotado el globo se determina en nuestro array de booleanos y desciende el numero de globos
			numG--;
			explotados[i] = true;
		}
	}
}
//--------------------------------------------------------------------------------//
void juegoPG::handle_event() {
	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) exit = true;
		else if (e.type == SDL_MOUSEBUTTONUP) {
			if (e.button.button == SDL_BUTTON_LEFT) {
				cout << "CLICK";
				onClick(e.button.x, e.button.y);
			}
		}
	}
}
//--------------------------------------------------------------------------------//
void juegoPG::run()
{
	if (!error){
		Uint32 MSxUpdate = 500;
		cout << "Play \n";
		Uint32 lastUpdate = SDL_GetTicks();
		string puntuacion = "preparado!!?? ";
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Practica1", puntuacion.c_str(), nullptr);
		
		render();
		handle_event();
		while (!exit && !gameOver){
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate){//while(elapsed >= MSxUpdate)
				update();
				lastUpdate = SDL_GetTicks();
			}

			render();
			handle_event();
			if (numG == 0) { // Cuando el juego acaba aparece una ventana con la puntuacion que hemos conseguido y con un boton OK que cuando se pulsa se cierran las consolas
				string puntuacion = "Puntuacion: ";
				puntuacion += to_string(puntos);
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Has terminado!!", puntuacion.c_str(), nullptr);
				gameOver = true;
			}
		}

		render();
		if (exit) cout << "Exit \n";
		else cout << "Has obtenido " << puntos << " puntos \n";
		SDL_Delay(1000);
	}



}

//--------------------------------------------------------------------------------//
juegoPG::~juegoPG()
{
	closeSDL();
	freeGlobos();
	ptexture[2] = nullptr;
	pWindow = nullptr;
	pRenderer = nullptr;
}
