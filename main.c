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
    printf("          [1]start game");
    gotoxy(40,12);
    printf("          [2]load game");
    gotoxy(40,13);
    printf("          [3]top scores");
    gotoxy(40,14);
    printf("          [4]exit");
}

int main(){

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    box();
    names_of_menu();
    int pos=1;
    char ch;
    
    
    
    while(1){
        SetConsoleTextAttribute(console,12);
        gotoxy(40,11);printf("          [1]start game");
        ch=getch();
        
        if(ch==72)
        {
            pos--;
            if(pos==0)pos=4;
        }
        if(ch==80)
        {
            pos++;
            if(pos==5)pos=1;
        }
        
        switch(pos)
        {
            case 1:SetConsoleTextAttribute(console,12);gotoxy(40,11);printf("          [1]start game");break;
            case 2:SetConsoleTextAttribute(console,12);gotoxy(40,12);printf("          [2]load game");break;
            case 3:SetConsoleTextAttribute(console,12);gotoxy(40,13);printf("          [3]top scores");break;
            case 4:SetConsoleTextAttribute(console,12);gotoxy(40,14);printf("          [4]exit");break;
        }
    }

    //return default colour
    SetConsoleTextAttribute(console,15);
    return 0;
}