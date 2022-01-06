#ifndef GAME
#define GAME
#include "game_loop_and_AI.c"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

void riv(int sizegame);
void print_info(int z);
//end of vs comp definitions
void s4n(int n);
void arr_start_grid(int n);
void drawing_grid(int a);
int draw_lines(int r1,int r2 ,int c1, int c2,int size_of_game,char name);
/*********************** UNDO & REDO FUNCTIONS ************************************/
void undo_del_all(int r1,int r2,int c1,int c2,int size_of_game);
void redo_1(int r1,int r2,int c1,int c2,int size_of_game,char name);
/////////for deleting the repeated line in both two boxes
void delete_ver(int y,int z);
void delete_hor(int y,int z);
void delete_common(int num_boxes,char name);
void check_score(int *ch,int *row,int *col,int *k1,int *k2,int size,char name);
int scan_valid_integer(int max_num,int q,int start);
void color_box(int a1,int a2);
//start of Ai
//determining which box the AI will play in
void computer (int number_of_boxes,char name);
//[1]drawing the choice of computer on console
//[2]increasing the array score_4
//[3] using [1] to fill the grid array (simulation array)
void edit_drawing(int row_score,int col_score,int size_of_box,char name);
void game_loop_vs_player(int size_game,int role);
void game_loop_vs_AI(int size_AI,int role);
void scan_print_file(int x,char rw,int reqsize);
void getline_printinfile(FILE *undo,int reqsize);
#endif
