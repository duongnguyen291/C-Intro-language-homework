#include <stdio.h>


int main(){
    // int a = 291;
    // int b = 123;
    // float f = 3.141592;
    // int *ipointer = &a;
    // float *fpointer = &f;
    // printf("\nDia chi cua bien a la : %x %d",&a, &a);
    // printf("\nGia tri cua bien a la : %x %d ", a, a);
    // printf("\nGia tri chua trong con tro ptr: %x %d ",ipointer, ipointer);
    // printf("\nDia chi chua trong con tro ptr: %x %d",&ipointer, &ipointer);
    // printf("Dia chi cua a va b lan luot la : %d %d",&a, &b);
    // printf("\nGia tri chua trong con tro ptr: %d ", *ipointer);
    // printf("\nGia tri chua trong con tro ptr: %d %d", ipointer, &ipointer);
    // ipointer = &b;
    // printf("\nGia tri chua trong con tro ptr: %d ", *ipointer);
    // printf("\nGia tri chua trong con tro ptr: %d %d ", ipointer, &ipointer);
    /* ipointer = địa chỉ của biến a ( &a)
        *ipointer = giá trị mà địa chỉ (&a) đang gán 
        &ipointer = địa chỉ của pointer ( ko liên quan gì tới địa chỉ của a (&a) hay giá trị của địa chỉ a đang gán)
    */
    int arr[] = {1,2,3,4,5};
    int *ptr = arr;
    // printf("\nDia chi cua mang : %x", arr);
    // printf("\nDia chi cua arr[0] : %x", &arr[0]);
    // printf("\nGia tri cua ptr : %x", ptr);
    // printf("\nGia tri cua ptr : %x %x" , &ptr, *ptr);

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%5d",arr[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%5d",*(ptr+i));
    // }
    // printf("\n");
    //ptr = 3000;
    //ptr++;//++ptr, ptr = ptr(3000) + (1*số lượng byte của kiểu ptr = 4); 3000 + 4 = 3004
    //ptr +=5 nghĩa là ptr = ptr(3000) + (5* số lượng byte của kiểu ptr = 4); 3000 + 5*4 = 3020 ( đây là địa chỉ của ptr chứ không phải là giá trị)
    
    // for (; ptr <= &arr[4]; ptr++)
    // {
    //     //printf("\n %d %d", ptr, &arr[4]);
    //     printf("%5d",*ptr);
    // }
    printf("\nDia chi cua mang %d %d", &arr[3], arr[3]);
    ptr = 6422292;
    ptr++;
    printf("\nDia chi va gia tri cua ptr la %d %d", ptr, *ptr);
    return 0;
}