#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <SDL_ttf.h>
#include <windows.h>
#include "Media.h"


void meniu()
{
    SDL_Texture * surf1a = SDL_CreateTextureFromSurface(gRenderer, gMENU1a);
    SDL_Texture * surf1b = SDL_CreateTextureFromSurface(gRenderer, gMENU1b);

    SDL_Rect dstrect1 = { SCREEN_WIDTH/2-45, 300, 90, 30 };
                    SDL_RenderCopy(gRenderer, surf1a, NULL, &dstrect1);
}
