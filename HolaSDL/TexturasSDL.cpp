#include "TexturasSDL.h"
#include <iostream>;
using namespace std;

TexturasSDL::TexturasSDL()
{
}
//--------------------------------------------------------------------------------//
bool TexturasSDL::load(SDL_Renderer* pRenderer, SDL_Texture* & pTexture)
{
	//El archivo de imagen que se carga
	char imgName[] {"...\\bmps\\globos.png"};//supuesta ruta de la imagen
	SDL_Surface* pTempSurface = nullptr; //puntero a una superficie en la que se va a dibujar
	bool carga = true; //la imagen se ha cargado correctamente
	//Carga de la imagen
	pTempSurface = SDL_LoadBMP(imgName); //carga la superficie del archivo
	if (pTempSurface == nullptr)
	{
		cout << "Imposible cargar el archivo" << imgName << "! \nSDL Error: " << SDL_GetError() << "\n";
		carga = false;
	}
	else 
	{
		pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);//liberamos la superficie porque se ha cargado la textura
		carga = pTexture != nullptr;
		pTextura = pTexture;
	}
	return carga;
}
//--------------------------------------------------------------------------------//
void TexturasSDL::draw(SDL_Renderer* pRenderer, SDL_Rect const& rect){}
//--------------------------------------------------------------------------------//
TexturasSDL::~TexturasSDL()
{
}
