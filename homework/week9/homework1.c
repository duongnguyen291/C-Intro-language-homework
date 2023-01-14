#include <stdio.h>
int main(){
    int ngay_nam_vien,ngay_nam_vien_tatca = 0;
    int noitru = 150000,check1,check2,check3;
    float tien_thuoc,tien_phau_thuat,tien_thuoc_tatca = 0,tien_phau_thuat_tatca = 0;
    float discount;
    int home = 1, exit = 1;
    float tong_tien = 0, tien_thanh_toan = 0;
    int so_benh_nhan = 0;
    float luu_tru_tong_tien[100];
    float luu_tru_tien_thanh_toan[100];
    float luu_tru_tien_thuoc[100];
    float luu_tru_tien_phau_thuat[100];
    int gold, silver, citizen;
    float the_most_profit;
    float luu_tru_tien_bao_hiem[100];

    do{
        exit = 1;
        home = 1;
        printf("\nMENU\n1. Input data/Bill for new patient");
        printf("\n2. Print the total report");
        printf("\n3. Quit");
        
        do{
            printf("\nYour choice is: ");
            scanf(" %d",&home);  
                if(home<1||home>3){
                    printf("\nThe input is incorrect!!You have to choose 1, 2 or 3!");
                }
                }while(home<1||home>3);
        
            switch(home){

            case 1:
                the_most_profit = 0;
                silver = gold = citizen = 0;
                tien_thuoc_tatca = 0;
                tien_phau_thuat_tatca =0;
                tien_thanh_toan = 0;
                tong_tien = 0;
                so_benh_nhan = 0;
                do{
                    so_benh_nhan++; 
                    discount = 0;
                    check3 = 2;
                        printf("So ngay ban nam vien? ");
                        scanf("%d",&ngay_nam_vien);
                        ngay_nam_vien_tatca += ngay_nam_vien;

                        printf("So tien ban mua thuoc? ");
                        scanf("%f",&tien_thuoc);
                        
                        /*hỏi phẫu thuật hay không*/
                        printf("Ban co phai phau thuat khong? (1:co,0:Khong)\n");
                        scanf("%d", &check1);
                            if(check1 == 1){
                                printf("So tien phau thuoc la bao nhieu? ");
                                scanf("%f",&tien_phau_thuat);
                            }
                            else if (check1 == 0){
                                tien_phau_thuat = 0;
                            }
                            else {
                                printf("Ban chi duoc nhap 0 va 1! ");
                            }
                            /*hỏi bảo hiểm y tế */
                        printf("Bao hiem y te cua ban la loai gi?\n\t1.Gold(G)\n\t2.Silver(S)\n\t3.Citizen(C)\nƯ");
                        do{
                            printf("\nYour choice: ");
                            scanf("%d",&check2); 
                                if(check2==1){
                                    discount = 0.3;
                                    gold++;
                                }
                                else if(check2==2){
                                    discount = 0.5;
                                    silver++;
                                }
                                else if(check2==3){
                                    discount = 0.7;
                                    citizen++;
                                }
                                else{
                                    printf("Ban chi duoc nhap 1,2,3! ");
                                } 
                        }while(check2<1||check2>3);
                        //gán tiền từng bệnh nhân một
                        luu_tru_tien_thuoc[so_benh_nhan] = tien_thuoc; 
                        luu_tru_tien_phau_thuat[so_benh_nhan] = tien_phau_thuat;
                        luu_tru_tong_tien[so_benh_nhan] = ngay_nam_vien*150000 + tien_thuoc + tien_phau_thuat;
                        luu_tru_tien_thanh_toan[so_benh_nhan] = discount*luu_tru_tong_tien[so_benh_nhan];
                        luu_tru_tien_bao_hiem[so_benh_nhan] = luu_tru_tong_tien[so_benh_nhan] - luu_tru_tien_thanh_toan[so_benh_nhan];                

                        
                    printf("\nDo you want to enter new bill for new patient?\n\t1.Yes\n\t2.No");
                    do{
                        printf("\nYour choice: ");
                        scanf("%d",&check3); 
                        if(check3<1||check3>2){
                            printf("\nThe input is incorrect!!You have to choose 1, 2 !");
                        }
                    }while(check3<1||check3>3);

                }while(check3 == 1); 
                
                    //tính tổng tiền các bệnh nhân
                for(int i = 1; i<=so_benh_nhan; i++){
                    tien_thuoc_tatca += luu_tru_tien_thuoc[i]; 
                }
                for(int i = 1; i<=so_benh_nhan; i++){
                    tien_phau_thuat_tatca += luu_tru_tien_phau_thuat[i]; 
                }
                
                for(int i = 1; i<=so_benh_nhan ; i++){
                    tong_tien += luu_tru_tong_tien[i];
                }
                for(int i = 1; i<=so_benh_nhan;i++){
                    tien_thanh_toan += luu_tru_tien_thanh_toan[i];
                }
                the_most_profit = luu_tru_tien_bao_hiem[1];
                for(int i = 1; i<=so_benh_nhan;i++){
                    if(luu_tru_tien_bao_hiem[i] >= the_most_profit){
                        the_most_profit = luu_tru_tien_bao_hiem[i];
                    }
                }
                
                // printf("\nHOA DON TIEN VIEN");
                    printf("\nCac khoan chi phi:");
                    printf("\n\tTien noi tru (150000/ngay): %dx150000=%d (VND)",ngay_nam_vien,ngay_nam_vien*noitru);
                    printf("\n\tTien thuoc: %.2f (VND)",tien_thuoc);
                    printf("\n\tTien phau thuat: %.2f (VND)",tien_phau_thuat);
                    printf("\n---------------------------------------------------");
                    printf("\nTong tien: %dx150000 + %.2f + %.2f = %.2f (VND)",ngay_nam_vien,luu_tru_tien_thuoc[so_benh_nhan],luu_tru_tien_phau_thuat[so_benh_nhan],luu_tru_tong_tien[so_benh_nhan]);
                    printf("\nTien can thanh toan(da bao gom bao hiem): %.2fx%.1f=%.2f (VND)",luu_tru_tong_tien[so_benh_nhan],discount,luu_tru_tien_thanh_toan[so_benh_nhan]);
                break;

            case 2:
                /*Hóa đơn*/
                printf("\n--------------------------------------------------");
                printf("\nHOA DON TIEN VIEN");
                printf("\nSo benh nhan la %d",so_benh_nhan);
                printf("\nCac khoan chi phi:");
                printf("\n\tTien noi tru (150000/ngay): %dx150000=%d (VND)",ngay_nam_vien_tatca,ngay_nam_vien_tatca*noitru);
                printf("\n\tTien thuoc: %.2f (VND)",tien_thuoc_tatca);
                printf("\n\tTien phau thuat: %.2f (VND)",tien_phau_thuat_tatca);
                printf("\n---------------------------------------------------");

                printf("\nSo bao hiem y te G S C la: %d (G), %d (S) %d (C)",gold,silver,citizen);
                printf("\nTong tien: %.2f (VND)",tong_tien);
                printf("\nTien can thanh toan(da bao gom bao hiem): %.2f (VND)",tien_thanh_toan);
                printf("\nSo tien trung binh moi benh nhan phai tra la:%.2f : %d = %.2f",tien_thanh_toan,so_benh_nhan,tien_thanh_toan/(float)so_benh_nhan);
                printf("\nSo tien lon nhat duoc huong tu bao hiem la: %.2f",the_most_profit);
                break;
            case 3:
                exit = 3;
                continue;
            default: 
                printf("");
                break;
            }
    }while(exit != 3);
    return 0;
}