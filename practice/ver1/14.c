#include <stdio.h>
int tinhgiaithua(int n){
    if(n==1){return 1;}
    else return n*tinhgiaithua(n-1);
}
int main(){

    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("\nGiai thua cua n! la: %d",tinhgiaithua(n));    

    return 0;



}