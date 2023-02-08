#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    int b[size];
    copy_array(a,b,size);
    for(int i = (size-1) ;i >=0 ;i--){
        if(i - offset < 0){
            a[i] = b[(i - offset) + (size)];
        } 
        else{
            a[i] = a[i - offset];
        }    
    }

}
void rotate_array_left_to_right(int a[],int size, int offset){
    int b[size];
    copy_array(a,b,size);
    for(int i = 0;i < size ;i++){
        if(i + offset >= size){
            a[i] = b[(i + offset)-(size)];
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
    int home,offset;
    enter_array_value(a,n);
    do{
    printf("\nMENU\n\t1.Left to right\n\t2.Right to lef\n\t3.Choose the offset\n\t4.Quit");
    scanf("%d",&home);
    switch(home){    
        case 1:

        copy_array(a,b,n);
        lietke(a,n);
        rotate_array_left_to_right(a,n,offset);
        printf("\n");
        lietke(a,n);
        break;
    case 2:
        copy_array(a,b,n);
        lietke(a,n);
        rotate_array_right_to_left(a,n,offset);
        printf("\n");
        lietke(a,n);
        break;
    case 3:
        printf("\nChoose the offset : ");
        scanf("%d",&offset);
        break;
    case 4:
        exit(0);
    break;
    default: 
    printf("\nEnter again!");
    break;
    }
    }while(1);
    return 0;
}