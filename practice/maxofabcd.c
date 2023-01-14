#include <stdio.h>
int main(){
    int a,b,c,d;  
    scanf("%d %d %d %d", &a,&b,&c,&d);
    int dayso[4]={a,b,c,d};  
   
    printf("\nSo a b c d lan luot la: %d %d %d %d",a,b,c,d);
    int i = 1;
    int max = dayso[0];
    if(a==b && b==c && c==d){
        printf("\nNo the max valid !");
    }
    else{
    for (i=1; i<4;i++){ 
        if (dayso[i]>max){
            max = dayso[i];
         }
    }
    printf("\nThe max number is: %d", max);
    }
}