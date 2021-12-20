#include <stdio.h>

int main(){
    do{
    gotoxy(3,20);
    int row1,row2,col1,col2;
    printf("enter row1 row2 column1 column2");
    scanf("%d %d %d %d",&row1,&row2,&col1,&col2);
    if(row1>=1 && row1<=3 && row2>=1 && row2<=3 && col1>=1 && col1<=3 && col2>=1 && col2<=3){
        if((row1==row2)||(col1==col2)){

        }
    }

    }while()
    return 0;
}