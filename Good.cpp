/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <SDL_ttf.h>
#include <windows.h>
#include <cstdlib>
#include "render.h"
#include "Media.h"
#include <conio.h>
SDL_Texture* MENU1;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

SDL_Surface* gScreenSurface = NULL;
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Rendered texture


bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }

        //Create window
        gWindow = SDL_CreateWindow( "Convertor", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create vsynced renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Get window surface
                gScreenSurface = SDL_GetWindowSurface( gWindow );
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }

                //Initialize SDL_ttf
                if( TTF_Init() == -1 )
                {
                    printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}



void close()
{
    //Free loaded images
    gTextTexture.free();

    //Free global font
    TTF_CloseFont( gFont );
    gFont = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main( int argc, char* args[] )
{
system ("PAUSE");
    int x,y;//Start up SDL and create window

    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {

        // Initialize SDL_ttf library
        if (TTF_Init() != 0)
        {
            cerr << "TTF_Init() Failed: " << TTF_GetError() << endl;
            SDL_Quit();
            exit(1);
        }

        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            SDL_Renderer * renderer = SDL_CreateRenderer(gWindow, -1, 0);
            SDL_Texture * surf1a = SDL_CreateTextureFromSurface(gRenderer, gMENU1a);
            SDL_Texture * surf1b = SDL_CreateTextureFromSurface(gRenderer, gMENU1b);
            SDL_Texture * easteregg = SDL_CreateTextureFromSurface(gRenderer, gEasterEgg);
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //While application is running
            while( !quit )
            {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //User requests quit
                    switch(e.type)
                    {
                    case SDL_QUIT:
                        quit=true;
                        break;
                    case SDL_MOUSEMOTION:
                        x=e.motion.x;
                        y=e.motion.y;
                    }

                    cout<<x<<' '<<y<<endl;
                    system("cls");
                    //Clear screen
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderClear( gRenderer );

                    //Render red filled quad
                    SDL_Rect fillRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT  };
                    SDL_SetRenderDrawColor( gRenderer, 0, 0, 115, 1 );
                    SDL_RenderFillRect( gRenderer, &fillRect );


                    SDL_Rect dstrect1 = { 0, 300, 90, 30 };
                    dstrect1.x=SCREEN_WIDTH/2-45;
                    SDL_RenderCopy(gRenderer, surf1a, NULL, &dstrect1);
                    if((x>= SCREEN_WIDTH/2-45)&&(y>=300)&&(x<=SCREEN_WIDTH/2+45)&&(y<=330))
                        SDL_RenderCopy(gRenderer, surf1b, NULL, &dstrect1);
                    //SDL_RenderCopy(gRenderer, texture, NULL, NULL);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    if((x>= 0)&&(y>=0)&&(x<=20)&&(y<=20)&&e.type==SDL_MOUSEBUTTONDOWN)
                    {
                        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
                        SDL_RenderClear( gRenderer );

                        SDL_Rect easteregg1 = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
                        SDL_RenderCopy(gRenderer, easteregg, NULL, &easteregg1);
                        SDL_RenderPresent( gRenderer );
                        Sleep(2000);
                        quit=true;

                    }
                    SDL_RenderPresent(renderer);
                    //Render green outlined quad
                    SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
                    SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );
                    SDL_RenderDrawRect( gRenderer, &outlineRect );

                    //Draw blue horizontal line
                    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
                    SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );

                    //Draw vertical line of yellow dots

                    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
                    SDL_RenderDrawLine( gRenderer, SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT  );


                    SDL_SetRenderDrawColor( gRenderer, 255, 255, 0, 1 );
                    for ( int row=1; row <= SCREEN_HEIGHT; ++row)
                    {
                        // this for loop will print spaces before the "*"
                        for(int space_count = 1; space_count <= row; ++space_count)
                        {
                            //cout << " ";
                        }
                        for(int col = 1; col <= 9; ++col)
                        {
                            //cout << "*" << " ";
                            SDL_RenderDrawPoint( gRenderer, col++, row );
                        }
                        //cout << endl;
                        for(int col = SCREEN_WIDTH-9; col <= SCREEN_WIDTH; ++col)
                        {
                            //cout << "*" << " ";
                            SDL_RenderDrawPoint( gRenderer, col++, row );
                        }
                        //cout << endl;
                    }
                    for ( int col=1; col <= SCREEN_WIDTH; ++col)
                    {
                        // this for loop will print spaces before the "*"
                        for(int space_count = 1; space_count <= col; ++space_count)
                        {
                            //cout << " ";
                        }
                        for(int row = 1; row <= 9; ++row)
                        {
                            //cout << "*" << " ";
                            SDL_RenderDrawPoint( gRenderer, col, row++ );
                        }
                        //cout << endl;
                        for(int row = SCREEN_WIDTH-9; row <= SCREEN_WIDTH; ++row)
                        {
                            //cout << "*" << " ";
                            SDL_RenderDrawPoint( gRenderer, col, row++ );
                        }
                        //cout << endl;
                    }
                    //Update screen
                    //SDL_RenderPresent( gRenderer );
                    //Render current frame
                    gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, SCREEN_HEIGHT / 6-28 );

                    //Update screen
                    SDL_RenderPresent( gRenderer );
                }
            }
        }
    }

    //Free resources and close SDL
    close();
    //Sleep(2000);
    return 0;

    exit(0);
}
