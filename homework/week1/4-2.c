#include <stdio.h>
int main(){
    char s1[100],s2[100],s3[100],s4[100];
    char ten1[100],ten2[100],ten3[100];
    int dd1,mm1,yyyy1;
    int id,dd2,mm2,yyyy2;

    printf("Enter Name of University: ");
    scanf("%s",s1);
    scanf("%s",s2);
    scanf("%s",s3);
    scanf("%s",s4);
    printf("Enter Your Name:");
    scanf("%s",ten1);
    scanf("%s",ten2);
    scanf("%s",ten3);
    printf("Enter Your Date of Birth (dd/mm/yyyy):");
    scanf("%d%*c%d%*c%d",&dd1,&mm1,&yyyy1);
    printf("Enter Your ID:");
    scanf("%d",&id);
    printf("Enter Expired Year(dd/mm/yyyy):");
    scanf("%d%*c%d%*c%d",&dd2,&mm2,&yyyy2);

    







    printf("-----------------------------------------------------------------");
    printf("\n\n######\tTRUONG DAI HOC %s %s %s %s\n######\tHANOI UNIVERSITY OF SCIENCE AND TECHNOLOGY\n######",s1,s2,s3,s4);
    printf("\n-----------------------------------------------------------------");
    printf("\n##########\tHo ten/Name\t\t\t\t\t#\n##########\t%s %s %s\t\t\t\t#",ten1,ten2,ten3);
    printf("\n##########\tNgaysinh/D.O.B\t\t\t\t\t#\n##########\t%d/%d/%d\t\t\t\t\t#",dd1,mm1,yyyy1);
    printf("\n##########\tTRUONG CONG NGHE THONG TIN VA TRUYEN THONG\t#\n##########\tCONG NGHE THONG TIN GLOBAL ICT 2022-K67\t\t#\n##########\tINFORMATION TECHNOLOGY\t\t\t\t#");
    printf("\nMSSV/ID No.\tGia tri den/ Valid Until\t\t\t#");
    printf("\n %d\t%d/%d/%d\t\t\t\t\t#\n",id,dd2,mm2,yyyy2);
    printf("\n-----------------------------------------------------------------");

    return 0;
}