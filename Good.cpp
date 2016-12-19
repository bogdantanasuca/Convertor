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
void background();
//Frees media and shuts down SDL
void close();
void meniu(int x,int y,SDL_Event e);
void quit_button(int x,int y,SDL_Event e);
bool quit = false;
//Rendered texture

void butonas(char scris[30],int a,int b,int c,int d,int e);
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
            SDL_Texture * easteregg = SDL_CreateTextureFromSurface(gRenderer, gEasterEgg);

            //Main loop flag

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
    SDL_Rect fillRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT  };
    SDL_SetRenderDrawColor( gRenderer, 0, 0, 115, 1 );
    SDL_RenderFillRect( gRenderer, &fillRect );
                    //SDL_RenderPresent( gRenderer );


                    meniu(x,y,e);
                    background();
                    //SDL_RenderPresent( gRenderer );
                    //Render red filled quad


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
                        break;

                    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                    cout<<gTextTexture2.getHeight()<<endl;
                    //Update screen
                    //butonas("yala",0,320,320 , x , y );
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

void butonas(char scris[30],int a,int b,int c,int d,int e)
{
    SDL_Color textColor_blue = { 0, 0, 255 };
    SDL_Color textColor_red = { 255, 0, 0 };
    SDL_Texture * surface_gig = SDL_CreateTextureFromSurface(gRenderer, button);
    SDL_Rect dstrect_buttonas = { 0, 0, 90, 30 };
    dstrect_buttonas.x=b;
    dstrect_buttonas.y=c;

    SDL_RenderCopy(gRenderer, surface_gig, NULL, &dstrect_buttonas);
    if((d>= b)&&(e>=c)&&(d<=b+90)&&(e<=c+30))
        a=1;
    if(a==0)
        gTextTexture3.loadFromRenderedText( scris, textColor_blue,gFont3 );
    else
        gTextTexture3.loadFromRenderedText( scris, textColor_red,gFont3 );
    gTextTexture3.render( (90- gTextTexture3.getWidth() ) / 2+b, (30- gTextTexture3.getHeight() ) / 2 +c);

}

void meniu(int x,int y,SDL_Event e)
{
    background();
    int a,b,c,d;
    bool quit=false;
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
    SDL_RenderCopy(gRenderer, surf2a, NULL, &dstrect2);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf2b, NULL, &dstrect2);

    SDL_Rect dstrect3 = { 180, 270, 90, 30 };
    a=dstrect3.x;
    b=dstrect3.y;
    SDL_RenderCopy(gRenderer, surf3a, NULL, &dstrect3);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf3b, NULL, &dstrect3);

    SDL_Rect dstrect4 = { 370, 270, 90, 30 };
    a=dstrect4.x;
    b=dstrect4.y;
    SDL_RenderCopy(gRenderer, surf4a, NULL, &dstrect4);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf4b, NULL, &dstrect4);

    SDL_Rect dstrect5 = { 180, 320, 90, 30 };
    a=dstrect5.x;
    b=dstrect5.y;
    SDL_RenderCopy(gRenderer, surf5a, NULL, &dstrect5);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf5b, NULL, &dstrect5);

    SDL_Rect dstrect6 = { 370, 320, 90, 30 };
    a=dstrect6.x;
    b=dstrect6.y;
    SDL_RenderCopy(gRenderer, surf6a, NULL, &dstrect6);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf6b, NULL, &dstrect6);

    SDL_Rect dstrect7 = { 180, 370, 90, 30 };
    a=dstrect7.x;
    b=dstrect7.y;
    SDL_RenderCopy(gRenderer, surf7a, NULL, &dstrect7);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf7b, NULL, &dstrect7);

    SDL_Rect dstrect8 = { 370, 370, 90, 30 };
    a=dstrect8.x;
    b=dstrect8.y;
    SDL_RenderCopy(gRenderer, surf8a, NULL, &dstrect8);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf8b, NULL, &dstrect8);


    SDL_Rect dstrect9 = { 180, 420, 90, 30 };
    a=dstrect9.x;
    b=dstrect9.y;
    SDL_RenderCopy(gRenderer, surf9a, NULL, &dstrect9);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf9b, NULL, &dstrect9);

    SDL_Rect dstrect10 = { 370, 420, 90, 30 };
    a=dstrect10.x;
    b=dstrect10.y;
    SDL_RenderCopy(gRenderer, surf10a, NULL, &dstrect10);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf10b, NULL, &dstrect10);

    SDL_Rect dstrect11 = { SCREEN_WIDTH/2-45, 470, 90, 30 };
    a=dstrect11.x;
    b=dstrect11.y;
    SDL_RenderCopy(gRenderer, surf11a, NULL, &dstrect11);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf11b, NULL, &dstrect11);


        quit_button(x,y,e);
}

void background()
{



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
        for(int col = 1; col <= 9; ++col)
        {
            SDL_RenderDrawPoint( gRenderer, col++, row );
        }
        for(int col = SCREEN_WIDTH-9; col <= SCREEN_WIDTH; ++col)
        {
            SDL_RenderDrawPoint( gRenderer, col++, row );
        }
    }
    for ( int col=1; col <= SCREEN_WIDTH; ++col)
    {
        for(int row = 1; row <= 9; ++row)
        {
            SDL_RenderDrawPoint( gRenderer, col, row++ );
        }

        for(int row = SCREEN_WIDTH-9; row <= SCREEN_WIDTH; ++row)
        {
            SDL_RenderDrawPoint( gRenderer, col, row++ );
        }

    }

    //Render current frame
    gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, SCREEN_HEIGHT / 6-28 );
    gTextTexture2.render( ( SCREEN_WIDTH - gTextTexture2.getWidth() ) / 2, SCREEN_HEIGHT -40 );
}

void quit_button(int x,int y,SDL_Event e)
{
    int a,b,c,d;
        SDL_Texture * surf12a = SDL_CreateTextureFromSurface(gRenderer, gMENU12a);
    SDL_Texture * surf12b = SDL_CreateTextureFromSurface(gRenderer, gMENU12b);
    SDL_Rect dstrect12_quit = { SCREEN_WIDTH/2-45, 520, 90, 30 };
    a=dstrect12_quit.x;
    b=dstrect12_quit.y;
    c=dstrect12_quit.w;
    d=dstrect12_quit.h;
    SDL_RenderCopy(gRenderer, surf12a, NULL, &dstrect12_quit);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf12b, NULL, &dstrect12_quit);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
        quit=true;
}
