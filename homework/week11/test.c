#include <stdio.h>
#include <stdlib.h>

void array(int a[], int n); 
int find_max(int arr[],int n);
void lietke(int status[],int a){
    for(int i = 0; i < a; i++){
        printf("%5d",status[i]);
    }
}
int main(){
	int arr[10];
	array(arr,10);
	printf("\n%d",find_max(arr,10));

}
void array(int a[], int n){
	for(int i = 0;i < n; i++){
		printf("\nEnter the %d element: ",i+1);
		scanf("%d", &a[i]);
	}
}

int find_max(int arr[],int n){
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}
