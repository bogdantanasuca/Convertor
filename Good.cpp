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
//system ("PAUSE");
    int x,y,a,b,c,d;//Start up SDL and create window

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
            SDL_Texture * surf2a = SDL_CreateTextureFromSurface(gRenderer, gMENU2a);
            SDL_Texture * surf2b = SDL_CreateTextureFromSurface(gRenderer, gMENU2b);
            SDL_Texture * surf3a = SDL_CreateTextureFromSurface(gRenderer, gMENU3a);
            SDL_Texture * surf3b = SDL_CreateTextureFromSurface(gRenderer, gMENU3b);
            SDL_Texture * surf4a = SDL_CreateTextureFromSurface(gRenderer, gMENU4a);
            SDL_Texture * surf4b = SDL_CreateTextureFromSurface(gRenderer, gMENU4b);
            SDL_Texture * surf5a = SDL_CreateTextureFromSurface(gRenderer, gMENU5a);
            SDL_Texture * surf5b = SDL_CreateTextureFromSurface(gRenderer, gMENU5b);
            SDL_Texture * surf6a = SDL_CreateTextureFromSurface(gRenderer, gMENU6a);
            SDL_Texture * surf6b = SDL_CreateTextureFromSurface(gRenderer, gMENU6b);
            SDL_Texture * surf7a = SDL_CreateTextureFromSurface(gRenderer, gMENU7a);
            SDL_Texture * surf7b = SDL_CreateTextureFromSurface(gRenderer, gMENU7b);
            SDL_Texture * surf8a = SDL_CreateTextureFromSurface(gRenderer, gMENU8a);
            SDL_Texture * surf8b = SDL_CreateTextureFromSurface(gRenderer, gMENU8b);
            SDL_Texture * surf9a = SDL_CreateTextureFromSurface(gRenderer, gMENU9a);
            SDL_Texture * surf9b = SDL_CreateTextureFromSurface(gRenderer, gMENU9b);
            SDL_Texture * surf10a = SDL_CreateTextureFromSurface(gRenderer, gMENU10a);
            SDL_Texture * surf10b = SDL_CreateTextureFromSurface(gRenderer, gMENU10b);
            SDL_Texture * surf11a = SDL_CreateTextureFromSurface(gRenderer, gMENU11a);
            SDL_Texture * surf11b = SDL_CreateTextureFromSurface(gRenderer, gMENU11b);
            SDL_Texture * surf12a = SDL_CreateTextureFromSurface(gRenderer, gMENU12a);
            SDL_Texture * surf12b = SDL_CreateTextureFromSurface(gRenderer, gMENU12b);
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

                    SDL_Rect dstrect1 = { 180, 220, 90, 30 };
                    a=dstrect1.x;
                    b=dstrect1.y;
                    c=dstrect1.w;
                    d=dstrect1.h;
                    SDL_RenderCopy(gRenderer, surf1a, NULL, &dstrect1);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf1b, NULL, &dstrect1);

                    SDL_Rect dstrect2 = { 370, 220, 90, 30 };
                    a=dstrect2.x;
                    b=dstrect2.y;
                    c=dstrect2.w;
                    d=dstrect2.h;
                    SDL_RenderCopy(gRenderer, surf2a, NULL, &dstrect2);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf2b, NULL, &dstrect2);

                    SDL_Rect dstrect3 = { 180, 270, 90, 30 };
                    a=dstrect3.x;
                    b=dstrect3.y;
                    c=dstrect3.w;
                    d=dstrect3.h;
                    SDL_RenderCopy(gRenderer, surf3a, NULL, &dstrect3);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf3b, NULL, &dstrect3);

                    SDL_Rect dstrect4 = { 370, 270, 90, 30 };
                    a=dstrect4.x;
                    b=dstrect4.y;
                    c=dstrect4.w;
                    d=dstrect4.h;
                    SDL_RenderCopy(gRenderer, surf4a, NULL, &dstrect4);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf4b, NULL, &dstrect4);

                    SDL_Rect dstrect5 = { 180, 320, 90, 30 };
                    a=dstrect5.x;
                    b=dstrect5.y;
                    c=dstrect5.w;
                    d=dstrect5.h;
                    SDL_RenderCopy(gRenderer, surf5a, NULL, &dstrect5);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf5b, NULL, &dstrect5);

                    SDL_Rect dstrect6 = { 370, 320, 90, 30 };
                    a=dstrect6.x;
                    b=dstrect6.y;
                    c=dstrect6.w;
                    d=dstrect6.h;
                    SDL_RenderCopy(gRenderer, surf6a, NULL, &dstrect6);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf6b, NULL, &dstrect6);

                    SDL_Rect dstrect7 = { 180, 370, 90, 30 };
                    a=dstrect7.x;
                    b=dstrect7.y;
                    c=dstrect7.w;
                    d=dstrect7.h;
                    SDL_RenderCopy(gRenderer, surf7a, NULL, &dstrect7);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf7b, NULL, &dstrect7);

                    SDL_Rect dstrect8 = { 370, 370, 90, 30 };
                    a=dstrect8.x;
                    b=dstrect8.y;
                    c=dstrect8.w;
                    d=dstrect8.h;
                    SDL_RenderCopy(gRenderer, surf8a, NULL, &dstrect8);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf8b, NULL, &dstrect8);


                    SDL_Rect dstrect9 = { 180, 420, 90, 30 };
                    a=dstrect9.x;
                    b=dstrect9.y;
                    c=dstrect9.w;
                    d=dstrect9.h;
                    SDL_RenderCopy(gRenderer, surf9a, NULL, &dstrect9);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf9b, NULL, &dstrect9);

                    SDL_Rect dstrect10 = { 370, 420, 90, 30 };
                    a=dstrect10.x;
                    b=dstrect10.y;
                    c=dstrect10.w;
                    d=dstrect10.h;
                    SDL_RenderCopy(gRenderer, surf10a, NULL, &dstrect10);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf10b, NULL, &dstrect10);

                    SDL_Rect dstrect11 = { SCREEN_WIDTH/2-45, 470, 90, 30 };
                    a=dstrect11.x;
                    b=dstrect11.y;
                    c=dstrect11.w;
                    d=dstrect11.h;
                    SDL_RenderCopy(gRenderer, surf11a, NULL, &dstrect11);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf11b, NULL, &dstrect11);

                    SDL_Rect dstrect12 = { SCREEN_WIDTH/2-45, 520, 90, 30 };
                    a=dstrect12.x;
                    b=dstrect12.y;
                    c=dstrect12.w;
                    d=dstrect12.h;
                    SDL_RenderCopy(gRenderer, surf12a, NULL, &dstrect12);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
                       SDL_RenderCopy(gRenderer, surf12b, NULL, &dstrect12);
                    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
                       quit=true;
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
                    gTextTexture2.render( ( SCREEN_WIDTH - gTextTexture2.getWidth() ) / 2, SCREEN_HEIGHT -40 );

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
