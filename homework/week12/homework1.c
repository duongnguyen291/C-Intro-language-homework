#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("\nEnter the number: ");
    scanf("%d",&n);
    printf("\nThe number is : %d",n);
    printf("\nHehehe! ");
    for(int i = 0 ; i < 10; i++){
        printf("\n%d. I love you! ", i + 1);
    }

    return 0;
}
