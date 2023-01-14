#include <stdio.h>
int main(){
    int check=1;
    for(int j=1;j<=16;j++){
    for(int i=j;i<=256;i+=16){
            printf("\t%d:%c\t",i,i); 
            check+=1;    
    }
    printf("\n");
    }

    return 0;
}