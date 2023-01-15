#include <stdio.h>
#include <stdlib.h>
#define column_size 3
#define row_size 5
void reset(int a[row_size][column_size]);
void getpositive(float *n);

int main(){
    //intialization variables 
    int a[row_size][column_size];

    //Write menu
    printf("");


    return 0;
}

void reset(int a[row_size][column_size]){   
for(int i = 0;i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
            a[i][j] = 0;
        }
    }
}
void getpositive(float *n){
    do{
        printf("\nEnter: ");
        scanf("%f", &*n);
        if(*n<0){
            printf("\nThe answer is incorrect!Please enter again!");
        }
    }while(*n<0);
}