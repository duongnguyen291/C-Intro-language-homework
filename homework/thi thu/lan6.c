#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define max 100
void get_by_range(int *n, int a, int b);
void getpositive(int *n);
typedef struct{
  char name[20];
  float dai,rong,cao;
  int vanchuyen;
  float trongluong;
  float tienvanchuyen;
  float trongluongquydoi;
  
}shoppe;
float lamtron(float x){
  float integer_part = floor(x);
  float integer_thap = x - floor(x);
  if(integer_thap <=0.5){
    return integer_part + 0.5;
  }
  else return integer_part + 1;
}
shoppe input_data(){
  shoppe tmp;
  int check1;
  do{
    check1 = 1;
  printf("\nNhap ma kien hang(8 den 20 ki tu, chi so hoac chu): ");
  scanf(" %[^\n]%*c",tmp.name);
  for(int i = 0; i <strlen(tmp.name);i++){
    if(isalnum(tmp.name[i])==0){
      check1 = 0;
      break;
    }
  }
  }while((strlen(tmp.name) < 8 || strlen(tmp.name) > 20) || check1 == 0 );
  do{
  printf("\nNhap chieu dai-chieu rong-chieu cao (l-w-h): ");
  scanf("%f%*c%f%*c%f",&tmp.dai,&tmp.rong,&tmp.cao);
  if(tmp.dai < 0|| tmp.rong < 0 || tmp.cao < 0) printf("\nChieu dai chieu rong chieu cao lon hon 0");
  }while(tmp.dai < 0|| tmp.rong < 0 || tmp.cao < 0);
  do{
    printf("\nTrong luong tinh cua kien hang la: ");
    scanf("%f",&tmp.trongluong);
    if(tmp.trongluong<=0) printf("\nTrong luong can lon hon 0");
  }while(tmp.trongluong<=0);
  do{
    printf("\nChon loai van chuyen\n\t0.Van chuyen thuong\n\t1.Van chuyen nhanh\n\t-->");
    scanf("%d",&tmp.vanchuyen);
    if(tmp.vanchuyen < 0 || tmp.vanchuyen > 1) printf("\nChi duoc chon 1 hoac 0");
  }while(tmp.vanchuyen < 0 || tmp.vanchuyen > 1);
  return tmp;

}
void kienhangtuchoi(shoppe *p,int n){
  int count = 0;
  int check;
  printf("\nChi tiet cac kien hang bi tu choi la\n");
  printf("\n%-25s%-15s","Ma kien","Ly do tu choi");
  
  for(int i = 0; i < n ;i++){
    check = 0;
    if(p[i].dai < 10 || p[i].rong< 10 || p[i].cao <10){
      check = 1;
    }
    else if(p[i].dai > 150 || p[i].rong >150 || p[i].cao > 150){
      check = 2;
    }
    else if(p[i].trongluong > 30){
      check = 3;
    }
    if(check == 1){
       printf("\n%-25s%-15s",p[i].name ,"ER1");
       count++;
    }
    else if(check == 2){
      printf("\n%-25s%-15s",p[i].name ,"ER2");
      count++;
    }
    else if(check ==3){
     printf("\n%-25s%-15s",p[i].name ,"ER3");
     count++;
    } 
  }
  if(check == 0){
    printf("\nKhong co kien hang nao loi!");
  }
  printf("\nTong so: %d",count);
  
		  
}
void trongluongquydoi(shoppe *p,int n){
  for(int i = 0 ; i< n ;i++){
    if((p[i].dai + p[i].rong+ p[i].cao) < 80 ){
      p[i].trongluongquydoi = lamtron(p[i].trongluong);
    }
    else if((p[i].dai + p[i].rong +p[i].cao) >=80){
      if(p[i].vanchuyen == 0){
	p[i].trongluongquydoi = lamtron((p[i].dai*p[i].rong*p[i].cao)/4000);
      }
      else if(p[i].vanchuyen == 1){
	p[i].trongluongquydoi = lamtron((p[i].dai*p[i].rong*p[i].cao)/6000);
      }
      else printf("\nLoi kia");
    }
    else printf("\nLoi 1");
  }
   printf("\nChi tiet trong luong quy doi\n");
  printf("\n%-25s%-15s","Ma kien","Trong luong quy doi");
  for(int i = 0; i < n;i++){    
    printf("\n%-25s%-15.2f",p[i].name,p[i].trongluongquydoi);
  }
}
void tinhtien(shoppe *p,int n){
  for(int i = 0;i < n;i++){
  if(p[i].vanchuyen == 0){
    if(p[i].trongluongquydoi <= 3) p[i].tienvanchuyen = 16500;
    else {
      p[i].tienvanchuyen = 16500 + ((p[i].trongluongquydoi - 3)/0.5)*2500;
    }
    }
    
  
  else if(p[i].vanchuyen == 1){
    if(p[i].trongluongquydoi <= 3) p[i].tienvanchuyen = 22000;
    else{
      p[i].tienvanchuyen = 22000 + ((p[i].trongluongquydoi - 3)/0.5)*2500;
    }
    
  }
  }
    printf("\nChi tiet tien hang van chuyen\n");
  printf("\n%-25s%-15s","Ma kien","Tien van chuyen"); 
  for(int i = 0; i < n;i++){    
    printf("\n%-25s%-15.2f(VND)",p[i].name,p[i].tienvanchuyen);
  }
}
void donhanghople(shoppe *p,int n){
  int count = 0;
  int check;
   printf("\nChi tiet tien hang van chuyen hop le la\n");

   printf("\n%-25s%-20s%-30s%-10s","Ma kien","Can nang tinh phi","Hinh thuc van chuyen","Cuoc phi");
   for(int i = 0; i < n ;i++){
    check = 0;
    if(p[i].dai < 10 || p[i].rong< 10 || p[i].cao <10){
      check = 1;
    }
    else if(p[i].dai > 150 || p[i].rong >150 || p[i].cao > 150){
      check = 2;
    }
    else if(p[i].trongluong > 30){
      check = 3;
    }
    //
   if(check ==0){
      if(p[i].vanchuyen == 0){
	printf("\n%-25s%-20.2f%-30s%-10.2f",p[i].name,p[i].trongluongquydoi,"Chuyen thuong",p[i].tienvanchuyen); 
      }
      else if(p[i].vanchuyen == 1){
	printf("\n%-25s%-20.2f%-30s%-10.2f",p[i].name,p[i].trongluongquydoi,"Chuyen nhanh",p[i].tienvanchuyen);
      }
      count++;
    }
  }
   printf("\nTong so: %d",count);
}
void tongtien(shoppe *p,int n){
  //kiem tra tinh hop le cua hon hang
  int count = 0;
  int check;
  float sum = 0;
  float vat = 0;
  float total = 0;
   printf("\nChi tiet tien hang van chuyen hop le la\n");
   for(int i = 0; i < n ;i++){
    check = 0;
    if(p[i].dai < 10 || p[i].rong< 10 || p[i].cao <10){
      check = 1;
    }
    else if(p[i].dai > 150 || p[i].rong >150 || p[i].cao > 150){
      check = 2;
    }
    else if(p[i].trongluong > 30){
      check = 3;
    }
    //don hang thoa man
    if(check == 0){
      sum+=p[i].tienvanchuyen;
      count++;
    }   
   }
   vat = 0.08 * sum;
   total = sum+vat;
    //bat dau in ra menu
    printf("\nChi phi van chuyen\n=============");
    printf("\nSo kien da nhan: %d",count);
    printf("\nSo tien: %.2f",sum);
    printf("\nVAT: %.2f",vat);
    printf("\nTong chi phi: %.2f",total);
    
	   
}
//MAIN
int main(){
  //khai bao bien
  int home;
  shoppe data[100];
  int n;
  //lenh
  do{
    printf("\nMenu\n\t1.Nhap thong tin kien hang\n\t2.In ra kien hang bi tu choi\n\t3.Trong luong quy doi cua mot kien hang\n\t4.Tinh tien cua kien hang theo trong luong tinh cuoc\n\t5.In ra don hang hop le\n\t6.Tong tien khach hang phai tra\n\t7.Thoat\n\t-->   ");
    get_by_range(&home,1,7);
    switch(home){
    case 1:;
      printf("\nNhap so don hang (0 den 100) : ");
      get_by_range(&n,1,100);
      for(int i = 0; i < n;i++){
	data[i] = input_data();
      }
      
       break;
    case 2:
      kienhangtuchoi(data,n);
      break;
    case 3:
      trongluongquydoi(data,n);
      break;
    case 4:
      tinhtien(data,n);
      break;
    case 5:
      trongluongquydoi(data,n);
      tinhtien(data,n);
      donhanghople(data,n);
      break;
    case 6:
      tongtien(data,n);
      break;
    case 7:
     //thoát chương trình
      exit(0);
      break;
    default:
      printf("\nBan chon sai roi!");
      break;
    } 
  }while(1);

  return 0;
}



void get_by_range(int *n, int a, int b){
    do{
            printf("\nEnter: ");
            scanf("%d", &*n);
            if((*n < a)||(*n > b)){
                printf("\nBan nhap sai roi! Hay nhap lai theo huong dan!");
            }
        }while((*n<a)||(*n>b));
}
void getpositive(int *n){
    do{
        printf("\nEnter: ");
        scanf("%d", &*n);
        if(*n<0){
            printf("\nBan nhap sai roi! Hay nhap lai theo huong dan!");
        }
    }while(*n<0);
}
