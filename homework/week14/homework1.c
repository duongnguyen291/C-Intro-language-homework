#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void trimRight(char a[]){
    int i = strlen(a) - 1;
while( i > 0 && a[i] == ' '){
    a[i--] = '\0';
} 
    char b[] ="."; 
    strcat(a,b);
}
void trimLeft(char a[]){
    int i = 0;
    int count = 0;
    while(a[i] ==' ' && i < strlen(a)){
        count++;
    }
    a +=count;
}
// char *trimMiddle(char a[]){
//     int i = 0;
//     char p[1000];
//     for(int j = 0; i < strlen(a);j++){
//         if((a[j] = ' ') && (a[j+1] = ' ')){
//             continue;
//         }
//         p[i]=a[j];
//         i++;
//     }
//     p[i]='\0';
//     return p;
// }
void removeWhitespaces(char* str)
{
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

int main(){
    char a[1000];
    char vl[1000];
    int home;

    do{
        printf("\nMENU\n\t1.Enter the string\n\t2.Trim Right\n\t3.Trim Left\n\t4.Trim Middle\n\t5.Quit\n");
        scanf("%d",&home);
        switch (home)
        {
        case 1:
            printf("\nEnter the string a: ");
            scanf(" %[^\n]%*c",a);
            break;
        case 2:
            trimRight(a);
            printf("\n:%s",a);
            break;
        case 3:
            trimLeft(a);
            printf("\n:%s",a);
            break;
        case 4:
            removeWhitespaces(a);
            printf("\n:%s",a);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nYour choice is incorrect format");
            break;
        }
    }while(1);
    return 0;
}