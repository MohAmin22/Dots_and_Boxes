#ifndef GAME2X2
#define GAME2X2

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

//start of vs com definitions

int counter=0,i=0,roles_counter=0,largest_role=0,fileundonum=1,no_undos=0;
int Total_remaining=12;
int checkScore =2;
int row1,row2,col1,col2;
int four_choices=0;
int row_cc=0,col_cc=0,row_cc1=0;col_cc1=0;
clock_t start,end1,end2, diff,seconds,minutes;
int filenumber=0;
int filenumberload=0;


int score_4 [9][9]={0};
char score_4_name [9][9];
char grid[20][20]={0};
char roles_AorB[100];
typedef struct {
   int score;
   int number_of_moves ;
    char  player_name[100];


}player;
player player1 = {.score=0,.number_of_moves =0};
player player2 = {.score=0,.number_of_moves =0};

void riv(int sizegame){
int q;
for(q=0;q<2*sizegame*(sizegame+1);q++){
    roles_AorB[q]='C';
}

}
void print_info(int z){
gotoxy(35,3);
printf("The number of moves of %s : %d",player1.player_name,player1.number_of_moves);
gotoxy(35,4);
if(z==1){
printf("The number of moves of %s : %d",player2.player_name,player2.number_of_moves);
}
gotoxy(35,5);
printf("Score %d - %d",player1.score,player2.score);
gotoxy(35,6);
printf("The number of Remaining lines : %d " ,Total_remaining);

}



//end of vs comp definitions



void s4n(int n){
int a,b;
for (a=0;a<n;a++){
    for(b=0;b<n;b++){
        score_4_name[a][b]='c';
    }
}

}
void arr_start_grid(int n){

int k,j;
for(k=0;k<(2*n+1);k++){
    if(k%2==1){for(j=0;j<(2*n+1);j++)grid[k][j]='C';}
    else{
            for(j=0;j<(2*n+1);j++){
                if(j%2==0)grid[k][j]='D';
                else grid[k][j]='C';
            }
    }
}
}

void drawing_grid(int a){
    //**
    int k,j;
    for(k=1;k<=a+1;k++){gotoxy(2,3+(k-1)*2);printf("%d",k);}
    for(j=1;j<=a+1;j++){gotoxy(3+(j-1)*4,2);printf("%d",j);}

    for(k=1;k<=a+1;k++){
        gotoxy(3,3+(k-1)*2);
        for(j=1;j<=a+1;j++){
            gotoxy(3+(j-1)*4,3+(k-1)*2);
            printf("%c",254);
        }
    }
}

int draw_lines(int r1,int r2 ,int c1, int c2,int size_of_game,char name){
    int indc=0,indr=0,c=0,r=0; // the index when start drawing the lines ,  indc is index of x axis , indr is the index of y axis
    int i=0,ct=0,rt=0;


    if (r1 ==r2 && abs(c1-c2)==1){
        ct= c1>c2 ? c2 : c1;
            if(grid[(r1-1)*2][(ct-1)*2+1]=='C'){
                 c= c1>c2 ? c2 : c1;
                indr =3+2*(r1-1);
                indc =3+4*(c-1);
                gotoxy(indc+1,indr);
                for(i=0;i<3;i++)  printf("%c",205);
                grid[(r1-1)*2][(c-1)*2+1]=name;
                reset();
                if(r1==1){
                    score_4[0][c-1]++;
                }else if(r1==(size_of_game+1)){
                    score_4[r1-2][c-1]++;
                }else {
                  score_4[r1-2][c-1]++;
                  score_4[r1-1][c-1]++;
                }
                return 1;
            }else goto else1;

    }
    else if(c1 ==c2 && abs(r1-r2)==1){
        rt= r1>r2 ? r2 : r1;
        if(grid[(rt-1)*2+1][(c1-1)*2]=='C'){
         r= r1>r2 ? r2 : r1;
        indc =3+4*(c1-1);
        indr =3+2*(r-1);
        for(i=0;i<1;i++){gotoxy(indc,indr+1+i); printf("%c",186);}
        grid[(r-1)*2+1][(c1-1)*2]=name;
        reset();
         if(c1==1){
                score_4[r-1][0]++;
         }else if(c1==(size_of_game+1)){
                    score_4[r-1][c1-2]++;
        }else {
                  score_4[r-1][c1-2]++;
                  score_4[r-1][c1-1]++;
                }

        return 1;
        } else goto else1;
    }else {
        else1:
        reset();
        gotoxy(1,18);
        printf("please enter a valid coordinates :");
        return 2;
     }
}




/////////for deleting the repeated line in both two boxes



void delete_ver(int y,int z){
int deleted_row = 2*y+1;
int deleted_col = 2*z+2;

gotoxy(deleted_col*2+3,deleted_row+3);
printf(" ");

}

void delete_hor(int y,int z){
int deleted_row = 2*y+2;
int deleted_col = 2*z+1;

gotoxy(deleted_col*2+2,3+deleted_row);
printf("   ");


}




void delete_common(int num_boxes,char name){
int y=0;
int z=0;
    for(y=0;y<num_boxes;y++){
        for(z=0;z<num_boxes -1;z++){
            if(score_4_name[y][z]== name && score_4_name[y][z+1] == name){
                delete_ver(y,z);
            }
        }
    }
    for(y=0;y<num_boxes-1;y++){
        for(z=0;z<num_boxes;z++){
            if(score_4_name[y][z]== name && score_4_name[y+1][z] == name){
                delete_hor(y,z);
            }
        }
    }



}



