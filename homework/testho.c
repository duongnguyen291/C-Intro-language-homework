#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//MAIN
int main(){
  //khai bao bien
  int home;
  char sv[5][50];
  char search[50];
  int max;
  //lenh
  do{
    printf("\nMenu\n\t1.Nhap danh sach sinh vien\n\t2.Hien thi danh sach\n\t3.Tim kiem\n\t4.Tim kiem theo so ky tu trong ten\n\t5.Thoat\n\t->     ");
    scanf("%d",&home);
    switch(home){
    case 1:;
		for(int i =0;i < 5;i++){
			printf("\nNhap ten cua sinh vien thu %d: ",i+1);
			scanf(" %[^\n]%*c",sv[i]);
		}
       break;
    case 2:
		printf("\n|%-5s|%-30s|","STT","Ho va ten");
		for(int i = 0 ;i < 5;i++){
			printf("\n|%-5d|%-30s|",i+1,sv[i]);
		}
      break;
    case 3:
    printf("\nNhap chuoi tim kiem: ");
		scanf(" %[^\n]%*c",search);
    search[strlen(search)+1]= '\0';

    // Tìm kiếm sinh viên có tên chứa chuỗi tìm kiếm
    printf("Cac sinh vien co ten chua chuoi '%s':\n", search);
    for (int i = 0; i < 5; i++) {
        if (strstr(sv[i], search) != NULL) {
            printf("\n- %s", sv[i]);
        }
    }
      break;
    case 4:
		printf("\nNhap so ki tu toi da: ");
		scanf("%d",&max);
		for(int i = 0;i < 5;i++){
			if(strlen(sv[i]) <= max ){
				printf("\n- %s",sv[i]);
			}
		}
      break;
    case 5:
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
