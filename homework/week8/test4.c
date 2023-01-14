#include <stdio.h>
void getpositive(int *n){
    do{
        printf("\nEnter: ");
        scanf("%d", &*n);
        printf("%d", *n);
        if(*n<0){
            printf("\nThe answer is incorrect!Please enter again!");
        }
    }while(*n<0);
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("\n a trong function la: %d",a);
    printf("\n b trong function la: %d",b);

}
int main(){
    int num  = 291;
    int a = 100;
    int b = 200;
    printf("\n a truoc la: %d",a);
    printf("\n b truoc la: %d",b);
    swap(&a,&b);
    printf("\n a sau la: %d",a);
    printf("\n b sau la: %d",b);
    //getpositive(&num);
    printf("\n%d", num);    
}   