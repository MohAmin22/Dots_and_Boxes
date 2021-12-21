#include <stdio.h>
#include<windows.h>
#include<string.h>
#include <conio.h>
#include "game2x2.h"
#include "game5x5.h"
#include "menu.h"

typedef struct {
   int score;
   int lines_remainig ;
   int number_of_moves ;
    char  player_name[100];


}player;
player player1 ={0,12,0};
player player2 ={0,12,0};

//Global variable
int counter;
int Total_remaining=12;

int selection2=1;
int selection3=1;
int row1,row2,col1,col2;

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
                                            while(Total_remaining>0){
                                                
                                                player_1:
                                                  gotoxy(1,14);
                                                  printf("Player 1 role : \n");
                                                  printf("Enter R1 R2 C1 C2 : \n");
                                                  game_box();
                                                  row1=choice_menu();
                                                  row2=choice_menu();
                                                  col1=choice_menu();
                                                  col2=choice_menu();
                                                  //printf("%d %d %d %d",row1,row2,col1,col2);
                                                 // if(((row1 == row2 ) && (abs(col1 - col2)) )||(col1 == col2))
                                                 red();
                                                 while(1){
                                                     if(draw_lines2x2(row1,row2,col1,col2) == 1){
                                                         gotoxy(1,16);for(counter=0;counter<50;counter++)printf(" ");
                                                           break;
                                                         } 
                                                     else if(draw_lines2x2(row1,row2,col1,col2) == 2) goto player_1;
                                                 }
                                                 
                                                




                                                Total_remaining--;

                                               

                                                /*Total_remaining--;*/
                                            }

                                            


                                            printf("the second selection");



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