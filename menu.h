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

//function of position

int position(void){

}


//the code of the starting of the main menu


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

int menu1(void)
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

//function for deleting the main menu
void delete_main_menu(void){
    
    int j,i;
    for(j=0;j<6;j++)
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
    gotoxy(8,2);printf("%d",2);
    gotoxy(8,3);printf("%c",254);
    //the the third and the last box in the first row
    gotoxy(13,2);printf("%d",3);
    gotoxy(13,3);printf("%c",254);

    //row 2 column 1
    gotoxy(2,8);printf("%d",2);
    gotoxy(3,8);printf("%c",254);
    //row 2 column 2
    gotoxy(8,8);printf("%c",254);
    //row 2 column 3
    gotoxy(13,8);printf("%c",254);


    // first box in the third and the last row
    gotoxy(2,13);printf("%d",3);
    gotoxy(3,13);printf("%c",254);
    // second box in the third and the last row
    gotoxy(8,13);printf("%c",254);
    // third box in the third and the last row
    gotoxy(13,13);printf("%c",254);

}
