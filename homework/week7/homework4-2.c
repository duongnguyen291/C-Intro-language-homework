#include <stdio.h>
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);


    //điều chỉnh hàng đầu 
    for(int i=1;i<=n;i++)
    {
        printf("*");
    }
    printf("\n");
    //điều chỉnh giữa
    for(int i=1;i<=(n-2);i++){
        //điều chỉnh khoảng cách
        for(int j=1;j<=i;j++){
            printf(" ");
        }
        printf("*");
        printf("\n");

    }







    //điều chỉnh hàng cuối 
    for(int i=1;i<=n;i++)
    {
        printf("*");
    }

    return 0;
}