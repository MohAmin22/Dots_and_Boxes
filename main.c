#include <stdio.h>
#include<windows.h>
#include<string.h>

#include "menu.h"

typedef struct {
   int score;
   int lines_remainig ;
   int number_of_moves ;
    char  player_name[100];


}player;
player player1 ={0,12,0};
player player2 ={0,12,0};



int selection2=1;
int selection3=1;

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
                                            gotoxy(39,17);
                                            printf("the first selection");


                                        break;
                                        case 2: // vs player in (2x2)
                                            reset();
                                            gotoxy(39,17);
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