void check_score(int *ch,int *row,int *col,int *k1,int *k2,int size,char name){
    int i,j=0;
    *ch=0,*row=-1,*col=-1,*k1=-1,*k2=-1;
    for(i=0;i<size;i++){
        for(j=0;j<size;j++){
            if(score_4[i][j] ==4 ){
                score_4[i][j] = 6;
                score_4_name[i][j]=name;
                *ch=*ch+1;
                if(*ch==1){*row=i;*col=j;}
                else if(*ch==2){*k1=i;*k2=j;}
            }
        }
    }

}
int scan_valid_integer(int max_num,int q){
 while(1){
        char input[100] ;
        gets(input);
        char x = input[0];
        int y = strlen(input);
        if(y==1 && (x-48)>=1 && (x-48)<= max_num +1){
            gotoxy(1,19+(q-1));
            printf("                                                                                                                                        ");
            return (x-48);
            break;
        }else {

             gotoxy(1,19+(q-1));
             printf("                                                                                                                                      ");
             gotoxy(1,19+(q-1));
            printf("Enter a valid value : ");
            }

    }

 }


void color_box(int a1,int a2){
                                int i;
                                gotoxy((3+1)+4*(a2),3+2*(a1));for(i=0;i<3;i++)printf("%c",205);
                                gotoxy((3+1)+4*(a2),(3+2)+2*(a1));for(i=0;i<3;i++)printf("%c",205);
                                 gotoxy(3+4*(a2),(3+1)+2*(a1));
                                 for(i=0;i<1;i++){
                                        gotoxy(3+4*(a2),(3+i+1)+2*(a1));printf("%c",186);
                                }
                                 gotoxy((3+4)+4*(a2),(3+1)+2*(a1));
                                 for(i=0;i<1;i++){
                                        gotoxy((3+4)+4*(a2),(3+i+1)+2*(a1));printf("%c",186);
                                 }
}

//End of game2x2

//start of Ai
//determining which box the AI will play in

