// Practica realizada por Blanca Macazaga Zuazo y Adri�n Alc�ntara Delgado
#include "GlobosPG.h"
using namespace std;


GlobosPG::GlobosPG(TexturasSDL* img, int &px, int &py)
{
	x = px; //posicion en el eje x e y del globo
	y = py;
	imagen = img; //apuntara a la textura del globo ademas de hacer que se dibuje

	alto = ancho = 100; //tama�o del globo
	explotado = false; 
	invisible = false;
	puntos = 5; //puntos iniciales

	inflado = 100; //inicialmente el globo est� totalmente inflado
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
//actualiza el globo
bool GlobosPG::update(){
	//si se ha deshinchado o se ha explotado el globo ya no sera visible 
	if (inflado == 0 || explotado)
		return invisible = true;
	else{
		if (rand() % 100 < PVIS) //probabilidad de que sea visible o no
			invisible = false;
		else
			invisible = true;

		if (rand() % 100 < PDES){ //probabilidad de que se desinfle
			inflado -= 10; //disminuye el "aire" que tiene el globo
			alto -= 10; //disminuye el tama�o del globo
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
