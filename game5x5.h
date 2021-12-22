#include <stdio.h>
#include <string.h>
#include <math.h>
void drawing_grid5x5(void){
    
    int i,j;
    for(i=0;i<=10;i=i+2){
        gotoxy(3,3+i);
        for(j=0;j<=20;j=j+4){
            gotoxy(3+j,3+i);
            printf("%c",254);
        }
    }

    for(i=0;i<=10;i=i+2){gotoxy(2,3+i);printf("%d",(i/2)+1);}
    for(j=0;j<=20;j=j+4){gotoxy(3+j,2);printf("%d",(j/4)+1);}
}


void game_box5x5(void){
    int i,j;
    //start of box
    gotoxy(1,17);
    printf("%c",201);
    for(i=1;i<=5;i++)printf("%c",205);
    printf("%c",187);


   for(i=0;i<5;i++){
       gotoxy(1,18+i);
       printf("%c",186);
       for(j=0;j<5;j++){printf(" ");
       printf("%c",186);
       }
   }
    gotoxy(1,23);
    printf("%c",200);
    for(i=1;i<=5;i++)printf("%c",205);
    printf("%c",188);
}


int choice_menu5x5(void)
{
    
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    int pos=1;
    char ch;
    
    
    do
    {
        SetConsoleTextAttribute(console,15);
        
        gotoxy(2,18);printf(" [1] ");
        gotoxy(2,19);printf(" [2] ");
        gotoxy(2,20);printf(" [3] ");
        gotoxy(2,21);printf(" [4] ");
        gotoxy(2,22);printf(" [5] ");
        switch(pos)
        {
            case 1:SetConsoleTextAttribute(console,12);gotoxy(2,18);printf(" [1] ");break;
            case 2:SetConsoleTextAttribute(console,12);gotoxy(2,19);printf(" [2] ");break;
            case 3:SetConsoleTextAttribute(console,12);gotoxy(2,20);printf(" [3] ");break;
            case 4:SetConsoleTextAttribute(console,12);gotoxy(2,21);printf(" [4] ");break;
            case 5:SetConsoleTextAttribute(console,12);gotoxy(2,22);printf(" [5] ");break;

        }
        ch=getch(); 
        if(ch==72)
        {
            pos--;
            if(pos==0)pos=5;
        }
        if(ch==80)
        {
            pos++;
            if(pos==6)pos=1;
        }
        
    }while(ch!=13);
    gotoxy(1,21);
    reset();
    return pos;


}

int score_4_5x5 [5][5]={0};


char grid5x5[11][11] ={{254,' ',254,' ',254,' ',254,' ',254,' ',254},
                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                     {254,' ',254,' ',254,' ',254,' ',254,' ',254},
                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                     {254,' ',254,' ',254,' ',254,' ',254,' ',254},
                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                     {254,' ',254,' ',254,' ',254,' ',254,' ',254},
                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                     {254,' ',254,' ',254,' ',254,' ',254,' ',254},
                     {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
                     {254,' ',254,' ',254,' ',254,' ',254,' ',254}
                    };


int draw_lines5x5(int r1,int r2 ,int c1, int c2){
    int indc=0,indr=0,c=0,r=0; // the index when start drawing the lines ,  indc is index of x axis , indr is the index of y axis 
    int i=0,ct=0,rt=0;
    
   
    if (r1 ==r2 && abs(c1-c2)==1){
        ct= c1>c2 ? c2 : c1;
            if(grid2x2[(r1-1)*2][(ct-1)*2+1]==' '){
                c= c1>c2 ? c2 : c1;
                indr =3+2*(r1-1);
                indc =3+4*(c-1);
                gotoxy(indc+1,indr);
                for(i=0;i<3;i++)  printf("%c",205);
                grid2x2[(r1-1)*2][(ct-1)*2+1]=205;
                reset();
                /*if(r1==1 && ct==1)  score_4[0][0]++;
                else if(r1==1 && ct==2)  score_4[0][1]++;
                else if(r1==2 && ct==1)  {score_4[0][0]++;score_4[1][0]++;}
                else if(r1==2 && ct==2)  {score_4[0][1]++;score_4[1][1]++;}
                else if(r1==3 && ct==1)  score_4[1][0]++;
                else if(r1==3 && ct==2)  score_4[1][1]++;
                */
                
                return 1;
            }else goto else1;
        
    }
    else if(c1 ==c2 && abs(r1-r2)==1){
        rt= r1>r2 ? r2 : r1;
        if(grid2x2[(rt-1)*2+1][(c1-1)*2]==' '){
        r= r1>r2 ? r2 : r1;
        indc =3+4*(c1-1);
        indr =3+2*(r-1);
        for(i=0;i<2;i++){gotoxy(indc,indr+1+i); printf("%c",186);}
        grid2x2[(rt-1)*2+1][(c1-1)*2]=186;
        reset();
                /*if(c1==1 && rt==1)  score_4[0][0]++;
                else if(c1==1 && rt==2)  score_4[1][0]++;
                else if(c1==2 && rt==1)  {score_4[0][0]++;score_4[0][1]++;}
                else if(c1==2 && rt==2)  {score_4[1][0]++;score_4[1][1]++;}
                else if(c1==3 && rt==1)  score_4[0][1]++;
                else if(c1==3 && rt==2)  score_4[1][1]++;
                */      
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
