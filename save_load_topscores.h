#ifndef SLT
#define SLT
#include "save_load_topscores.c"

void saving(int size_game,int role);
void fn_save(int size_game,int role,FILE *file);
void loading(void);
void fn_load(FILE *fileload);
void topscore_names_scores(void);
void Ent_new_score(void);
void fn_edit_top(char req_name[],int req_score);

#endif
