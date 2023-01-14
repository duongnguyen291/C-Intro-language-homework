#include <stdio.h>
int main(){
    int a;
    puts("Enter a (a>=1):");
    scanf("%d", &a);
    if (a>=1){
        for(int i=7;i<=a;i++){
            if (i%3==2 && i%5==3){
                printf("\nNumber is: %i",i);
            }
         }
    }
    else if (a<1)
    {
        printf("Enter again!");
    }
    return 0;
    }

    
    
