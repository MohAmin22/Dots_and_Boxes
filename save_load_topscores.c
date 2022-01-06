#include "save_load_topscores.h"
void saving(int size_game,int role){
        if(filenumber==1){
                 FILE *file1;
                file1=fopen("filegame1.txt","w");
                fn_save(size_game,role,file1);
        }
        else if(filenumber==2){
                    FILE *file2;
                    file2=fopen("filegame2.txt","w");
                    fn_save(size_game,role,file2);
        }
        else if(filenumber==3){
                    FILE *file3;
                    file3=fopen("filegame3.txt","w");
                    fn_save(size_game,role,file3);
        }
}

void fn_save(int size_game,int role,FILE *file){
 int e,q;
        fprintf(file,"%s",player1.player_name);fprintf(file,"\n");
        if(role==3||role==4||role ==5){fprintf(file,"computer");fprintf(file,"\n");}
        else{fprintf(file,"%s",player2.player_name);fprintf(file,"\n");}
        fprintf(file,"%d",player1.score);fprintf(file,"\n");
        fprintf(file,"%d",player2.score);fprintf(file,"\n");
        fprintf(file,"%d",player1.number_of_moves);fprintf(file,"\n");
        fprintf(file,"%d",player2.number_of_moves);fprintf(file,"\n");
        fprintf(file,"%d",Total_remaining);fprintf(file,"\n");
        fprintf(file,"%d",size_game);fprintf(file,"\n");
        fprintf(file,"%d",role);fprintf(file,"\n");

        for(q=0;q<2*size_game+1;q++){
            for(e=0;e<2*size_game+1;e++){
                fprintf(file,"%c",grid[q][e]);
            }
            fprintf(file,"\n");
        }

            fprintf(file,"\n");
        for(q=0;q<size_game;q++){
            for(e=0;e<size_game;e++){
                fprintf(file,"%d",score_4[q][e]);
                fprintf(file," ");
            }
        }

            fprintf(file,"\n");
         for(q=0;q<size_game;q++){
            for(e=0;e<size_game;e++){
                fprintf(file,"%c",score_4_name[q][e]);
            }
        }
        fclose(file);

}

void loading(void){
            if(filenumberload==1){
                 FILE *file1load;
                file1load=fopen("filegame1.txt","r");
                if(file1load==NULL){gotoxy(0,11);cyan();printf("the file is empty\nEnter [1]for mainmenu...Enter[2]for select another folder: ");backing_in_load=scan_valid_integer(2,12,0);}
                else if (file1load !=NULL  ) {
                        int temp;fseek (file1load, 0, SEEK_END);temp = ftell(file1load);
                        if (temp==0) {gotoxy(0,11);cyan();printf("the file is empty\nEnter [1]for mainmenu...Enter[2]for select another folder: ");backing_in_load=scan_valid_integer(2,12,0);}
                        else{fclose(file1load);file1load=fopen("filegame1.txt","r");fn_load(file1load);}
                }
        }
        else if(filenumberload==2){
                    FILE *file2load;
                    file2load=fopen("filegame2.txt","r");
                    if(file2load==NULL){gotoxy(0,11);cyan();printf("the file is empty\nEnter [1]for mainmenu...Enter[2]for select another folder: ");backing_in_load=scan_valid_integer(2,12,0);}
                    else if (file2load !=NULL  ) {
                        int temp;fseek (file2load, 0, SEEK_END);temp = ftell(file2load);
                        if (temp==0) {gotoxy(0,11);cyan();printf("the file is empty\nEnter [1]for mainmenu...Enter[2]for select another folder: ");backing_in_load=scan_valid_integer(2,12,0);}
                        else{fclose(file2load);file2load=fopen("filegame2.txt","r");fn_load(file2load);}
                }
        }
        else if(filenumberload==3){
                    FILE *file3load;
                    file3load=fopen("filegame3.txt","r");
                    if(file3load==NULL){gotoxy(0,11); cyan();printf("the file is empty\nEnter [1]for mainmenu...Enter[2]for select another folder: ");backing_in_load=scan_valid_integer(2,12,0);}
                    else if (file3load !=NULL  ) {
                        int temp;fseek (file3load, 0, SEEK_END);temp = ftell(file3load);
                        if (temp==0) {gotoxy(0,11);cyan();printf("the file is empty\nEnter [1]for mainmenu...Enter[2]for select another folder: ");backing_in_load=scan_valid_integer(2,12,0);}
                        else{fclose(file3load);file3load=fopen("filegame3.txt","r");fn_load(file3load);}
                }
        }
}


