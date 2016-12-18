#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <SDL_ttf.h>
#include <windows.h>

SDL_Surface* gMENU1a = NULL;
SDL_Surface* gMENU1b= NULL;
SDL_Surface* gEasterEgg= NULL;
LTexture gTextTexture;

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Open the font
	gMENU1a = SDL_LoadBMP( "1a.bmp" );
    gMENU1b = SDL_LoadBMP( "1b.bmp" );
    gEasterEgg = SDL_LoadBMP( "trollface (1).bmp" );
	gFont = TTF_OpenFont( "FreeSanse.ttf", 90 );
	if( gFont == NULL || gMENU1a == NULL||gEasterEgg== NULL)
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = { 255, 255, 0 };
		if( !gTextTexture.loadFromRenderedText( "Convertor", textColor ) )
		{
			printf( "Failed to render text texture!\n" );
			success = false;
		}
	}

	return success;
}
