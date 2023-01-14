#include <stdio.h>
int main(){
    int n;
    printf("Enter the n:");
    scanf("%d",&n);
//hàng trên
    for(int i=1;i<=n;i++){
        printf("*");
        
    }
//điều chỉnh 2 cột
    printf("\n");
    for(int i = 1;i<=(n-2);i++){
        printf("*");
        for(int j=1;j<=(n-2);j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
    }



//hàng dưới
for(int i=1;i<=n;i++){
        printf("*");
    }








    return 0;
}