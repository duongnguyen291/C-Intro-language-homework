#include <stdio.h>
int main(){
    int n;
    int count=0;
    do{
    for(int i=2;i<100;i++){
        for(int j=2;j<i;j++){
            if(i%j==0){
                break;
            }
            else{
                count++;
                printf("%d",i);}

        }
    }
    }while(count<=n);

    return 0;

}