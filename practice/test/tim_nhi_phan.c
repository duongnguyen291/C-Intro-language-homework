#include <stdio.h>
#include <stdlib.h>
#define size 10
void input_array(int a[],int n){
    for(int i = 0; i < n;i++){
        printf("\nEnter element %d :",i+1);
        scanf("%d",&a[i]);
    }
}
void sort(int a[],int n){
    int tmp;
    //n là số phần tử trong mảng
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]){
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
}
int binarySearch(int a[],int n,int x){
    int left = 0 , right = n - 1;
    while(left <= right){
        int mid = (left+right)/2;
        if(a[mid] == x){
            return 1;}//tìm thấy
        else if(a[mid] < x){
            left = mid + 1; 
        }
        else if(a[mid] > x){
            right = mid - 1; 
        }
    }
    return 0;
}
int main(){
int a[size];
input_array(a,size);
sort(a,size);
int n;
while(1){
    printf("\nEnter n:");
    scanf("%d",&n);
    printf("\n%d",binarySearch(a,size,n));
    if(binarySearch(a,size,n) == 1){
        exit(0);
    }
}
}