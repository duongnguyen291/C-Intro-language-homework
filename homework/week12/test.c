#include <stdio.h>
#include <stdlib.h>
#define column_size 3
#define row_size 5
void reset(int a[row_size][column_size]);
void getpositive(int *n);
void get_by_range(int *n, int a, int b);
void print_status(int a[row_size][column_size]);
void turn_row(int a[row_size][column_size]);
void lietke(int a[row_size][column_size]);
void turn_column(int a[row_size][column_size]);
int check_row(int a[row_size][column_size],int row);
int check_column(int a[row_size][column_size],int column);
int main(){
    //intialization variables 
    int a[row_size][column_size];
    int home;
    int n;
    //reset all the elements of array
    for(int i = 0;i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
            a[i][j] = 0;
        }
    }

    //Write menu
    do{
        printf("\nWelcome to the light control of LAB");
        printf("\n0. Print the status");
        printf("\n1. Turn on the lights in rows");
        printf("\n2. Turn on the lights in columns");
        printf("\n3. Turn on the lights by position");
        printf("\n4. View the power comsumption of the luminaire according to the current state");
        printf("\n5. Reset");
        printf("\n6. Quit");
        printf("\nYour choice is : ");
        get_by_range(&home,0,6);

    switch (home)
    {
    case 0:
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
        break;
    case 1:
        turn_row(a);
        //lietke(a[row_size][column_size]);       
        break;
    case 2:
        turn_column(a);
        //lietke(a[row_size][column_size]);
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        reset(a);
        break;
    case 6:
        printf("\nThanks for using our service !");
        exit(0);
        break;
    default:
        printf("\nYour choice is incorrect!");
        break;
    }
    }while(1);
    return 0;
}


void lietke(int a[row_size][column_size]){
    for(int i = 0;i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
           printf("%5d",a[i][j]);
        }
        printf("\n");
    }
}

void reset(int a[row_size][column_size]){   
for(int i = 0;i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
            a[i][j] = 0;
        }
    }
}
void getpositive(int *n){
    do{
        printf("\nEnter: ");
        scanf("%d", &*n);
        if(*n<0){
            printf("\nThe answer is incorrect!Please enter again!");
        }
    }while(*n<0);
}
void get_by_range(int *n, int a, int b){
    do{
            printf("\nEnter: ");
            scanf("%d", &*n);
            if((*n < a)||(*n > b)){
                printf("\nThe answer is incorrect!Please enter again!");
            }
        }while((*n<a)||(*n>b));
}
void turn_row(int a[row_size][column_size]){
    int n;
    printf("\nChoose the number of row: ");
    scanf("%d",&n);
    for(int i = 0; i < column_size;i++){
        a[n-1][i] = 1;
    }
}
void turn_column(int a[row_size][column_size]){
    int n;
    printf("\nChoose the number of column: ");
    scanf("%d",&n);
    for(int i = 0; i < row_size;i++){
        a[i][n-1] = 1;
    }
}
int check_row(int a[row_size][column_size],int row){
    int check = 1;
    for(int i = 0; i < row_size; i++){
        if(a[row-1][i] == 1){
            check*=check;
        }
        else{
            check = 0;
        }
    }
    return check;
}
int check_column(int a[row_size][column_size],int column){
    int check = 1;
    for(int i = 0; i < row_size; i++){
        if(a[i][column-1] == 1){
            check*=check;
        }
        else{
            check = 0;
        }
    }
    return check;
}