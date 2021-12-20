#include <stdio.h>
#include <windows.h>
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

//the code of gotoxy function
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

void drawing_2x2grid(void){
    // first box in the first row
    gotoxy(3,2);printf("%d",1);
    gotoxy(2,3);printf("%d",1);
    gotoxy(3,3);printf("%c",254);
    //the middle box in the first row
    gotoxy(13,2);printf("%d",2);
    gotoxy(13,3);printf("%c",254);
    //the the third and the last box in the first row
    gotoxy(23,2);printf("%d",3);
    gotoxy(23,3);printf("%c",254);

    //row 2 column 1
    gotoxy(2,8);printf("%d",2);
    gotoxy(3,8);printf("%c",254);
    //row 2 column 2
    gotoxy(13,8);printf("%c",254);
    //row 2 column 3
    gotoxy(23,8);printf("%c",254);


    // first box in the third and the last row
    gotoxy(2,13);printf("%d",3);
    gotoxy(3,13);printf("%c",254);
    // second box in the third and the last row
    gotoxy(13,13);printf("%c",254);
    // third box in the third and the last row
    gotoxy(23,13);printf("%c",254);



}

