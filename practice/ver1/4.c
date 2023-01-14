#include <stdio.h>
int main(){
    int n; 
    int sum1=0,sum2=0,sum3=0;
    scanf("%d",&n);
    /*Tính tổng các số tự nhiên không lớn hơn n*/
    for(int i=1;i<=n;i++ ){
        sum1+=i;
    }
    /*Tính tổng các số tự nhiên lẻ không lớn hơn n*/
    
    for(int j=1;j<=n;j++){
        if (j%2==1){
            sum2+=j;}
    /*Tính tổng các số tự nhiên chẵn không lớn hơn n*/}
    for (int k=1;k<=n;k++){
        if (k%2==0){
            sum3+=k;
        }
    }
    printf("%d\n%d\n%d",sum1,sum2,sum3);
    return 0;
}