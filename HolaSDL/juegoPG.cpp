#include "juegoPG.h"
#include "TexturasSDL.h"
#include <iostream>
#include "GlobosPG.h"
using namespace std;

juegoPG::juegoPG()
{
	srand(SDL_GetTicks());
	ptexture = nullptr;
	SDL_Window * pWindow = nullptr;
	SDL_Renderer * pRenderer = nullptr;

	error = false;
	exit = false;
	gameOver = false;
	puntos = 0;
	initSDL();
	initGlobos();


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
	//declaras variables aleatorias x e y que indican la posicion de cada globo
	int x;
	int y;
	ptexture = new TexturasSDL;
	string nombre = { "..\\bmps\\globoN.png" };
	ptexture->load(pRenderer, nombre);


	for (int i = 0; i < dim; i++){
		x = rand() % 450;
		y = rand() % 450;
		globos[i] = new GlobosPG(ptexture, x, y);
		explotados[i] = false;
	}



	numG = dim; //numero total de globos al principio del juego
	return (ptexture != nullptr);
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
	delete(ptexture);

}
//--------------------------------------------------------------------------------//
//dibuja los globos que estan visibles, para ello deberia hacer probablemente un for recorriendo todos los globos y accediendo a su atributo visible,
//en caso de que el globo lo sea se dibuja con draw(pRenderer), pRenderer está declarado arriba pero no asginado
void juegoPG::render()const {

	SDL_RenderClear(pRenderer);

	for (int i = 0; i < dim; i++){
		globos[i]->draw(pRenderer);
	}

	//Show the window
	SDL_RenderPresent(pRenderer);
}
//--------------------------------------------------------------------------------//
//comprueba si al hacer click ha explotado el globo a traves del metodo onClick de GlobosPG y si lo ha explotado saca los puntos del globo y los suma
//a los puntos conseguidos en total
void juegoPG::onClick(int &pmx, int &pmy){

	for (int i = 0; i < dim; i++){ //revisar
		if (globos[i]->onClick(pmx, pmy) && !explotados[i]){ //&& !explotados[i]){
			puntos += globos[i]->getPuntos();
		}
	}
}
//--------------------------------------------------------------------------------//
//recorre todos los globos actualizandolos y comprobando si se han desinflado o explotado, y por lo tanto no son visibles
void juegoPG::update() {
	for (int i = 0; i < dim; i++){
		if (globos[i]->update() && !explotados[i]){ //REVISAR
			numG--;
			explotados[i] = true;
		}
	}

	//if (numG == 0)
	//gameOver = true;
	//actualizacion del numero de globos activos


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
		render();
		handle_event();
		while (!exit && !gameOver){
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate){//while(elapsed >= MSxUpdate)
				update();
				lastUpdate = SDL_GetTicks();
			}

			render();
			handle_event();
			if (numG == 0) {
				string buffer = "Puntuacion: ";
				buffer += to_string(puntos);
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Has terminado!!", buffer.c_str(), nullptr);
				gameOver = true;
			}
		}

		render();
		if (exit) cout << "Exit \n";
		else cout << "Has obtenido " << puntos << " puntos \n";
		SDL_Delay(1000); //cin.get();
	}



}

//--------------------------------------------------------------------------------//
juegoPG::~juegoPG()
{
	closeSDL();
	freeGlobos();
	pWindow = nullptr;
	pRenderer = nullptr;
}
