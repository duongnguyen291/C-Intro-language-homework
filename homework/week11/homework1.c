#include <stdio.h>
#include <math.h>

int main(){
    //khai báo biến
    float expert1[5], expert2[5];
    char jersey1[5],jersey2[5];
    int home = 1;
    float sum1,sum2;
    //Menu
    do{
        home = 1;
        do{
            printf("\nMENU\n1. Enter jersey number and Player reviews!\n2.Results\n3.Total Report\n4.Quit");
            printf("\n-->Your choice: ");
            scanf("%d",&home);
            if(home<0&&home>4){
                printf("\nYour choice is incorrect! Please enter again!");
            }
        }while(home<0&&home>4);

        switch (home)
        {
        case 1:
            printf("\n---------The expert 1 turn---------");
            for(int i = 0; i<5;i++){
                do{
                    printf("\nEnter the jersey number and point of player %d (number/point):",i+1);
                    scanf(" %d%*c%f", &jersey1[i],&expert1[i]);
                        //lúc này in ra nhận giá trị 0
                        printf("%f",expert1[i]);
                    if((expert1[i]<0||expert1[i]>10)&&jersey1[i]<0){
                        printf("\nYour choice of jersey number and the score you giving is incorrect! ");
                    }
                    else if(expert1[i]<0||expert1[i]>10){
                        printf("\nThe score you giving is incorrect!");
                    }
                    else if(jersey1[i]<0){
                        printf("\nYour choice of jersey number is incorrect!");
                    }

                }while(expert1[i]<0||expert1[i]>10||jersey1[i]<0);
            }
                    for (int i = 0; i < 5; i++) {
                        expert1[i] = roundf(expert1[i] * 2) / 2;
                    }
            printf("\n---------The expert 2 turn---------");
            for(int i = 0; i<5;i++){
                do{
                printf("\nEnter the jersey number and point of player %d (number/point):",i+1);
                scanf(" %d%*c%f", &jersey2[i],&expert2[i]);

                if((expert2[i]<0||expert2[i]>10)&&jersey2[i]<0){
                    printf("\nYour choice of jersey number and the score you giving is incorrect! ");
                }
                else if(expert2[i]<0||expert2[i]>10){
                    printf("\nThe score you giving is incorrect!");
                }
                else if(jersey2[i]<0){
                    printf("\nYour choice of jersey number is incorrect!");
                }
                }while(expert2[i]<0||expert2[i]>10||jersey2[i]<0);
            }
                for(int i = 0; i < 5; i++){
                        expert2[i] = roundf(expert2[i] * 2) / 2;
                }
            break;
        case 2:
            printf("\nThe results table of judges 1!\n--------------------");
            printf("\nThe jersey number \tScore");
            for(int i = 0;i<5;i++){
                printf("\n%d\t\t\t%.1f",jersey1[i],expert1[i]);
            }
            printf("\n--------------------");
            printf("\nThe results table of judges 2!\n--------------------");
            printf("\nThe jersey number \tScore");
            for(int i = 0;i<5;i++){
                printf("\n%d\t\t\t%.1f",jersey2[i],expert2[i]);
            }
            printf("\n--------------------");

            break;
        case 3:
            sum1 = 0, sum2 = 0;
            for(int i = 0;i<5;i++){
                sum1+=expert1[i];
                sum2+=expert2[i];
            }
        printf("\nThe most dificult judge is : %d", (sum1<sum2) ? 1 :2 );
        printf("\nThe most easy judge is : %d", (sum1<sum2) ? 2 :1 );
            break;       
        default:
            break;
        }


    }while(home!=4);   
    return 0;
}