#include <stdio.h>

int main()
{
    float start, end , jump, fahRenHit;
    int variableNum, check ,choice;
    do{
        printf("Welcom to the Degree Conversion Table! This will convert from Celius to Fahrenhit! \n 1. Enter the value \n 2. Display the conversion table \n 3. Exit \n Your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the begin value in C: ");
                scanf("%f",&start);
        
                printf("Enter the end value in C: ");
                scanf("%f",&end);

                printf("Enter the step: ");
                scanf("%f",&jump);
                check = 0;
                break;
            
            case 2:
                if( (int)(end - start) % (int)jump == 0)
                    variableNum = (int)((end - start)/jump) +1;
                else
                    variableNum = (int)((end - start)/jump) +2;

                for( int i = 0; i < variableNum ; i++)
                {
                    if (i + 1 == variableNum){
                        start = end;
                    }
                    fahRenHit = 1.8 * start + 32.0;
                    printf("%7.2f\t\t | \t%7.2f\n", start, fahRenHit );
                    start = start + jump;
                }
                check = 0;
                break;

            case 3:
                check = 1;
                break;
            
            default:
                printf("You have enter wrong number! You must enter number from 1 to 3!\n Please enter again!\n");
                check = 0;
                break;
        }
    }while(check != 1);
    return 0;
}

