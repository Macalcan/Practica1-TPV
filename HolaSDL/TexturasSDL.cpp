#include "TexturasSDL.h"
#include <iostream>
#include <string>
#include "SDL_image.h"
using namespace std;

TexturasSDL::TexturasSDL()
{
	SDL_Texture* pTextura = nullptr; //inicializamos el puntero que apunta a la textura de nuestro globo a null porque todav�a no tenemos textura
}
//--------------------------------------------------------------------------------//
bool TexturasSDL::load(SDL_Renderer* pRenderer, string const& nombArch)
{
	//El archivo de imagen que se carga
	SDL_Surface* pTempSurface = nullptr; //puntero a una superficie en la que se va a dibujar
	bool carga = true; //Suponemos que la imagen se ha cargado correctamente
	//Carga de la imagen
	pTempSurface = loadFile(nombArch); //carga la superficie del archivo y es apuntada por nuestra superficie

	if (pTempSurface == nullptr)
	{
		cout << "Imposible cargar el archivo" << nombArch << "! \nSDL Error: " << SDL_GetError() << "\n";
		carga = false;
	}
	else
	{
		pTextura = SDL_CreateTextureFromSurface(pRenderer, pTempSurface); //Se crea una textura a partir de nuestra superficie
		SDL_FreeSurface(pTempSurface);//liberamos la superficie porque se ha cargado la textura
		carga = pTextura != nullptr;
		alto = pTempSurface->h;
		ancho = pTempSurface->w;
	}

	return carga;
}
//--------------------------------------------------------------------------------//
SDL_Texture* TexturasSDL::getTextura(){
	return pTextura;
}
void TexturasSDL::draw(SDL_Renderer* pRenderer, SDL_Rect const& rect){
	SDL_Rect tRect;
	tRect = { 0, 0, alto, ancho };
	SDL_RenderCopy(pRenderer, pTextura, &tRect, &rect);

}
//--------------------------------------------------------------------------------//
SDL_Surface* TexturasSDL::loadFile(string file)
{

	SDL_Surface* archivo = nullptr;
	archivo = IMG_Load(file.c_str());
	return archivo;
}
//--------------------------------------------------------------------------------//
TexturasSDL::~TexturasSDL()
{
	//destruimos la textura y liberamos el puntero
	SDL_DestroyTexture(pTextura);
	pTextura = nullptr;
}
