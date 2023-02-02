#include <stdio.h>
int convert(int *n);
int main(){
int n;

printf("\nEnter the number n: ");
scanf("%d",&n);
printf("\nConvert number is: %d",convert(&n));
return  0;    
}
int convert(int *n){
    int u = 0;
    while(*n != 0){
        u = u*10 + *n%10;
        *n/=10;
    }
    return u;
}