void fn_load(FILE *fileload){
        int rule;
        int sizeload;

        fscanf(fileload,"%s",player1.player_name);fscanf(fileload,"\n");
        fscanf(fileload,"%s",player2.player_name);fscanf(fileload,"\n");
        fscanf(fileload,"%d",&player1.score);fscanf(fileload,"\n");
        fscanf(fileload,"%d",&player2.score);fscanf(fileload,"\n");
        fscanf(fileload,"%d",&player1.number_of_moves);fscanf(fileload,"\n");
        fscanf(fileload,"%d",&player2.number_of_moves);fscanf(fileload,"\n");
        fscanf(fileload,"%d",&Total_remaining);fscanf(fileload,"\n");
        fscanf(fileload,"%d",&sizeload);fscanf(fileload,"\n");
        fscanf(fileload,"%d",&rule);fscanf(fileload,"\n");
        int e,q;
        for(q=0;q<2*sizeload+1;q++){
            for(e=0;e<2*sizeload+1;e++){
                fscanf(fileload,"%c",&grid[q][e]);
            }
            fscanf(fileload,"\n");
        }fscanf(fileload,"\n");

        for(q=0;q<sizeload;q++){
            for(e=0;e<sizeload;e++){
                fscanf(fileload,"%d",&score_4[q][e]);
                fscanf(fileload," ");
            }
        }

         fscanf(fileload,"\n");
        for(q=0;q<sizeload;q++){
            for(e=0;e<sizeload;e++){
                fscanf(fileload,"%c",&score_4_name[q][e]);
            }
        }

    fclose(fileload);

    //printing grid
    drawing_grid(sizeload);
        for(q=0;q<2*sizeload+1;q++){
            for(e=0;e<2*sizeload+1;e++){
                        if(q%2==0){
                            if(grid[q][e]=='A'){red();gotoxy(2+2*e,3+q);printf("%c%c%c",205,205,205);reset();}
                            else if(grid[q][e]=='B'){cyan();gotoxy(2+2*e,3+q);printf("%c%c%c",205,205,205);reset();}
                        }
                        else {
                                    if(grid[q][e]=='A'){red();gotoxy(3+2*e,3+q);printf("%c",186);reset();}
                                    else if(grid[q][e]=='B'){cyan();gotoxy(3+2*e,3+q);printf("%c",186);reset();}

                        }
            }
        }

         for(q=0;q<sizeload;q++){
            for(e=0;e<sizeload;e++){
                if(score_4_name[q][e]=='A'){red();gotoxy((3+2)+4*e,(3+1)+2*q);printf("A");color_box(q,e);reset();}
                else if(score_4_name[q][e]=='B'){cyan();gotoxy((3+2)+4*e,(3+1)+2*q);printf("B");color_box(q,e);reset();}
            }
         }

if(rule==3 || rule==4 ||rule ==5)game_loop_vs_AI(sizeload,rule);
else game_loop_vs_player(sizeload,rule);
}


int scores_values[10];
char names_wvalues[10][100];
int position=-1;


void topscore_names_scores(void){
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);


        char n[100];
        int sc=0,i;
        FILE *name;
        FILE *score;
        name=fopen("top_names.txt","r");
        score=fopen("top_scores.txt","r");
        SetConsoleTextAttribute(console,11);
        system("cls");gotoxy(0,0);
        for(i=1;i<=10;i++){
                    fscanf(name,"%s",n);fscanf(name,"\n");
                    fscanf(score,"%d",&sc);fscanf(score,"\n");
                    printf("[%d] %s              with score : %d\n",i,n,sc);
        }
        SetConsoleTextAttribute(console,15);
        fclose(name);
        fclose(score);
}

