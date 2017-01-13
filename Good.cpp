

//Using SDL, SDL_image, standard IO, math, and strings
#include <iostream>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <SDL_ttf.h>

#include <stdlib.h>
#include <cstdlib>
#include "render.h"
#include "Media.h"
#include "ok.h"
#include "siruri.h"
#include "transformari.h"
#include <conio.h>
#include <unistd.h>
#include <iomanip>
#define _WIN32_WINNT 0x0500
#include<windows.h>
int lung;
SDL_Texture* MENU1;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

SDL_Surface* gScreenSurface = NULL;
using namespace std;

#include "files+matrixes.h"



char textinput[256];
char textoutput[256];



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
void quit_button_back(int x,int y,SDL_Event e);
bool quit = false;
//Rendered texture

void butonas(char scris[256],int b,int c,int d,int e);
void butonas1(char scris[256],int b,int c,int d,int e);
void mini_butonas(char scris[256],int b,int c,int d,int e);
void maxi_butonas(char scris[256],int a,int b,int a1,int b1,int c,int d);
void maxi_butonas_dynamic(char scris[256],int a,int b,int c,int d);
int is_butonas_clicked(int b,int c,int d,int e,SDL_Event a);
int is_butonas1_clicked(int b,int c,int d,int e,SDL_Event a);
int is_mini_butonas_clicked(int b,int c,int d,int e,SDL_Event a);
int is_maxi_butonas_clicked(int a,int b,int a1,int b1,int c,int d,SDL_Event e);
void butonas_dynamic_afisare(char scris[256],int a,int b);
int is_dynamic_butonas_clicked(char scris [256],int a,int b,int c,int d,SDL_Event e);
void input(SDL_Event e,int x,int y);
void color_background(char scris[30],int b,int c);


int g1,g2;

