#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define amountClass 200
typedef struct bkhoa{
  int classID;
  char courseName[30];
  char room[10];
  int day;
  char slots[10];
}bkhoa;
void get_by_range(int *n, int a, int b);
void getpositive(int *n);
void bo_sung_lop_hoc(struct bkhoa *p,int new, int old){
  for(int i = old ; i < new;i++){
    printf("Nhap mon hoc thu %d",i+1);
    do{
  printf("\nNhap Class ID: ");
  scanf("%d",&p[i].classID);
  if(p[i].classID < 1){printf("\nVui long nhap so lon hon 0");}
  }while(p[i].classID < 1);
  printf("\nNhap Course Name(ten hoc phan): ");
  scanf(" %[^\n]%*c", p[i].courseName);
  printf("\nNhap Room(phong hoc: vi du: D3-301): ");
  scanf(" %[^\n]%*c", p[i].room);
  do{
  printf("\nNhap ngay hoc: ");
  scanf("%d",&p[i].day);
    //lam not chuc nang
  if(p[i].day < 2||p[i].day>7){
    printf("\nNgay hoc phai be hon 2 va lon hon 7");}
  }while(p[i].day < 2|| p[i].day>7);
  printf("\nNhap tiet hoc bat dau va ket thuc:");
  scanf(" %[^\n]",p[i].slots);
  //for(int j = 0 ;j < strlen(p[i].slots;j++){
  //p[i][j].slots  } 
  }
}

void in_thong_tin_lop(struct bkhoa *p, int n){
  printf("%-10s%-30s%-15s%-5s%-10s","Ma lop", "Ten mon hoc", "Ten phong", "Thu", "Tiet hoc");
  for(int i = 0 ; i < n;i++){
    printf("\n%-10d%-30s%-15s%-5d%-10s",p[i].classID,p[i].courseName,p[i].room,p[i].day,p[i].slots);
  }
}
void tim_kiem_phong(struct bkhoa *p,int n, char *class){
  for(int i = 0; i < n;i++){
    if(strcmp(p[i].room,class) == 0){
      printf("\n%-10d%-30s%-15s%-5d%-10s",p[i].classID,p[i].courseName,p[i].room,p[i].day,p[i].slots); 
  }
  }
}
  int kiem_tra_phong(struct bkhoa *p,int n, char *class){
    int check = 0;
    for(int i = 0; i < n;i++){
      if(strcmp(p[i].room,class) == 0){
	check = 1;
	continue;
      }
    }
    return check;
  }
void sap_xep(struct bkhoa *p,int n){
  int temp_classid,temp_day;
  char temp_name[30], temp_slots[10], temp_room[10];
  //sap xep theo thu tu tang dan
  for(int i = 0;i< n -1;i++){
 for(int j = 0; j < n-i-1; j++){
    if(p[j].classID > p[j+1].classID){
        // hoan doi gia tri giua p[j] va p[j+1]
        struct bkhoa temp = p[j];
        p[j] = p[j+1];
        p[j+1] = temp;
    }
 }
  }
}
void trung_phong(struct bkhoa *p,int n){


}
//MAIN
int main(){
  //khai bao bien
  int home;
  bkhoa data[amountClass];
  int n_cu = 0;
  int n_moi= 0;
  char timphong[10];
  //lenh
  do{
    printf("\nMenu chuong trinh\n\t1.Bo sung lop hoc\n\t2.In thong tin cac lop hoc\n\t3.Tim kiem theo phong\n\t4.Sap xep\n\t5.Kiem tra trung phong\n\t6.Thoat chuong trinh\nYour choice is:   ");
    scanf("%d",&home);
    switch(home){
    case 1:
      printf("Nhap so lop hoc can bo sung (N > 0 va N < %d): ", amountClass-n_cu);
      n_cu += n_moi;
      get_by_range(&n_moi,1,amountClass-n_cu);
      bo_sung_lop_hoc(data,n_moi+n_cu,n_cu);
       break;
    case 2:
     in_thong_tin_lop(data,n_cu+n_moi);
      break;
    case 3:
    
      printf("\nNhap phong ban muon tim kiem : ");
      scanf(" %[^\n]%*c", timphong);
      if(kiem_tra_phong(data,n_cu+n_moi,timphong)==0){
	printf("Khong ton tai phong %s trong danh sach",timphong);
      }
      else if(kiem_tra_phong(data,n_cu+n_moi,timphong)==1){
	printf("%-10s%-30s%-15s%-5s%-10s","Ma lop", "Ten mon hoc", "Ten phong", "Thu", "Tiet hoc");
	tim_kiem_phong(data,n_cu+n_moi,timphong);
      }
      break;
    case 4:
      sap_xep(data,n_cu+n_moi);
      in_thong_tin_lop(data,n_cu+n_moi);
      break;
    case 5:
      break;
    case 6:
      exit(0);
      break;
    default:
      printf(" Again");
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
