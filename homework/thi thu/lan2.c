#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void get_by_range(int *n, int a, int b);
void getpositive(int *n);
//MAIN
int find_max_number(int str[],int n){
    int count = str[0];
    for(int i = 0;i < n-1;i++){
        if(str[i] < str[i+1]) count =str[i+1];
    }
    return count;
}
void frequency(int str[],int n){
    int count = 0;
    for(int i = 0; i <= find_max_number(str,n) ; i++){
        count = 0;
        for(int j = 0;j < n;j++){
            if(str[j] == i ) count++;
        }
        if(count>0){
        printf("\n%d%5d",i,count);
        }
    }
}
int fib(int n){
    int fib1 = 0, fib2 = 1;
    int temp;
    for(int i = 0;i < n - 1; i++){
        temp = fib2;
        fib2 = fib1 + fib2;
        fib1 = temp;
    }
    return fib2;
}
int check_password(char *password) {
    int has_digit = 0, has_lower = 0, has_upper = 0;
    int i = 0;

    while (password[i] != '\0') {
        if (isdigit(password[i])) {
            has_digit = 1;
        } else if (islower(password[i])) {
            has_lower = 1;
        } else if (isupper(password[i])) {
            has_upper = 1;
        } else {
            // Nếu ký tự không phải số hoặc chữ cái thì mật khẩu không hợp lệ
            return 0;
        }

        i++;
    }

    // Kiểm tra độ dài mật khẩu và các yêu cầu khác
    if (i >= 10 && has_digit && has_lower && has_upper) {
        return 1;
    } else {
        return 0;
    }
}

int main(){
  //khai bao bien
  int home;
  int str[20];
  char password[100];
  int n;
  //lenh
  do{
    printf("\nMenu\n\t1.Frequency\n\t2.Fibonacci\n\t3.Password\n\t4.Date\n\t5.Exit\n\tYour choice is:    ");
    scanf("%d",&home);
    switch(home){
    case 1:;
        printf("\nEnter n element (0 < n < 20)");
        get_by_range(&n,1,20);
        printf("\nEnter array!");
        for(int i = 0;i < n;i++){
            printf("\nEnter %d elements:",i+1);
            scanf("%d",&str[i]);
        }
        frequency(str,n);
       break;
    case 2:
        printf("\nEnter n  (0 < n < 30)");
        get_by_range(&n,1,30);
        //tính 
        printf("\nSo fibonacci thu %d la : %d",n,fib(n));
        
      break;
    case 3:
        do{
        printf("\nEnter the password:  ");
        scanf(" %[^\n]%*c",password);
        if(check_password(password) == 0){
            printf("\nThe password too week. The strong password must have:\n\t-At least 10 characters\n\t-At least 1 number\n\t-At least 1 capitalization and lowercase\n\t-Password only have characters and number(0...9)");
        }
        }while(check_password(password) == 0);
        printf("\nMat khau da du manh! ");
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