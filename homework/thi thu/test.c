#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

#define max 30


typedef struct{
	int id;
	char nation[30];
	char name[max];
	float results[30];
	float final;
}vdv;
void nhap1(vdv *x){
	printf("Enter the ID: ");
	scanf("%d", &x->id);
	getchar();
	printf("Enter the Nation: ");
	scanf(" %[^\n]%*c",x->nation);
	printf("Enter the name: ");
	scanf(" %[^\n]%*c",x->name);
	
}
void xuat1(vdv x){
	printf("%-10d%-16s%-16s%-10.2lf%10.2lf%10.2lf%10.2lf\n",x.id, x.nation, x.name,x.results[0],x.results[1],x.results[2],x.final);
	
}

int main(){
	vdv x[1000];
int n;
int cnt=0;
int choice;
int tmp;
do {
printf("Olympic Menu\n");
printf("1.Enter the informations.\n");
printf("2. Print\n");
printf("3. Battle.\n");
printf("4.Find.\n");
printf("5.Print result.\n");
printf("6.Quit.\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch (choice){
case 1:
 		
            do{
                printf("Enter the number for teams: ");
                scanf("%i",&n);
                tmp=cnt+n;
                if(n<0||n>20){
                	printf("Invalid, enter between 1 and 20 !\n");
				}
            }while(tmp<0||tmp>20);
            for(int i=cnt;i<tmp;i++)
                {
                    nhap1(&x[i]);
                }
                cnt=tmp;
                     
              break;
	case 2:
		for(int i=0;i<cnt;i++)
                {
                    xuat1(x[i]);
                }
		break;
		case 3:
			break;
			case 4:;
			break;
			case 5:;
			break;
			case 6:;
			break;
default:
printf("Invalid options, please enter between 1 and 6 !\n");  
}
}while (choice != 6);
return 0;
}