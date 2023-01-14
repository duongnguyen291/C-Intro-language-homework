#include <stdio.h>
int tich(int a){
    if(a==1){return 1;}
    return tich(a-1)*a;
}
int main(){
    int n;
    int i=1;
    int total=0;
    scanf("%d",&n);
    for(i;i<=n;i++){
        total += tich(i);
    }
    printf("%d",total);

    return 0;
    
}