#include <stdio.h>
void getpositive(int n){
    do{
        printf("\nEnter: ");
        scanf("%d", &n);
        printf("%d", n);
        if(n<0){
            printf("\nThe answer is incorrect!Please enter again!");
        }
    }while(n<0);
}

int main(){
    int num  = 291;
    getpositive(num);
    printf("\n%d", num);    
}   