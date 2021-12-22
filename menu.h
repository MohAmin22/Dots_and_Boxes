#ifndef MENU
#define MENU
#include <stdio.h>
#include <windows.h>
#include "game5x5.h"
#include<math.h>
//the colors
void red () {
  system("");
  printf("\033[1;31m");
}

void cyan (void) {
      system("");
  printf("\033[0;36m");
}

void purple(void) {
      system("");
    printf("\033[0;35m");
}

void reset (void) {
    system("");
  printf("\033[0m");
}


void gotoxy(int x,int y)
{
    COORD coord= {0,0};
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

//the code of the starting of the main menu


void box(int a)
{
    int i,j;
    //start of box
    gotoxy(39,10);
    printf("%c",201);
    for(i=1;i<=35;i++)printf("%c",205);
    printf("%c",187);

    //spaces
    for(i=0;i<a;i++){
    gotoxy(39,11+i);
    printf("%c",186);
    for(j=1;j<=35;j++)printf(" ");
    printf("%c",186);
    }
    //the end of the box
    gotoxy(39,11+a);
    printf("%c",200);
    for(i=1;i<=35;i++)printf("%c",205);
    printf("%c",188);
}

int main_menu(void)
{

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int pos=1;
    char ch;


    do
    {
        SetConsoleTextAttribute(console,15);

        gotoxy(40,11);printf("          [1]start game");
        gotoxy(40,12);printf("          [2]load game");
        gotoxy(40,13);printf("          [3]top scores");
        gotoxy(40,14);printf("          [4]exit");

        switch(pos)
        {
            case 1:SetConsoleTextAttribute(console,12);gotoxy(40,11);printf("          [1]start game");break;
            case 2:SetConsoleTextAttribute(console,12);gotoxy(40,12);printf("          [2]load game");break;
            case 3:SetConsoleTextAttribute(console,12);gotoxy(40,13);printf("          [3]top scores");break;
            case 4:SetConsoleTextAttribute(console,12);gotoxy(40,14);printf("          [4]exit");break;
        }
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

    }while(ch!=13);
    gotoxy(39,16);
    return pos;

}


int level_menu(void)
{

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int pos=1;
    char ch;


    do
    {
        SetConsoleTextAttribute(console,15);

        gotoxy(40,11);printf("       [1]Beginner mode(2x2)");
        gotoxy(40,12);printf("       [2]Expert mode(5x5)");

        switch(pos)
        {
            case 1:SetConsoleTextAttribute(console,12);gotoxy(40,11);printf("       [1]Beginner mode(2x2)");break;
            case 2:SetConsoleTextAttribute(console,12);gotoxy(40,12);printf("       [2]Expert mode(5x5)");break;

        }
        ch=getch();
        if(ch==72)
        {
            pos--;
            if(pos==0)pos=2;
        }
        if(ch==80)
        {
            pos++;
            if(pos==3)pos=1;
        }

    }while(ch!=13);
    gotoxy(39,16);
    return pos;

}

//the menu of vs
int vs_menu(void)
{

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int pos=1;
    char ch;


    do
    {
        SetConsoleTextAttribute(console,15);

        gotoxy(40,11);printf("       [1]Vs Computer");
        gotoxy(40,12);printf("       [2]Vs Player");

        switch(pos)
        {
            case 1:SetConsoleTextAttribute(console,12);gotoxy(40,11);printf("       [1]Vs Computer");break;
            case 2:SetConsoleTextAttribute(console,12);gotoxy(40,12);printf("       [2]Vs Player");break;

        }
        ch=getch();
        if(ch==72)
        {
            pos--;
            if(pos==0)pos=2;
        }
        if(ch==80)
        {
            pos++;
            if(pos==3)pos=1;
        }

    }while(ch!=13);
    gotoxy(39,16);
    return pos;

}

//function for deleting the main menu
void delete_main_menu(int a){

    int j,i;
    for(j=0;j<a+2;j++)
    {
        gotoxy(39,10+j);
        for(i=1;i<=37;i++)printf(" ");
    }
}


//game edit:

void game_box(void){
    int i,j;
    //start of box
    gotoxy(1,17);
    printf("%c",201);
    for(i=1;i<=5;i++)printf("%c",205);
    printf("%c",187);

    gotoxy(1,18);
    printf("%c",186);
    for(j=1;j<=5;j++)printf(" ");
    printf("%c",186);
    gotoxy(1,19);
    printf("%c",186);
    for(j=1;j<=5;j++)printf(" ");
    printf("%c",186);
    gotoxy(1,20);
    printf("%c",186);
    for(j=1;j<=5;j++)printf(" ");
    printf("%c",186);

    gotoxy(1,21);
    printf("%c",200);
    for(i=1;i<=5;i++)printf("%c",205);
    printf("%c",188);
}

int choice_menu(void)
{

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int pos=1;
    char ch;


    do
    {
        SetConsoleTextAttribute(console,15);

        gotoxy(2,18);printf(" [1] ");
        gotoxy(2,19);printf(" [2] ");
        gotoxy(2,20);printf(" [3] ");
        switch(pos)
        {
            case 1:SetConsoleTextAttribute(console,12);gotoxy(2,18);printf(" [1] ");break;
            case 2:SetConsoleTextAttribute(console,12);gotoxy(2,19);printf(" [2] ");break;
            case 3:SetConsoleTextAttribute(console,12);gotoxy(2,20);printf(" [3] ");break;

        }
        ch=getch();
        if(ch==72)
        {
            pos--;
            if(pos==0)pos=3;
        }
        if(ch==80)
        {
            pos++;
            if(pos==4)pos=1;
        }

    }while(ch!=13);
    gotoxy(1,21);
    reset();
    return pos;


}
void delete_choice_menu(void){
    int i,j;
    for(i=0;i<5;i++){
        gotoxy(1,16+i);
        for(j=1;j<=7;j++){
            printf(" ");
        }
    }
}
#endif // end of menu
