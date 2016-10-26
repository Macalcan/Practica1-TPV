#include "GlobosPG.h"
using namespace std;


GlobosPG::GlobosPG(TexturasSDL* img, int &px, int &py)
{
	//asignacion de la posicion x para un globo que luego ha de ser aleatoria
	px = x; //comprobar que aparece segun al ventana del juego

	//asignacion de la posicion y para un globo que luego ha de ser aleatoria
	py = y;

	alto = ancho = 100;
	explotado = false;
	puntos = 0;
	visible = false;
	hinchado = 100;
}
//--------------------------------------------------------------------------------//
void GlobosPG::draw(SDL_Renderer* pRenderer){}
//--------------------------------------------------------------------------------//
bool GlobosPG::onClick(int &pmx, int &pmy){

	//comprueba si se ha explotado el globo en el rectangulo de la imagen
	if (pmx >= x && pmx <= (x + ancho) && pmy >= y && pmy <= (y + alto))
		explotado = true;
	
	return explotado;
}
//--------------------------------------------------------------------------------//
bool GlobosPG::update(){
	if  (hinchado = 0 || explotado)
		visible = false;
}
//--------------------------------------------------------------------------------//
GlobosPG::~GlobosPG()
{

}
