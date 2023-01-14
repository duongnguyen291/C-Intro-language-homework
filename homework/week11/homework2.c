#include <stdio.h>
#include <stdlib.h>
#define size 40
int status[size], powerComsumption[size];
void reset(int status[], int powerComsumption[]);
void getnumber(int range1, int range2, int *n);
void lietke(int status[],int a);
int find_max(int arr[]);
int find_min(int arr[]);
int bill(int consume[]);
int main(){
    int home;
    int computer_number, on_off,off_on;
    for(int i = 0; i < 40;i++){
        status[i] = 0;
        powerComsumption[i] = 0;
    }
    do{
        printf("\nMENU");
        printf("\n1. Choose the computer and option");
        printf("\n2. Total status of the LAB 381");
        printf("\n3. Power Comsumption, Bill of electricity and Total Report");
        printf("\n4. Reset entire the computer");
        printf("\n5. Quit");
        printf("\nYour choice is:  ");
        scanf("%d",&home);

        switch (home)
        {
        case 1:        
                printf("\nChoose the computer number: ");
                getnumber(1,40,&computer_number);
                if(status[computer_number - 1] == 1){
                    printf("\nThe machine was used!");
                    printf("\nDo you want turn off the computer?\n1.Yes\n2.No");
                    getnumber(1,2,&off_on);
                    status[computer_number - 1] = (off_on == 1 ) ? 0 : 1; 
                }   
                else{        
                    printf("\nDo you want turn on the computer?\n1.Yes\n2.No");
                    getnumber(1,2,&on_off);
                    status[computer_number - 1] = (on_off == 1 ) ? 1 : 0; 
                    powerComsumption[computer_number - 1] +=400;
                }
            //lietke(status,40);
            
            break;
        case 2:          
            printf("---------------------------------------------------------------------------------------------------------------------------------\n");
                int count = 1, comp = 1;
                int number1 = 1,number2 = 1;
                for(int i = 0; i < 20; i++){
                    if((i+1) % 4==0){
                    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
                    }
                    else{       
                        for(int j = 0; j < 8; j++){
                            printf("|");
                            if((i+1) % 4 == 1){
                                printf("  COMP %d\t",  comp);
                                comp++;
                            }
                            else if((i+1) % 4 == 2){
                                //printf("%d",comp);
                                if(status[number1- 1] == 1){
                                    printf("  ON\t\t");
                                }
                                else{
                                    printf("  Off\t\t");
                                }
                                number1++;
                            }
                            else if((i+1) % 4 == 3){
                                printf("%4dW\t\t",powerComsumption[number2-1]);
                                number2++;
                            }
                            printf("|");
                        }
                        printf("\n");

                    }
                }
            break;
        case 3:
            printf("\nPower comsumption is : %d (W) ",bill(powerComsumption));
            //Power Comsumption, Bill of electricity and Total Report
            float W = bill(powerComsumption);
            float kW =  W/1000;            
            float bill = kW * 750;
            printf("\nTotal bill is : %.2f(kW) x 750 (dong) = %.2f (dong)",kW,bill);
            printf("\nThe most used machine's number is : %d ", find_max(powerComsumption));
            printf("\nThe least used machine's number is : %d ", find_min(powerComsumption));
            break;
        case 4:
            reset(status,powerComsumption);
            break;
        case 5: 
            printf("\nThanks for using our service!");
            exit(0);
            break;
        default:
            break;
        }

    }while(1);  
    return 0;
}
int find_max(int arr[]){
	int max = 0, n;
	for (int i = 0; i < 40; i++) {
		if (max < arr[i]) {
			max = arr[i];
			n = i+1;
		}
	}
	return n;
}
int find_min(int arr[]){
	int min = 1000000, n;
	for (int i = 0; i < 40; i++) { 
		if (min > arr[i]) {
			min = arr[i];
			n = i + 1;
		}
	}
	return n;
}
int bill(int consume[]){
	int bill = 0;
	for (int i = 0; i < 40; i++) {
		bill = bill + consume[i];
	}
	return bill;
}
void getnumber(int range1, int range2, int *n){
    do{
        printf("\nEnter: ");
        scanf("%d", &*n);
        if((*n<range1) || (*n > range2)){
            printf("\nYour choice is incorrect! Please enter again! ");
        }
    }while((*n<range1) || (*n > range2));
}

void reset(int status[], int powerComsumption[]){
    for(int i = 0; i < 40;i++){
        status[i] = 0;
        powerComsumption[i] = 0;
    }
}
void lietke(int status[],int a){
    for(int i = 0; i < a; i++){
        printf("%5d",status[i]);
    }
}

    