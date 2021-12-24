#ifndef AI
#define AI
#include "menu.h"
#include <stdio.h>
#include "game2x2.h"
#include "game5x5.h"


void computer (int number_of_boxes){
int counter1=0;int counter2=0;
for(counter1 =0 ;counter1 < number_of_boxes;counter1++){
    for(counter2 =0 ;counter2 < number_of_boxes;counter2++){
        if(score_4[counter1][counter2]==3){
            score_4[counter1][counter2]++;
            edit_drawing(counter1,counter2);
            goto forced_break;

        }

    }
}

for(counter1 =0 ;counter1 < number_of_boxes;counter1++){
    for(counter2 =0 ;counter2 < number_of_boxes;counter2++){
        if(score_4[counter1][counter2]==0 ||score_4[counter1][counter2]==1 ){
            score_4[counter1][counter2]++;
            edit_drawing(counter1,counter2);
            goto forced_break;

        }

    }
}

for(counter1 =0 ;counter1 < number_of_boxes;counter1++){
    for(counter2 =0 ;counter2 < number_of_boxes;counter2++){
        if(score_4[counter1][counter2]==2){
            score_4[counter1][counter2]++;
            edit_drawing(counter1,counter2);
            goto forced_break;

        }

    }
}
forced_break ://end of computer turn


}

/*void edit_drawing(int row_score,int col_score,int size_of_box){
int r = 2*row_score;
int c = (2*col_score) +1;
if(grid[r][c] == ' '){
    grid[r][c] = 205;
    if(row_score != 0 ) score_4[row_score-1][col_score]++;


}else if(grid[r+1][c+1] == ' '){
        grid[r+1][c+1] = 186;
        if(col_score != (size_of_box - 1) ) score_4[row_score][col_score+1]++;



}else if(grid[r+2][c] == ' '){
        grid[r+2][c] = 205;
        if(row_score != (size_of_box - 1) ) score_4[row_score+1][col_score]++;

}else if(grid[r-1][c-1] == ' '){
        grid[r-1][c-1] = 186;
        if(col_score != 0 ) score_4[row_score][col_score-1]++;

}


}

*/
void edit_drawing(int row_score,int col_score,int size_of_box){
int r = 2*row_score;
int c = (2*col_score) +1;
int counter3=0;
if(grid[r][c] == ' '){          //up
    grid[r][c] = 205;

    gotoxy((3+1)+4*col_score,3+2*row_score);
    for(counter3 =0;counter3<3;counter3++) printf("%c",205);

    if(row_score != 0 ) score_4[row_score-1][col_score]++;


}else if(grid[r+1][c+1] == ' '){    //Right    
        grid[r+1][c+1] = 186;

        gotoxy((3+4)+4*(col_score),(3+1)+2*(row_score));
        for(counter3=0;counter3<1;counter3++){
        gotoxy((3+4)+4*(col_score),(3+counter3+1)+2*(row_score));printf("%c",186);
        }

        if(col_score != (size_of_box - 1) ) score_4[row_score][col_score+1]++;



}else if(grid[r+2][c] == ' '){      //Down
        grid[r+2][c] = 205;

        gotoxy((3+1)+4*(col_score),3+2*(row_score));for(counter3=0;counter3<3;counter3++)printf("%c",205);

        if(row_score != (size_of_box - 1) ) score_4[row_score+1][col_score]++;

}else if(grid[r-1][c-1] == ' '){
        grid[r-1][c-1] = 186;

            gotoxy(3+4*(col_score),(3+1)+2*(row_score));
             for(counter3=0;counter3<1;counter3++){
             gotoxy(3+4*(col_score),(3+counter3+1)+2*(row_score));printf("%c",186);
             }


        if(col_score != 0 ) score_4[row_score][col_score-1]++;

}


}

#endif