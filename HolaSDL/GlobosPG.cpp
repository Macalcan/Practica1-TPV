// Practica realizada por Blanca Macazaga Zuazo y Adrián Alcántara Delgado
#include "GlobosPG.h"
using namespace std;


GlobosPG::GlobosPG(TexturasSDL* img, int &px, int &py)
{
	//asignacion de la posicion x para un globo que luego ha de ser aleatoria
	x = px; //comprobar que aparece segun al ventana del juego
	//asignacion de la posicion y para un globo que luego ha de ser aleatoria
	y = py;
	imagen = img;//->getTextura();

	alto = ancho = 100;
	explotado = false;
	invisible = false;
	puntos = 5;

	inflado = 100;
	daTrue = false;
}
//--------------------------------------------------------------------------------//
void GlobosPG::draw(SDL_Renderer* pRenderer)const{
	if (!invisible){ //en caso de estar visible se dibuja
		SDL_Rect datBalloon;
		datBalloon = { x, y, ancho, alto };
		imagen->draw(pRenderer, datBalloon);
	}
}
//--------------------------------------------------------------------------------//
bool GlobosPG::onClick(int &pmx, int &pmy){
	//comprueba si se ha explotado el globo en el rectangulo de la imagen
	if (!invisible && pmx >= x && pmx <= (x + ancho) && pmy >= y && pmy <= (y + alto)){
		return explotado = true;
	}
	else return false;
}
//--------------------------------------------------------------------------------//
bool GlobosPG::update(){
	//si se ha deshinchado o se ha explotado el globo ya no sera visible 
	if (inflado == 0 || explotado)
		return invisible = true;
	else{
		if (rand() % 100 < PVIS)
			invisible = false;
		else
			invisible = true;

		if (rand() % 100 < PDES){
			inflado -= 10; //disminuye el tamaño del globo
			alto -= 10;
			ancho -= 10;
			puntos += 2;//aumentan los puntos que se recibe al explotar el globo cuanto menos inflado este
		}
		return false;
	}
}
//getter de puntos del globo
int GlobosPG::getPuntos(){
	return puntos;
}

//--------------------------------------------------------------------------------//
GlobosPG::~GlobosPG()
{

}
