#include <stdio.h>
void xoa(int a[], int *n,int locate){
    for(int i = locate + 1; i < n;i++){
        a[i-1] = a[i];
    }
    n--;
}
void xoa_trung(int a[], int *n){
    for(int i = 0;i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i]==a[j]){
                xoa(a,n,j);
                i--;
            }
        }
    }
}
int main(){
    int size1, size2;
    //nhập thành phần mảng
    printf("\nEnter the size of the array 1: ");
    scanf("%d",&size1);
    char array1[size1];
        for(int i = 0; i < size1;i++){
            printf("\nEnter the variables %d : ",i+1);
            scanf("%d",&array1[i]);
        }
    printf("\nEnter the size of the array 2: ");
    scanf("%d",&size2);
    char array2[size2];
        for(int i = 0; i < size2;i++){
            printf("\nEnter the variables %d : ",i+1);
            scanf("%d",&array2[i]);
        }

    //chạy mảng các phần tử trùng nhau
    int k = 0; 
    int size3 = (size1 > size2) ? size2 : size1; 
    char array3[size3];
    for(int i = 0; i < size1;i++ ){
        for(int j = 0; j < size2;j++){
            if(array1[i]==array2[j]){
                array3[k] = array1[i];
                k++;
            }
        }
    }
    printf("\nThe array1 is: ");
    for(int i = 0; i < size1 ;i++){
        printf(" %d ",array1[i]);
    }
    printf("\nThe array2 is: ");
    for(int i = 0; i < size2 ;i++){
        printf(" %d ",array2[i]);
    }
    printf("\nThe array3 is: ");        
    for(int i = 1; i <= k ;i++){
        printf("\nThe element %d is: %d ",i,array3[i-1]);
    }
    xoa_trung(array3,&size3);
}