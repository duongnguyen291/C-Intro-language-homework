#include <stdio.h>
//liệt kê tất cả phần tử trong mảng 1 chiều
void lietke(int status[],int a){
    for(int i = 0; i < a; i++){
        printf("%5d",status[i]);
    }
}
//gán 2 mảng bằng nhau 
void copy_array(int a[],int b[],int size){
    for(int i = 0; i < size ;i++){
        b[i] = a[i];
    }
}
void rotate_array_right_to_left(int a[],int size, int offset){


}
void rotate_array_left_to_right(int a[],int size, int offset){
    int temp  = a[0];
    int b[size];
    copy_array(a,b,size);
    for(int i = 0;i < size ;i++){
        if(i + offset >= size){
            a[i] = b[(i + offset)-10];
        }
        else{
            a[i] = a[i + offset];
        }    
    }
}
void enter_array_value(int a[],int n){
    for(int i = 0;i < n ;i++){
        printf("\nEnter a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
int main(){
    int n;
    printf("\nEnter size of the array: ");
    scanf("%d",&n);
    int a[n];
    int b[n];
    enter_array_value(a,n);
    copy_array(a,b,n);
    lietke(a,n);
    rotate_array_left_to_right(a,n,3);
    printf("\n");
    lietke(a,n);
    return 0;
}