void computer (int number_of_boxes,char name){
int counter1=0;int counter2=0;
for(counter1 =0 ;counter1 < number_of_boxes;counter1++){
    for(counter2 =0 ;counter2 < number_of_boxes;counter2++){
        if(score_4[counter1][counter2]==3){
            score_4[counter1][counter2]++;
            edit_drawing(counter1,counter2,number_of_boxes,name);
            goto forced;

        }

    }
}

for(counter1 =0 ;counter1 < number_of_boxes;counter1++){
    for(counter2 =0 ;counter2 < number_of_boxes;counter2++){
        if(score_4[counter1][counter2]==0 ||score_4[counter1][counter2]==1 ){
                        if(counter1 == 0 && counter2 == 0){
                                    if(score_4[counter1][counter2+1] != 2 && grid[2*counter1+1][2*counter2+2] == 'C'){//right
                                            score_4[counter1][counter2]++;
                                            score_4[counter1][counter2+1]++;
                                            grid[2*counter1+1][2*counter2+2] = name;
                                            gotoxy(7+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;

                                    }else if(score_4[counter1+1][counter2] != 2 && grid[2*counter1+2][2*counter2+1] == 'C'){//down
                                            score_4[counter1][counter2]++;
                                            score_4[counter1+1][counter2]++;
                                            grid[2*counter1+2][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,5+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;

                                    }



                        }else if(counter1 == 0 && counter2 == number_of_boxes-1){
                                    if(score_4[counter1][counter2-1] != 2 && grid[2*counter1+1][2*counter2] == 'C'){//left
                                            score_4[counter1][counter2]++;
                                            score_4[counter1][counter2-1]++;
                                            grid[2*counter1+1][2*counter2] = name;
                                            gotoxy(3+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;


                                    }else if(score_4[counter1+1][counter2] != 2 && grid[2*counter1+2][2*counter2+1] == 'C'){//down
                                            score_4[counter1][counter2]++;
                                            score_4[counter1+1][counter2]++;
                                            grid[2*counter1+2][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,5+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;

                                    }



                        }else if(counter1 == number_of_boxes-1 && counter2 == 0){
                                    if(score_4[counter1][counter2+1] != 2 && grid[2*counter1+1][2*counter2+2] == 'C'){//right
                                            score_4[counter1][counter2]++;
                                            score_4[counter1][counter2+1]++;
                                            grid[2*counter1+1][2*counter2+2] = name;
                                            gotoxy(7+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;


                                    }else if(score_4[counter1-1][counter2] != 2 && grid[2*counter1][2*counter2+1] == 'C'){//up
                                            score_4[counter1][counter2]++;
                                            score_4[counter1-1][counter2]++;
                                            grid[2*counter1][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,3+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;
                                    }



                        }else if(counter1 == number_of_boxes-1 && counter2 == number_of_boxes-1){
                                    if(score_4[counter1-1][counter2] != 2 && grid[2*counter1][2*counter2+1] == 'C'){//up
                                            score_4[counter1][counter2]++;
                                            score_4[counter1-1][counter2]++;
                                            grid[2*counter1][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,3+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;

                                    }else if(score_4[counter1][counter2-1] != 2 && grid[2*counter1+1][2*counter2] == 'C'){//left
                                            score_4[counter1][counter2]++;
                                            score_4[counter1][counter2-1]++;
                                            grid[2*counter1+1][2*counter2] = name;
                                            gotoxy(3+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;
                                    }



                        }else if(counter1 == 0 && counter2 != 0 && counter2 != number_of_boxes-1){
                                    if(score_4[counter1][counter2+1] != 2 && grid[2*counter1+1][2*counter2+2] == 'C'){//right
                                            score_4[counter1][counter2]++;
                                            score_4[counter1][counter2+1]++;
                                            grid[2*counter1+1][2*counter2+2] = name;
                                            gotoxy(7+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;


                                    }else if(score_4[counter1+1][counter2] != 2 && grid[2*counter1+2][2*counter2+1] == 'C'){//down
                                           score_4[counter1][counter2]++;
                                            score_4[counter1+1][counter2]++;
                                            grid[2*counter1+2][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,5+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;



                                    }else if(score_4[counter1][counter2-1] != 2 && grid[2*counter1+1][2*counter2] == 'C'){//left
                                            score_4[counter1][counter2]++;
                                            score_4[counter1][counter2-1]++;
                                            grid[2*counter1+1][2*counter2] = name;
                                            gotoxy(3+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;

                                    }


                        }else if(counter1 == number_of_boxes-1 && counter2 != 0 && counter2 != number_of_boxes-1){

                                    if(score_4[counter1-1][counter2] != 2 && grid[2*counter1][2*counter2+1] == 'C'){//up
                                            score_4[counter1][counter2]++;
                                            score_4[counter1-1][counter2]++;
                                            grid[2*counter1][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,3+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;

                                    }else if(score_4[counter1][counter2+1] != 2 && grid[2*counter1+1][2*counter2+2] == 'C'){//right
                                            score_4[counter1][counter2]++;
                                            score_4[counter1][counter2+1]++;
                                            grid[2*counter1+1][2*counter2+2] = name;
                                            gotoxy(7+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;



                                    }else if(score_4[counter1][counter2-1] != 2 && grid[2*counter1+1][2*counter2] == 'C'){//left
                                            score_4[counter1][counter2]++;
                                            score_4[counter1][counter2-1]++;
                                            grid[2*counter1+1][2*counter2] = name;
                                            gotoxy(3+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;

                                    }

                        }else if(counter2 == 0 && counter1 != 0 && counter1 != number_of_boxes-1){
                                    if(score_4[counter1-1][counter2] != 2 && grid[2*counter1][2*counter2+1] == 'C'){//up
                                            score_4[counter1][counter2]++;
                                            score_4[counter1-1][counter2]++;
                                            grid[2*counter1][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,3+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;


                                    }else if(score_4[counter1][counter2+1] != 2 && grid[2*counter1+1][2*counter2+2] == 'C'){//right
                                            score_4[counter1][counter2]++;
                                            score_4[counter1][counter2+1]++;
                                            grid[2*counter1+1][2*counter2+2] = name;
                                            gotoxy(7+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;

                                    }else if(score_4[counter1+1][counter2] != 2 && grid[2*counter1+2][2*counter2+1] == 'C'){//down
                                           score_4[counter1][counter2]++;
                                            score_4[counter1+1][counter2]++;
                                            grid[2*counter1+2][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,5+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;

                                    }


                        }else if(counter2 == number_of_boxes-1 && counter1 != 0 && counter1 != number_of_boxes-1){
                                    if(score_4[counter1-1][counter2] != 2 && grid[2*counter1][2*counter2+1] == 'C'){//up
                                            score_4[counter1][counter2]++;
                                            score_4[counter1-1][counter2]++;
                                            grid[2*counter1][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,3+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;


                                    }else if(score_4[counter1][counter2-1] != 2 && grid[2*counter1+1][2*counter2] == 'C'){//left

                                           score_4[counter1][counter2]++;
                                            score_4[counter1][counter2-1]++;
                                            grid[2*counter1+1][2*counter2] = name;
                                            gotoxy(3+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;


                                    }else if(score_4[counter1+1][counter2] != 2 && grid[2*counter1+2][2*counter2+1] == 'C'){//down
                                           score_4[counter1][counter2]++;
                                            score_4[counter1+1][counter2]++;
                                            grid[2*counter1+2][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,5+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;

                                    }


                        }else{
                                if(counter2 == number_of_boxes-1 && counter1 != 0 && counter1 != number_of_boxes-1){//up
                                            score_4[counter1][counter2]++;
                                            score_4[counter1-1][counter2]++;
                                            grid[2*counter1][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,3+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;
//**********

                                }else if(score_4[counter1+1][counter2] != 2 && grid[2*counter1+2][2*counter2+1] == 'C'){//down
                                            score_4[counter1][counter2]++;
                                            score_4[counter1+1][counter2]++;
                                            grid[2*counter1+2][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,5+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;


                                }else if(score_4[counter1][counter2+1] != 2 && grid[2*counter1+1][2*counter2+2] == 'C'){//right
                                           score_4[counter1][counter2]++;
                                            score_4[counter1][counter2+1]++;
                                            grid[2*counter1+1][2*counter2+2] = name;
                                            gotoxy(7+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;

                                }else if(score_4[counter1][counter2-1] != 2 && grid[2*counter1+1][2*counter2] == 'C'){//left

                                          score_4[counter1][counter2]++;
                                            score_4[counter1][counter2-1]++;
                                            grid[2*counter1+1][2*counter2] = name;
                                            gotoxy(3+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;


                                }


                        }

        }

    }
}


for(counter1 =0 ;counter1 < number_of_boxes;counter1++){
    for(counter2 =0 ;counter2 < number_of_boxes;counter2++){


        if(score_4[counter1][counter2]==0 ||score_4[counter1][counter2]==1){

                        if(counter1 == 0 && counter2 == 0){
                                if(grid[2*counter1][2*counter2+1] == 'C'){ //up
                                    score_4[counter1][counter2]++;
                                    grid[2*counter1][2*counter2+1] = name;
                                    gotoxy(4+4*counter2,3+2*counter1);
                                    printf("%c%c%c",205,205,205);
                                    goto forced;

                                }else if(grid[2*counter1+1][2*counter2] == 'C'){ //left
                                           score_4[counter1][counter2]++;
                                            grid[2*counter1+1][2*counter2] = name;
                                            gotoxy(3+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;

                                }



                        }else if(counter1 == 0 && counter2 == number_of_boxes-1){

                                if(grid[2*counter1][2*counter2+1] == 'C'){ //up
                                    score_4[counter1][counter2]++;
                                    grid[2*counter1][2*counter2+1] = name;
                                    gotoxy(4+4*counter2,3+2*counter1);
                                    printf("%c%c%c",205,205,205);
                                    goto forced;

                                }else if (grid[2*counter1+1][2*counter2+2] == 'C'){ //right
                                            score_4[counter1][counter2]++;
                                            grid[2*counter1+1][2*counter2+2] = name;
                                            gotoxy(7+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;
                                }


                        }else if(counter1 == number_of_boxes-1 && counter2 == 0){

                               if(grid[2*counter1+1][2*counter2] == 'C'){ //left
                                           score_4[counter1][counter2]++;
                                            grid[2*counter1+1][2*counter2] = name;
                                            gotoxy(3+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;

                                }else if (grid[2*counter1+2][2*counter2+1] == 'C'){ //down
                                             score_4[counter1][counter2]++;
                                            grid[2*counter1+2][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,5+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;
                                }

                        }else if(counter1 == number_of_boxes-1 && counter2 == number_of_boxes-1){

                                if(grid[2*counter1+1][2*counter2+2] == 'C'){//right
                                           score_4[counter1][counter2]++;
                                            grid[2*counter1+1][2*counter2+2] = name;
                                            gotoxy(7+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;


                                }else if(grid[2*counter1+2][2*counter2+1] == 'C'){//down
                                            score_4[counter1][counter2]++;
                                            grid[2*counter1+2][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,5+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;


                                }

                        }else if(counter1 == 0 && counter2 != 0 && counter2 != number_of_boxes-1 &&grid[2*counter1][2*counter2+1] == 'C'){

                               //up

                                   score_4[counter1][counter2]++;
                                    grid[2*counter1][2*counter2+1] = name;
                                    gotoxy(4+4*counter2,3+2*counter1);
                                    printf("%c%c%c",205,205,205);
                                    goto forced;




                        }else if(counter1 == number_of_boxes-1 && counter2 != 0 && counter2 != number_of_boxes-1&&grid[2*counter1+2][2*counter2+1] == 'C'){
                           //down
                                            score_4[counter1][counter2]++;
                                            grid[2*counter1+2][2*counter2+1] = name;
                                            gotoxy(4+4*counter2,5+2*counter1);
                                            printf("%c%c%c",205,205,205);
                                            goto forced;






                        }else if(counter2 == 0 && counter1 != 0 && counter1 != number_of_boxes-1&&grid[2*counter1+1][2*counter2] == 'C'){

                              //left

                                          score_4[counter1][counter2]++;
                                            grid[2*counter1+1][2*counter2] = name;
                                            gotoxy(3+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;





                        }else if(counter2 == number_of_boxes-1 && counter1 != 0 && counter1 != number_of_boxes-1&&grid[2*counter1+1][2*counter2+2] == 'C'){

                               //right
                                          score_4[counter1][counter2]++;
                                            grid[2*counter1+1][2*counter2+2] = name;
                                            gotoxy(7+4*counter2,4+2*counter1);
                                            printf("%c",186);
                                            goto forced;


                        }
        }
    }
}


for(counter1 =0 ;counter1 < number_of_boxes;counter1++){
    for(counter2 =0 ;counter2 < number_of_boxes;counter2++){
        if(score_4[counter1][counter2]==2){
            score_4[counter1][counter2]++;
            edit_drawing(counter1,counter2,number_of_boxes);
            goto forced;
        }

    }
}
forced ://end of computer turn
gotoxy(38,27);
printf("AI WILL BEAT YOU");

}

//[1]drawing the choice of computer on console
//[2]increasing the array score_4
//[3] using [1] to fill the grid array (simulation array)

void edit_drawing(int row_score,int col_score,int size_of_box,char name){
int r = 2*row_score;
int c = (2*col_score) +1;
int counter3=0;
if(grid[r][c] == 'C'){          //up
    grid[r][c] = name;

    gotoxy((3+1)+4*col_score,3+2*row_score);
    for(counter3 =0;counter3<3;counter3++) printf("%c",205);

    if(row_score != 0 ) score_4[row_score-1][col_score]++;


}else if(grid[r+1][c+1] == 'C'){    //Right
        grid[r+1][c+1] = name;

        gotoxy((3+4)+4*(col_score),(3+1)+2*(row_score));
        for(counter3=0;counter3<1;counter3++){
        gotoxy((3+4)+4*(col_score),(3+counter3+1)+2*(row_score));printf("%c",186);
        }

        if(col_score != (size_of_box - 1) ) score_4[row_score][col_score+1]++;



}else if(grid[r+2][c] == 'C'){      //Down
        grid[r+2][c] = name;
///////////////y coordinate must be 5+2*row_score
        gotoxy((3+1)+4*(col_score),5+2*(row_score));for(counter3=0;counter3<3;counter3++)printf("%c",205);

        if(row_score != (size_of_box - 1) ) score_4[row_score+1][col_score]++;

}else if(grid[r-1][c-1] == 'C'){ //left
    /////////must be grid[r+1][c-1]
        grid[r+1][c-1] = name;

            gotoxy(3+4*(col_score),(3+1)+2*(row_score));
             for(counter3=0;counter3<1;counter3++){
             gotoxy(3+4*(col_score),(3+counter3+1)+2*(row_score));printf("%c",186);
             }


        if(col_score != 0 ) score_4[row_score][col_score-1]++;

}


}

void game_loop_vs_player(int size_game,int role){
//start of game:
                                                                                                int e,q;
                                                                                                reset();
                                                                                                opcl();
                                                                                                if(role==0){goto start_game;}
                                                                                                else if(role==1){goto player_1;}
                                                                                                else if(role==2){goto player_2;}


                                                                                                //edit here

                                                                                                start_game:

                                                                                                gotoxy(30,11);
                                                                                                red();
                                                                                                printf("Player  A name : ");
                                                                                                gets(player1.player_name);
                                                                                                cyan();
                                                                                                gotoxy(30,12);
                                                                                                printf("Player  B name : ");
                                                                                                gets(player2.player_name);
                                                                                                reset();
                                                                                                system("cls");
                                                                                                drawing_grid(size_game);
                                                                                                arr_start_grid(size_game);
                                                                                                riv(size_game);
                                                                                                s4n(size_game);
                                                                                                printf("\n");
                                                                                                //  Game loop
                                                                                                start = clock();
                                                                                                gotoxy(35,7);
                                                                                                printf("Time since starting %d : %d",minutes,seconds);
                                                                                                Total_remaining=2*size_game*(size_game+1);
                                                                                                while(Total_remaining>0){

                                                                                                    player_1:

                                                                                                        //scan_print_file(0,'w');
                                                                                                        gotoxy(1,15);printf("for continue [1]....undo[2]....redo[3]....save game[4] :");
                                                                                                        four_choices=scan_valid_integer(4,-3);
                                                                                                        switch(four_choices){
                                                                                                        case 1:
                                                                                                            //continue
                                                                                                            scan_print_file(0,'w');
                                                                                                                if(roles_counter!=largest_role){
                                                                                                                                moving_for_undo(2*size_game*(size_game+1)-Total_remaining+1);
                                                                                                                                largest_role=roles_counter;
                                                                                                                }

                                                                                                           roles_AorB[roles_counter]='A';roles_counter++;largest_role++;

                                                                                                            goto cont1_cs1;
                                                                                                        break;
                                                                                                        case 2:
                                                                                                            //undo
                                                                                                            if(roles_AorB[roles_counter]=='C')scan_print_file(0,'w');
                                                                                                            roles_counter--;
                                                                                                            scan_print_file((2*size_game*(size_game+1)-Total_remaining)*8-7,'r');
                                                                                                            print_after_undo(size_game);
                                                                                                            print_info(1);
                                                                                                            if(roles_AorB[roles_counter]=='A')goto player_1;
                                                                                                            else if(roles_AorB[roles_counter]=='B')goto player_2;
                                                                                                        break;
                                                                                                        case 3:
                                                                                                            //redo
                                                                                                        break;
                                                                                                        case 4:
                                                                                                            //saving
                                                                                                            gotoxy(1,15);purple();printf("Enter [1]first file ....[2]second file....[3]third file :");reset();
                                                                                                            filenumber=scan_valid_integer(3,-3);
                                                                                                            saving(size_game,1);
                                                                                                            goto cont1_cs1;
                                                                                                        }


                                                                                                    cont1_cs1:


                                                                                                                for(q=0;q<11;q++){
                                                                                                                        gotoxy(40,20+q);
                                                                                                                    for(e=0;e<11;e++){
                                                                                                                        printf("%c ",grid[q][e]);
                                                                                                                    }printf("\n");


                                                                                                                }


                                                                                                      print_info(1);
                                                                                                      gotoxy(1,16);
                                                                                                      red();
                                                                                                      printf("%s's Turn : \n",player1.player_name);
                                                                                                      printf("Enter R1 R2 C1 C2 : \n");
                                                                                                      gotoxy(1,19);printf("Enter row 1:");
                                                                                                      row1=scan_valid_integer(size_game,1);
                                                                                                      gotoxy(1,20);printf("Enter row 2:");
                                                                                                      row2=scan_valid_integer(size_game,2);
                                                                                                      gotoxy(1,21);printf("Enter col 1:");
                                                                                                      col1=scan_valid_integer(size_game,3);
                                                                                                      gotoxy(1,22);printf("Enter col 2:");
                                                                                                      col2=scan_valid_integer(size_game,4);




                                                                                                     while(1){
                                                                                                         if(draw_lines(row1,row2,col1,col2,size_game,'A') == 1){
                                                                                                             gotoxy(1,18);for(counter=0;counter<50;counter++)printf(" ");
                                                                                                             player1.number_of_moves++;
                                                                                                               break;
                                                                                                             }
                                                                                                         else if(draw_lines(row1,row2,col1,col2,size_game,'A') == 2) goto cont1_cs1;
                                                                                                     }


                                                                                                    //scan_print_file(0,'w');




                                                                                                    check_score(&checkScore,&row_cc,&col_cc,&row_cc1,&col_cc1,size_game,'A');
                                                                                                    if( checkScore == 1 ){
                                                                                                            player1.score++;
                                                                                                            //change the color of the box:
                                                                                                            red();
                                                                                                            color_box(row_cc,col_cc);
                                                                                                            gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("A");
                                                                                                            delete_common(size_game,'A');
                                                                                                            reset();
                                                                                                            Total_remaining--;
                                                                                                        //scan_print_file(0,'w');


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
                                                                                                        delete_common(size_game,'A');
                                                                                                        reset();
                                                                                                        Total_remaining--;
                                                                                                        //scan_print_file(0,'w');

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
                                                                                                    //scan_print_file(0,'w');
                                                                                                    if(Total_remaining == 0){
                                                                                                        goto after_game;
                                                                                                        break;

                                                                                                    }




                                                                                                    //**player2
                                                                                                   player_2:

                                                                                                                    //scan_print_file(0,'w');
                                                                                                                    gotoxy(1,15);printf("for continue[1]....undo[2]....redo[3]....save game[4]:");
                                                                                                                    four_choices=scan_valid_integer(4,-3);
                                                                                                                    switch(four_choices){
                                                                                                                    case 1:
                                                                                                                        //continue
                                                                                                                            scan_print_file(0,'w');
                                                                                                                            if(roles_counter!=largest_role){
                                                                                                                                    moving_for_undo(2*size_game*(size_game+1)-Total_remaining+1);
                                                                                                                                        largest_role=roles_counter;
                                                                                                                            }


                                                                                                                        roles_AorB[roles_counter]='B';roles_counter++;largest_role++;
                                                                                                                        goto cont2_cs1;
                                                                                                                    break;
                                                                                                                    case 2:
                                                                                                                        //undo
                                                                                                                        if(roles_AorB[roles_counter]=='C')scan_print_file(0,'w');
                                                                                                                        roles_counter--;
                                                                                                                        scan_print_file((2*size_game*(size_game+1)-Total_remaining)*8-7,'r');
                                                                                                                        print_after_undo(size_game);
                                                                                                                        print_info(1);
                                                                                                                            if(roles_AorB[roles_counter]=='A')goto player_1;
                                                                                                                            else if(roles_AorB[roles_counter]=='B')goto player_2;
                                                                                                                    break;
                                                                                                                    case 3:
                                                                                                                        //redo

                                                                                                                    break;
                                                                                                                    case 4:
                                                                                                                                gotoxy(1,15);purple();printf("Enter [1]first file ....[2]second file....[3]third file :");reset();
                                                                                                                                filenumber=scan_valid_integer(3,-3);
                                                                                                                                saving(size_game,2);
                                                                                                                                goto cont2_cs1;
                                                                                                                    break;
                                                                                                                    }

                                                                                                        cont2_cs1:


                                                                                                            for(q=0;q<11;q++){
                                                                                                                        gotoxy(40,20+q);
                                                                                                                    for(e=0;e<11;e++){
                                                                                                                        printf("%c ",grid[q][e]);
                                                                                                                    }printf("\n");


                                                                                                                }




                                                                                                      print_info(1);
                                                                                                      gotoxy(1,16);
                                                                                                      cyan();
                                                                                                      printf("%s's Turn : \n",player2.player_name);
                                                                                                      printf("Enter R1 R2 C1 C2 : \n");
                                                                                                        gotoxy(1,19);printf("Enter row 1:");
                                                                                                      row1=scan_valid_integer(size_game,1);
                                                                                                      gotoxy(1,20);printf("Enter row 2:");
                                                                                                      row2=scan_valid_integer(size_game,2);
                                                                                                      gotoxy(1,21);printf("Enter col 1:");
                                                                                                      col1=scan_valid_integer(size_game,3);
                                                                                                      gotoxy(1,22);printf("Enter col 2:");
                                                                                                      col2=scan_valid_integer(size_game,4);




                                                                                                     while(1){
                                                                                                         if(draw_lines(row1,row2,col1,col2,size_game,'B') == 1){
                                                                                                             gotoxy(1,18);for(counter=0;counter<50;counter++)printf(" ");
                                                                                                             player2.number_of_moves++;
                                                                                                               break;
                                                                                                             }
                                                                                                         else if(draw_lines(row1,row2,col1,col2,size_game,'B') == 2) goto cont2_cs1;
                                                                                                     }


                                                                                                        //scan_print_file(0,'w');

                                                                                                      check_score(&checkScore,&row_cc,&col_cc,&row_cc1,&col_cc1,size_game,'B');
                                                                                                    if( checkScore == 1 ){
                                                                                                            player2.score++;
                                                                                                            //change the color of the box:
                                                                                                            cyan();
                                                                                                            color_box(row_cc,col_cc);
                                                                                                            gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("B");
                                                                                                            delete_common(size_game,'B');
                                                                                                            reset();
                                                                                                            Total_remaining--;
                                                                                                            //scan_print_file(0,'w');
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
                                                                                                        delete_common(size_game,'B');
                                                                                                        reset();
                                                                                                        Total_remaining--;
                                                                                                        //scan_print_file(0,'w');
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
                                                                                                    //scan_print_file(0,'w');
                                                                                                   if(Total_remaining == 0){
                                                                                                        goto after_game;
                                                                                                        break;
                                                                                                   }
                                                                                                }
                                                                                                after_game:
                                                                                                 print_info(1); // to update info after the final line
                                                                                                //determining winner
                                                                                                Ent_new_score();
                                                                                                gotoxy(1,25);
                                                                                                purple();
                                                                                                if(player1.score > player2.score){
                                                                                                   printf("The winner is : %s",player1.player_name);
                                                                                                   }
                                                                                                else if(player1.score < player2.score)
                                                                                                    printf("The winner is : %s",player2.player_name);
                                                                                                else if(player1.score == player2.score) printf("There are no winner the game is draw ");




//end of game
}

void game_loop_vs_AI(int size_AI,int role){
                                            reset();
                                            int e,q;

                                             if(role==3){goto startgame;}
                                            else if(role==4){goto player1;}
                                            else if(role==5){goto AI;}

                                            startgame:

                                            gotoxy(30,11);
                                            red();
                                            printf("Player  A name : ");
                                            gets(player1.player_name);
                                            reset();
                                            player2.player_name[100]="computer";
                                            system("cls");
                                            drawing_grid(size_AI);
                                            arr_start_grid(size_AI);
                                            s4n(size_AI);
                                            printf("\n");
                                            //game loop
                                            start = clock();
                                            gotoxy(35,7);
                                            printf("Time since starting %d : %d",minutes,seconds);
                                            Total_remaining=2*size_AI*(size_AI+1);
                                            while(Total_remaining>0){

                                                player1:


                                                gotoxy(1,15);printf("for continue [1]....undo[2]....redo[3]....save game[4] :");
                                               four_choices=scan_valid_integer(4,-3);
                                                  switch(four_choices){
                                                                                                        case 1:
                                                                                                            goto cont_1_cs1;
                                                                                                        break;
                                                                                                        case 2:
                                                                                                            //undo
                                                                                                        break;
                                                                                                        case 3:
                                                                                                            //redo
                                                                                                        break;
                                                                                                        case 4:
                                                                                                            gotoxy(1,15);purple();printf("Enter [1]first file ....[2]second file....[3]third file :");reset();
                                                                                                            filenumber=scan_valid_integer(3,-3);
                                                                                                            saving(size_AI,4);
                                                                                                            goto cont_1_cs1;
                                                                                                        break;
                                                                                                        }


                                                  cont_1_cs1:


                                                  print_info(0);
                                                  gotoxy(1,16);
                                                  red();
                                                  printf("%s's Turn : \n",player1.player_name);
                                                  printf("Enter R1 R2 C1 C2 : \n");

                                                  gotoxy(1,19);printf("Enter row 1:");
                                                  row1=scan_valid_integer(size_AI,1);
                                                  gotoxy(1,20);printf("Enter row 2:");
                                                  row2=scan_valid_integer(size_AI,2);
                                                  gotoxy(1,21);printf("Enter col 1:");
                                                  col1=scan_valid_integer(size_AI,3);
                                                  gotoxy(1,22);printf("Enter col 2:");
                                                  col2=scan_valid_integer(size_AI,4);



                                                 while(1){
                                                     if(draw_lines(row1,row2,col1,col2,size_AI,'A') == 1){
                                                         gotoxy(1,18);for(counter=0;counter<50;counter++)printf(" ");
                                                         player1.number_of_moves++;
                                                           break;
                                                         }
                                                     else if(draw_lines(row1,row2,col1,col2,size_AI,'A') == 2) goto cont_1_cs1;
                                                 }


                                                         for(q=0;q<size_AI*2 +1;q++){
                                                                gotoxy(19,20+q);
                                                                for(e=0;e<size_AI*2 +1;e++){
                                                                                    printf("%c ",grid[q][e]);
                                                                }
                                                        }


                                                check_score(&checkScore,&row_cc,&col_cc,&row_cc1,&col_cc1,size_AI,'A');
                                                if( checkScore == 1 ){
                                                        player1.score++;
                                                        //change the color of the box:
                                                        red();
                                                        color_box(row_cc,col_cc);
                                                        gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("A");
                                                        delete_common(size_AI,'A');
                                                        reset();
                                                        Total_remaining--;
                                                        if(Total_remaining ==0){
                                                            goto afterGame;
                                                        }
                                                    goto player1;
                                                }
                                                if(checkScore==2){
                                                    player1.score+=2;
                                                    red();
                                                    color_box(row_cc,col_cc);
                                                    gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("A");
                                                    color_box(row_cc1,col_cc1);
                                                    gotoxy((3+2)+4*(col_cc1),(3+1)+2*(row_cc1));printf("A");
                                                    delete_common(size_AI,'A');
                                                    reset();
                                                    Total_remaining--;


                                                        if(Total_remaining ==0){
                                                            goto afterGame;
                                                        }
                                                        goto player1;
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
                                                    goto afterGame;
                                                    break;

                                                }
                                                AI:
                                                    print_info(0);
                                                    gotoxy(1,16);
                                                    cyan();
                                                    printf("%s's Turn : \n",player2.player_name);
                                                    computer(size_AI,'B');/********************************************/

                                                    check_score(&checkScore,&row_cc,&col_cc,&row_cc1,&col_cc1,size_AI,'B');
                                                if( checkScore == 1 ){
                                                        player2.score++;
                                                        //change the color of the box:
                                                        cyan();
                                                        color_box(row_cc,col_cc);
                                                        gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("B");
                                                        delete_common(size_AI,'B');
                                                        reset();
                                                        Total_remaining--;
                                                        if(Total_remaining ==0){
                                                            goto afterGame;
                                                        }
                                                    goto AI;
                                                }
                                                if(checkScore==2){
                                                    player2.score+=2;
                                                    cyan();
                                                    color_box(row_cc,col_cc);
                                                    gotoxy((3+2)+4*(col_cc),(3+1)+2*(row_cc));printf("B");
                                                    color_box(row_cc1,col_cc1);
                                                    gotoxy((3+2)+4*(col_cc1),(3+1)+2*(row_cc1));printf("B");
                                                    delete_common(size_AI,'B');
                                                    reset();
                                                    Total_remaining--;
                                                        if(Total_remaining ==0){
                                                            goto afterGame;
                                                        }

                                                        goto AI;
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
                                                    goto afterGame;
                                                    break;

                                                }




                                            }//after game loop
                                                afterGame:
                                             print_info(0); // to update info after the final line
                                            //determining winner
                                            gotoxy(1,25);
                                            purple();
                                            if(player1.score > player2.score){
                                               printf("The winner is : %s",player1.player_name);
                                               Ent_new_score();
                                               }
                                            else if(player1.score < player2.score)
                                                printf("The winner is : %s",player2.player_name);
                                            else if(player1.score == player2.score) printf("There are no winner the game is draw ");

                                            printf("the first selection");


}


char line[256];
char score_4_edit[5][5];
int num1_temp;
void opcl(void){
    FILE *op;
    op=fopen("undo1.txt","w");
    fclose(op);
}
void scan_print_file(int x,char rw){
    if(rw=='r'){
            FILE *undo1;undo1=fopen("undo1.txt","r");
            getline_scanfromfile(x,undo1);
    }else if(rw=='w'){
            FILE *undo1;undo1=fopen("undo1.txt","a");
            getline_printinfile(undo1);
    }
}
void getline_scanfromfile(int x,FILE *undo){
    int e,q;
    for(e=1;e<x;e++){fscanf(undo,"%s",line);fscanf(undo,"\n");}
    //for grid scaning
            for(q=0;q<11;q++){for(e=0;e<11;e++){fscanf(undo,"%c",&grid[q][e]);}}fscanf(undo,"\n");
            for(q=0;q<5;q++){for(e=0;e<5;e++){fscanf(undo,"%c",&score_4_edit[q][e]);}}fscanf(undo,"\n");
            for(q=0;q<5;q++){for(e=0;e<5;e++){fscanf(undo,"%c",&score_4_name[q][e]);}}fscanf(undo,"\n");
    //for total remaining
            fscanf(undo,"%d",&Total_remaining);fscanf(undo,"\n");
            fscanf(undo,"%d",&(player1.number_of_moves));fscanf(undo,"\n");
            fscanf(undo,"%d",&(player2.number_of_moves));fscanf(undo,"\n");
            fscanf(undo,"%d",&(player1.score));fscanf(undo,"\n");
            fscanf(undo,"%d",&(player2.score));fscanf(undo,"\n");
fclose(undo);
    for(q=0;q<5;q++){for(e=0;e<5;e++){score_4[q][e]=score_4_edit[q][e]-48;}}
}
void getline_printinfile(FILE *undo){
        int e,q;
    //edit of score4
    for(q=0;q<5;q++){for(e=0;e<5;e++){score_4_edit[q][e]=score_4[q][e]+48;}}
    //for arrays req
            for(q=0;q<11;q++){for(e=0;e<11;e++){fprintf(undo,"%c",grid[q][e]);}}fprintf(undo,"\n");
            for(q=0;q<5;q++){for(e=0;e<5;e++){fprintf(undo,"%c",score_4_edit[q][e]);}}fprintf(undo,"\n");
            for(q=0;q<5;q++){for(e=0;e<5;e++){fprintf(undo,"%c",score_4_name[q][e]);}}fprintf(undo,"\n");
    //for number req
            fprintf(undo,"%d",Total_remaining);fprintf(undo,"\n");
            fprintf(undo,"%d",(player1.number_of_moves));fprintf(undo,"\n");
            fprintf(undo,"%d",(player2.number_of_moves));fprintf(undo,"\n");
            fprintf(undo,"%d",(player1.score));fprintf(undo,"\n");
            fprintf(undo,"%d",(player2.score));fprintf(undo,"\n");
fclose(undo);
}
void moving_for_undo(int endoftext){
    FILE *undo1;FILE *undo2;
    undo1=fopen("undo1.txt","r");undo2=fopen("undo2.txt","w");
    int e,q;
 for(q=0;q<endoftext;q++){
    for(e=0;e<3;e++){fscanf(undo1,"%s",line);fscanf(undo1,"\n");fprintf(undo2,"%s",line);fprintf(undo2,"\n");}
    for(e=0;e<5;e++){fscanf(undo1,"%d",&num1_temp);fscanf(undo1,"\n");fprintf(undo2,"%d",num1_temp);fprintf(undo2,"\n");}
    }
    fclose(undo1);fclose(undo2);
    FILE *undo3;FILE *undo4;
    undo3=fopen("undo1.txt","w");undo4=fopen("undo2.txt","r");
 for(q=0;q<endoftext;q++){
    for(e=0;e<3;e++){fscanf(undo4,"%s",line);fscanf(undo4,"\n");fprintf(undo3,"%s",line);fprintf(undo3,"\n");}
    for(e=0;e<5;e++){fscanf(undo4,"%d",&num1_temp);fscanf(undo4,"\n");fprintf(undo3,"%d",num1_temp);fprintf(undo3,"\n");}
    }
    fclose(undo3);fclose(undo4);

}

#endif
