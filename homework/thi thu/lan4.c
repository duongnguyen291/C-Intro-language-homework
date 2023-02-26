//bai quan ly phong tro 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define max 200
void get_by_range(int *n, int a, int b);
void getpositive(int *n);
typedef struct{
  char name[4];
  float dientich;
  int dieuhoa;

}phongtro;
phongtro input_data(){
  phongtro tmp;
  printf("\nNhap ten phong tro: ");
  scanf(" %[^\n]%*c",tmp.name);
  do{
    printf("\nNhap dien tich phong tro ( 10 den 40m^2): ");
    scanf("%f",&tmp.dientich);
  }while(tmp.dientich < 10 || tmp.dientich > 40);
 do{
    printf("\nPhong tro da lap dieu hoa chua?\n\t0.Chua lap dieu hoa\n\t1.Da lap dieu hoa\n\t->  ");
    scanf("%d",&tmp.dieuhoa);
  }while(tmp.dieuhoa < 0   || tmp.dieuhoa >1 );
 return tmp;
}
void print(phongtro *p,int n){
  printf("\n%-10s%-10s%-10s","Ten phong","Dien tich","Dieu hoa");
  for(int i = 0 ;i < n;i++){
    if(p[i].dieuhoa == 1){
      printf("\n%-10s%-10.1f%-10s",p[i].name,p[i].dientich,"Co");
    }
    else  if(p[i].dieuhoa == 0){
      printf("\n%-10s%-10.1f%-10s",p[i].name,p[i].dientich,"Khong");
    }
  }
}
//MAIN
int main(){
  //khai bao bien
  phongtro data[max];
  int dieuhoa[4];
  int cu = 0,moi = 0;
  float dientich;
  int check3 = 0;
  int home;
  float check5;
  phongtro temp;
  //lenh
  do{
    printf("\nMenu\n\t1.Nhap thong tin phong tro\n\t2.In thong tin\n\t3.Tim kiem theo dien tich\n\t4.Sap xep\n\t5.Thong ke so luong dieu hoa can bo sung\n\t6.thoat\n\t-->  ");
    get_by_range(&home,1,6);
    
    switch(home){
    case 1:
      if(moi == 0){
	printf("\nNhap so phong tro: ");
	get_by_range(&moi,0,max);
	cu = moi;
	for(int i = 0;i < moi;i++){
	  printf("\nNhap thong tin cua phong tro thu %d",i+1);
	  data[i]=input_data();
	}

      }
      else if(moi > 0){
	printf("\nNhap so phong them vao: ");
	get_by_range(&moi,0,max-cu);
	for(int i = cu;i < cu+moi;i++){
	  printf("\nNhap thong tin cua phong tro thu %d",i+1);
	  data[i]=input_data();
	}
	cu +=moi;
      }
       break;
    case 2:
      print(data,cu);
      break;
    case 3:
      do{
	printf("\nNhap dien tich can tim: ");
       scanf("%f", &dientich);
            if((dientich< 10)||(dientich > 40)){
                printf("\nBan nhap sai roi! Hay nhap lai!");
            }
        }while((dientich < 10)||(dientich>40));
      check3 = 0;
      for(int i = 0;i < cu;i++){
	if(dientich-5 < data[i].dientich || data[i].dientich < dientich + 5){
	  check3 = 1;
	  break;
	}
      }
      if(check3==1){
	 printf("\n%-10s%-10s%-10s","Ten phong","Dien tich","Dieu hoa");
	 for(int i = 0 ;i < cu;i++){
	   if(dientich - 5 < data[i].dientich && data[i].dientich < dientich+5){
	   if(data[i].dieuhoa == 1){
	     printf("\n%-10s%-10.1f%-10s",data[i].name,data[i].dientich,"Co");
	   }
	   else  if(data[i].dieuhoa == 0){
	     printf("\n%-10s%-10.1f%-10s",data[i].name,data[i].dientich,"Khong");
	   }
	 }
	}
      }
      else if(check3==0){
	printf("\nKhong co phong thoa man!");
      }
      break;
    case 4:
      for(int i = 0;i < cu - 1 ;i++){
	for(int j = i+1;j < cu ;j++){
	  if(data[i].dientich < data[j].dientich){
	    temp = data[i];
	    data[i] = data[j];
	    data[j] = temp;
	  }	  
	}
      }
      print(data,cu);
      break;
    case 5:
      for( int i = 0; i < 4;i++){
	dieuhoa[i] = 0;
      }
      for(int i = 0;i < cu;i++){
	check5= data[i].dientich;
	if(data[i].dieuhoa==0){
	  if(check5 <15){
	    dieuhoa[0]+=1;
	  }
	  else if(check5>=15 &&check5<22){
	    dieuhoa[1]+=1;
	  }
	  else if(check5>=22&&check5<30){
	    dieuhoa[2]+=1;
	  }
	  else if(check5>=30&&check5<=40){
	    dieuhoa[3]+=1;
	  }
	  else printf("\nSai lieu");
	}
      }
      printf("\nSo luong dieu hoa can mua la: ");
      printf("\n\t1.9000BTU: %d\n\t2.12000BTU: %d\n\t3.18000BTU: %d\n\t4.21000BTU: %d\n",dieuhoa[0],dieuhoa[1],dieuhoa[2],dieuhoa[3]);
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
                printf("\nBan nhap sai roi! Hay nhap lai!");
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
