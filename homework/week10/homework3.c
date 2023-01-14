#include <stdio.h>
float converting(float fahrenheit);
float converting_table(float start, float end , float step);
void getpositive(float *n);
int main(){
    float c,f,start,end,step;
    printf("\nEnter the value of fahrenheit: ");
    getpositive(&f);
    c = ((float)5/9)*(f-32);
    printf("\nThe first: %.2f",c);
    printf("\nThe value of celcius 1st: %.2f ", converting(f));
    printf("\nEnter the start: ");
        getpositive(&start);
    printf("\nEnter the end: ");
        getpositive(&end);
    printf("\nEnter the step: ");
        getpositive(&step);
    converting_table(start,end,step);
    return 0;
}

float converting(float fahrenheit){
    float celcius = ((float)5/9)*(fahrenheit-32);
    return celcius;
}

float converting_table(float start, float end , float step){
    printf("\nFahrenheit\t\tCelsius");
    printf("\n-----------------------");
    for(float i = start ; i <= end ; i += step){
        printf("\n%.2f\t\t%.2f",i, converting(i));
    }

}
void getpositive(float *n){
    do{
        printf("\nEnter: ");
        scanf("%f", &*n);
        if(*n<0){
            printf("\nThe answer is incorrect!Please enter again!");
        }
    }while(*n<0);
}