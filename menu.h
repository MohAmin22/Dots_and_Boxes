#ifndef MENU
#define MENU
#include "menu.c"
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include<time.h>
//the colors

void welcome(void);
void red ();
void cyan (void);
void purple(void);
void reset (void);
void gotoxy(int x,int y);
//the code of the starting of the main menu
void box(int a);
int main_menu(void);
int level_menu(void);
//the menu of vs
int vs_menu(void);
//game edit:
void game_box(void);
int choice_menu(void);
void saving(int size_game,int role);
void fn_save(int size_game,int role,FILE *file);
void loading(void);
void fn_load(FILE *fileload);
void topscore_names_scores(void);
void Ent_new_score(void);
void fn_edit_top(char req_name[],int req_score);
void print_after_undo(int sizeload);


#endif // end of menu
