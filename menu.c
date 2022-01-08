#include "menu.h"
//the colors



void red (void) {
 HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(console,12);
}
void red_box(void) {
 HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(console,192);
}

void cyan (void) {
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(console,9);
}
void cyan_box (void) {
  HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(console,144);
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
     SetConsoleTextAttribute(console,9);
    gotoxy(50,8);printf("/*Main..Menu*/");

    do
    {
             SetConsoleTextAttribute(console,15);

        gotoxy(40,11);printf("          [1]start game");
        gotoxy(40,12);printf("          [2]load game");
        gotoxy(40,13);printf("          [3]top scores");
        gotoxy(40,14);printf("          [4]exit");

        switch(pos)
        {
            case 1: SetConsoleTextAttribute(console,12);gotoxy(40,11);printf("          [1]start game");break;
            case 2: SetConsoleTextAttribute(console,12);gotoxy(40,12);printf("          [2]load game");break;
            case 3: SetConsoleTextAttribute(console,12);gotoxy(40,13);printf("          [3]top scores");break;
            case 4: SetConsoleTextAttribute(console,12);gotoxy(40,14);printf("          [4]exit");break;
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
    return pos;

}


int level_menu(void)
{
     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int pos=1;
    char ch;
        SetConsoleTextAttribute(console,9);
     gotoxy(50,8);printf("/*level..Menu*/");
    do
    {
         SetConsoleTextAttribute(console,15);

        gotoxy(40,11);printf("       [1]Beginner mode(2x2)");
        gotoxy(40,12);printf("       [2]Expert mode(5x5)");

        switch(pos)
        {
            case 1: SetConsoleTextAttribute(console,12);gotoxy(40,11);printf("       [1]Beginner mode(2x2)");break;
            case 2: SetConsoleTextAttribute(console,12);gotoxy(40,12);printf("       [2]Expert mode(5x5)");break;

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
    return pos;

}

//the menu of vs
int vs_menu(void)
{
     HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int pos=1;
    char ch;
     SetConsoleTextAttribute(console,9);
    gotoxy(50,8);printf("/*vs..Menu*/");

    do
    {
         SetConsoleTextAttribute(console,15);
        gotoxy(40,11);printf("       [1]Vs Computer");
        gotoxy(40,12);printf("       [2]Vs Player");

        switch(pos)
        {
            case 1: SetConsoleTextAttribute(console,12);gotoxy(40,11);printf("       [1]Vs Computer");break;
            case 2: SetConsoleTextAttribute(console,12);gotoxy(40,12);printf("       [2]Vs Player");break;

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
    return pos;

}
