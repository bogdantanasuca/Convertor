#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <SDL_ttf.h>


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
SDL_Surface* button1 = NULL;
SDL_Surface* mini_button = NULL;
SDL_Surface* background_color = NULL;
SDL_Surface* mijloc = NULL;
LTexture gTextTexture;
LTexture gTextTexture2;
LTexture gTextTexture3;
LTexture gTextTexture4;
LTexture gTextTexture5;
LTexture gMenuTexture1;
LTexture gMenuTexture2;
LTexture gMenuTexture3;
LTexture gMenuTexture4;
LTexture gMenuTexture5;
LTexture gMenuTexture6;
LTexture gMenuTexture7;
LTexture gMenuTexture8;
LTexture gMenuTexture9;
LTexture gMenuTexture10;
LTexture gMenuTexture11;

LTexture gInputTextTexture;

SDL_Texture * surface_prisma;
SDL_Rect dstrect_prisma;

Mix_Music *gMusic1 = NULL;
Mix_Music *gMusic2 = NULL;



bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Open the font
    gMENU1a = SDL_LoadBMP( "Media/1a.bmp" );
    gMENU1b = SDL_LoadBMP( "Media/1b.bmp" );
    gMENU2a = SDL_LoadBMP( "Media/2a.bmp" );
    gMENU2b = SDL_LoadBMP( "Media/2b.bmp" );
    gMENU3a = SDL_LoadBMP( "Media/3a.bmp" );
    gMENU3b = SDL_LoadBMP( "Media/3b.bmp" );
    gMENU4a = SDL_LoadBMP( "Media/4a.bmp" );
    gMENU4b = SDL_LoadBMP( "Media/4b.bmp" );
    gMENU5a = SDL_LoadBMP( "Media/5a.bmp" );
    gMENU5b = SDL_LoadBMP( "Media/5b.bmp" );
    gMENU6a = SDL_LoadBMP( "Media/6a.bmp" );
    gMENU6b = SDL_LoadBMP( "Media/6b.bmp" );
    gMENU7a = SDL_LoadBMP( "Media/7a.bmp" );
    gMENU7b = SDL_LoadBMP( "Media/7b.bmp" );
    gMENU8a = SDL_LoadBMP( "Media/8a.bmp" );
    gMENU8b = SDL_LoadBMP( "Media/8b.bmp" );
    gMENU9a = SDL_LoadBMP( "Media/9a.bmp" );
    gMENU9b = SDL_LoadBMP( "Media/9b.bmp" );
    gMENU10a = SDL_LoadBMP( "Media/10a.bmp" );
    gMENU10b = SDL_LoadBMP( "Media/10b.bmp" );
    gMENU11a = SDL_LoadBMP( "Media/11a.bmp" );
    gMENU11b = SDL_LoadBMP( "Media/11b.bmp" );
    gMENU12a = SDL_LoadBMP( "Media/12a.bmp" );
    gMENU12b = SDL_LoadBMP( "Media/12b.bmp" );
    button = SDL_LoadBMP( "Media/button.bmp" );
    button1 = SDL_LoadBMP( "Media/button1.bmp" );
    background_color = SDL_LoadBMP( "Media/background.bmp" );
    mini_button = SDL_LoadBMP( "Media/mini_button.bmp" );
    mijloc = SDL_LoadBMP( "Media/prisma.bmp" );
    gEasterEgg = SDL_LoadBMP( "Media/trollface (1).bmp" );
    SDL_Color textColor = { 255, 255, 0 };
    gFont = TTF_OpenFont( "Media/FreeSanse.ttf", 90 );
    gTextTexture.loadFromRenderedText( "Convertor", textColor,gFont );
    gFont2 = TTF_OpenFont( "Media/riesling.ttf",25 );
    gFont3 = TTF_OpenFont( "Media/arial-rounded-mt-bold.ttf",21 );
    gFont4 = TTF_OpenFont( "Media/arial-rounded-mt-bold.ttf",15 );
    gFont5 = TTF_OpenFont( "Media/arial-rounded-mt-bold.ttf",30 );
    gTextTexture2.loadFromRenderedText( "VISAN STUDIO®  2016-2017", textColor,gFont2 );
    gTextTexture5.loadFromRenderedText( "Alege un domeniu", textColor,gFont5 );
    gMenuTexture1.loadFromRenderedText( "Lungime", textColor,gFont5 );
    gMenuTexture2.loadFromRenderedText( "Arie", textColor,gFont5 );
    gMenuTexture3.loadFromRenderedText( "Volum", textColor,gFont5 );
    gMenuTexture4.loadFromRenderedText( "Timp", textColor,gFont5 );
    gMenuTexture5.loadFromRenderedText( "Viteza", textColor,gFont5 );
    gMenuTexture6.loadFromRenderedText( "Temperatura", textColor,gFont5 );
    gMenuTexture7.loadFromRenderedText( "Masa", textColor,gFont5 );
    gMenuTexture8.loadFromRenderedText( "Energie", textColor,gFont5 );
    gMenuTexture9.loadFromRenderedText( "Presiune", textColor,gFont5 );
    gMenuTexture10.loadFromRenderedText( "Densitate", textColor,gFont5 );
    gMenuTexture11.loadFromRenderedText( "Consum carburant", textColor,gFont5 );


    surface_prisma = SDL_CreateTextureFromSurface(gRenderer, mijloc);
    dstrect_prisma = { (640-579)/2, (640-355)/2, 579, 355 };


    if( gFont2 == NULL || gMENU2a == NULL||mijloc== NULL)
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
gMusic1 = Mix_LoadMUS( "Media/COSTI_IONITA_ADRIAN_MINUNE_-_OF_VIATA_MEA.wav" );
gMusic2 = Mix_LoadMUS( "Media/COSTI_IONITA_-_CATE_NOPTI_AM_PLANS.wav" );



    return success;
}
