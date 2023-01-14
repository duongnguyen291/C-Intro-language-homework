#include <stdio.h>
#define overnight 7
#define threeday 5
#define weekly 3
int main(){
    int n1,n2,n3;
    int dd,mm,yyyy;
    printf("Welcome to BK DVD shop. Please\nInput the date(dd/mm/yyyy):");
    scanf("%d%*c%d%*c%d",&dd,&mm,&yyyy);
    printf("Number of overnight DVD:");
    scanf("%d",&n1);
    printf("Number of 3-days:");
    scanf("%d",&n2);
    printf("Number of weekly DVD:");
    scanf("%d",&n3);
    int total =  n1*7+n2*5*3+n3*3*7;
    printf("Your total cost: %dx7 + %dx5x3 + %dx3x7=\n%d",n1,n2,n3,total);

    return 0;
}