#include <iostream>

using namespace std;
#define _WIN32_WINNT 0x0500
#include <windows.h>

void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      
    SetConsoleScreenBufferSize(Handle, coord);            
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            
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
    for(i=2;i<width;i++)
        cout<<(char)205;
    cout<<(char)187;
    cout<<endl;
    cout<<(char)186<<(char)201;
    for(i=3;i<width-1;i++)
        cout<<(char)205;
    cout<<(char)187<<(char)186<<endl;
    for(i=3;i<height-1;i++)
    {
        cout<<(char)186<<(char)186;
        for(j=3;j<width-1;j++)
        cout<<" ";
        cout<<(char)186<<(char)186;
        cout<<endl;
    }
    cout<<(char)186<<(char)200;
    for(i=3;i<width-1;i++)
        cout<<(char)205;
    cout<<(char)188<<(char)186;
    cout<<endl;
    cout<<(char)200;
    for(i=2;i<width;i++)
        cout<<(char)205;
    cout<<(char)188;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
