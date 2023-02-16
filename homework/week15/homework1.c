#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 11
int checkValidNumberPlate(char str[size]){
    int check = 1;
    for(int i = 0; i < size;i++ ){
        if(i == 0){
            if( str[i] < 50 || str[i] > 51 ){
                check = 0; 
                break;
            }
        }
        else if(i == 1){
            if(str[i] != '9' && str[i] != '0' && str[i] != '1' && str[i] != '2'){
                check = 0;
                break;
            }
        }
        else if(i == 3){
            if(str[i] < 41 || str[i] > 90 ){
                check = 0;
                break;
            }
        }
        else if(i >  3 && i < 8){
            if(str[i] < 48 || str[i] > 57){
                check = 0;
                break;
            }
        }
        else if(i > 8){
            if(str[i] < 48 || str[i] > 57){
                check = 0;
                break;
            }
        }
    }   
    return check;
}
int main(){ 
    char number_plate[10];
    printf("\nEnter number plates (DD-LDDDD.DD): ");
    scanf(" %[^\n]%*c", number_plate);
    printf("\n%s",number_plate);
    if(checkValidNumberPlate(number_plate) == 1){
        printf("\nLegit!");
    }
    else if(checkValidNumberPlate(number_plate) == 0 ){
        printf("\nNot Legit!");        
    }
	return 0;
}