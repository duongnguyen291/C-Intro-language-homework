#include <stdio.h>
int main(){
    float boy_height, girl1_height, girl2_height;
    int age1,age2,girl1=0, girl2=0;
    printf("Login - Enter your height (cm):");
    scanf("%f",&boy_height);
    printf("Hi Lan:\n");
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




    printf("\nHi Mai:\n");
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
    

    if(girl1=girl2){
        printf("\n-Lan, are you free on Saturday?\n-Mai, are you free on Sunday?");
    }
    else if(girl1 > girl2){
        printf("\n-Lan, are you free on Saturday?");
    }
    else if(girl2 > girl1){
        printf("\n-Mai, are you free on Saturday?");
    }
    return 0;
}