#include <stdio.h>
int main(){
    int a,b,c;
    puts("Enter the number a:");
    scanf("%d",&a);
    puts("Enter the number b:");
    scanf("%d",&b);
    puts("Enter the number c:");
    scanf("%d",&c);
    int set[3]={a,b,c};
    int i=0,j=0;
    int max = set[0], min = set[0];
    printf("%d",set[0]);
    for (i=1;i<3;i++){    
        if (set[i]>max)
        {
         max = set[i];}
        }
    for (j=1;j<3;j++){
        if (set[j]<min)
        {
            min = set[j];
        }
    }
    
    printf("\nThe max number is : %d",max);
     printf("\nThe min number is : %d",min);

    }
        
    
    

