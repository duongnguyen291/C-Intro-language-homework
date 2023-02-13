#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <stddef.h>
#define N 1000
/*
//Trim Left spaces
void trim_Left(char *str) {
    int i = 0, j = 0;

    while (str[i])
    {
        while (isspace(str[i])) i++;
        str[j++] = str[i++];
    }
    str[j] = '\0';
}
//Trim Right spaces
void trim_Right(char *str) {
	char *end; //The last pointer of the process string
	
    end = str + strlen(str) - 1;      

    while(end > str && (isspace((unsigned char)*end) || (*end == '.'))) end--;

    end[1] = '\0';

} */
//Trim Inside spaces
void trim_Space(char *str)
{
    int i = 0, j = 0;
    int index = 1;
    while (str[i])
    {
        while (isspace(str[i]) && isspace(str[i + 1]))
        {
            i++;
        }
        if (isspace(str[i]) && !isspace(str[i+1]) && index == 1) {
            i++;
            index = 0;
        }

        str[j++] = str[i++];
    }
    str[j] = '\0';
}

void lowerCase(char *a) {
    int i = 1;
    while (i < strlen(a)) {
        //Lowercase all the character
        if (a[i] >= 'A' && a[i] <= 'Z') 
            a[i] = a[i] + 32;
        i++;
    }
}

void upperCase(char *a) {
    if (a[0] >= 'a' && a[0] <= 'z') a[0] = a[0] - 32;
            //Capitalize the first letter of each word
    for (int i = 1; i < strlen(a); i++) {
        if(a[i] == ' ' && a[i+1] != ' ')
            a[i+1] = a[i+1] - 32;
    }
}


int main() {
    char s[N];
    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);
    trim_Space(s); 
    lowerCase(s);
    upperCase(s);
    printf("The string after standardlization: %s\n", s);

    return 0;
}