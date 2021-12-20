#include <stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include "menu.h"



int main(){

    box();
    int selection=menu1(); //selection is the variable that contains the player's choice from the main menu
    //return default colour
    reset();
    switch(selection)
    {
        
        case 1:  //case that player choice [1]start game
        
        
        case 2:  //case that player choice [2]load a previous game
       

        case 3: //the case that the player choice top scorers

        case 4: //the case that the player choice [4]exit
          exit(0);

        
    }
    
    
    
   
    
    
    
    return 0;
}