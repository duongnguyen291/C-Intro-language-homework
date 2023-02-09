#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void trimRight(char a[]){
    int i = strlen(a) - 1;
while( i > 0 && a[i] == ' '){
    a[i--] = '\0';
} 
    char b[] ="."; 
    strcat(a,b);
}
char *trim_Left(char *source) {
    while (*source == ' ')
        *source++;
    
    return source;
}
void trimMiddle(char a[]){
    



}

char *removeWhitespace(const char *str) {
    int i = 0, j = 0;
    int len = strlen(str);
    char *result = (char *)malloc((len + 1) * sizeof(char));

    while (str[i]) {
        while (str[i] == ' ' && str[i + 1] == ' ') i++;
        result[j++] = str[i++];
    }

    result[j] = '\0';
    return result;
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
            trimMiddle(a);
            printf("\n:%s",a);
            break;
        case 5:
            exit(0);
            break;
        case 6:
            removeWhitespace(a);
            printf("\n:%s",a);
            break;
        default:
            printf("\nYour choice is incorrect format");
            break;
        }
    }while(1);
    return 0;
}