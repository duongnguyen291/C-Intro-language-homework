#include <stdio.h>
int main(){
    int n,i=7,sum=0; 
    scanf("%d",n);
    for(i;i<=n;i++){
        if(i%7==0){
            sum+=i;
        }
    }
    printf("%d",sum);

}