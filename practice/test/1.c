#include <stdio.h>

void local_maximum_number(int size){
    printf("\nEnter the size of the array: ");
    scanf("%d",&size);
    int sum = 0;
    int a[size];
    for(int i = 0; i <size ; i++){
        printf("\nEnter the element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    for(int i = 1; i< size - 1; i++){
        if((a[i]>a[i-1])&&(a[i]>a[i+1])){
            sum += a[i];
        }
    }
    printf("\nThe sum of the local maximum number is : %d",sum );
}


int main(){
    int n;
    local_maximum_number(n);


    return 0;
}