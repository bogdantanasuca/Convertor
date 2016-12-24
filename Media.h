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
SDL_Surface* gMENU2a = NULL;
SDL_Surface* gMENU2b= NULL;
SDL_Surface* gMENU3a = NULL;
SDL_Surface* gMENU3b= NULL;
SDL_Surface* gMENU4a = NULL;
SDL_Surface* gMENU4b= NULL;
SDL_Surface* gMENU5a = NULL;
SDL_Surface* gMENU5b= NULL;
SDL_Surface* gMENU6a = NULL;
SDL_Surface* gMENU6b= NULL;
SDL_Surface* gMENU7a = NULL;
SDL_Surface* gMENU7b= NULL;
SDL_Surface* gMENU8a = NULL;
SDL_Surface* gMENU8b= NULL;
SDL_Surface* gMENU9a = NULL;
SDL_Surface* gMENU9b= NULL;
SDL_Surface* gMENU10a = NULL;
SDL_Surface* gMENU10b= NULL;
SDL_Surface* gMENU11a = NULL;
SDL_Surface* gMENU11b= NULL;
SDL_Surface* gMENU12a = NULL;
SDL_Surface* gMENU12b= NULL;
SDL_Surface* gEasterEgg= NULL;
SDL_Surface* button = NULL;
SDL_Surface* mini_button = NULL;
LTexture gTextTexture;
LTexture gTextTexture2;
LTexture gTextTexture3;
LTexture gTextTexture4;


LTexture gInputTextTexture;

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Open the font
    gMENU1a = SDL_LoadBMP( "1a.bmp" );
    gMENU1b = SDL_LoadBMP( "1b.bmp" );
    gMENU2a = SDL_LoadBMP( "2a.bmp" );
    gMENU2b = SDL_LoadBMP( "2b.bmp" );
    gMENU3a = SDL_LoadBMP( "3a.bmp" );
    gMENU3b = SDL_LoadBMP( "3b.bmp" );
    gMENU4a = SDL_LoadBMP( "4a.bmp" );
    gMENU4b = SDL_LoadBMP( "4b.bmp" );
    gMENU5a = SDL_LoadBMP( "5a.bmp" );
    gMENU5b = SDL_LoadBMP( "5b.bmp" );
    gMENU6a = SDL_LoadBMP( "6a.bmp" );
    gMENU6b = SDL_LoadBMP( "6b.bmp" );
    gMENU7a = SDL_LoadBMP( "7a.bmp" );
    gMENU7b = SDL_LoadBMP( "7b.bmp" );
    gMENU8a = SDL_LoadBMP( "8a.bmp" );
    gMENU8b = SDL_LoadBMP( "8b.bmp" );
    gMENU9a = SDL_LoadBMP( "9a.bmp" );
    gMENU9b = SDL_LoadBMP( "9b.bmp" );
    gMENU10a = SDL_LoadBMP( "10a.bmp" );
    gMENU10b = SDL_LoadBMP( "10b.bmp" );
    gMENU11a = SDL_LoadBMP( "11a.bmp" );
    gMENU11b = SDL_LoadBMP( "11b.bmp" );
    gMENU12a = SDL_LoadBMP( "12a.bmp" );
    gMENU12b = SDL_LoadBMP( "12b.bmp" );
    button = SDL_LoadBMP( "button.bmp" );
    mini_button = SDL_LoadBMP( "mini_button.bmp" );

    gEasterEgg = SDL_LoadBMP( "trollface (1).bmp" );
    SDL_Color textColor = { 255, 255, 0 };
    gFont = TTF_OpenFont( "FreeSanse.ttf", 90 );
    gTextTexture.loadFromRenderedText( "Convertor", textColor,gFont );
    gFont2 = TTF_OpenFont( "riesling.ttf",25 );
    gFont3 = TTF_OpenFont( "bauhaus.ttf",21 );
    gFont4 = TTF_OpenFont( "bauhaus.ttf",15 );
    gTextTexture2.loadFromRenderedText( "VISAN STUDIO®  2016-2017", textColor,gFont2 );



    if( gFont2 == NULL || gMENU2a == NULL||gEasterEgg== NULL)
    {
        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
        success = false;
    }
    else
    {
        //Render text
        SDL_Color textColor = { 255, 255, 0 };
        if( !gTextTexture.loadFromRenderedText( "Convertor", textColor,gFont) )
        {
            printf( "Failed to render text texture!\n" );
            success = false;
        }
    }

    return success;
}
