#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void get_by_range(int *n, int a, int b);
void getpositive(int *n);
typedef struct {
  char name[50];
  double cccd;
  char sdt[15];
  float nhietdo;
  int ha1,ha2;
  char checksdt[15];
}benhnhan;
benhnhan input_data(){
  benhnhan tmp;
  printf("\nHo va ten: ");
  scanf(" %[^\n]%*c",tmp.name);
  printf("\nNhap can cuoc cong dan: ");
  scanf(" %lf",&tmp.cccd);
  printf("\nNhap so dien thoai: ");
  scanf(" %[^\n]%*c",tmp.sdt);
  printf("\nNhiet do: ");
  scanf(" %f",&tmp.nhietdo);
  printf("\n Huyet ap tam thu: ");
  scanf("%d",&tmp.ha1);
  printf("\n Huyet ap tam truong: ");
  scanf("%d",&tmp.ha2);
  return tmp;
}
int kiemTraNhietDo(float nhietdo){
  if(nhietdo>=36.8&&nhietdo<=38) {return 1;}
  else return 0;
}
int kiemTraHuyetAp(int ha1,int ha2){
  if((ha1>100&&ha1<130) && ( ha2 > 79 &&ha2 < 89)){ return 1;}
     else return 0;
}

//MAIN
int main(){
  //khai bao bien
  int home,check1,check5;
  int n_cu,n_moi;
  int i = 0;
  int ha1,ha2;
  float nhietdo;
  benhnhan data[200];
  char checksdt[15];
  //lenh
  do{
    printf("\nMenu\n\t1.Nhap thong tin\n\t2.In danh sach\n\t3.Kiem tra dieu kien tiem\n\t4.Danh sach du dieu kien tiem\n\t5.Tra cuu thong tin nguoi dang ky tiem theo SDT\n\t6.Thoat \n\t-->  ");
    get_by_range(&home,1,6);
    switch(home){
    case 1:;
      n_cu = n_moi = 1;
      do{
	data[i] = input_data();
	i++;
	printf("\nBan co muon nhap tiep khong?\n\t1.Co\n\t2.Khong\n-> ");
	get_by_range(&check1,1,2);
      }while(check1 == 1);
       break;
    case 2:
      printf("\n%-5s%-30s%-20s%-20s","STT","Ho va ten","CCCD", "SDT");
      printf("\n--------------------------------------------------------");
      for(int j = 0 ;j < i;j++){
	printf("\n%-5d%-30s%-20.0lf%-20s",j+1,data[j].name,data[j].cccd, data[j].sdt);
      }
      break;
    case 3:
      printf("\nKiem tra thu dieu kien duoc tiem: ");
      printf("\nNhap nhiet do, huyet ap tam thu, huyet ap tam truong theo format sau: nhietdo-ha1-ha2: ");
      scanf("%f%*c%d%*c%d",&nhietdo,&ha1,&ha2);

      if(kiemTraNhietDo(nhietdo)==1&&kiemTraHuyetAp(ha1,ha2)==1) printf("\nDu dieu kien tiem!");
      else printf("Khong du dieu kien tiem");
      break;
    case 4:
      printf("\nDanh sach nguoi du dieu kien tiem chung");
      printf("\n%-5s%-30s%-20s%-20s","STT","Ho va ten","CCCD", "SDT");
      printf("\n--------------------------------------------------------");
      for(int j = 0 ;j < i;j++){
	if(kiemTraNhietDo(data[j].nhietdo)&&kiemTraHuyetAp(data[j].ha1,data[j].ha2)){
	printf("\n%-5d%-30s%-20.0lf%-20s",j+1,data[j].name,data[j].cccd, data[j].sdt);
	}
      }
      break;
    case 5:
      check5 = 0;
      printf("\nNhap so dien thoai: ");
      scanf(" %[^\n]%*c",checksdt);
      for(int j = 0;j < i;j++){
	if(strcmp(data[j].sdt,checksdt)==0){
	    check5 = 1;
	    break;
	  }
      }
	if(check5){
	  printf("\nDanh sach nguoi co sdt: %s",checksdt);
      printf("\n%-5s%-30s%-20s%-20s","STT","Ho va ten","CCCD", "SDT");
      printf("\n--------------------------------------------------------");
      for(int j = 0 ;j < i;j++){
	if(strcmp(data[j].sdt,checksdt)==0){
	printf("\n%-5d%-30s%-20.0lf%-20s",j+1,data[j].name,data[j].cccd, data[j].sdt);
	}
      }
	}
	else if(check5==0){
	  printf("\nKhong co nguoi nao");

	}
      break;
    case 6:
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
                printf("\nThe answer is incorrect!Please enter again!");
            }
        }while((*n<a)||(*n>b));
}
void getpositive(int *n){
    do{
        printf("\nEnter: ");
        scanf("%d", &*n);
        if(*n<0){
            printf("\nThe answer is incorrect!Please enter again!");
        }
    }while(*n<0);
}