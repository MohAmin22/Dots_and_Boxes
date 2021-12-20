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





int main(){
    
    box();
    int selection=menu1(); //selection is the variable that contains the player's choice from the main menu
    //return default colour
    reset();
    
    switch(selection)
    {
        
        case 1:  //case that player choice [1]start game
        delete_main_menu();
        drawing_2x2grid();        


















        case 2:  //case that player choice [2]load a previous game
        printf("that is the second case");

        case 3: //the case that the player choice top scorers

        case 4: //the case that the player choice [4]exit
          exit(0);

        
    }
    
    
    
   
    
    
    
    return 0;
}