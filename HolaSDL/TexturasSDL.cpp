#include "TexturasSDL.h"
#include <iostream>
#include <string>
using namespace std;

TexturasSDL::TexturasSDL()
{
	SDL_Texture* pTextura = nullptr;
}
//--------------------------------------------------------------------------------//
bool TexturasSDL::load(SDL_Renderer* pRenderer, string const& nombArch)
{
	//El archivo de imagen que se carga
	SDL_Surface* pTempSurface = nullptr; //puntero a una superficie en la que se va a dibujar
	bool carga = true; //la imagen se ha cargado correctamente
	//Carga de la imagen
	pTempSurface = loadFile(nombArch); //carga la superficie del archivo
	if (pTempSurface == nullptr)
	{
		cout << "Imposible cargar el archivo" << nombArch << "! \nSDL Error: " << SDL_GetError() << "\n";
		carga = false;
	}
	else 
	{
		pTextura = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);//liberamos la superficie porque se ha cargado la textura
		carga = pTextura != nullptr;
	}
	return carga;
}
//--------------------------------------------------------------------------------//
void TexturasSDL::draw(SDL_Renderer* pRenderer, SDL_Rect const& Winrect){
	SDL_Rect rect;//dimensiones de la textura
	rect.h = 0;
	rect.w = 0;
	rect.x = 0;
	rect.y = 0;

	//Clear the window to background color 
	SDL_RenderClear(pRenderer);

	SDL_RenderCopy(pRenderer, pTextura, &rect, &Winrect);
	//Show the window
	SDL_RenderPresent(pRenderer);
}
//--------------------------------------------------------------------------------//
SDL_Surface* TexturasSDL::loadFile(string file)
{
	SDL_Surface* archivo = nullptr;
	archivo = SDL_LoadBMP(file.c_str());
	return archivo;
}
//--------------------------------------------------------------------------------//
TexturasSDL::~TexturasSDL()
{
	SDL_DestroyTexture (pTextura);
	pTextura = nullptr;
}
