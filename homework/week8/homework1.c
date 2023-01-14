#include <stdio.h>
#include <math.h>
#include <string.h>
int main(){
    //viết menu
    int home;
    int n;
    int check =0;
    int check1=0;
    do{
    printf("\nMENU\n1.Nhap so N:\n2.Liet ke cac so hoan hao tu 1 den N\n3.Liet ke cac so nguyen to be hon N\n4.Liet ke cac uoc cua N\n5.Thoat\n");
    printf("Lua chon cua ban la: ");
    scanf("%d%*c",&home);
    switch(home){
        case 1:
    //Nhập số n
    do{
    printf("\nEnter n:");
    scanf("%d",&n);
    home=1;
    check1=2;
    if(n>0){
        break;
    }
    else if(check1>0){
        printf("Hay nhap so lon hon 0!");
    }    
    }while(n<=0);
    break;
        case 2:
    //2.viết chương trình tìm các số hoàn hảo bé hơn N
    printf("So N la: %d\n",n);
    for(int a=2;a<n;a++)
    {
        int sum=0;
        for(int i=1;i<a;i++)
        {
            if(a%i==0){
            sum+=i;
            }

        }
        if(sum==a){
            printf("\nSo hoan hao la: %d",a);
        }
    }
    home=2;
    break;
    //Liệt kê các số nguyên tố bé hơn N
    case 3:
    printf("So N la: %d\n",n);
    printf("\nSo nguyen to la: 2");
    for(int i=3;i<n;i++){
        for(int j=2;j<sqrt(n)+1;j++){
            if(i%j==0){
                check =0;
                break;
            }
            else{
                check =1;
            }
        }
        if(check==1){
            printf("\nSo nguyen to la: %d",i);
        }
    }
    home=3;
    break;
    //Liệt kê các ước của N
    case 4:
    printf("So N la: %d\n",n);
    for(int i=1;i<=n;i++){
        if(n%i==0){
            printf("\nUoc cua N la: %d",i);
        }
    }
    home==4;
    break;
    case 5:
    home==5 ;
    break;
    default: printf("\nNhap du lieu sai! Hay nhap lai!");
    break;
    }
    }while(home==1||home==2||home==4||home==3);
    return 0;
} 