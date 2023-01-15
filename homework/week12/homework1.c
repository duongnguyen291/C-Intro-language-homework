#include <stdio.h>
#include <stdlib.h>
#define column_size 3
#define row_size 5
void reset(int a[row_size][column_size]);
void getpositive(int *n);
void get_by_range(int *n, int a, int b);
void print_status(int a[row_size][column_size]);
int main(){
    //intialization variables 
    int a[row_size][column_size];
    int home;
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
        printf("\n---------------------------");
            for(int i = 0; i < row_size;i++){
                printf("\n");
                for(int j = 0; j < column_size;j++){
                    printf("| %5d |", a[i][j]);
                }
                printf("\n---------------------------");
            }
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        reset(&a[row_size][column_size]);
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
                printf("%d",n);
            }
        }while((*n<a)||(*n>b));
}

