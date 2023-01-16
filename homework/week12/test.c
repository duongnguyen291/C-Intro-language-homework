#include <stdio.h>
#include <stdlib.h>
#define column_size 3
#define row_size 5
void reset(int a[row_size][column_size]);

int main(){
    int a = 10;
    int *p = &a; // 'p' points to 'a`
    int **pp = &p;
    printf("\n%5d %5d",a,&a);
    printf("\n%d",p);
    printf("\n%d",pp);

    return 0;
}

void reset(int a[row_size][column_size]){   
for(int i = 0;i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
            a[i][j] = 0;
        }
    }
}