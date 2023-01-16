#include <stdio.h>
#include <stdlib.h>
#define month 12
void get_by_range(int *n, int a, int b);

int main(){
    int spending[month];
    int home;
    do{
        printf("\nHUST Money Lover Program! ");
        printf("\n1. Spending mode");
        printf("\n2.Enter value");
        printf("\n3.Table report");
        printf("\n4.Total report");
        printf("\n5.Quit");
        printf("\nYour chose is:");
        get_by_range(&home,1,5);
        switch (home)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            printf("\nThanks for using our service");
            exit(0);
            break;       
        default:
            printf("\nYour choice is incorrect!");
            break;
        }        

    }while(1);
    return 0;
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