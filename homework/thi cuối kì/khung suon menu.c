#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void get_by_range(int *n, int a, int b);
void getpositive(int *n);
//MAIN
int main(){
  //khai bao bien
  int home;
  //lenh
  do{
    printf("\nMenu");
    scanf("%d",&home);
    switch(home){
    case 1:;

       break;
    case 2:

      break;
    case 3:

      break;
    case 4:

      break;
    case 5:

      break;
    case 6:
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
