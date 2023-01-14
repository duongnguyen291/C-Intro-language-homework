#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main(){
    
    /*Nhập và sinh kết quả ngẫu nhiên*/
    int ketqua;
    int xoso;
    printf("Nhap xo so:");
    scanf("%d",&xoso);
    if(xoso<0 || xoso>1000000){
        printf("Ban dang ki khong thanh cong!\nHay nhap so duong va it hon 6 chu so!\n");
    }
    int check = abs(ketqua - xoso);
    srand(time(NULL));
    ketqua = 1 + rand()%(100000-1);

    /*Hiển thị số XỔ SỐ nhập và kết quả */
    /*if(xoso<1000000 && xoso>=100000){
        printf("Ve so cua ban la: %d",xoso);
 
    }
    else if(xoso<100000 && xoso >=10000){
        printf("Ve so cua ban la: 0%d",xoso);
 
    }
    else if(xoso<10000 && xoso >=1000){
        printf("Ve so cua ban la: 00%d",xoso);

    }
    else if(xoso<1000 && xoso >=100){
        printf("Ve so cua ban la: 000%d",xoso);

    }
    else if(xoso<100 && xoso >=10){
        printf("Ve so cua ban la: 0000%d",xoso);

    }
    else if(xoso<10 && xoso >=1){
        printf("Ve so cua ban la: 00000%d",xoso);
    }
    else {
        printf("Ve so khong hop le!");
    }
    */
    printf("Ve so cua ban la: %06d",xoso);
/*Hiển thị số KẾT QUẢ nhập và kết quả */
    if(ketqua<1000000 && ketqua>=100000){
        printf("\nKet qua xo so là: %d\n",ketqua);
    }
    else if(ketqua<100000 && ketqua >=10000){
        printf("\nKet qua xo so là: 0%d\n",ketqua);
    }
    else if(ketqua<10000 && ketqua >=1000){
        printf("\nKet qua xo so là: 00%d\n",ketqua);
    }
    else if(ketqua<1000 && ketqua >=100){
        printf("\nKet qua xo so là: 000%d\n",ketqua);
    }
    else if(ketqua<100 && ketqua >=10){
        printf("\nKet qua xo so là: 0000%d\n",ketqua);
    }
    else if(ketqua<10 && ketqua >=1){
        printf("\nKet qua xo so là: 00000%d\n",ketqua);
    }


    /*Thông báo trúng giải*/
    if(check == 0 ){
        printf("Ban da trung giai\n");
        printf("Chuc mung ban da trung giai dac biet voi tri gia 3 ty dong!");
    }
    
    else if(check>=100000 && check % 100000==0){
        printf("Ban da trung giai\n");
        printf("Chuc mung ban da trung giai nhat voi gia tri 200 trieu dong!");
    }
    else if(check >=10000 && check %10000==0){
        printf("Ban da trung giai\n");
        printf("Chuc mung ban da trung giai nhi voi gia tri 100 trieu dong!");
    }
    else if(check >=1000 && check %1000==0){
        printf("Ban da trung giai\n");
        printf("Chuc mung ban da trung giai ba voi gia tri 10 trieu dong!");
    }
    else if(check >=100 && check %100==0){
        printf("Ban da trung giai\n");
        printf("Chuc mung ban da trung giai khuyen khich voi gia tri 500 nghin dong!");
    }
    else {
        printf("\nRat tiec! Ban khong trung giai!");
    }
    return 0;
}