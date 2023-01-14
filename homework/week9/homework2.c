#include <stdio.h>


int main()
{
    int money,n,check = 0,t;
    int array[] = {500 , 200, 100, 50, 20, 10, 5};
    do
    {
        printf("Welcom to cash machine\n Please enter your amount of money to withdraw \n Attention! Please enter the money that divisible by 5000. \n");
        scanf("%d",&money);
        n = money / 1000;
        if (n % 5 != 0 || money % 1000 != 0){
            printf("You have enter the wrong money! Please enter the number that divisible for 5000!\n");
            check = 1;
        }
        else{
            printf("%d = ",money);
            for (int i = 0; i <= 6; i++)
            {
                if (n >= array[i])
                {
                    t = n/array[i];
                    n = n - array[i] * t;
                    switch(t){
                        case 1:
                            printf("%d bill %d000",t,array[i]);
                            break;
                        
                        default:
                            printf("%d bills %d000",t,array[i]);
                            break;
                    }
                    t = 0;  
                    if(n == 0)
                        printf("\n");
                    else 
                        printf(" + ");
                }
            }
            check = 0;
        }
    } while (check != 0);
    
    return 0;
}