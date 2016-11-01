#include "juegoPG.h"
#include "TexturasSDL.h"
#include <iostream>
#include "GlobosPG.h"
using namespace std;

juegoPG::juegoPG()
{
	const int ancho = 640;   //dimensiones de la ventana
	const int alto = 480; 
	
	
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
	bool addTexture = true;

	TexturasSDL t;
	t.loadFile("globoN.png"); //comrpobar que no se tenga que poner la ruta
	globos.size(1) const; //vector de los globos
	numG = globos.size(); //numero de globos sin explotar independientemente de si son visibles o no
}

//--------------------------------------------------------------------------------//
void juegoPG::closeSDL() {}
//--------------------------------------------------------------------------------//
void juegoPG::freeGlobos() {
	globos = nullptr;
}
//--------------------------------------------------------------------------------//
//dibuja los globos que estan visibles, para ello deberia hacer probablemente un for recorriendo todos los globos y accediendo a su atributo visible,
//en caso de que el globo lo sea se dibuja con draw(pRenderer), pRenderer está declarado arriba pero no asginado
void juegoPG::render() {
	if (globos.getVisible()){
		globos.draw(pRenderer);
	}
}
//--------------------------------------------------------------------------------//
//comprueba si al hacer click ha explotado el globo a traves del metodo onClick de GlobosPG y si lo ha explotado saca los puntos del globo y los suma
//a los puntos conseguidos en total
//¿habria que comprobarlo en todos los globos?
void juegoPG::onClick(int &pmx, int &pmy){
	int aux; //auxiliar para obtener los puntos de un globo
	
	if (globos.onClick(&pmx, &pmy)){
		aux = globos.getPuntos();
		puntos += aux;
		numG--;
	}
}
//--------------------------------------------------------------------------------//
//recorre todos los globos actualizandolos y comprobando si se han desinflado o explotado, y por lo tanto no son visibles
void juegoPG::update() {
	for (int i = 0; i < globos.size(); i++){
		bool aux = (*globos)[i].update();
		if (aux)
			numG--;
		
	}
	//actualizacion del numero de globos activos

	
}
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
