#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define max 100000
void get_by_range(int *n, int a, int b);
void getpositive(int *n);
// MAIN
typedef struct
{
    char name[30];
    char id[13];
    char que[30];
    float gpa;
} sinhvien;
sinhvien input_data()
{
    sinhvien tmp;
    printf("\nHo va ten: ");
    scanf(" %[^\n]%*c", tmp.name);
    printf("\nNhap ID:  ");
    scanf(" %[^\n]%*c", tmp.id);
    printf("\nNhap que quan:  ");
    scanf(" %[^\n]%*c", tmp.que);
    do
    {
        printf("\nNhap GPA trong khoang 0-4: ");
        scanf("%f", &tmp.gpa);
    } while (tmp.gpa < 0 || tmp.gpa > 4);

    return tmp;
}

void print(sinhvien *p, int n)
{
    printf("\n%-5s%-30s%-15s%-15s%-5s", "STT", "Ten", "MSSV", "Que quan", "GPA");

    for (int i = 0; i < n; i++)
    {
        printf("\n%-5d%-30s%-15s%-15s%-5.1f", i + 1, p[i].name, p[i].id, p[i].que, p[i].gpa);
    }
}
int main()
{
    // khai bao bien
    sinhvien data[max];
    int cu = 0, moi = 0, check;
    float tb, sum;
    sinhvien temp;
    char mssv[13], quequan[30];
    float gpa;
    int home;
    // lenh
    do
    {
        printf("\nMenu\n\t1.Nhap thong tin\n\t2.In thong tin\n\t3.Tim kiem theo ma so sinh vien\n\t4.Tim kiem theo GPA va que quan\n\t5.Sap xep\n\t6.Thoat\n\tLua chon cua ban la:    ");
        scanf("%d", &home);
        switch (home)
        {
        case 1:
            if (moi == 0)
            {
                printf("\nNhap so luong sinh vien: ");
                getpositive(&moi);
                cu = moi;
                for (int i = 0; i < moi; i++)
                {
                    printf("\nNhap sinh vien thu %d", i + 1);
                    data[i] = input_data();
                }
            }
            else if (moi > 0)
            {
                printf("\nNhap them so luong sinh vien moi: ");
                get_by_range(&moi, 0, max - cu);

                for (int i = cu; i < cu + moi; i++)
                {
                    printf("\nNhap sinh vien thu %d", i + 1);
                    data[i] = input_data();
                }
                cu += moi;
            }
            break;
        case 2:
            print(data, cu);
            sum = 0;
            for (int i = 0; i < cu; i++)
            {
                sum += data[i].gpa;
            }
            tb = sum / cu;
            printf("\nDiem trung binh tat ca sinh vien la: %.1f", tb);
            break;
        case 3:
            printf("\nNhap MSSV: ");
            scanf(" %[^\n]%*c", mssv);
            check = 0;

            for (int i = 0; i < cu; i++)
            {
                if (strcmp(data[i].id, mssv) == 0)
                {
                    check = 1;
                    break;
                }
            }
            if (check)
            {
                printf("\n%-5s%-30s%-15s%-15s%-5s", "STT", "Ten", "MSSV", "Que quan", "GPA");

                for (int i = 0; i < cu; i++)
                {
                    if (strcmp(data[i].id, mssv) == 0)
                    {
                        printf("\n%-5d%-30s%-15s%-15s%-5.1f", i + 1, data[i].name, data[i].id, data[i].que, data[i].gpa);
                    }
                }
            }
            else if (check == 0)
            {
                printf("\nKhong co sinh vien nao!");
            }
            break;
        case 4:
            printf("\nNhap que quan: ");
            scanf(" %[^\n]%*c", quequan);

            printf("\n%-5s%-30s%-15s%-15s%-5s", "STT", "Ten", "MSSV", "Que quan", "GPA");

            for (int i = 0; i < cu; i++)
            {
                if ((strcmp(data[i].que, quequan) == 0) && data[i].gpa > tb)
                {
                    printf("\n%-5d%-30s%-15s%-15s%-5.1f", i + 1, data[i].name, data[i].id, data[i].que, data[i].gpa);
                }
            }

            break;
        case 5:

            for (int i = 0; i < cu - 1; i++)
            {
                for (int j = i + 1; j < cu; j++)
                {
                    if (data[i].gpa > data[j].gpa)
                    {
                        temp = data[j];
                        data[j] = data[i];
                        data[i] = temp;
                    }
                }
            }
            print(data, cu);
            break;
        case 6:
            // thoát chương trình
            exit(0);
            break;
        default:
            printf("\nBan chon sai roi!");
            break;
        }
    } while (1);

    return 0;
}

void get_by_range(int *n, int a, int b)
{
    do
    {
        printf("\nEnter: ");
        scanf("%d", &*n);
        if ((*n < a) || (*n > b))
        {
            printf("\nThe answer is incorrect!Please enter again!");
        }
    } while ((*n < a) || (*n > b));
}
void getpositive(int *n)
{
    do
    {
        printf("\nEnter: ");
        scanf("%d", &*n);
        if (*n < 0)
        {
            printf("\nThe answer is incorrect!Please enter again!");
        }
    } while (*n < 0);
}
