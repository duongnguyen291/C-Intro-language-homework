#include <stdio.h>
int main(){
    int n,i=2;
    int count = 0;
    scanf("%d",&n);
    if (n<1){
        printf("Nhap so >0");
    }
    else if (n==1){
        printf("1=2^0");
    }
    else {
        printf("%d = ",n);
        while(n>1){
            if(n%i==0){
                count++;
                if (n==i){
                    printf("%d^%d",i,count);
                }
                n/=i;
            }
            else{
                if (count>0){
                    printf("%d^%dx",i,count);
                    count=0;
                }
                i++;
            }
        }
        
    }
    return 0;

}