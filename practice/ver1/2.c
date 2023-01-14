/*Nhập số tự nhiên n rồi tính tổng S= 1+2+...+n*/
#include <stdio.h>
int tinhtong(int n){
    if (n==1) {return 1;}
    return tinhtong(n-1)+n;
}
int main(){
    int a,sum = 0,i =1;
    scanf("%d",&a);
    for(i;i<=a;i++){
    sum+= i;
    }      
    printf("\nThe Sum by for is : %d",sum);
    int n;
    scanf("%d",&n);
    printf("\nThe sum by recursive is : %d", tinhtong(n));

    

}