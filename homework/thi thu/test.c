#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
char str[100];

printf("\nenter: ");
scanf(" %[^\n]%*c", str);
printf("\nSo tu: %d",strlen(str));

}