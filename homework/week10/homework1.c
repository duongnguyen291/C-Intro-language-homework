/*Một năm có 7 tháng có 31 ngày là các tháng 1, tháng 3,
tháng 5, tháng 7, tháng 8, tháng 10 và tháng 12. Các tháng
còn lại là tháng 4, tháng 6, tháng 9 và tháng 11 sẽ có 30
ngày. Tháng 2 là tháng thiếu, tháng này thường có số ngày 
là 28 vào năm không nhuận hoặc có 29 vào năm nhuận.*/
#include <stdio.h>
void isLeapYear(unsigned int n);
int ex2(int mm,int yy);
void gettime(int mm,int yy); 
int main(){
    int mm,yy;
    do{
        printf("\nEnter the month and year (mm/yy): ");
        scanf(" %d%*c%d",&mm,&yy);
        if((mm<=0||mm>12)&&(yy<=0)){
                printf("\nYour month and your year is incorrect!Please enter again!");
            }
        else if((mm<=0||mm>12)||(yy<=0)){
            if((mm<=0||mm>12)){
                printf("\nYour months is incorrect!Please enter again!");
            }
            else if(yy<=0){
                printf("\nYour year is incorrect!Please enter again!");
            }
        }
    }while((mm<=0||mm>12)||(yy<=0));
    isLeapYear(yy);
    printf("\nThe number of day of the month is : %d",ex2(mm,yy));
    
    return 0;
}

void isLeapYear(unsigned int n){
    if((n%4 == 0 && n%100 !=0) || n%400 == 0 ){
        printf("\nThis is leap year!");
    }
    else {printf("\nThis is not leap year!");}
}
int ex2(int mm,int yy ){
    int days;
    if((yy%4 == 0 && yy%100 !=0) || yy%400 == 0 ){
        switch (mm)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
        days = 30;
            break;
        case 2:
        days = 29;
            break;
        default:
        days = 0;
            break;
        }
    }
    else {
        switch (mm)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
        days = 30;
            break;
        case 2:
        days = 28;
            break;
        default:
        days = 0;
            break;
        }

    }
    return days;   
}
