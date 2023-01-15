#include <stdio.h>
#include <stdlib.h>
#define column_size 3
#define row_size 5
void reset(int a[row_size][column_size]);

int main(){

    int a[row_size][column_size];

    

    return 0;
}

void reset(int a[row_size][column_size]){   
for(int i = 0;i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
            a[i][j] = 0;
        }
    }
}