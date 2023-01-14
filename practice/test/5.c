#include <stdio.h>
void volume(int *x){
    *x = (*x)*(*x)*(*x);
}
void get_positive(int *n){
    do{
        printf("\nEnter the positive number: ");
        scanf("%d",&*n);
        if(*n<0){
            printf("\nYour answer is incorrect! Pls enter again!");
        }
    }while(*n<=0);

}
int main(){
    int x = 5;
    get_positive(&x);
    printf("\n%d",x);
}