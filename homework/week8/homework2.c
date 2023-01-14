#include <stdio.h>
#include <math.h>
int main(){
    //tạo giao diện menu
    char home; 
    int check=0; 
    float saiso,n;
    int check1=0;
    //khai báo của sinx
    double giaithua,dau;
    double S_truoc,S_sau,T,luythua;
    //khai báo biến của e mũ x
	double kGiaiThua = 1;
	int k =0;
	double xMuK = 1 ;
	double kq = 0 ;
	double tam = xMuK / kGiaiThua;
    //khai báo biến của căn bậc x
    double xn,ketqua;
    xn = (n+1)/2;
    do{
    printf("\nMENU - MAY TINH KHOA HOC!");
    printf("\n\t(N). Nhap lieu - nhap so thuc duong va sai so");
    printf("\n\t(S). Sin(x)");
    printf("\n\t(C). Can bac hai cua x");
    printf("\n\t(E). e mu x");
    printf("\n\t(T). Thoat");
    printf("\nLua chon cua ban la: ");
    scanf(" %c",&home);
    switch(home)
    {
    //nhập số N (home==N)
    case 'N':
    case 'n':
    //nhập số n
       do{
    printf("\nEnter n: ");
    scanf("%f",&n);
    if(n<=0){
        printf("Hay nhap so lon hon 0!");
    }
    }while(n<=0);
    //nhập sai số
    do{ 
    printf("\nNhap sai so: ");
    scanf("%f",&saiso); 
    if(saiso<=0){
        printf("Hay nhap so lon hon 0!");      
    }
    }while(saiso<=0);
        break;

    //Tính sinx
    case 'S':
    case 's':
    S_truoc=S_sau=T=luythua=n;
    dau=-1,giaithua=1;
       for(int i=3;i<50;i+=2,dau=-dau){
            S_truoc=S_sau;
            T=(luythua*=n*n)/(giaithua*=i*(i-1));
            S_sau+=(dau*T);
            if(fabs(S_sau-S_truoc)<saiso){
                break;
            }
        }
        printf("\nSinx tinh bang taylor la: %lf",S_sau);
        printf("\nSinx tinh bang thu vien la: %lf",sin(n));

       break;
    //Tính e mũ x
    case'E':
    case 'e':
        kGiaiThua = 1;
        k = 0;
        xMuK = 1;
        kq = 0;
        tam = xMuK / kGiaiThua;
        while(tam >= saiso) {
		kq += tam;
		k++;
		xMuK *= n;
		kGiaiThua *= k;
		tam = xMuK / kGiaiThua;
	}
        printf("\nE mu x tinh bang taylor la: %lf",kq);
        printf("\nE mu x tinh bang thu vien la: %lf",exp(n));
    
        break;
    case 'C':
    case 'c':
        xn=(n+1)/2;
        do{
            ketqua = xn;
            xn = 0.5 * (xn + n/xn);
        }while(fabs(xn-ketqua)>saiso);
        printf("\nCan bac hai cua x la: %lf",xn);
        printf("\nCan bac hai cua x tinh bang thu vien la: %lf",sqrt(n));
        break;
    //thoát
    case 'T':
    case 't':
        check=1;
    break;
    default:
    printf("\nBan nhap sai roi! Hay nhap dung ki tu");
        break;
    }
    }while(check==0);
    return 0;
}