#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define row_size 3
#define column_size 5

//lấy giá trị int theo khoảng từ a đến b cho đến khi nào được thì thôi
void get_by_range(int *n, int a, int b){
    do{
            printf("\nEnter: ");
            scanf("%d", &*n);
            if((*n < a)||(*n > b)){
                printf("\nThe answer is incorrect!Please enter again!");
            }
        }while((*n<a)||(*n>b));
}

//lấy giá trị int cho đến khi nguyên dương
void getpositive(int *n){
    do{
        printf("\nEnter: ");
        scanf("%d", &*n);
        if(*n<0){
            printf("\nThe answer is incorrect!Please enter again!");
        }
    }while(*n<0);
}

//tìm phần tử max trong mảng (ĐƯA VỀ vị trí TỪ 0 ĐẤY )
int find_max(int a[],int size ){
    int max = a[0], n = 0 ;
    for(int i = 1; i <size;i++){
        if(max <= a[i]){
            max = a[i];
            n = i + 1;
        }
    }
    return n;
}

//tìm phần tử min trong mảng
int find_min(int a[], int size){
    int min = a[0], n = 0 ;
    for(int i = 1; i < size;i++){
        if(min >= a[i]){
            min = a[i];
            n = i + 1;
        }
    }
    return n;
}

//tổng phần tử trong mảng 2 chiều
int bill_two(int consume[row_size][column_size]){
	int bill = 0;
	for (int i = 0; i < row_size; i++) {
		for(int j = 0;j <column_size;j++ ){
            bill += consume[i][j];
        }
	}
	return bill;
}

//tổng phần tử trong mảng 1 chiều
int bill_one(int consume[],int size){
	int bill = 0;
	for (int i = 0; i < size; i++) {
		bill = bill + consume[i];
	}
	return bill;
}

//liệt kê tất cả phần tử trong mảng 1 chiều
void lietke(int status[],int a){
    for(int i = 0; i < a; i++){
        printf("%5d",status[i]);
    }
}
//kiểm tra năm nhuận
void isLeapYear(unsigned int n){
    if((n%4 == 0 && n%100 !=0) || n%400 == 0 ){
        printf("\nThis is leap year!");
    }
    else {printf("\nThis is not leap year!");}
}

//Nhập phần tử của mảng 
void enter_array_value(int a[],int n){
    for(int i = 0;i <n ;i++){
        printf("\nEnter a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
//copy mảng b bằng với mảng a
void copy_array(int a[],int b[],int size1){
    for(int i = 0; i < size1;i++){
        b[i] = a[i];
    }
}
int main(){
    printf("Hello");
    return 0;
}