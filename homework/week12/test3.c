#include <stdio.h>
int main(){
    int n;
    int *iptr;
    iptr = &n;
    *iptr = 5;
    printf("\nn = %d ",n);
}