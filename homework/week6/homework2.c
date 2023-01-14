#include <stdio.h>
int main(){
    char name[100];
    int dd,mm,yy,ngay_nam_vien;
    int noitru = 150000,check1,check2;
    float tien_thuoc,tien_phau_thuat;
    float discount;
    printf("Ten ban la gi? ");
    scanf("%[^\n]", name);
    printf("Ngay thang nam sinh (dd/mm/yy): ");
    scanf("%d%*c%d%*c%d",&dd,&mm,&yy);
    int age = 2022 - yy;
    printf("So ngay ban nam vien?");
    scanf("%d",&ngay_nam_vien);
    printf("So tien ban mua thuoc? ");
    scanf("%f",&tien_thuoc);

    /*hỏi phẫu thuật hay không*/
    printf("Ban co phai phau thuat khong? (1:co,0:Khong)\n");
    scanf("%d", &check1);
        if(check1 == 1){
            printf("So tien phau thuoc la bao nhieu?");
            scanf("%f",&tien_phau_thuat);
        }
        else if (check1 == 0){
            tien_phau_thuat = 0;
        }
        else {
            printf("Ban chi duoc nhap 0 va 1!");
        }
    /*hỏi bảo hiểm y tế */
    printf("Bao hiem y te cua ban la loai gi?\n\t1.Gold(G)\n\t2.Silver(S)\n\t3.Citizen(C)\nƯ");
    scanf("%d",&check2);
        if(check2==1){
            discount = 0.3;
        }
        else if(check2==2){
            discount = 0.5;
        }
        else if(check2==3){
            discount = 0.7;
        }
        else{
            printf("Ban chi duoc nhap 1,2,3!");
        }
    float tong_tien = ngay_nam_vien*150000+tien_thuoc+tien_phau_thuat;
    float tien_thanh_toan = tong_tien*discount;
    /*Hóa đơn*/
    printf("Thong tin benh nhan:");
    printf("\n\tHo va ten: %s",name);
    printf("\n\tNgay thang nam sinh: %d/%d/%d",dd,mm,yy);
    printf("\n\tSo tuoi cua benh nhan: %d",age);
    printf("\n--------------------------------------------------");
    printf("\nHOA DON TIEN VIEN");
    printf("\nCac khoan chi phi:");
    printf("\n\tTien noi tru (150000/ngay): %dx150000=%d (VND)",ngay_nam_vien,ngay_nam_vien*noitru);
    printf("\n\tTien thuoc: %.2f (VND)",tien_thuoc);
    printf("\n\tTien phau thuat: %.2f (VND)",tien_phau_thuat);
    printf("\n---------------------------------------------------");
    printf("\nTong tien: %dx150000 + %.2f + %.2f = %.2f (VND)",ngay_nam_vien,tien_thuoc,tien_phau_thuat,tong_tien);
    printf("\nTien can thanh toan(da bao gom bao hiem): %.2fx%.1f=%.2f (VND)",tong_tien,discount,tien_thanh_toan);



    return 0;
}