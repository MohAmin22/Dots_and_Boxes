#include <stdio.h>
#include <string.h>
#include "game5x5.h"
#include <math.h>

int score_4 [2][2]={0};

char grid2x2[5][5] ={{254,' ',254,' ',254},
                     {' ',' ',' ',' ',' '},
                     {254,' ',254,' ',254},
                     {' ',' ',' ',' ',' '},
                     {254,' ',254,' ',254}};


void drawing_2x2grid(void){
    // first box in the first row
    gotoxy(3,2);printf("%d",1);
    gotoxy(2,3);printf("%d",1);
    gotoxy(13,2);printf("%d",2);
    gotoxy(2,8);printf("%d",2);
    gotoxy(23,2);printf("%d",3);
    gotoxy(2,13);printf("%d",3);
    
    gotoxy(3,3);printf("%c",254);
    //the middle box in the first row
    
    gotoxy(13,3);printf("%c",254);
    //the the third and the last box in the first row
    
    gotoxy(23,3);printf("%c",254);

    //row 2 column 1
    
    gotoxy(3,8);printf("%c",254);
    //row 2 column 2
    gotoxy(13,8);printf("%c",254);
    //row 2 column 3
    gotoxy(23,8);printf("%c",254);


    // first box in the third and the last row
    
    gotoxy(3,13);printf("%c",254);
    // second box in the third and the last row
    gotoxy(13,13);printf("%c",254);
    // third box in the third and the last row
    gotoxy(23,13);printf("%c",254);



}



/*

int scan_valid_integer_1_or_2(){
 while(1){
    char input[1000];
    gets(input);
    char x = input[0];
    int y = strlen(input);
    if(y!=1 || (  (x-48)>2 && (x-48)<10)){
            printf("Enter a valid value :  ");

    }else{
        return (x-48);

    }
 }
}
*/
/*
void draw_lines_2x2 (int r1,int r2,int c1,int c2){
int i=0;
while(1){
if(r1 ==1 &&c1==1 && r2==1 && c2 ==2){  //hor   1
    if(grid2x2[0][1]==' '){
    gotoxy(4,3);
    for(i=0;i<9;i++)    printf("%c",205);
    grid2x2[0][1] = 205;
    }else goto else1;
}else if(r1 ==1 &&c1==1 && r2==2 && c2 ==1){ //ver  2 
    if(grid2x2[1][0]==' '){
    gotoxy(3,4);
    for(i=0;i<4;i++)    {gotoxy(3,4+i);printf("%c",186);}
    grid2x2[1][0] = 186;
    }else goto else1;
}else if(r1 ==2 &&c1==1 && r2==2 && c2 ==2){  //hor   3
    if(grid2x2[2][1]){
    gotoxy(4,8);
    for(i=0;i<9;i++)    printf("%c",205);
    grid2x2[2][1] = 205;
    }else goto else1;
}else if(r1 ==1 &&c1==2 && r2==2 && c2 ==2){  //ver 4
    gotoxy(4,3);
    for(i=0;i<9;i++)    printf("%c",205);
    grid2x2[0][1] = 205;

}else if(r1 ==1 &&c1==1 && r2==1 && c2 ==2){
    gotoxy(4,3);
    for(i=0;i<9;i++)    printf("%c",205);
    grid2x2[0][1] = 205;

}else if(r1 ==1 &&c1==1 && r2==1 && c2 ==2){
    gotoxy(4,3);
    for(i=0;i<9;i++)    printf("%c",205);
    grid2x2[0][1] = 205;

}else if(r1 ==1 &&c1==1 && r2==1 && c2 ==2){
    gotoxy(4,3);
    for(i=0;i<9;i++)    printf("%c",205);
    grid2x2[0][1] = 205;

}else if(r1 ==1 &&c1==1 && r2==1 && c2 ==2){
    gotoxy(4,3);
    for(i=0;i<9;i++)    printf("%c",205);
    grid2x2[0][1] = 205;

}else if(r1 ==1 &&c1==1 && r2==1 && c2 ==2){
    gotoxy(4,3);
    for(i=0;i<9;i++)    printf("%c",205);
    grid2x2[0][1] = 205;

}else if(r1 ==1 &&c1==1 && r2==1 && c2 ==2){
    gotoxy(4,3);
    for(i=0;i<9;i++)    printf("%c",205);
    grid2x2[0][1] = 205;

}else if(r1 ==1 &&c1==1 && r2==1 && c2 ==2){
    gotoxy(4,3);
    for(i=0;i<9;i++)    printf("%c",205);
    grid2x2[0][1] = 205;

}else if(r1 ==1 &&c1==1 && r2==1 && c2 ==2){
    gotoxy(4,3);
    for(i=0;i<9;i++)    printf("%c",205);
    grid2x2[0][1] = 205;

}else{
    else1:
}

}


} */

int draw_lines2x2(int r1,int r2 ,int c1, int c2){
    int indc=0,indr=0,c=0,r=0; // the index when start drawing the lines ,  indc is index of x axis , indr is the index of y axis 
    int i=0,ct=0,rt=0;
    
   
    if (r1 ==r2 && abs(c1-c2)==1){
        ct= c1>c2 ? c2 : c1;
            if(grid2x2[(r1-1)*2][(ct-1)*2+1]==' '){
                c= c1>c2 ? c2 : c1;
                indr =3+5*(r1-1);
                indc =3+10*(c-1);
                gotoxy(indc+1,indr);
                for(i=0;i<9;i++)  printf("%c",205);
                grid2x2[(r1-1)*2][(ct-1)*2+1]=205;
                reset();
                if(r1==1 && ct==1)  score_4[0][0]++;
                else if(r1==1 && ct==2)  score_4[0][1]++;
                else if(r1==2 && ct==1)  {score_4[0][0]++;score_4[1][0]++;}
                else if(r1==2 && ct==2)  {score_4[0][1]++;score_4[1][1]++;}
                else if(r1==3 && ct==1)  score_4[1][0]++;
                else if(r1==3 && ct==2)  score_4[1][1]++;

                
                return 1;
            }else goto else1;
        
    }
    else if(c1 ==c2 && abs(r1-r2)==1){
        rt= r1>r2 ? r2 : r1;
        if(grid2x2[(rt-1)*2+1][(c1-1)*2]==' '){
        r= r1>r2 ? r2 : r1;
        indc =3+10*(c1-1);
        indr =3+5*(r-1);
        for(i=0;i<4;i++){
            gotoxy(indc,indr+1+i); 
            printf("%c",186);
            }
        grid2x2[(rt-1)*2+1][(c1-1)*2]=186;
        reset();
                if(c1==1 && rt==1)  score_4[0][0]++;
                else if(c1==1 && rt==2)  score_4[1][0]++;
                else if(c1==2 && rt==1)  {score_4[0][0]++;score_4[0][1]++;}
                else if(c1==2 && rt==2)  {score_4[1][0]++;score_4[1][1]++;}
                else if(c1==3 && rt==1)  score_4[0][1]++;
                else if(c1==3 && rt==2)  score_4[1][1]++;
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
int check_score(void){
    int i,j=0,ch=0;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            if(score_4[i][j] ==4 ){
                score_4[i][j] = 6;
                ch=1;
            }
        }
    }
    return ch;
}