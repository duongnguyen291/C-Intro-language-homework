#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	int t;
    puts("Nhap so lan thu:");
	scanf("%d", &t);
	while(t--) {
            int x;
        puts("Nhap so ky tu:");
        scanf("%d",&x);
		char a[x];
		int cntT=0;
		int cnti=0;
		int cntm=0;
		int cntu=0;
		int cntr=0;
		int cnt=0;
        puts("Nhap ky tu: ");
		scanf("%s",&a);

		for(int i=0;i<strlen(a);i++){

                if (a[i]=='T') cntT++;
                else if (a[i]=='i') cnti++;
                else if (a[i]=='m') cntm++;
                else if (a[i]=='u') cntu++;
                else if (a[i]=='r') cntr++;
                else
                    ++cnt;

                }



        if (cntT*cnti*cntm*cntu*cntr==1&&cnt==0)
                    printf ("YES\n");
                else printf("NO\n");
	}
	}