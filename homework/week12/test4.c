#include <stdio.h>

typedef struct quanlysinhvien{
    long long mssv;
    char name[33];
    float grade;
    char classment;
    } student;

student input(){
    student hocsinh;
    printf("MSSV  ");
    scanf("%lld", &hocsinh.mssv);
    printf("name  ");
    scanf(" %[^\n]%*c",&hocsinh.name);
    //scanf("%s",hocsinh.name);
    printf("grade  ");
    scanf("%f", &hocsinh.grade);
    if( hocsinh.grade >= 9 && hocsinh.grade <=10){
        hocsinh.classment='A';
    }
    if( hocsinh.grade >= 8 && hocsinh.grade <9){
        hocsinh.classment='B';

    }
    if( hocsinh.grade >= 6.5 && hocsinh.grade <8){
        hocsinh.classment='C';
    }
    if( hocsinh.grade <6.5){
        hocsinh.classment='D';}

    return hocsinh;}

int main (){
    int n;
    printf("so sinh vien ");
    scanf("%d", &n);
    int i=0;
    student a[n];
    for(i=0; i<n; i++){
        a[i]=input();
    }
    int j=0;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            student temp;
            if(a[i].grade<a[j].grade){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("MSSV\t\tNAME\t\tGRADE\t\tCLASSMENT\n");
    for(i=0; i<n; i++){
        printf("%lld\t", a[i].mssv);
       puts(a[i].name);
     // printf("%s",a[i].name);
        printf("\t\t%f\t\t%c\n", a[i].grade, a[i].classment);

    }

    }