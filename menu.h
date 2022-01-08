#ifndef MENU
#define MENU
#include "menu.c"
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include<time.h>
//the colors


void red ();
void cyan (void);
void purple(void);
void red_box(void);
void cyan_box (void);
void reset (void);
void gotoxy(int x,int y);
//the code of the starting of the main menu
void box(int a);
int main_menu(void);
int level_menu(void);
//the menu of vs
int vs_menu(void);

#endif // end of menu
