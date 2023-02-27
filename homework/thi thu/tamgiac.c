#include <stdio.h>

// Hàm vẽ tam giác
void veTamGiac(int chieuCao, int xuoi) {
    int i, j;

    if (xuoi) {
        // Tam giác xuôi
        for (i = 1; i <= chieuCao; i++) {
            for (j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else {
        // Tam giác ngược
        for (i = chieuCao; i >= 1; i--) {
            for (j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
}
void veTamGiacCan(int chieuCao, int xuoi) {
    int i, j, k;

    if (xuoi) {
        // Tam giác cân xuôi
        for (i = 1; i <= chieuCao; i++) {
            for (k = chieuCao - i; k > 0; k--) {
                printf(" ");
            }
            for (j = 1; j <= 2 * i - 1; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else {
        // Tam giác cân ngược
        for (i = chieuCao; i >= 1; i--) {
            for (k = chieuCao - i; k > 0; k--) {
                printf(" ");
            }
            for (j = 1; j <= 2 * i - 1; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
}
int main() {
    int chieuCao, xuoi;

    printf("Nhap chieu cao cua tam giac: ");
    scanf("%d", &chieuCao);

    printf("Nhap 1 de ve tam giac xuoi, 0 de ve tam giac nguoc: ");
    scanf("%d", &xuoi);

    veTamGiacCan(chieuCao, xuoi);


    //đổi sdt

    char s[12];
    printf("Nhap so dien thoai: ");
    scanf("%s", s);

    // Loai bo chu so dau tien neu la 0
    if (s[0] == '0') {
        memmove(s, s+1, strlen(s)); // Dich chuyen chuoi sang trai mot vi tri
    }

    // Xu ly theo quy tac
    if (strlen(s) == 11) {
        printf("Khac nha mang!\n");
    } else if (strncmp(s, "169", 3) == 0) {
        printf("39%s\n", s+3);
    } else if (strncmp(s, "168", 3) == 0) {
        printf("38%s\n", s+3);
    } else if (strncmp(s, "167", 3) == 0) {
        printf("37%s\n", s+3);
    } else if (strncmp(s, "166", 3) == 0) {
        printf("36%s\n", s+3);
    } else if (strncmp(s, "165", 3) == 0) {
        printf("35%s\n", s+3);
    } else if (strncmp(s, "164", 3) == 0) {
        printf("34%s\n", s+3);
    } else if (strncmp(s, "163", 3) == 0) {
        printf("33%s\n", s+3);
    } else if (strncmp(s, "162", 3) == 0) {
        printf("32%s\n", s+3);
    } else if (strncmp(s, "161", 3) == 0) {
        printf("31%s\n", s+3);
    } else if (strncmp(s, "160", 3) == 0) {
        printf("30%s\n", s+3);
    } else {
        printf("Khong dung quy tac!\n");
    }

    return 0;
}