void Ent_new_score(void){
    int j,i,news=10;


    FILE *name;
    FILE *score;
    int temp_score;
    char temp_name[100];
    name=fopen("top_names.txt","r");
    score=fopen("top_scores.txt","r");
    for(i=0;i<10;i++){
        fscanf(score,"%d",&scores_values[i]);fscanf(score,"\n");
        fscanf(name,"%s",names_wvalues[i]);fscanf(name,"\n");
    }
    fclose(name);
    fclose(score);
    /*
    for(i=0;i<10;i++){
            //review two dimensional array of names
        printf("%s",names_wvalues[i]);printf(" ");
        printf(": %d",scores_values[i]);printf("\n");

    }
*/
    name=fopen("top_names.txt","w");
    score=fopen("top_scores.txt","w");
    if(player1.score>player2.score){
                        for(j=0;j<10;j++){
                            if((strcmp(player1.player_name,names_wvalues[j]))==0){news=j;goto contin1;}
                        }
                        contin1:
                        if(news==10){
                                fn_edit_top(player1.player_name,player1.score);
                                for(i=0;i<10;i++){
                                fprintf(score,"%d",scores_values[i]);fprintf(score,"\n");
                                fprintf(name,"%s",names_wvalues[i]);fprintf(name,"\n");
                                }
                        }else if(news!=10){
                                //
                                if(scores_values[news]<player1.score)
                                {
                                    scores_values[news]=player1.score;
                                            for(i=news-1;i>=0;i--){
                                                if(scores_values[i+1]>scores_values[i]){
                                                        temp_score=scores_values[i+1];
                                                        scores_values[i+1]=scores_values[i];
                                                        scores_values[i]=temp_score;

                                                        strcpy(temp_name,names_wvalues[i+1]);
                                                        strcpy(names_wvalues[i+1],names_wvalues[i]);
                                                        strcpy(names_wvalues[i],temp_name);
                                                }
                                            }



                                            for(i=0;i<10;i++){
                                                fprintf(score,"%d",scores_values[i]);fprintf(score,"\n");
                                                fprintf(name,"%s",names_wvalues[i]);fprintf(name,"\n");
                                            }
                                }else if(scores_values[news]>=player1.score){
                                    for(i=0;i<10;i++){
                                                fprintf(score,"%d",scores_values[i]);fprintf(score,"\n");
                                                fprintf(name,"%s",names_wvalues[i]);fprintf(name,"\n");
                                    }

                                }

                        }


    }


    else if(player2.score>player1.score){




                    for(j=0;j<10;j++){
                            if((strcmp(player2.player_name,names_wvalues[j]))==0){news=j;goto contin2;}
                        }
                        contin2:
                        if(news==10){
                                fn_edit_top(player2.player_name,player2.score);
                                for(i=0;i<10;i++){
                                fprintf(score,"%d",scores_values[i]);fprintf(score,"\n");
                                fprintf(name,"%s",names_wvalues[i]);fprintf(name,"\n");
                                }
                        }else if(news!=10){
                                //
                                if(scores_values[news]<player2.score)
                                {
                                    scores_values[news]=player2.score;
                                            for(i=news-1;i>=0;i--){
                                                if(scores_values[i+1]>scores_values[i]){
                                                        temp_score=scores_values[i+1];
                                                        scores_values[i+1]=scores_values[i];
                                                        scores_values[i]=temp_score;

                                                        strcpy(temp_name,names_wvalues[i+1]);
                                                        strcpy(names_wvalues[i+1],names_wvalues[i]);
                                                        strcpy(names_wvalues[i],temp_name);
                                                }
                                            }



                                            for(i=0;i<10;i++){
                                                fprintf(score,"%d",scores_values[i]);fprintf(score,"\n");
                                                fprintf(name,"%s",names_wvalues[i]);fprintf(name,"\n");
                                            }
                                }else if(scores_values[news]>=player2.score){
                                    for(i=0;i<10;i++){
                                                fprintf(score,"%d",scores_values[i]);fprintf(score,"\n");
                                                fprintf(name,"%s",names_wvalues[i]);fprintf(name,"\n");
                                    }

                                }

                        }





    /*    fn_edit_top(player2.player_name,ps2);
        for(i=0;i<10;i++){
            //review two dimensional array of names
        fprintf(score,"%d",scores_values[i]);fprintf(score,"\n");
        fprintf(name,"%s",names_wvalues[i]);fprintf(name,"\n");
    }
*/
    }else if(player2.score == player1.score){
      for(i=0;i<10;i++){

       fprintf(score,"%d",scores_values[i]);fprintf(score,"\n");
       fprintf(name,"%s",names_wvalues[i]);fprintf(name,"\n");
     }
    }
fclose(name);
fclose(score);

}



void fn_edit_top(char req_name[],int req_score){
                        for(i=0;i<10;i++){
                            if(req_score>scores_values[i]){position=i;goto movetop;}
                        }
                        movetop:
                                if(position!=-1){
                                            for(i=8;i>=position;i--){
                                                scores_values[i+1]=scores_values[i];
                                                strcpy(names_wvalues[i+1],names_wvalues[i]);
                                            }
                                            scores_values[position]=req_score;
                                            //names_wvalues[position][100]=player_name1;
                                            strcpy(names_wvalues[position],req_name);
                                }
}
