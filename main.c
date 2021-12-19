#include <stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

int main(){
\\ stoping and typing into it
void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

\\ 









    return 0;
}