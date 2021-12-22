#include <stdio.h>
#include<windows.h>
#include<string.h>
#include <conio.h>
#include<math.h>
#include <time.h>
#include "game2x2.h"
#include "game5x5.h"
#include "menu.h"


//Global variable
int counter=0,i=0;
int Total_remaining=12;
int checkScore =2;
int selection2=1;
int selection3=1;
int row1,row2,col1,col2;
clock_t start,end1,end2, diff,seconds,minutes;
//**
int row_change_color2x2=0,col_change_color2x2=0;

typedef struct {
   int score;
   int number_of_moves ;
    char  player_name[100];


}player;
player player1 = {.score=0,.number_of_moves =0};
player player2 = {.score=0,.number_of_moves =0};


void print_info(){
gotoxy(27,3);
printf("The number of moves of %s : %d",player1.player_name,player1.number_of_moves);
gotoxy(27,4);
printf("The number of moves of %s : %d",player2.player_name,player2.number_of_moves);
gotoxy(27,5);
printf("Score %d - %d",player1.score,player2.score);
gotoxy(27,6);
printf("The number of Remaining lines : %d " ,Total_remaining);

}

int main(){

    box(4);
    int selection1=main_menu(); //selection is the variable that contains the player's choice from the main menu
    //return default colour
    reset();

    switch(selection1)
    {

        case 1:  //case that player choice [1]start game
            delete_main_menu(4);
            // create a frame contains 2 rows (choices)
            box(2);
            selection2 = level_menu();
            //the choice from level menu
                    switch(selection2){
                         case 1 : // begginer mode (2x2)  if he choose 1
                            delete_main_menu(4);
                            reset();
                                    box(2);
                                    selection3 = vs_menu(); // the choice from vs menu
                                    switch(selection3){
                                        case 1: // vs computer in (2x2)
                                            reset();
                                            delete_main_menu(4);
                                            gotoxy(39,17);

                                            printf("the first selection");


                                        break;
                                        case 2: // vs player in (2x2)
                                            reset();
                                            delete_main_menu(4);
                                            gotoxy(1,1);


                                            printf("Player  1 name : ");
                                            gets(player1.player_name);
                                            printf("Player  2 name : ");
                                            gets(player2.player_name);
                                            system("cls");
                                            drawing_2x2grid();
                                            printf("\n");
                                            //  Game loop
                                            start = clock();
                                            gotoxy(27,7);
                                            printf("Time since starting %d : %d",minutes,seconds);

                                            while(Total_remaining>0){
//**player1
                                                player_1:

                                                  print_info();
                                                  gotoxy(1,14);
                                                  printf("%s's Turn : \n",player1.player_name);
                                                  printf("Enter R1 R2 C1 C2 : \n");
                                                  game_box();
                                                  gotoxy(10,19);printf("%c%c choose row 1        ",174,61);
                                                  row1=choice_menu();
                                                  gotoxy(10,19);printf("%c%c choose row 2       ",174,61);
                                                  row2=choice_menu();
                                                  gotoxy(10,19);printf("%c%c choose column 1",174,61);
                                                  col1=choice_menu();
                                                  gotoxy(10,19);printf("%c%c choose column 2",174,61);
                                                  col2=choice_menu();
                                                  red();
                                                 while(1){
                                                     if(draw_lines2x2(row1,row2,col1,col2) == 1){
                                                         gotoxy(1,16);for(counter=0;counter<50;counter++)printf(" ");
                                                         player1.number_of_moves++;
                                                           break;
                                                         }
                                                     else if(draw_lines2x2(row1,row2,col1,col2) == 2) goto player_1;
                                                 }
//**
                                                check_score(&checkScore,&row_change_color2x2,&col_change_color2x2);
                                                if( (checkScore == 1) && (row_change_color2x2!=-1) && (col_change_color2x2!=-1) ){
                                                        player1.score++;
                                                        //change the color of the box:
                                                        red();
                                                        gotoxy((3+1)+10*(col_change_color2x2),3+5*(row_change_color2x2));
                                                        for(i=0;i<9;i++)printf("%c",205);
                                                        gotoxy((3+1)+10*(col_change_color2x2),(3+5)+5*(row_change_color2x2));
                                                        for(i=0;i<9;i++)printf("%c",205);
                                                        gotoxy(3+10*(col_change_color2x2),(3+1)+5*(row_change_color2x2));
                                                        for(i=0;i<4;i++){gotoxy(3+10*(col_change_color2x2),(3+i+1)+5*(row_change_color2x2));printf("%c",186);}
                                                        gotoxy((3+10)+10*(col_change_color2x2),(3+1)+5*(row_change_color2x2));
                                                        for(i=0;i<4;i++){gotoxy((3+10)+10*(col_change_color2x2),(3+i+1)+5*(row_change_color2x2));printf("%c",186);}
                                                        reset();
                                                        Total_remaining--;
                                                        goto player_1;
                                                }
                                               //timer update after player's role
                                                end1 = clock();
                                                diff = (int)(end1 - start)/CLOCKS_PER_SEC;
                                                seconds = diff % 60;
                                                minutes  = diff /60;
                                                gotoxy(27,7);
                                                printf("Time since starting %d : %d",minutes,seconds);




                                                Total_remaining--;
                                                if(Total_remaining == 0)
                                                    break;




//**player2
                                               player_2:


                                                  print_info();
                                                  gotoxy(1,14);
                                                  printf("%s's Turn : \n",player2.player_name);
                                                  printf("Enter R1 R2 C1 C2 : \n");
                                                  game_box();
                                                    gotoxy(10,19);printf("%c%c choose row 1       ",174,61);
                                                  row1=choice_menu();
                                                    gotoxy(10,19);printf("%c%c choose row 2      ",174,61);
                                                  row2=choice_menu();
                                                    gotoxy(10,19);printf("%c%c choose column 1",174,61);
                                                  col1=choice_menu();
                                                    gotoxy(10,19);printf("%c%c choose column 2",174,61);
                                                  col2=choice_menu();
                                                 cyan();
                                                 while(1){
                                                     if(draw_lines2x2(row1,row2,col1,col2) == 1){
                                                         gotoxy(1,16);for(counter=0;counter<50;counter++)printf(" ");
                                                         player2.number_of_moves++;
                                                           break;
                                                         }
                                                     else if(draw_lines2x2(row1,row2,col1,col2) == 2) goto player_2;
                                                 }
                                                 check_score(&(checkScore),&(row_change_color2x2),&(col_change_color2x2));
                                                if( (checkScore == 1) && (row_change_color2x2!=-1) && (col_change_color2x2!=-1) ){
                                                        player2.score++;
                                                        //change the color of the box:
                                                        cyan();
                                                        gotoxy((3+1)+10*(col_change_color2x2),3+5*(row_change_color2x2));
                                                        for(i=0;i<9;i++)printf("%c",205);
                                                        gotoxy((3+1)+10*(col_change_color2x2),(3+5)+5*(row_change_color2x2));
                                                        for(i=0;i<9;i++)printf("%c",205);
                                                        gotoxy(3+10*(col_change_color2x2),(3+1)+5*(row_change_color2x2));
                                                        for(i=0;i<4;i++){gotoxy(3+10*(col_change_color2x2),(3+i+1)+5*(row_change_color2x2));printf("%c",186);}
                                                        gotoxy((3+10)+10*(col_change_color2x2),(3+1)+5*(row_change_color2x2));
                                                        for(i=0;i<4;i++){gotoxy((3+10)+10*(col_change_color2x2),(3+i+1)+5*(row_change_color2x2));printf("%c",186);}
                                                        reset();
                                                        Total_remaining--;
                                                        goto player_2;
                                                }
                                                //timer update after player's role
                                                end2 = clock();
                                                diff = (int)(end2 - start)/CLOCKS_PER_SEC;
                                                seconds = diff % 60;
                                                minutes  = diff /60;
                                                gotoxy(27,7);
                                                printf("Time since starting %d : %d",minutes,seconds);

                                                Total_remaining--;
                                               if(Total_remaining == 0)
                                                    break;


                                            }
                                          print_info(); // to update info after the final line

                                            //determining winner
                                            if(player1.score > player2.score)
                                               printf("The winner is %s :",player1.player_name);
                                            else if(player1.score < player2.score)
                                                printf("The winner is %s :",player2.player_name);
                                            else printf("There are no winner the game is draw ");

                                        break;

                                    }
                           // drawing_2x2grid();

                         break;
                        case 2 :// Expert mode (5x5)  if he choose 2
                            delete_main_menu(4);
                            reset();
                                    selection3 = vs_menu(); // the choice from vs menu

                                   box(2);
                                    switch(selection3){
                                        case 1: // vs computer (5x5)
                                                reset();
                                                gotoxy(39,17);
                                                printf("the first selection");

                                        break;
                                        case 2: // vs player (5x5)
                                                reset();
                                                gotoxy(39,17);
                                                printf("the second selection");


                                        break;

                                    }

                          break;
                    }
            break;




        case 2:  //case that player choice [2]load a previous game
        printf("that is the second case");
        break;
        case 3: //the case that the player choice top scorers
        break;
        case 4: //the case that the player choice [4]exit
          break;


    }
    return 0;
}
