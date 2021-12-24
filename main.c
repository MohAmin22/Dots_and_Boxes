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
int row_cc=0,col_cc=0,row_cc1=0,col_cc1=0;

typedef struct {
   int score;
   int number_of_moves ;
    char  player_name[100];


}player;
player player1 = {.score=0,.number_of_moves =0};
player player2 = {.score=0,.number_of_moves =0};


void print_info(){
gotoxy(35,3);
printf("The number of moves of %s : %d",player1.player_name,player1.number_of_moves);
gotoxy(35,4);
printf("The number of moves of %s : %d",player2.player_name,player2.number_of_moves);
gotoxy(35,5);
printf("Score %d - %d",player1.score,player2.score);
gotoxy(35,6);
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
             system("cls");
            // create a frame contains 2 rows (choices)
            box(2);
            selection2 = level_menu();
            //the choice from level menu
                    switch(selection2){
                         case 1 : // begginer mode (2x2)  if he choose 1
                            system("cls");
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

/***********************************************************************************************************************************************************************************/
                                            reset();
                                            system("cls");
                                            gotoxy(1,1);
                                            printf("Player  A name : ");
                                            gets(player1.player_name);
                                            printf("Player  B name : ");
                                            gets(player2.player_name);
                                            system("cls");
                                            drawing_grid(2);
                                            arr_start_grid(2);
                                            printf("\n");
                                            //  Game loop
                                            start = clock();
                                            gotoxy(35,7);
                                            printf("Time since starting %d : %d",minutes,seconds);
                                            Total_remaining=12;
                                            while(Total_remaining>0){
                                                //**player1
                                                player_1:

                                                  print_info();
                                                  gotoxy(1,14);
                                                  red();
                                                  printf("%s's Turn : \n",player1.player_name);
                                                  printf("Enter R1 R2 C1 C2 : \n");

                                                  gotoxy(1,19);printf("Enter row 1:");
                                                  row1=scan_valid_integer(2,1);
                                                  gotoxy(1,20);printf("Enter row 2:");
                                                  row2=scan_valid_integer(2,2);
                                                  gotoxy(1,21);printf("Enter col 1:");
                                                  col1=scan_valid_integer(2,3);
                                                  gotoxy(1,22);printf("Enter col 2:");
                                                  col2=scan_valid_integer(2,4);

                                                 while(1){
                                                     if(draw_lines2x2(row1,row2,col1,col2,2) == 1){
                                                         gotoxy(1,16);for(counter=0;counter<50;counter++)printf(" ");
                                                         player1.number_of_moves++;
                                                           break;
                                                         }
                                                     else if(draw_lines2x2(row1,row2,col1,col2,2) == 2) goto player_1;
                                                 }


                                                check_score(&checkScore,&row_cc,&col_cc,&row_cc1,&col_cc1,2,'A');
                                                if( checkScore == 1 ){
                                                        player1.score++;
                                                        //change the color of the box:
                                                        red();
                                                        color_box(row_cc,col_cc);
                                                        gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("A");
                                                        delete_common(2,'A');
                                                        reset();
                                                        Total_remaining--;
                                                        if(Total_remaining ==0){
                                                            goto after_game;
                                                        }
                                                    goto player_1;
                                                }
                                                if(checkScore==2){
                                                    player1.score+=2;
                                                    red();
                                                    color_box(row_cc,col_cc);
                                                    gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("A");
                                                    color_box(row_cc1,col_cc1);
                                                    gotoxy((3+2)+4*(col_cc1),(3+1)+2*(row_cc1));printf("A");
                                                    delete_common(2,'A');
                                                    reset();
                                                    Total_remaining--;
                                                        if(Total_remaining ==0){
                                                            goto after_game;
                                                        }
                                                        goto player_1;
                                                }
                                                

                                               //timer update after player's role
                                                end1 = clock();
                                                diff = (int)(end1 - start)/CLOCKS_PER_SEC;
                                                seconds = diff % 60;
                                                minutes  = diff /60;
                                                gotoxy(35,7);
                                                printf("Time since starting %d : %d",minutes,seconds);
                                                Total_remaining--;
                                                if(Total_remaining == 0){
                                                    goto after_game;
                                                    break;

                                                }




                                                //**player2
                                               player_2:


                                                  print_info();
                                                  gotoxy(1,14);
                                                  cyan();
                                                  printf("%s's Turn : \n",player2.player_name);
                                                  printf("Enter R1 R2 C1 C2 : \n");
                                                  gotoxy(1,19);printf("Enter row 1:");
                                                  row1=scan_valid_integer(2,1);
                                                  gotoxy(1,20);printf("Enter row 2:");
                                                  row2=scan_valid_integer(2,2);
                                                  gotoxy(1,21);printf("Enter col 1:");
                                                  col1=scan_valid_integer(2,3);
                                                  gotoxy(1,22);printf("Enter col 2:");
                                                  col2=scan_valid_integer(2,4);

                                                 while(1){
                                                     if(draw_lines2x2(row1,row2,col1,col2,2) == 1){
                                                         gotoxy(1,16);for(counter=0;counter<50;counter++)printf(" ");
                                                         player2.number_of_moves++;
                                                           break;
                                                         }
                                                     else if(draw_lines2x2(row1,row2,col1,col2,2) == 2) goto player_2;
                                                 }
                                                  check_score(&checkScore,&row_cc,&col_cc,&row_cc1,&col_cc1,2,'B');
                                                if( checkScore == 1 ){
                                                        player2.score++;
                                                        //change the color of the box:
                                                        cyan(); 
                                                        color_box(row_cc,col_cc); 
                                                        gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("B");
                                                        delete_common(2,'B');
                                                        reset();
                                                        Total_remaining--;
                                                        if(Total_remaining ==0){
                                                            goto after_game;
                                                        }
                                                        goto player_2;
                                                }
                                                if(checkScore==2){
                                                    player2.score+=2;
                                                    cyan();
                                                    color_box(row_cc,col_cc);
                                                    gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("B");
                                                    color_box(row_cc1,col_cc1);
                                                    gotoxy((3+2)+4*(col_cc1),(3+1)+2*(row_cc1));printf("B");
                                                    delete_common(2,'B');
                                                    reset();
                                                    Total_remaining--;
                                                        if(Total_remaining ==0){
                                                            goto after_game;
                                                        }
                                                        goto player_2;
                                                }

                                                //timer update after player's role
                                                end2 = clock();
                                                diff = (int)(end2 - start)/CLOCKS_PER_SEC;
                                                seconds = diff % 60;
                                                minutes  = diff /60;
                                                gotoxy(35,7);
                                                printf("Time since starting %d : %d",minutes,seconds);

                                                Total_remaining--;
                                                


                                               if(Total_remaining == 0){
                                                    goto after_game;
                                                    break;
                                               }







                                            }
                                            after_game:
                                             print_info(); // to update info after the final line
                                            //determining winner
                                            gotoxy(1,25);
                                            purple();
                                            if(player1.score > player2.score)
                                               printf("The winner is : %s",player1.player_name);
                                            else if(player1.score < player2.score)
                                                printf("The winner is : %s",player2.player_name);
                                            else if(player1.score == player2.score) printf("There are no winner the game is draw ");
                                            
                                        break;

                                    }
                         break;





                        case 2 :// Expert mode (5x5)  if he choose 2
                            delete_main_menu(4);
                            reset();
                                     box(2);
                                    selection3 = vs_menu(); // the choice from vs menu


                                    switch(selection3){
                                        case 1: // vs computer (5x5)
                                                reset();
                                                gotoxy(39,17);
                                                printf("the first selection");

                                        break;
                                        case 2: // vs player (5x5)

/***********************************************************************************************************************************************************************************/
                                            reset();
                                            system("cls");
                                            gotoxy(1,1);
                                            printf("Player  A name : ");
                                            gets(player1.player_name);
                                            printf("Player  2 name : ");
                                            gets(player2.player_name);
                                            system("cls");
                                            drawing_grid(5);
                                            arr_start_grid(5);
                                            printf("\n");
                                            //  Game loop
                                            start = clock();
                                            gotoxy(35,7);
                                            printf("Time since starting %d : %d",minutes,seconds);
                                            Total_remaining=2*5*6;
                                            while(Total_remaining>0){
//**player1
                                                player_1_5x5:

                                                  print_info();
                                                  gotoxy(1,14);
                                                  red();
                                                  printf("%s's Turn : \n",player1.player_name);
                                                  printf("Enter R1 R2 C1 C2 : \n");

                                                  gotoxy(1,19);printf("Enter row 1:");
                                                  row1=scan_valid_integer(5,1);
                                                  gotoxy(1,20);printf("Enter row 2:");
                                                  row2=scan_valid_integer(5,2);
                                                  gotoxy(1,21);printf("Enter col 1:");
                                                  col1=scan_valid_integer(5,3);
                                                  gotoxy(1,22);printf("Enter col 2:");
                                                  col2=scan_valid_integer(5,4);

                                                 while(1){
                                                     if(draw_lines2x2(row1,row2,col1,col2,5) == 1){
                                                         gotoxy(1,16);for(counter=0;counter<50;counter++)printf(" ");
                                                         player1.number_of_moves++;
                                                           break;
                                                         }
                                                     else if(draw_lines2x2(row1,row2,col1,col2,5) == 2) goto player_1_5x5;
                                                 }


                                                check_score(&checkScore,&row_cc,&col_cc,&row_cc1,&col_cc1,5,'A');
                                                if( checkScore == 1 ){
                                                        player1.score++;
                                                        //change the color of the box:
                                                        red();
                                                        color_box(row_cc,col_cc); 
                                                        gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("A");
                                                        delete_common(5,'A');
                                                        reset();
                                                        Total_remaining--;
                                                        if(Total_remaining ==0){
                                                            goto after_game_5x5;
                                                        }
                                                        goto player_1_5x5;
                                                }
                                                if(checkScore==2){
                                                    player1.score+=2;
                                                    red();
                                                    color_box(row_cc,col_cc);
                                                    gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("A");
                                                    color_box(row_cc1,col_cc1);
                                                    gotoxy((3+2)+4*(col_cc1),(3+1)+2*(row_cc1));printf("A");
                                                    delete_common(5,'A');
                                                    reset();
                                                    Total_remaining--;
                                                        if(Total_remaining ==0){
                                                            goto after_game_5x5;
                                                        }
                                                        goto player_1_5x5;
                                                }

                                               //timer update after player's role
                                                end1 = clock();
                                                diff = (int)(end1 - start)/CLOCKS_PER_SEC;
                                                seconds = diff % 60;
                                                minutes  = diff /60;
                                                gotoxy(35,7);
                                                printf("Time since starting %d : %d",minutes,seconds);
                                                Total_remaining--;
                                                gotoxy(35,25);
                                                
                                                if(Total_remaining == 0){
                                                    goto after_game_5x5;
                                                    break;

                                                }
//**player2
                                               player_2_5x5:


                                                  print_info();
                                                  gotoxy(1,14);
                                                  cyan();
                                                  printf("%s's Turn : \n",player2.player_name);
                                                  printf("Enter R1 R2 C1 C2 : \n");
                                                  gotoxy(1,19);printf("Enter row 1:");
                                                  row1=scan_valid_integer(5,1);
                                                  gotoxy(1,20);printf("Enter row 2:");
                                                  row2=scan_valid_integer(5,2);
                                                  gotoxy(1,21);printf("Enter col 1:");
                                                  col1=scan_valid_integer(5,3);
                                                  gotoxy(1,22);printf("Enter col 2:");
                                                  col2=scan_valid_integer(5,4);

                                                 while(1){
                                                     if(draw_lines2x2(row1,row2,col1,col2,5) == 1){
                                                         gotoxy(1,16);for(counter=0;counter<50;counter++)printf(" ");
                                                         player2.number_of_moves++;
                                                           break;
                                                         }
                                                     else if(draw_lines2x2(row1,row2,col1,col2,5) == 2) goto player_2_5x5;
                                                 }
                                                  check_score(&checkScore,&row_cc,&col_cc,&row_cc1,&col_cc1,5,'B');
                                                if( checkScore == 1 ){
                                                        player2.score++;
                                                        //change the color of the box:
                                                        cyan();
                                                        color_box(row_cc,col_cc);
                                                        gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("B");
                                                        delete_common(5,'B'); 
                                                        reset();
                                                        Total_remaining--;
                                                        if(Total_remaining ==0){
                                                            goto after_game_5x5;
                                                        }
                                                        goto player_2_5x5;
                                                }
                                                if(checkScore==2){
                                                    player2.score+=2;
                                                    cyan();
                                                    color_box(row_cc,col_cc);
                                                    gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("B");
                                                    color_box(row_cc1,col_cc1);
                                                    gotoxy((3+2)+4*(col_cc1),(3+1)+2*(row_cc1));printf("B");
                                                    delete_common(5,'B');
                                                    reset();
                                                    Total_remaining--;
                                                        if(Total_remaining ==0){
                                                            goto after_game_5x5;
                                                        }
                                                        goto player_2_5x5;
                                                }

                                                //timer update after player's role
                                                end2 = clock();
                                                diff = (int)(end2 - start)/CLOCKS_PER_SEC;
                                                seconds = diff % 60;
                                                minutes  = diff /60;
                                                gotoxy(35,7);
                                                printf("Time since starting %d : %d",minutes,seconds);

                                                Total_remaining--;
                                                gotoxy(35,25);
                                                

                                               if(Total_remaining == 0){
                                                    goto after_game_5x5;
                                                    break;
                                               }







                                            }//end of while 5x5
                                            after_game_5x5:
                                             print_info(); // to update info after the final line
                                            //determining winner
                                            system("cls");
                                            if(player1.score > player2.score)
                                               printf("The winner is %s :",player1.player_name);
                                            else if(player1.score < player2.score)
                                                printf("The winner is %s :",player2.player_name);
                                            else if(player1.score == player2.score) printf("There are no winner the game is draw ");
/***********************************************************************************************************************************************************************************/
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