void submeniu1(int x,int y,SDL_Event e)
{

    int j,i;
    citire_lungime(lungime);
    SDL_RenderCopy(gRenderer, surface_prisma, NULL, &dstrect_prisma);
    quit_button_back(x,y,e);

    if(submenu1_ok1_1)
        strcpy (a,"Select");
    butonas1(a,35,200,x,y);
    if(is_butonas1_clicked(35,200,x,y,e))
    {
        //SDL_RenderPresent( gRenderer );
        submenu1_ok1=0;
    }
    if(!submenu1_ok1_1 && strcmp("",textinput))
        maxi_butonas_dynamic(textinput,50,335,x,y);


    if(strcmp("",textoutput)!=0&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        trans_lungime(textinput,textoutput,g1,g2);
        textoutput[16]='\0';
        butonas_dynamic_afisare(textoutput,50,500);
    }


    if(!submenu1_ok1_1 && !strcmp("",textinput))
    {
        if(submenu1_ok2_1==0)
            maxi_butonas("",50,335,60,20,x,y);
    }
    if(!submenu1_ok1)
    {
        int submenu1_ok1_openleftdropmenu=1;
        for(i=1; i<=9; i++)
        {
            mini_butonas(lungime[i-1],55,213+i*17,x,y);
            if(is_mini_butonas_clicked(55,213+i*17,x,y,e))
            {
                submenu1_ok1=1;
                submenu1_ok1_1=0;
                strcpy (a,lungime[i-1]);
                submenu1_ok1_openleftdropmenu=0;
                g1=i-1;
                return;
            }
        }
    }
    if(submenu1_ok2_1)
        strcpy (b,"Select");
    butonas1(b,SCREEN_WIDTH-165,200,x,y);
    if(is_butonas1_clicked(SCREEN_WIDTH-165,200,x,y,e))
        submenu1_ok2=0;
    if(!submenu1_ok2)
    {
        for(j=1; j<=9; j++)
        {
            mini_butonas(lungime[j-1],SCREEN_WIDTH-145,213+j*17,x,y);
            if(is_mini_butonas_clicked(SCREEN_WIDTH-145,213+j*17,x,y,e))
            {
                submenu1_ok2=1;
                submenu1_ok2_1=0;
                strcpy (b,lungime[j-1]);
                g2=j-1;
            }
        }
    }
    if(strcmp(textinput,"")==0&&is_maxi_butonas_clicked(50,335,60,20,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_lungime(textinput,textoutput,g1,g2);
    }
    else if(is_dynamic_butonas_clicked(textinput,50,335,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_lungime(textinput,textoutput,g1,g2);
    }
    gMenuTexture1.render( ( SCREEN_WIDTH - gMenuTexture1.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
}
void submeniu2(int x,int y,SDL_Event e)
{
    int j,i;
    citire_arie(arie);
    SDL_RenderCopy(gRenderer, surface_prisma, NULL, &dstrect_prisma);
    quit_button_back(x,y,e);
    if(submenu1_ok1_1)
        strcpy (a,"Select");
    butonas1(a,35,200,x,y);
    if(is_butonas1_clicked(35,200,x,y,e))
    {
        //SDL_RenderPresent( gRenderer );
        submenu1_ok1=0;
    }
    if(!submenu1_ok1_1 && strcmp("",textinput))
        maxi_butonas_dynamic(textinput,50,335,x,y);


    if(strcmp("",textoutput)!=0&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        trans_arie(textinput,textoutput,g1,g2);
        textoutput[16]='\0';
        butonas_dynamic_afisare(textoutput,50,500);
    }


    if(!submenu1_ok1_1 && !strcmp("",textinput))
    {
        if(submenu1_ok2_1==0)
            maxi_butonas("",50,335,60,20,x,y);
    }
    if(!submenu1_ok1)
    {
        int submenu1_ok1_openleftdropmenu=1;
        for(i=1; i<=10; i++)
        {
            mini_butonas(arie[i-1],55,213+i*17,x,y);
            if(is_mini_butonas_clicked(55,213+i*17,x,y,e))
            {
                submenu1_ok1=1;
                submenu1_ok1_1=0;
                strcpy (a,arie[i-1]);
                submenu1_ok1_openleftdropmenu=0;
                g1=i-1;
                return;
            }
        }
    }
    if(submenu1_ok2_1)
        strcpy (b,"Select");
    butonas1(b,SCREEN_WIDTH-165,200,x,y);
    if(is_butonas1_clicked(SCREEN_WIDTH-165,200,x,y,e))
        submenu1_ok2=0;
    if(!submenu1_ok2)
    {
        for(j=1; j<=10; j++)
        {
            mini_butonas(arie[j-1],SCREEN_WIDTH-145,213+j*17,x,y);
            if(is_mini_butonas_clicked(SCREEN_WIDTH-145,213+j*17,x,y,e))
            {
                submenu1_ok2=1;
                submenu1_ok2_1=0;
                strcpy (b,arie[j-1]);
                g2=j-1;
            }
        }
    }
    if(strcmp(textinput,"")==0&&is_maxi_butonas_clicked(50,335,60,20,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_arie(textinput,textoutput,g1,g2);
    }
    else if(is_dynamic_butonas_clicked(textinput,50,335,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_arie(textinput,textoutput,g1,g2);
    }

    gMenuTexture2.render( ( SCREEN_WIDTH - gMenuTexture2.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
}
void submeniu3(int x,int y,SDL_Event e)
{
    int j,i;
    citire_volum(volum);
    SDL_RenderCopy(gRenderer, surface_prisma, NULL, &dstrect_prisma);
    quit_button_back(x,y,e);
    if(submenu1_ok1_1)
        strcpy (a,"Select");
    butonas1(a,35,200,x,y);
    if(is_butonas1_clicked(35,200,x,y,e))
    {
        //SDL_RenderPresent( gRenderer );
        submenu1_ok1=0;
    }
    if(!submenu1_ok1_1 && strcmp("",textinput))
        maxi_butonas_dynamic(textinput,50,335,x,y);


    if(strcmp("",textoutput)!=0&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        trans_volum(textinput,textoutput,g1,g2);
        textoutput[16]='\0';
        butonas_dynamic_afisare(textoutput,50,500);
    }


    if(!submenu1_ok1_1 && !strcmp("",textinput))
    {
        if(submenu1_ok2_1==0)
            maxi_butonas("",50,335,60,20,x,y);
    }
    if(!submenu1_ok1)
    {
        int submenu1_ok1_openleftdropmenu=1;
        for(i=1; i<=12; i++)
        {
            mini_butonas(volum[i-1],55,213+i*17,x,y);
            if(is_mini_butonas_clicked(55,213+i*17,x,y,e))
            {
                submenu1_ok1=1;
                submenu1_ok1_1=0;
                strcpy (a,volum[i-1]);
                submenu1_ok1_openleftdropmenu=0;
                g1=i-1;
                return;
            }
        }
    }
    if(submenu1_ok2_1)
        strcpy (b,"Select");
    butonas1(b,SCREEN_WIDTH-165,200,x,y);
    if(is_butonas1_clicked(SCREEN_WIDTH-165,200,x,y,e))
        submenu1_ok2=0;
    if(!submenu1_ok2)
    {
        for(j=1; j<=12; j++)
        {
            mini_butonas(volum[j-1],SCREEN_WIDTH-145,213+j*17,x,y);
            if(is_mini_butonas_clicked(SCREEN_WIDTH-145,213+j*17,x,y,e))
            {
                submenu1_ok2=1;
                submenu1_ok2_1=0;
                strcpy (b,volum[j-1]);
                g2=j-1;
            }
        }
    }
    if(strcmp(textinput,"")==0&&is_maxi_butonas_clicked(50,335,60,20,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_volum(textinput,textoutput,g1,g2);
    }
    else if(is_dynamic_butonas_clicked(textinput,50,335,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_volum(textinput,textoutput,g1,g2);
    }

    gMenuTexture3.render( ( SCREEN_WIDTH - gMenuTexture3.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
}
void submeniu4(int x,int y,SDL_Event e)
{
    int j,i;
    citire_timp(timp);
    SDL_RenderCopy(gRenderer, surface_prisma, NULL, &dstrect_prisma);
    quit_button_back(x,y,e);
    if(submenu1_ok1_1)
        strcpy (a,"Select");
    butonas1(a,35,200,x,y);
    if(is_butonas1_clicked(35,200,x,y,e))
    {
        //SDL_RenderPresent( gRenderer );
        submenu1_ok1=0;
    }
    if(!submenu1_ok1_1 && strcmp("",textinput))
        maxi_butonas_dynamic(textinput,50,335,x,y);


    if(strcmp("",textoutput)!=0&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        trans_timp(textinput,textoutput,g1,g2);
        textoutput[16]='\0';
        butonas_dynamic_afisare(textoutput,50,500);
    }


    if(!submenu1_ok1_1 && !strcmp("",textinput))
    {
        if(submenu1_ok2_1==0)
            maxi_butonas("",50,335,60,20,x,y);
    }
    if(!submenu1_ok1)
    {
        int submenu1_ok1_openleftdropmenu=1;
        for(i=1; i<=6; i++)
        {
            mini_butonas(timp[i-1],55,213+i*17,x,y);
            if(is_mini_butonas_clicked(55,213+i*17,x,y,e))
            {
                submenu1_ok1=1;
                submenu1_ok1_1=0;
                strcpy (a,timp[i-1]);
                submenu1_ok1_openleftdropmenu=0;
                g1=i-1;
                return;
            }
        }
    }
    if(submenu1_ok2_1)
        strcpy (b,"Select");
    butonas1(b,SCREEN_WIDTH-165,200,x,y);
    if(is_butonas1_clicked(SCREEN_WIDTH-165,200,x,y,e))
        submenu1_ok2=0;
    if(!submenu1_ok2)
    {
        for(j=1; j<=6; j++)
        {
            mini_butonas(timp[j-1],SCREEN_WIDTH-145,213+j*17,x,y);
            if(is_mini_butonas_clicked(SCREEN_WIDTH-145,213+j*17,x,y,e))
            {
                submenu1_ok2=1;
                submenu1_ok2_1=0;
                strcpy (b,timp[j-1]);
                g2=j-1;
            }
        }
    }
    if(strcmp(textinput,"")==0&&is_maxi_butonas_clicked(50,335,60,20,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_timp(textinput,textoutput,g1,g2);
    }
    else if(is_dynamic_butonas_clicked(textinput,50,335,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_timp(textinput,textoutput,g1,g2);
    }
    gMenuTexture4.render( ( SCREEN_WIDTH - gMenuTexture4.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
}
void submeniu5(int x,int y,SDL_Event e)
{
    int j,i;
    citire_viteza(viteza);
    SDL_RenderCopy(gRenderer, surface_prisma, NULL, &dstrect_prisma);
    quit_button_back(x,y,e);
    if(submenu1_ok1_1)
        strcpy (a,"Select");
    butonas1(a,35,200,x,y);
    if(is_butonas1_clicked(35,200,x,y,e))
    {
        //SDL_RenderPresent( gRenderer );
        submenu1_ok1=0;
    }
    if(!submenu1_ok1_1 && strcmp("",textinput))
        maxi_butonas_dynamic(textinput,50,335,x,y);


    if(strcmp("",textoutput)!=0&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        trans_viteza(textinput,textoutput,g1,g2);
        textoutput[16]='\0';
        butonas_dynamic_afisare(textoutput,50,500);
    }


    if(!submenu1_ok1_1 && !strcmp("",textinput))
    {
        if(submenu1_ok2_1==0)
            maxi_butonas("",50,335,60,20,x,y);
    }
    if(!submenu1_ok1)
    {
        int submenu1_ok1_openleftdropmenu=1;
        for(i=1; i<=19; i++)
        {
            mini_butonas(viteza[i-1],55,213+i*17,x,y);
            if(is_mini_butonas_clicked(55,213+i*17,x,y,e))
            {
                submenu1_ok1=1;
                submenu1_ok1_1=0;
                strcpy (a,viteza[i-1]);
                submenu1_ok1_openleftdropmenu=0;
                g1=i-1;
                return;
            }
        }
    }
    if(submenu1_ok2_1)
        strcpy (b,"Select");
    butonas1(b,SCREEN_WIDTH-165,200,x,y);
    if(is_butonas1_clicked(SCREEN_WIDTH-165,200,x,y,e))
        submenu1_ok2=0;
    if(!submenu1_ok2)
    {
        for(j=1; j<=19; j++)
        {
            mini_butonas(viteza[j-1],SCREEN_WIDTH-145,213+j*17,x,y);
            if(is_mini_butonas_clicked(SCREEN_WIDTH-145,213+j*17,x,y,e))
            {
                submenu1_ok2=1;
                submenu1_ok2_1=0;
                strcpy (b,viteza[j-1]);
                g2=j-1;
            }
        }
    }
    if(strcmp(textinput,"")==0&&is_maxi_butonas_clicked(50,335,60,20,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_viteza(textinput,textoutput,g1,g2);
    }
    else if(is_dynamic_butonas_clicked(textinput,50,335,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_viteza(textinput,textoutput,g1,g2);
    }
    gMenuTexture5.render( ( SCREEN_WIDTH - gMenuTexture5.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
}
void submeniu6(int x,int y,SDL_Event e)
{
    int j,i;
    citire_temperatura(temperatura);
    SDL_RenderCopy(gRenderer, surface_prisma, NULL, &dstrect_prisma);
    quit_button_back(x,y,e);
    if(submenu1_ok1_1)
        strcpy (a,"Select");
    butonas1(a,35,200,x,y);
    if(is_butonas1_clicked(35,200,x,y,e))
    {
        //SDL_RenderPresent( gRenderer );
        submenu1_ok1=0;
    }
    if(!submenu1_ok1_1 && strcmp("",textinput))
        maxi_butonas_dynamic(textinput,50,335,x,y);


    if(strcmp("",textoutput)!=0&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        trans_temperatura(textinput,textoutput,g1,g2);
        textoutput[16]='\0';
        butonas_dynamic_afisare(textoutput,50,500);
    }


    if(!submenu1_ok1_1 && !strcmp("",textinput))
    {
        if(submenu1_ok2_1==0)
            maxi_butonas("",50,335,60,20,x,y);
    }
    if(!submenu1_ok1)
    {
        int submenu1_ok1_openleftdropmenu=1;
        for(i=1; i<=4; i++)
        {
            mini_butonas(temperatura[i-1],55,213+i*17,x,y);
            if(is_mini_butonas_clicked(55,213+i*17,x,y,e))
            {
                submenu1_ok1=1;
                submenu1_ok1_1=0;
                strcpy (a,temperatura[i-1]);
                submenu1_ok1_openleftdropmenu=0;
                g1=i-1;
                return;
            }
        }
    }
    if(submenu1_ok2_1)
        strcpy (b,"Select");
    butonas1(b,SCREEN_WIDTH-165,200,x,y);
    if(is_butonas1_clicked(SCREEN_WIDTH-165,200,x,y,e))
        submenu1_ok2=0;
    if(!submenu1_ok2)
    {
        for(j=1; j<=4; j++)
        {
            mini_butonas(temperatura[j-1],SCREEN_WIDTH-145,213+j*17,x,y);
            if(is_mini_butonas_clicked(SCREEN_WIDTH-145,213+j*17,x,y,e))
            {
                submenu1_ok2=1;
                submenu1_ok2_1=0;
                strcpy (b,temperatura[j-1]);
                g2=j-1;
            }
        }
    }
    if(strcmp(textinput,"")==0&&is_maxi_butonas_clicked(50,335,60,20,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_temperatura(textinput,textoutput,g1,g2);
    }
    else if(is_dynamic_butonas_clicked(textinput,50,335,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_temperatura(textinput,textoutput,g1,g2);
    }
    gMenuTexture6.render( ( SCREEN_WIDTH - gMenuTexture6.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
}
void submeniu7(int x,int y,SDL_Event e)
{
    int j,i;
    citire_masa(masa);
    SDL_RenderCopy(gRenderer, surface_prisma, NULL, &dstrect_prisma);
    quit_button_back(x,y,e);
    if(submenu1_ok1_1)
        strcpy (a,"Select");
    butonas1(a,35,200,x,y);
    if(is_butonas1_clicked(35,200,x,y,e))
    {
        //SDL_RenderPresent( gRenderer );
        submenu1_ok1=0;
    }
    if(!submenu1_ok1_1 && strcmp("",textinput))
        maxi_butonas_dynamic(textinput,50,335,x,y);


    if(strcmp("",textoutput)!=0&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        trans_masa(textinput,textoutput,g1,g2);
        textoutput[16]='\0';
        butonas_dynamic_afisare(textoutput,50,500);
    }


    if(!submenu1_ok1_1 && !strcmp("",textinput))
    {
        if(submenu1_ok2_1==0)
            maxi_butonas("",50,335,60,20,x,y);
    }
    if(!submenu1_ok1)
    {
        int submenu1_ok1_openleftdropmenu=1;
        for(i=1; i<=8; i++)
        {
            mini_butonas(masa[i-1],55,213+i*17,x,y);
            if(is_mini_butonas_clicked(55,213+i*17,x,y,e))
            {
                submenu1_ok1=1;
                submenu1_ok1_1=0;
                strcpy (a,masa[i-1]);
                submenu1_ok1_openleftdropmenu=0;
                g1=i-1;
                return;
            }
        }
    }
    if(submenu1_ok2_1)
        strcpy (b,"Select");
    butonas1(b,SCREEN_WIDTH-165,200,x,y);
    if(is_butonas1_clicked(SCREEN_WIDTH-165,200,x,y,e))
        submenu1_ok2=0;
    if(!submenu1_ok2)
    {
        for(j=1; j<=8; j++)
        {
            mini_butonas(masa[j-1],SCREEN_WIDTH-145,213+j*17,x,y);
            if(is_mini_butonas_clicked(SCREEN_WIDTH-145,213+j*17,x,y,e))
            {
                submenu1_ok2=1;
                submenu1_ok2_1=0;
                strcpy (b,masa[j-1]);
                g2=j-1;
            }
        }
    }
    if(strcmp(textinput,"")==0&&is_maxi_butonas_clicked(50,335,60,20,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_masa(textinput,textoutput,g1,g2);
    }
    else if(is_dynamic_butonas_clicked(textinput,50,335,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_masa(textinput,textoutput,g1,g2);
    }
    gMenuTexture7.render( ( SCREEN_WIDTH - gMenuTexture7.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
}
void submeniu8(int x,int y,SDL_Event e)
{
    int j,i;
    citire_energie(energie);
    SDL_RenderCopy(gRenderer, surface_prisma, NULL, &dstrect_prisma);
    quit_button_back(x,y,e);
    if(submenu1_ok1_1)
        strcpy (a,"Select");
    butonas1(a,35,200,x,y);
    if(is_butonas1_clicked(35,200,x,y,e))
    {
        //SDL_RenderPresent( gRenderer );
        submenu1_ok1=0;
    }
    if(!submenu1_ok1_1 && strcmp("",textinput))
        maxi_butonas_dynamic(textinput,50,335,x,y);


    if(strcmp("",textoutput)!=0&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        trans_energie(textinput,textoutput,g1,g2);
        textoutput[16]='\0';
        butonas_dynamic_afisare(textoutput,50,500);
    }


    if(!submenu1_ok1_1 && !strcmp("",textinput))
    {
        if(submenu1_ok2_1==0)
            maxi_butonas("",50,335,60,20,x,y);
    }
    if(!submenu1_ok1)
    {
        int submenu1_ok1_openleftdropmenu=1;
        for(i=1; i<=7; i++)
        {
            mini_butonas(energie[i-1],55,213+i*17,x,y);
            if(is_mini_butonas_clicked(55,213+i*17,x,y,e))
            {
                submenu1_ok1=1;
                submenu1_ok1_1=0;
                strcpy (a,energie[i-1]);
                submenu1_ok1_openleftdropmenu=0;
                g1=i-1;
                return;
            }
        }
    }
    if(submenu1_ok2_1)
        strcpy (b,"Select");
    butonas1(b,SCREEN_WIDTH-165,200,x,y);
    if(is_butonas1_clicked(SCREEN_WIDTH-165,200,x,y,e))
        submenu1_ok2=0;
    if(!submenu1_ok2)
    {
        for(j=1; j<=8; j++)
        {
            mini_butonas(energie[j-1],SCREEN_WIDTH-145,213+j*17,x,y);
            if(is_mini_butonas_clicked(SCREEN_WIDTH-145,213+j*17,x,y,e))
            {
                submenu1_ok2=1;
                submenu1_ok2_1=0;
                strcpy (b,energie[j-1]);
                g2=j-1;
            }
        }
    }
    if(strcmp(textinput,"")==0&&is_maxi_butonas_clicked(50,335,60,20,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_energie(textinput,textoutput,g1,g2);
    }
    else if(is_dynamic_butonas_clicked(textinput,50,335,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_energie(textinput,textoutput,g1,g2);
    }
    gMenuTexture8.render( ( SCREEN_WIDTH - gMenuTexture8.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
}
void submeniu9(int x,int y,SDL_Event e)
{
    int j,i;
    citire_presiune(presiune);
    SDL_RenderCopy(gRenderer, surface_prisma, NULL, &dstrect_prisma);
    quit_button_back(x,y,e);
    if(submenu1_ok1_1)
        strcpy (a,"Select");
    butonas1(a,35,200,x,y);
    if(is_butonas1_clicked(35,200,x,y,e))
    {
        //SDL_RenderPresent( gRenderer );
        submenu1_ok1=0;
    }
    if(!submenu1_ok1_1 && strcmp("",textinput))
        maxi_butonas_dynamic(textinput,50,335,x,y);



    if(strcmp("",textoutput)!=0&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        trans_presiune(textinput,textoutput,g1,g2);
        textoutput[16]='\0';
        butonas_dynamic_afisare(textoutput,50,500);
    }


    if(!submenu1_ok1_1 && !strcmp("",textinput))
    {
        if(submenu1_ok2_1==0)
            maxi_butonas("",50,335,60,20,x,y);
    }
    if(!submenu1_ok1)
    {
        int submenu1_ok1_openleftdropmenu=1;
        for(i=1; i<=18; i++)
        {
            mini_butonas(presiune[i-1],55,213+i*17,x,y);
            if(is_mini_butonas_clicked(55,213+i*17,x,y,e))
            {
                submenu1_ok1=1;
                submenu1_ok1_1=0;
                strcpy (a,presiune[i-1]);
                submenu1_ok1_openleftdropmenu=0;
                g1=i-1;
                return;
            }
        }
    }
    if(submenu1_ok2_1)
        strcpy (b,"Select");
    butonas1(b,SCREEN_WIDTH-165,200,x,y);
    if(is_butonas1_clicked(SCREEN_WIDTH-165,200,x,y,e))
        submenu1_ok2=0;
    if(!submenu1_ok2)
    {
        for(j=1; j<=18; j++)
        {
            mini_butonas(presiune[j-1],SCREEN_WIDTH-145,213+j*17,x,y);
            if(is_mini_butonas_clicked(SCREEN_WIDTH-145,213+j*17,x,y,e))
            {
                submenu1_ok2=1;
                submenu1_ok2_1=0;
                strcpy (b,presiune[j-1]);
                g2=j-1;
            }
        }
    }
    if(strcmp(textinput,"")==0&&is_maxi_butonas_clicked(50,335,60,20,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_presiune(textinput,textoutput,g1,g2);
    }
    else if(is_dynamic_butonas_clicked(textinput,50,335,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_presiune(textinput,textoutput,g1,g2);
    }
    gMenuTexture9.render( ( SCREEN_WIDTH - gMenuTexture9.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
}
void submeniu10(int x,int y,SDL_Event e)
{
    int j,i;
    citire_densitate(densitate);
    SDL_RenderCopy(gRenderer, surface_prisma, NULL, &dstrect_prisma);
    quit_button_back(x,y,e);
    if(submenu1_ok1_1)
        strcpy (a,"Select");
    butonas1(a,35,200,x,y);
    if(is_butonas1_clicked(35,200,x,y,e))
    {
        //SDL_RenderPresent( gRenderer );
        submenu1_ok1=0;
    }
    if(!submenu1_ok1_1 && strcmp("",textinput))
        maxi_butonas_dynamic(textinput,50,335,x,y);


    if(strcmp("",textoutput)!=0&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        trans_densitate(textinput,textoutput,g1,g2);
        textoutput[16]='\0';
        butonas_dynamic_afisare(textoutput,50,500);
    }


    if(!submenu1_ok1_1 && !strcmp("",textinput))
    {
        if(submenu1_ok2_1==0)
            maxi_butonas("",50,335,60,20,x,y);
    }
    if(!submenu1_ok1)
    {
        int submenu1_ok1_openleftdropmenu=1;
        for(i=1; i<=20; i++)
        {
            mini_butonas(densitate[i-1],55,213+i*17,x,y);
            if(is_mini_butonas_clicked(55,213+i*17,x,y,e))
            {
                submenu1_ok1=1;
                submenu1_ok1_1=0;
                strcpy (a,densitate[i-1]);
                submenu1_ok1_openleftdropmenu=0;
                g1=i-1;
                return;
            }
        }
    }
    if(submenu1_ok2_1)
        strcpy (b,"Select");
    butonas1(b,SCREEN_WIDTH-165,200,x,y);
    if(is_butonas1_clicked(SCREEN_WIDTH-165,200,x,y,e))
        submenu1_ok2=0;
    if(!submenu1_ok2)
    {
        for(j=1; j<=20; j++)
        {
            mini_butonas(densitate[j-1],SCREEN_WIDTH-145,213+j*17,x,y);
            if(is_mini_butonas_clicked(SCREEN_WIDTH-145,213+j*17,x,y,e))
            {
                submenu1_ok2=1;
                submenu1_ok2_1=0;
                strcpy (b,densitate[j-1]);
                g2=j-1;
            }
        }
    }
    if(strcmp(textinput,"")==0&&is_maxi_butonas_clicked(50,335,60,20,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_densitate(textinput,textoutput,g1,g2);
    }
    else if(is_dynamic_butonas_clicked(textinput,50,335,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_densitate(textinput,textoutput,g1,g2);
    }


    gMenuTexture10.render( ( SCREEN_WIDTH - gMenuTexture10.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
}
void submeniu11(int x,int y,SDL_Event e)
{
    int j,i;
    citire_consum(consum);
    SDL_RenderCopy(gRenderer, surface_prisma, NULL, &dstrect_prisma);
    quit_button_back(x,y,e);
    if(submenu1_ok1_1)
        strcpy (a,"Select");
    butonas1(a,35,200,x,y);
    if(is_butonas1_clicked(35,200,x,y,e))
    {
        //SDL_RenderPresent( gRenderer );
        submenu1_ok1=0;
    }
    if(!submenu1_ok1_1 && strcmp("",textinput))
    {
        maxi_butonas_dynamic(textinput,50,335,x,y);

    }


    if(strcmp("",textoutput)!=0&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        trans_consum(textinput,textoutput,g1,g2);
        textoutput[16]='\0';
        butonas_dynamic_afisare(textoutput,50,500);
    }


    if(!submenu1_ok1_1 && !strcmp("",textinput))
    {
        if(submenu1_ok2_1==0)
            maxi_butonas("",50,335,60,20,x,y);
    }

    if(!submenu1_ok1)
    {
        int submenu1_ok1_openleftdropmenu=1;
        for(i=1; i<=6; i++)
        {
            mini_butonas(consum[i-1],55,213+i*17,x,y);
            if(is_mini_butonas_clicked(55,213+i*17,x,y,e))
            {
                submenu1_ok1=1;
                submenu1_ok1_1=0;
                strcpy (a,consum[i-1]);
                submenu1_ok1_openleftdropmenu=0;
                g1=i-1;
                return;
            }
        }
    }
    if(submenu1_ok2_1)
        strcpy (b,"Select");
    butonas1(b,SCREEN_WIDTH-165,200,x,y);
    if(is_butonas1_clicked(SCREEN_WIDTH-165,200,x,y,e))
        submenu1_ok2=0;
    if(!submenu1_ok2)
    {
        for(j=1; j<=6; j++)
        {
            mini_butonas(consum[j-1],SCREEN_WIDTH-145,213+j*17,x,y);
            if(is_mini_butonas_clicked(SCREEN_WIDTH-145,213+j*17,x,y,e))
            {
                submenu1_ok2=1;
                submenu1_ok2_1=0;
                strcpy (b,consum[j-1]);
                g2=j-1;
            }
        }
    }
    if(strcmp(textinput,"")==0&&is_maxi_butonas_clicked(50,335,60,20,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_consum(textinput,textoutput,g1,g2);
    }
    else if(is_dynamic_butonas_clicked(textinput,50,335,x,y,e)&&!submenu1_ok1_openleftdropmenu&&submenu1_ok2_1==0)
    {
        input(e,50,335);
        trans_consum(textinput,textoutput,g1,g2);
    }
    gMenuTexture11.render( ( SCREEN_WIDTH - gMenuTexture11.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
}






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

                SDL_Surface *surface;     // Declare an SDL_Surface to be filled in with pixel data from an image file
                surface = SDL_LoadBMP( "Media/icon.bmp" );

                // The icon is attached to the window pointer
                SDL_SetWindowIcon(gWindow, surface);
                SDL_FreeSurface(surface);

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
                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
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
    //Free the music
    Mix_FreeMusic( gMusic1 );
    gMusic1 = NULL;
    Mix_FreeMusic( gMusic2 );
    gMusic2 = NULL;
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
    ShowWindow( GetConsoleWindow(), SW_HIDE );
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

            //Set text color as black
            SDL_Color textColor = { 0, 0, 0, 0xFF };

            //The current input text.
            std::string inputText = "Some Text";


            gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor,gFont );

            //Enable text input
            SDL_StartTextInput();


            //While application is running
            while( !quit )
            {
                //The rerender text flag
                bool renderText = false;
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

                    if(ok_menu)
                        meniu(x,y,e);
                    if(ok_submenu1)
                        submeniu1(x,y,e);
                    if(ok_submenu2)
                        submeniu2(x,y,e);
                    if(ok_submenu3)
                        submeniu3(x,y,e);
                    if(ok_submenu4)
                        submeniu4(x,y,e);
                    if(ok_submenu5)
                        submeniu5(x,y,e);
                    if(ok_submenu6)
                        submeniu6(x,y,e);
                    if(ok_submenu7)
                        submeniu7(x,y,e);
                    if(ok_submenu8)
                        submeniu8(x,y,e);
                    if(ok_submenu9)
                        submeniu9(x,y,e);
                    if(ok_submenu10)
                        submeniu10(x,y,e);
                    if(ok_submenu11)
                        submeniu11(x,y,e);

                    background();
                    if( e.type == SDL_KEYDOWN )
                    {
                        switch( e.key.keysym.sym )
                        {
                        case SDLK_1:
                            //If there is no music playing
                            if( Mix_PlayingMusic() == 0 )
                            {
                                //Play the music
                                Mix_PlayMusic( gMusic1, -1 );
                            }
                            //If music is being played
                            else
                            {
                                //If the music is paused
                                if( Mix_PausedMusic() == 1 )
                                {
                                    //Resume the music
                                    Mix_ResumeMusic();
                                }
                                //If the music is playing
                                else
                                {
                                    //Pause the music
                                    Mix_PauseMusic();
                                }
                            }
                            break;
                        case SDLK_2:
                            //If there is no music playing
                            if( Mix_PlayingMusic() == 0 )
                            {
                                //Play the music
                                Mix_PlayMusic( gMusic2, -1 );
                            }
                            //If music is being played
                            else
                            {
                                //If the music is paused
                                if( Mix_PausedMusic() == 1 )
                                {
                                    //Resume the music
                                    Mix_ResumeMusic();
                                }
                                //If the music is playing
                                else
                                {
                                    //Pause the music
                                    Mix_PauseMusic();
                                }
                            }
                            break;

                        case SDLK_3:
                            //Stop the music
                            Mix_HaltMusic();
                            break;
                        case SDLK_4:
                            //close console
                             ShowWindow( GetConsoleWindow(), SW_HIDE );
                            break;
                        case SDLK_5:
                            //Show the console
                             ShowWindow( GetConsoleWindow(), SW_RESTORE );
                            break;
                        }
                    }


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

                    //Update screen
                    SDL_RenderPresent( gRenderer );
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
void color_background(char scris[256],int b,int c)
{
    SDL_Texture * surface_gig = SDL_CreateTextureFromSurface(gRenderer, background_color);
    SDL_Rect dstrect_buttonas = { 0, 0, 290, 50 };
    dstrect_buttonas.x=b;
    dstrect_buttonas.y=c;

    SDL_RenderCopy(gRenderer, surface_gig, NULL, &dstrect_buttonas);


}
int is_butonas_clicked(int b,int c,int d,int e,SDL_Event a)
{
    if((d>= b)&&(e>=c)&&(d<=b+90)&&(e<=c+30)&&a.type==SDL_MOUSEBUTTONDOWN)
        return 1;
    return 0;
}
int is_butonas1_clicked(int b,int c,int d,int e,SDL_Event a)
{
    if((d>= b)&&(e>=c)&&(d<=b+130)&&(e<=c+30)&&a.type==SDL_MOUSEBUTTONDOWN)
        return 1;
    return 0;
}
int is_mini_butonas_clicked(int b,int c,int d,int e,SDL_Event a)
{
    if((d>= b)&&(e>=c)&&(d<=b+90)&&(e<=c+17)&&a.type==SDL_MOUSEBUTTONDOWN)
        return 1;
    return 0;
}
int is_maxi_butonas_clicked(int a,int b,int a1,int b1,int c,int d,SDL_Event e)
{
    if((c>= a)&&(d>=b)&&(c<=a+a1)&&(d<=b+b1)&&e.type==SDL_MOUSEBUTTONDOWN)
        return 1;
    return 0;
}

int is_dynamic_butonas_clicked(char scris[256],int a,int b,int c,int d,SDL_Event e)
{
    SDL_Color textColor_red = { 255, 0, 0 };
    gTextTexture4.loadFromRenderedText( scris, textColor_red,gFont4 );
    if((c>= a)&&(d>=b)&&(c<=a+gTextTexture4.getWidth()+20)&&(d<=b+gTextTexture4.getHeight()+20)&&e.type==SDL_MOUSEBUTTONDOWN)
        return 1;
    return 0;
}
void butonas(char scris[256],int b,int c,int d,int e)
{
    int a=0;
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
void butonas1(char scris[256],int b,int c,int d,int e)
{
    int a=0;
    SDL_Color textColor_blue = { 0, 0, 255 };
    SDL_Color textColor_red = { 255, 0, 0 };
    SDL_Texture * surface_gig = SDL_CreateTextureFromSurface(gRenderer, button1);
    SDL_Rect dstrect_buttonas = { 0, 0, 130, 30 };
    dstrect_buttonas.x=b;
    dstrect_buttonas.y=c;

    SDL_RenderCopy(gRenderer, surface_gig, NULL, &dstrect_buttonas);
    if((d>= b)&&(e>=c)&&(d<=b+130)&&(e<=c+30))
        a=1;
    if(a==0)
        gTextTexture3.loadFromRenderedText( scris, textColor_blue,gFont3 );
    else
        gTextTexture3.loadFromRenderedText( scris, textColor_red,gFont3 );
    gTextTexture3.render( (130- gTextTexture3.getWidth() ) / 2+b, (30- gTextTexture3.getHeight() ) / 2 +c);

}
void mini_butonas(char scris[256],int b,int c,int d,int e)
{
    int a=0;
    SDL_Color textColor_blue = { 0, 0, 255 };
    SDL_Color textColor_red = { 255, 0, 0 };
    SDL_Texture * surface_gig = SDL_CreateTextureFromSurface(gRenderer, mini_button);
    SDL_Rect dstrect_buttonas = { 0, 0, 90, 17 };
    dstrect_buttonas.x=b;
    dstrect_buttonas.y=c;

    SDL_RenderCopy(gRenderer, surface_gig, NULL, &dstrect_buttonas);
    if((d>= b)&&(e>=c)&&(d<=b+90)&&(e<=c+17))
        a=1;
    if(a==0)
        gTextTexture4.loadFromRenderedText( scris, textColor_blue,gFont4 );
    else
        gTextTexture4.loadFromRenderedText( scris, textColor_red,gFont4 );
    gTextTexture4.render( (90- gTextTexture4.getWidth() ) / 2+b, (17- gTextTexture4.getHeight() ) / 2 +c);

}

void maxi_butonas(char scris[256],int a,int b,int a1,int b1,int c,int d)
{
    int bines=0;
    SDL_Color textColor_blue = { 0, 0, 255 };
    SDL_Color textColor_red = { 255, 0, 0 };
    SDL_Texture * surface_gig = SDL_CreateTextureFromSurface(gRenderer, mini_button);
    SDL_Rect dstrect_buttonas = { 0, 0, 0, 0 };
    dstrect_buttonas.x=a;
    dstrect_buttonas.y=b;
    dstrect_buttonas.w=a1;
    dstrect_buttonas.h=b1;

    SDL_RenderCopy(gRenderer, surface_gig, NULL, &dstrect_buttonas);
    if((c>= a)&&(d>=b)&&(c<=a+a1)&&(d<=b+b1))
        bines=1;
    if(bines==0)
        gTextTexture4.loadFromRenderedText( scris, textColor_blue,gFont4 );
    else
        gTextTexture4.loadFromRenderedText( scris, textColor_red,gFont4 );
    gTextTexture4.render( (a1- gTextTexture4.getWidth() ) / 2+a, (b1- gTextTexture4.getHeight() ) / 2 +b);

}
void maxi_butonas_dynamic(char scris[256],int a,int b,int c,int d)
{
    int bines=0;
    SDL_Color textColor_blue = { 0, 0, 255 };
    SDL_Color textColor_red = { 255, 0, 0 };
    gTextTexture4.loadFromRenderedText( scris, textColor_red,gFont4 );
    if((c>= a)&&(d>=b)&&(c<=a+gTextTexture4.getWidth()+20)&&(d<=b+gTextTexture4.getHeight()+20))
        bines=1;
    if(bines==0)
        gTextTexture4.loadFromRenderedText( scris, textColor_blue,gFont4 );
    else
        gTextTexture4.loadFromRenderedText( scris, textColor_red,gFont4 );
    SDL_Texture * surface_gig = SDL_CreateTextureFromSurface(gRenderer, mini_button);
    SDL_Rect dstrect_buttonas = { 0, 0, 0, 0 };
    dstrect_buttonas.x=a;
    dstrect_buttonas.y=b;
    dstrect_buttonas.w=gTextTexture4.getWidth()+20;
    dstrect_buttonas.h=gTextTexture4.getHeight()+20;

    SDL_RenderCopy(gRenderer, surface_gig, NULL, &dstrect_buttonas);

    //gTextTexture4.render( (a1- gTextTexture4.getWidth() ) / 2+a, (b1- gTextTexture4.getHeight() ) / 2 +b);
    gTextTexture4.render( a+10,b+10);
}
void butonas_dynamic_afisare(char scris[256],int a,int b)
{
    int bines=0;
    SDL_Color textColor_blue = { 0, 0, 255 };
    SDL_Color textColor_red = { 255, 0, 0 };
    gTextTexture4.loadFromRenderedText( scris, textColor_blue,gFont4 );
    SDL_Texture * surface_gig2 = SDL_CreateTextureFromSurface(gRenderer, button);
    SDL_Rect dstrect_buttonas = { 0, 0, 0, 0 };
    dstrect_buttonas.x=a;
    dstrect_buttonas.y=b;
    dstrect_buttonas.w=gTextTexture4.getWidth()+20;
    dstrect_buttonas.h=gTextTexture4.getHeight()+20;

    SDL_RenderCopy(gRenderer, surface_gig2, NULL, &dstrect_buttonas);

    gTextTexture4.render( a+10,b+10);
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

    SDL_Rect dstrect1 = { SCREEN_WIDTH/2-135, 220, 90, 30 };
    a=dstrect1.x;
    b=dstrect1.y;
    c=dstrect1.w;
    d=dstrect1.h;
    SDL_RenderCopy(gRenderer, surf1a, NULL, &dstrect1);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf1b, NULL, &dstrect1);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
    {
        ok_menu=0;
        ok_submenu1=1;
    }

    SDL_Rect dstrect2 = { SCREEN_WIDTH/2+45, 220, 90, 30 };
    a=dstrect2.x;
    b=dstrect2.y;
    SDL_RenderCopy(gRenderer, surf2a, NULL, &dstrect2);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf2b, NULL, &dstrect2);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
    {
        ok_menu=0;
        ok_submenu2=1;
    }
    SDL_Rect dstrect3 = { SCREEN_WIDTH/2-135, 270, 90, 30 };
    a=dstrect3.x;
    b=dstrect3.y;
    SDL_RenderCopy(gRenderer, surf3a, NULL, &dstrect3);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf3b, NULL, &dstrect3);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
    {
        ok_menu=0;
        ok_submenu3=1;
    }
    SDL_Rect dstrect4 = { SCREEN_WIDTH/2+45, 270, 90, 30 };
    a=dstrect4.x;
    b=dstrect4.y;
    SDL_RenderCopy(gRenderer, surf4a, NULL, &dstrect4);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf4b, NULL, &dstrect4);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
    {
        ok_menu=0;
        ok_submenu4=1;
    }
    SDL_Rect dstrect5 = { SCREEN_WIDTH/2-135, 320, 90, 30 };
    a=dstrect5.x;
    b=dstrect5.y;
    SDL_RenderCopy(gRenderer, surf5a, NULL, &dstrect5);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf5b, NULL, &dstrect5);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
    {
        ok_menu=0;
        ok_submenu5=1;
    }
    SDL_Rect dstrect6 = { SCREEN_WIDTH/2+45, 320, 90, 30 };
    a=dstrect6.x;
    b=dstrect6.y;
    SDL_RenderCopy(gRenderer, surf6a, NULL, &dstrect6);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf6b, NULL, &dstrect6);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
    {
        ok_menu=0;
        ok_submenu6=1;
    }
    SDL_Rect dstrect7 = { SCREEN_WIDTH/2-135, 370, 90, 30 };
    a=dstrect7.x;
    b=dstrect7.y;
    SDL_RenderCopy(gRenderer, surf7a, NULL, &dstrect7);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf7b, NULL, &dstrect7);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
    {
        ok_menu=0;
        ok_submenu7=1;
    }
    SDL_Rect dstrect8 = { SCREEN_WIDTH/2+45, 370, 90, 30 };
    a=dstrect8.x;
    b=dstrect8.y;
    SDL_RenderCopy(gRenderer, surf8a, NULL, &dstrect8);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf8b, NULL, &dstrect8);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
    {
        ok_menu=0;
        ok_submenu8=1;
    }

    SDL_Rect dstrect9 = { SCREEN_WIDTH/2-135, 420, 90, 30 };
    a=dstrect9.x;
    b=dstrect9.y;
    SDL_RenderCopy(gRenderer, surf9a, NULL, &dstrect9);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf9b, NULL, &dstrect9);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
    {
        ok_menu=0;
        ok_submenu9=1;
    }
    SDL_Rect dstrect10 = { SCREEN_WIDTH/2+45, 420, 90, 30 };
    a=dstrect10.x;
    b=dstrect10.y;
    SDL_RenderCopy(gRenderer, surf10a, NULL, &dstrect10);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf10b, NULL, &dstrect10);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
    {
        ok_menu=0;
        ok_submenu10=1;
    }
    SDL_Rect dstrect11 = { SCREEN_WIDTH/2-45, 470, 90, 30 };
    a=dstrect11.x;
    b=dstrect11.y;
    SDL_RenderCopy(gRenderer, surf11a, NULL, &dstrect11);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d))
        SDL_RenderCopy(gRenderer, surf11b, NULL, &dstrect11);
    if((x>= a)&&(y>=b)&&(x<=a+c)&&(y<=b+d)&&e.type==SDL_MOUSEBUTTONDOWN)
    {
        ok_menu=0;
        ok_submenu11=1;
    }
    gTextTexture5.render( ( SCREEN_WIDTH - gTextTexture5.getWidth() ) / 2, SCREEN_HEIGHT / 6+35 );
    quit_button(x,y,e);
}

void background()
{



    SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );
    //SDL_RenderDrawRect( gRenderer, &outlineRect );
    /*
        //Draw blue horizontal line
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
        SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );
    */
    //Draw vertical line of yellow dots
    /*
        SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF );
        SDL_RenderDrawLine( gRenderer, SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT  );
    */

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
    gTextTexture.render( ( SCREEN_WIDTH - gTextTexture.getWidth() ) / 2, SCREEN_HEIGHT / 6-70 );
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
    {
        quit=true;
        close();
    }
}
std::string inputText = "";
void quit_button_back(int x,int y,SDL_Event e)
{
    butonas("Exit",SCREEN_WIDTH/2+45, SCREEN_HEIGHT -80,x,y);
    if(is_butonas_clicked(SCREEN_WIDTH/2+45, SCREEN_HEIGHT -80,x,y,e))
    {
        quit=true;
        close();
    }
    butonas("Back",SCREEN_WIDTH/2-135, SCREEN_HEIGHT -80,x,y);
    if(is_butonas_clicked(SCREEN_WIDTH/2-135, SCREEN_HEIGHT -80,x,y,e))
    {
        inputText = "";
        strcpy(textinput,"");
        strcpy(textoutput,"");
        ok_menu=1;
        ok_submenu1=0;
        strcpy (a,"Select");
        strcpy (b,"Select");
        ok_submenu2=0;
        ok_submenu3=0;
        ok_submenu4=0;
        ok_submenu5=0;
        ok_submenu6=0;
        ok_submenu7=0;
        ok_submenu8=0;
        ok_submenu9=0;
        ok_submenu10=0;
        ok_submenu11=0;
        submenu1_ok1=1;
        submenu1_ok2=1;
        submenu1_ok1_1=1;
        submenu1_ok2_1=1;
        g1=0;
        g2=0;
    }
}




void input(SDL_Event e,int x,int y)
{
    int ok=1,k=0;
    maxi_butonas_dynamic("Introdu un numar",x,y-40,x,y);
    while(k==0)
    {
        k=1;
        SDL_Color textColor = { 0, 0, 0, 0xFF };

        //The current input text.

        gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor,gFont3 );

        //Enable text input
        SDL_StartTextInput();
        while( ok )
        {

            //The rerender text flag
            bool renderText = false;

            //Handle events on queue
            while( SDL_PollEvent( &e ) != 0 )
            {
                //User requests quit
                if( e.type == SDL_QUIT )
                {
                    quit = true;
                }
                //Special key input
                else if( e.type == SDL_KEYDOWN )
                {
                    //Handle backspace
                    if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
                    {
                        //lop off character
                        inputText.pop_back();
                        renderText = true;

                    }
                    //Handle copy
                    else if( e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
                    {
                        SDL_SetClipboardText( inputText.c_str() );
                    }
                    //Handle paste
                    else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
                    {
                        inputText = SDL_GetClipboardText();
                        renderText = true;
                    }
                }
                //Special text input event
                else if( e.type == SDL_TEXTINPUT&&inputText.length()<16 )
                {
                    //Not copy or pasting
                    if( !( ( e.text.text[ 0 ] == 'c' || e.text.text[ 0 ] == 'C' ) && ( e.text.text[ 0 ] == 'v' || e.text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )
                    {
                        //Append character
                        inputText += e.text.text;
                        renderText = true;
                    }
                }

            }

            //Rerender text if needed
            if( renderText )
            {
                //Text is not empty
                if( inputText != "" )
                {
                    //Render new text
                    gInputTextTexture.loadFromRenderedText( inputText.c_str(), textColor,gFont3 );
                }
                //Text is empty
                else
                {
                    //Render space texture
                    gInputTextTexture.loadFromRenderedText( " ", textColor,gFont3 );
                }
            }


            strcpy(textinput,inputText.c_str());

            SDL_RenderPresent( gRenderer );

            color_background("",x,y);

            maxi_butonas_dynamic(textinput,x,y,x,y);
            background();
            SDL_RenderPresent( gRenderer );
            //Update screen




            if( e.key.keysym.sym == SDLK_ESCAPE||e.key.keysym.sym ==SDLK_RETURN )
                break;
        }

        //Disable text input
        SDL_StopTextInput();
        for(int i=0; i<strlen(textinput); i++)
        {
            if((textinput[i]<'0' || textinput[i]>'9')&&(textinput[i]!='.'))
            {
                k=0;
                break;
            }
        }
    }

}
