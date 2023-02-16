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
//Tổng hợp các thuật toán sắp xếp mảng
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}
//
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}
//quicksort
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* Hàm chính sắp xếp mảng */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số phân hoạch */
        int pi = partition(arr, low, high);
 
        // Sắp xếp các phần tử trước và sau phân hoạch
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Hàm phân hoạch mảng để sắp xếp */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Chỉ số của phần tử nhỏ nhất
 
    for (int j = low; j <= high- 1; j++)
    {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot)
        {
            i++;    // Tăng chỉ số phần tử nhỏ nhất
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}




int main(){
    printf("Hello");
    return 0;
}