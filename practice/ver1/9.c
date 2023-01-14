#include <stdio.h>
int main(){
    int n,check = 3;
    scanf("%d",&n);
    if(n<2){
        printf("Khong phai so nguyen to");     
    }    
    else {
        for(int i=2;i<n;i++){
            if(n%i==0){
                check = 0;
                break;
            }
            else{
                check =1;
            }
        }
    }
    if(check==1){
        printf("n la so nguyen to");
    }
    else if (check ==0){
        printf("n khong phai la so nguyen to");
    }
}