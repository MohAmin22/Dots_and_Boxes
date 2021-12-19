#include <stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void box(void)
{
    int i,j;
    //start of box
    gotoxy(39,10);
    printf("%c",201);
    for(i=1;i<=35;i++)printf("%c",205);
    printf("%c",187);
    
    //spaces
    for(i=0;i<4;i++){
    gotoxy(39,11+i);
    printf("%c",186);
    for(j=1;j<=35;j++)printf(" ");
    printf("%c",186);
    }
    //the end of the box
    gotoxy(39,15);
    printf("%c",200);
    for(i=1;i<=35;i++)printf("%c",205);
    printf("%c",188);
}

void names_of_menu(void)
{
    gotoxy(40,11);
    printf("[1]start game");
    gotoxy(40,12);
    printf("[2]load game");
    gotoxy(40,13);
    printf("[3]top scores");
    gotoxy(40,14);
    printf("[4]exit");
}

int main(){

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    box();
    names_of_menu();
    int pos=1;
    char ch;
    while(1){
    SetConsoleTextAttribute(console,10);
    gotoxy(40,11);printf("[1]start game");gotoxy(40,15);
    ch=getch();
    if(ch!=-32)
    switch(pos){
        case 1:break;
        case 2:break;
        case 3:break;
        case 4:break;
    }
    }

    //return default colour
    SetConsoleTextAttribute(console,15);
    return 0;
}