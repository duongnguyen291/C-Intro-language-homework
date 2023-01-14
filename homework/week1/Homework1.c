#include <stdio.h>
int main(){
    printf("EXTENSION TO SOLVE FOLLOWING EQUATION: a*x+b=c");
    float a,b,c;
    while (a==0){
    puts("\nEnter the coefficient a:");
    scanf("%f",&a);
    }
    puts("\nEnter the coefficient b:");
    scanf("%f",&b);
    puts("Enter the coefficient c:");
    scanf("%f",&c);
    printf("\nSo we have a function: %f*x+%f=%f",a,b,c);
    float d;
    d = (c-b)/a;
    printf("\nThe result is: %f ",d);
   
}

