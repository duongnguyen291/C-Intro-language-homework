#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
    
typedef struct student{
    char name[1000];
}student;

void removeWhitespace(char str[]){
    //xóa khoảng trắng
    int i = 0, j = 0;
    while (str[i])
    {
        while (isspace(str[i]) && isspace(str[i + 1]))
        {
            i++;
        }
        str[j++] = str[i++];
    }
    str[j] = '\0';
}
//lower all the characters
char *lower(char str[]){
    for(int i = 0; i < strlen(str);i++){
        str[i] = tolower(str[i]);
    }
    return str;
}
char *upper_first_character(char str[]){
    str[0] = toupper(str[0]);
    for(int i = 1; i <strlen(str); i++){
        if(isspace(str[i]) && str[i+1] != ' '){
            str[i+1] = toupper(str[i+1]);
        }
    }
    return str;
}
void chuan_hoa_ten(char a[]){
    removeWhitespace(a);
    lower(a);
    upper_first_character(a);
}

int main(){
    student a,b,c,d,e;
    student p[10];
    int home;
    do{
        printf("\nMENU\n\t1.Enter the name of 5 student\n\t2.Chuan hoa ten\n\t3.Quit\n");
        scanf("%d",&home);
        switch (home)
        {
        case 1:
            printf("\nEnter the name of student a: ");
            scanf(" %[^\n]%*c",a);
            break;
        case 2:
            chuan_hoa_ten(a.name);
            chuan_hoa_ten(b.name);
            chuan_hoa_ten(c.name);
            chuan_hoa_ten(d.name);
            chuan_hoa_ten(e.name);

                printf("\n%s",a.name);
                printf("\n%s",b.name);
                printf("\n%s",c.name);
                printf("\n%s",d.name);
                printf("\n%s",e.name);       
            break;;
        case 3:
            exit(0);
            break;
        default:
            printf("\nYour choice is incorrect format");
            break;
        }
    }while(1);

    return 0;
}