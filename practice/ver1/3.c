/*Nhập số tự nhiên n rồi tính: S= 1 +1/2 + 1/3 +...+ 1/n */
#include <stdio.h>
int main(){
    int a;
    float i,sum=0;
    scanf("%d",&a);
    for (i;i<=a;i++) sum+= 1/ i;
    printf("\nThe sum by for is : %f",sum);//Tính bằng for
    return 0;
}