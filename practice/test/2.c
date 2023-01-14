#include <stdio.h>
int * sort_decreasing(){
    int temp;
    static int a[9];
    for(int i = 0; i < 9 ; i++){
    printf("\nEnter the %d element is: ",i);
    scanf("%d",&a[i]);
    }
    for(int i = 0; i < 9; i++){
        for(int j = i+1; j < 9;j++){
            if(a[i]<a[j]){
                temp = a[j];
                a[j] = a[i];
                a[i] = temp; 
            }
        }
    }
    return a;
}
int main(){
    int *p;
    p = sort_decreasing(9);
    for(int i = 0; i < 9; i++){
        printf( "\nThe elements is: %d",(p[i]));
    }
    return 0;
}