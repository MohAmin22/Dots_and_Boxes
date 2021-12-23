#include <stdio.h>
#include <string.h>
#include "game5x5.h"
#include <math.h>

int score_4 [9][9]={0};
char grid[20][20]={0} ;
void arr_start_grid(int n){

int k,j;
for(k=0;k<(2*n+1);k++){
    if(k%2==1){for(j=0;j<(2*n+1);j++)grid[k][j]=' ';}
    else{
            for(j=0;j<(2*n+1);j++){
                if(j%2==0)grid[k][j]=254;
                else grid[k][j]=' ';
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

int draw_lines2x2(int r1,int r2 ,int c1, int c2,int size_of_game){
    int indc=0,indr=0,c=0,r=0; // the index when start drawing the lines ,  indc is index of x axis , indr is the index of y axis
    int i=0,ct=0,rt=0;


    if (r1 ==r2 && abs(c1-c2)==1){
        ct= c1>c2 ? c2 : c1;
            if(grid[(r1-1)*2][(ct-1)*2+1]==' '){
                 c= c1>c2 ? c2 : c1;
                indr =3+2*(r1-1);
                indc =3+4*(c-1);
                gotoxy(indc+1,indr);
                for(i=0;i<3;i++)  printf("%c",205);
                grid[(r1-1)*2][(c-1)*2+1]=205;
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
        if(grid[(rt-1)*2+1][(c1-1)*2]==' '){
         r= r1>r2 ? r2 : r1;
        indc =3+4*(c1-1);
        indr =3+2*(r-1);
        for(i=0;i<1;i++){gotoxy(indc,indr+1+i); printf("%c",186);}
        grid[(r-1)*2+1][(c1-1)*2]=186;
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
        gotoxy(1,16);
        printf("please enter a valid coordinates :");
        return 2;
     }
}

void check_score(int *ch,int *row,int *col,int *k1,int *k2){
    int i,j=0;
    *ch=0,*row=-1,*col=-1,*k1==-1,*k2==-1;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            if(score_4[i][j] ==4 ){
                score_4[i][j] = 6;
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
            printf("                                                                                                                               ");
            return (x-48);
            break;
        }else {

             gotoxy(1,19+(q-1));
             printf("                                                                                                                       ");
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
