#include <stdio.h>
int main(){
    int mm,yy;
    printf("Nhap vao thang va nam (mm/yy):");
    scanf("%d%*c%d",&mm,&yy);
    if(yy%4==0){
        switch (mm)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("Thang %d co 31 ngay!",mm);
            break;
        case 4:
        case 6:
        case 9:
            printf("Thang %d có 30 ngay!",mm);
            break;
        case 2: 
            printf("Thang %d co 29 ngay!",mm);
        default:
            break;
        }
    }
    else if(yy%4!=0){
        switch (mm)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("Thang %d co 31 ngay!",mm);
            break;
        case 4:
        case 6:
        case 9:
            printf("Thang %d có 30 ngay!",mm);
            break;
        case 2: 
            printf("Thang %d co 28 ngay!",mm);
        default:
            break;
        }
    }
    return 0;
}