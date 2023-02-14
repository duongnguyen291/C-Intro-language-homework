#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void ma_hoa(char str[],int k){
for(int i = 0;i <strlen(str);i++){
    if(!isspace(str[i])){
    str[i] = str[i] + k;
    }
    }
}
void giai_ma(char str[],int k){
for(int i = 0;i <strlen(str);i++){
    if(!isspace(str[i])){
    str[i] = str[i] - k;
    }
    }
}
int main(){
    char a[1000];
    int home;
    int step;
    do{
        printf("\nMENU\n");
            printf("\t1. Encyption the paragraph\n");
            printf("\t2. Decoding the paragraph\n ");
            printf("\t3. Enter string\n");
            printf("\t4. Exit\n");
            printf("------------------------------\n");
            printf("Choose your number (from 1 to 3): ");
            scanf("%d", &home);
        switch (home){
			case 1: {
				printf("------------------------------\n");
				printf("Enter the k step: ");
    			scanf("%d", &step);
				ma_hoa(a,step);
				printf("%s\n",a);		
				break;
			}
			case 2: {
				printf("------------------------------\n");
				printf("Enter the k step: ");
    			scanf("%d", &step);
                giai_ma(a,step);
				printf("%s\n", a);
				break;
			}
            case 3:
                printf("\nEnter the string:");
                scanf(" %[^\n]%*c", a);
                break;
			case 4: {
				printf("------------------------------\n");
				printf("Thank you for using our service!!!\n");
				exit(0);
				break;
			}
			default: {
				printf("------------------------------\n");
				printf("Please enter other numbers (from 1 to 3) once again!!!\n");
				break;
			}            
        }
    }while(1);
}