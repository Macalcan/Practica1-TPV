#include "TexturasSDL.h"
#include <iostream>
#include <string>
using namespace std;

TexturasSDL::TexturasSDL()
{
}
//--------------------------------------------------------------------------------//
bool TexturasSDL::load(SDL_Renderer* pRenderer, string const& nombArch, SDL_Color const& colKey)
{
	//El archivo de imagen que se carga
	string imgName {nombArch};//supuesta ruta de la imagen
	SDL_Surface* pTempSurface = nullptr; //puntero a una superficie en la que se va a dibujar
	bool carga = true; //la imagen se ha cargado correctamente
	//Carga de la imagen
	pTempSurface = SDL_LoadBMP(imgName.c_str()); //carga la superficie del archivo
	if (pTempSurface == nullptr)
	{
		cout << "Imposible cargar el archivo" << imgName << "! \nSDL Error: " << SDL_GetError() << "\n";
		carga = false;
	}
	else 
	{
		//pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);//liberamos la superficie porque se ha cargado la textura
		carga = pTextura != nullptr;
	}
	/*if (loadFile(nombArch) == nullptr)
	{
		cout << "Imposible cargar el archivo" << imgName << "! \nSDL Error: " << SDL_GetError() << "\n";
		carga = false;
	}
	else 
	{
		carga = pTextura != nullptr;
	}*/
	return carga;
}
//--------------------------------------------------------------------------------//
void TexturasSDL::draw(SDL_Renderer* pRenderer, SDL_Rect const& rect){}
//--------------------------------------------------------------------------------//
TexturasSDL::~TexturasSDL()
{
}
