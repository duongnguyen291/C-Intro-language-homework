#include <stdio.h>
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);

    //nửa tam giác trên
    for(int i=1;i<=n;i++)
    {
        // vong for dieu khien cac khoang trong
        for(int j=1;j<=n-i;j++)
        {
            printf(" ");
        }
        // vong for de in dau sao
        for(int j=1;j<=2*i-1;j++)
        {
            printf("*");
        }        
        printf("\n");
    }
    
    //nửa tam giác dưới
    for(int i=(n-1);i>0;i--)
    {   //điều khoảng trống
        for(int j=(n-1);j>=i;j--){
            printf(" ");
        }
        for(int j=(2*i-1);j>0;j--){
            printf("*");
        }
        printf("\n");
    }
    


    
    return 0;
}