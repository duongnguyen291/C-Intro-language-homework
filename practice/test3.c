#include <stdio.h>
void sort_decreasing(int a[],int n);


int main(){
    int i;
    int n = 10;
    int a[10] = {923,0000,234,34,4,100000,3434,12333,3423,12};
int max=0,temp=0; 
for(i=0;i<n;i++) { 
    if(a[i]==0) 
        temp=temp+1; 
    if(a[i]!=0){ 
        if(temp>max){ 
            max=temp; 
            temp=0; 
            } 
    } 
}
if(temp>max) {max=temp;} 
printf("\nDo dai day con bang 0 lon nhat la:", max);
return 0;
}