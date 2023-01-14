#include <stdio.h>
int main(){
    int n;
    int sum=0;
    printf("Enter n: ");
    scanf("%d",&n);

    while(n){
        sum+=n%10;
        n/=10;

    }
    printf("Sum is: %d",sum);

    return 0;
}