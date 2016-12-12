#include <iostream>
#include <fstream>
using namespace std;
ifstream fin1("Convert.in");
#include <stdio.h>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <conio.h>
HWND hConsole;

MENUITEMINFO mii;
void centerconsole()
{
    	//Get the window console handle(isn't the right code but works for these sample
	HWND ConsoleWindow;
	ConsoleWindow=GetForegroundWindow();

	//Getting the desktop hadle and rectangule
	HWND   hwndScreen;
	RECT   rectScreen;
	hwndScreen=GetDesktopWindow ();
	GetWindowRect(hwndScreen,&rectScreen);



	// Get the current width and height of the console
	RECT rConsole;
	GetWindowRect (ConsoleWindow,&rConsole);
	int Width = rConsole.left = rConsole.right;
	int Height = rConsole.bottom - rConsole.top;

	//caculate the window console to center of the screen
	int ConsolePosX;
	int ConsolePosY;
	ConsolePosX = ((rectScreen.right-rectScreen.left)/2-Width/2 );
	ConsolePosY = ((rectScreen.bottom-rectScreen.top)/2- Height/2 );
	SetWindowPos(ConsoleWindow,NULL,ConsolePosX,ConsolePosY, Width, Height, SWP_SHOWWINDOW || SWP_NOSIZE);

	_getch();
}
void misc()
{


    SMALL_RECT windowSize = {0, 0, 100, 100};

    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    SetConsoleTitle("CONVERTOR");

    Sleep(10); //Let the window to update the Title!

    hConsole=FindWindow(NULL, "CONVERTOR");

    HMENU hMenu = GetSystemMenu ( (HWND)hConsole, FALSE);



    mii.fState = MFS_GRAYED;

    EnableMenuItem(hMenu,4,MF_DISABLED);

    SetMenuItemInfo(hMenu,4,MF_BYPOSITION,&mii);



    DeleteMenu( hMenu, 1, MF_BYPOSITION); // disable 'Move'

    DeleteMenu( hMenu, 1, MF_BYPOSITION); // disable 'Size'


    DeleteMenu( hMenu, 2, MF_BYPOSITION); // disable 'Maximize'

    HWND consoleWindow  = GetConsoleWindow();//1.
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE); //2.
    style = style & ~(WS_MINIMIZEBOX);//3.
    SetWindowLong(consoleWindow, GWL_STYLE, style);//4.disable 'minimize'

    //DeleteMenu( hMenu, 3, MF_BYPOSITION); // disable 'Close or X'


}
void SetConsoleWindowSize(int x, int y)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    // If either dimension is greater than the largest console window we can have,
    // there is no point in attempting the change.
  COORD largestSize = GetLargestConsoleWindowSize(h);


    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
GetConsoleScreenBufferInfo(h, &bufferInfo);


    SMALL_RECT& winInfo = bufferInfo.srWindow;
    COORD windowSize = { winInfo.Right - winInfo.Left + 1, winInfo.Bottom - winInfo.Top + 1};

    if (windowSize.X > x || windowSize.Y > y)
    {
        // window size needs to be adjusted before the buffer size can be reduced.
        SMALL_RECT info =
        {
            0,
            0,
            x < windowSize.X ? x-1 : windowSize.X-1,
            y < windowSize.Y ? y-1 : windowSize.Y-1
        };

        SetConsoleWindowInfo(h, TRUE, &info);

    }

    COORD size = { 101,y+5 };
    SetConsoleScreenBufferSize(h, size);



    SMALL_RECT info = { 0, 0, x - 1, y - 1 };
    SetConsoleWindowInfo(h, TRUE, &info);

}

void printmargins(int width,int height)
{
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED |
                             FOREGROUND_GREEN |
                             FOREGROUND_INTENSITY |
                             BACKGROUND_BLUE
                            );
    cout<<(char)201;
    int i,j;
    for(i=2; i<width; i++)
        cout<<(char)205;
    cout<<(char)187;
    cout<<endl;
    cout<<(char)186<<(char)201;
    for(i=3; i<width-1; i++)
        cout<<(char)205;
    cout<<(char)187<<(char)186<<endl;
    for(i=3; i<height-1; i++)
    {
        cout<<(char)186<<(char)186;
        for(j=3; j<width-1; j++)
            cout<<" ";
        cout<<(char)186<<(char)186;
        cout<<endl;
    }
    cout<<(char)186<<(char)200;
    for(i=3; i<width-1; i++)
        cout<<(char)205;
    cout<<(char)188<<(char)186;
    cout<<endl;
    cout<<(char)200;
    for(i=2; i<width; i++)
        cout<<(char)205;
    cout<<(char)188;
}
void gotoXY(int x, int y)
{
    //Initialize the coordinates
    COORD coord = {x, y};
    //Set the position
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    return;
}
void start()
{
    SetConsoleWindowSize(100,50);
    misc();

    printmargins(100,50);
    int i,j;
    char x;
    for(i=0; i<8; i++)
    {
        for(j=0; j<63; j++)
        {
            gotoXY(19+j,5+i);
            fin1>> noskipws >>x;
            cout<<(char)x;
        }
        cout<<endl;
    }
centerconsole();
}
int main()
{
    start();
    gotoXY(0,51);
    /*HWND hWnd = GetConsoleWindow();
    RECT rct;
    int width, height;
    if (GetWindowRect(hWnd, &rct))
    {
        width = rct.right - rct.left;
        height = rct.bottom - rct.top;
    }
    cout<<width<<" by "<<height<<endl;*/

    Sleep(6000);
}
