#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void get_by_range(int *n, int a, int b);
void getpositive(int *n);
void lietke(int status[],int a){
    for(int i = 0; i < a; i++){
        printf("%5d",status[i]);
    }
}
//MAIN
int main(){
  //khai bao bien
  int home;
  int n1;
  int arr[20];
  int count[20][20];
  //lenh
  do{
    printf("\nMenu\n\t1.Frequenct\n\t2.Fibonacci\n\t3.Password\n\t4.Date\n\t5.Quit\nYour choice is:    ");
    scanf("%d",&home);
    switch(home){
    case 1:;
        printf("\nEnter the integer number (0 < n <=20): ");
        scanf("%d",&n1);
        for (int i = 0; i < n1; i++){
            scanf("%d",&arr[i]);
        }
        for(int i = 0; i < n1 ;i++){
          
        }
        
       break;
    case 2:

      break;
    case 3:

      break;
    case 4:

      break;
    case 5:
     //thoát chương trình
      exit(0);
      break;
    default:
      printf("\nBan chon sai roi!");
      break;
    } 
  }while(1);

  return 0;
}



void get_by_range(int *n, int a, int b){
    do{
            printf("\nEnter: ");
            scanf("%d", &*n);
            if((*n < a)||(*n > b)){
                printf("\nThe answer is incorrect!Please enter again!");
            }
        }while((*n<a)||(*n>b));
}
void getpositive(int *n){
    do{
        printf("\nEnter: ");
        scanf("%d", &*n);
        if(*n<0){
            printf("\nThe answer is incorrect!Please enter again!");
        }
    }while(*n<0);
}