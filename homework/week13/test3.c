#include <stdio.h>
#include <string.h>

typedef struct name
{
    char name[50];
}name;

int main(){
    name country_list[3];
    strcpy(country_list[0].name, "viet nam");
    strcpy(country_list[1].name,"trung quoc");
    strcpy(country_list[2].name,"hoa ki vl");
    
    int point[3] = {1,2,3};
    int vl[3] = {1,2,3};
    printf("\nCountry\t\tPoint\tVl");
    for(int i = 0;i<3;i++){
        printf("\n%s\t%d\t%d",country_list[i].name,point[i],vl[i]);
    }



}