#include <stdio.h>
#include <stdlib.h>
#define column_size 3
#define row_size 5
int check_row(int a[row_size][column_size],int row){
    int check = 1;
    for(int i = 0; i < column_size; i++){
        if(a[row-1][i] == 1){
            check*=check;
        }
        else{
            check = 0;
        }
    }
    return check;
}
int main(){
    int n;
    int a[row_size][column_size];

    printf("\nChoose the number of row: ");
    scanf("%d",&n);
    for(int i = 0;i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
            a[i][j] = 0;
        }
    }
    for(int i = 0; i < column_size;i++){
                a[n-1][i] = 1;
            }
    printf("\n-------------------------------------------------");
            for(int i = 0; i < row_size;i++){
                printf("\n");
                for(int j = 0; j < column_size;j++){
                    if(a[i][j] == 1){
                        printf("|\tON\t|");
                    }
                    //a[i][j]== 1 ? printf("|\tON\t|") : printf("|\tOFF\t|");
                    else if(a[i][j] == 0){
                        printf("|\tOFF\t|");
                    }
                }
                printf("\n-------------------------------------------------");
            }       
    printf("\nThe results %d is :%d ",n,check_row(a,n));




}