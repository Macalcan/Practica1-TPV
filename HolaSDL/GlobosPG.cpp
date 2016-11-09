#include "GlobosPG.h"
using namespace std;


GlobosPG::GlobosPG(TexturasSDL* img, int &px, int &py)
{
	//asignacion de la posicion x para un globo que luego ha de ser aleatoria
	x = px; //comprobar que aparece segun al ventana del juego
	//asignacion de la posicion y para un globo que luego ha de ser aleatoria
	y = py;
	imagen = img;//->getTextura();


	//SDL_Renderer* pRender = img;
	alto = ancho = 100;
	explotado = false;
	invisible = false;
	puntos = 5;

	inflado = 100;
	daTrue = false;
	/*//medidas del globo
	balloon.h = alto;
	balloon.w = ancho;
	balloon.x = x;
	balloon.y = y;*/
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
bool GlobosPG::onClick(int &pmx, int &pmy) {

		if (!invisible && pmx >= x && pmx <= (x + ancho) && pmy >= y && pmy <= (y + alto)) {
				invisible = true;
			return true;
	}
	else return false;
}
//--------------------------------------------------------------------------------//
bool GlobosPG::update(){
	//!!!!!!!!!!!!!!!!!!! mirar si estas lineas han de ir dentro del if else (en el else) o no
	if (inflado == 0 && !invisible || explotado && !invisible)
		return true;
	else {
		if (rand() % 100 < PVIS)
			invisible = false;
		else invisible = true;
		inflado -= 5;
		alto -= 5;
		ancho -= 5;
		if (inflado == 0) {
			return false;
		}
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
