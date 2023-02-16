#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define people 5
typedef struct candidates{
   char name[100];
   int point;
}candidates;

int main(){
candidates data[people];
//
for(int i = 0; i < people ;i++){
    printf("\nEnter the name of candidates %d: ", i+1);
    scanf(" %[^\n]%*c",data[i].name);
}

printf("\nThe question 1: Ai dep trai nhat ? \n\t1.Duong\n\t2.Khong ai\n\t3.Khong biet");
scanf("");

}