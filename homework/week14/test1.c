#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 1000

void encryption(char *s, int k) {
    int i = 0;
    while(i < strlen(s)) {
        if (!isspace(s[i])) s[i] = s[i] + k;
        i++;
    }
}
void decoding(char *s, int k) {
	int i = 0;
	while (i < strlen(s)) {
		if (!isspace(s[i])) s[i] = s[i] - k;
		i++;
	}
}

int main() {
    char s[N];
    int k, choice;
    //Read input
    printf("Enter the paragraph: ");
    scanf("%[^\n]s", s);
    
    do {
    	printf("\nMENU\n");
    	printf("\t1. Encyption the paragraph\n");
    	printf("\t2. Decoding the paragraph\n ");
    	printf("\t3. Exit\n");
    	printf("------------------------------\n");
		printf("Choose your number (from 1 to 3): ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1: {
				printf("------------------------------\n");
				printf("Enter the k step: ");
    			scanf("%d", &k);
				encryption(s, k);
				printf("%s\n", s);		
				break;
			}
			case 2: {
				printf("------------------------------\n");
				printf("Enter the k step: ");
    			scanf("%d", &k);
				decoding(s, k);
				printf("%s\n", s);
				break;
			}
			case 3: {
				printf("------------------------------\n");
				printf("Thank you for using our service!!!\n");
				exit(0);
				break;
			}
			default: {
				printf("------------------------------\n");
				printf("Please enter other numbers (from 1 to 3) once again!!!\n");
				break;
			}
		}
	} while (1);
	return 0;   
}