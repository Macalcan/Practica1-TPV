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
bool GlobosPG::onClick(int &pmx, int &pmy){

	//comprueba si se ha explotado el globo en el rectangulo de la imagen
	if (pmx >= x && pmx <= (x + ancho) && pmy >= y && pmy <= (y + alto))
		return explotado = true;


}
//--------------------------------------------------------------------------------//
bool GlobosPG::update(){
	//!!!!!!!!!!!!!!!!!!! mirar si estas lineas han de ir dentro del if else (en el else) o no
	inflado -= 5; //disminuye el tamaño del globo
	//puntos++;
	alto -= 5;
	ancho -= 5;
	//si se ha deshinchado o se ha explotado el globo ya no sera visible 
	if (inflado == 0 || explotado){
		return invisible = true;
	}
	else
		return invisible = false;


}
//getter de puntos del globo
int GlobosPG::getPuntos(){
	return puntos;
}

//--------------------------------------------------------------------------------//
GlobosPG::~GlobosPG()
{

}
