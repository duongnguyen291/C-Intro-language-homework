#include <stdio.h>
#include <math.h>

int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    
    if(n<0){
        printf("Enter n>0!");
    }
    else{
        long dao = 0;
        long m = n;
        while(m>0){
            dao=dao*10+m%10;
            m/=10;
        }
        if(dao==n){
            printf("N la so thuan nghich!");
        }
        else if(dao!=n){
            printf("N khong phai so thuan nghich");
        }
    }
    



    return 0;
}