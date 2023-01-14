#include <stdio.h>
int main(){
    int n;
    do{
    printf("Enter the n (n<8): ");
    scanf("%d",&n);
    }while(n>=8||n<=0);    
    printf("%d",n);
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            printf(" ");
        }
        for(int j=1;j<=2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}   