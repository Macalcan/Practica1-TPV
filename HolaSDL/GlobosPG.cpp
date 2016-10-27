#include "GlobosPG.h"
using namespace std;


GlobosPG::GlobosPG(TexturasSDL* img, int &px, int &py)
{
	//asignacion de la posicion x para un globo que luego ha de ser aleatoria
	x = px; //comprobar que aparece segun al ventana del juego

	//asignacion de la posicion y para un globo que luego ha de ser aleatoria
	y = py;

	alto = ancho = 100;
	explotado = false;
	puntos = 0; //en desuso
	//visible = true;
	inflado = 100;

	//medidas del globo
	balloon.h = alto;
	balloon.w = ancho;
	balloon.x = x;
	balloon.y = y;
}
//--------------------------------------------------------------------------------//
void GlobosPG::draw(SDL_Renderer* pRenderer)const{
	TexturasSDL aux; //auxiliar para llamar a draw de texturasSDL
	aux.draw(pRenderer, balloon);
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
	inflado -= 10; //disminuye el tamaño del globo
	balloon.h -= 10;
	balloon.w -= 10;
	//si se ha deshinchado o se ha explotado el globo ya no sera visible 
	if (inflado == 0 || explotado){
		return true;
	}
	else
		return false;


}
//--------------------------------------------------------------------------------//
GlobosPG::~GlobosPG()
{
	
}
