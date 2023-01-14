#include <stdio.h>
int main(){
    float boy_height, girl1_height, girl2_height;
    int age1,age2,girl1=0, girl2=0;
    char name1[100],name2[100];
    int check=1;

    do{


    printf("\nLogin - Enter your height (cm):");
    scanf("%f",&boy_height);
    printf("Hi:\n");
    scanf("%*c%[^\n]", name1);
    printf("-How old are you? ");
    scanf("%d",&age1);
    if(age1<=16){
        girl1 -=2;
        printf("(-2)"); 
    }
    else if(age1>16 && age1<21){
        girl1+=5;
        printf("(5)");
    }
    else if(age1>=21 && age1 <=100){
        girl1+=2;
        printf("(2)");
    }
    else {
        printf("Dien lai thong tin");
    }
    printf("\n-What's your height? ");
    scanf("%f",&girl1_height);
    if(girl1_height>=boy_height){
        girl1 -=1;
        printf("(-1)"); 
    }
    else if(girl1_height<(boy_height - 30)){
        girl1-=2;
        printf("(-2)");
    }
    else if(girl1_height< boy_height && girl1_height>=(boy_height-30)){
        girl1+=3;
        printf("(3)");
    }
    else {
        printf("Dien lai thong tin");
    }

    printf("\nHi:\n");
    scanf("%*c%[^\n]",name2);
    printf("-How old are you? ");
    scanf("%d",&age2);
    if(age2<=16){
        girl2 -=2;
        printf("(-2)"); 
    }
    else if(age2>16 && age2<21){
        girl2+=5;
        printf("(5)");
    }
    else if(age2>=21 && age2 <=100){
        girl2+=2;
        printf("(2)");
    }
    else {
        printf("Dien lai thong tin");
    }
    printf("\n-What's your height? ");
    scanf("%f",&girl2_height);
    if(girl2_height>=boy_height){
        girl2 -=1;
        printf("(-1)"); 
    }
    else if(girl2_height<(boy_height - 30)){
        girl2-=2;
        printf("(-2)");
    }
    else if(girl2_height< boy_height && girl2_height>=(boy_height-30)){
        girl2+=3;
        printf("(3)");
    }
    else {
        printf("Dien lai thong tin");
    }
    

    if(girl1==girl2){
        printf("\n-%s, are you free on Saturday?\n-%s, are you free on Sunday1?",name1,name2);
    }
    else if(girl1 > girl2){
        printf("\n-%s, are you free on Saturday?",name1);
    }
    else if(girl2 > girl1){
        printf("\n-%s, are you free on Saturday?",name2);
    }
    
    char check1;
    printf("\nDo you want continue with a new session? Yes (y or Y) or No (N or n): ");
    scanf("%*c%c",&check1);

    
    switch(check1){
        case 'Y':
        case 'y':
            check = 1;
            break;
        case 'N':
        case 'n':
            check = 0;
            break;
        default: 
            printf("\nThe answer is incorrect! Please enter again!");
            break;
    }

    }while(check==1);
    
    return 0;
}