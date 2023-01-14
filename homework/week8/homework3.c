#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int destination;
    int play_first = 1+rand()%(2-1);
    int check=1;
    printf("\nEnter destination number: ");
    scanf("%d",&destination);
    int start = 1+rand()%(destination-1);
    int sum = start,temp,number,number_old=-8;
    printf("\nICT GAME CENTER - SMART STRATEGY! ");
    printf("\nStart: %d",start);
    printf("\nWho play first (randomly): %d",play_first);
    while(sum<destination){
        check=1;
        printf("\nP%d - turn ",play_first);
        play_first = (play_first == 1) ? 2 : 1 ; 
        while(check){
            check = 0;
            printf("\nChoose the number: ");
            scanf("%d",&number);
            //truong hop cho loi
            if(number>5){
                printf("\n<ivalid - greater than 5");
                check=1;
                continue;
            }
            if((number+number_old)%2==0&&number_old>0){
                printf("%s",(number%2==0)?"\n<ivalid - even as previous slectioned>":"\n<ivalid - odd as previous slectioned>");
                check=1;
                
            }

        }
        number_old = number;  
        //truong hop oke
        sum +=number;  
        printf("\nNow the number is : %d",sum);

    }
    printf("\nP%d has won the game! Congratulation!!",play_first);

    return 0;
}