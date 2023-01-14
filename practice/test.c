#include<stdio.h>
#include<stdlib.h>
#define SIZE 40

int status[SIZE], consume[SIZE], total[SIZE], more[SIZE], less[SIZE];

void room_Menu(int status[], int consume[]) {
    printf("---------------------------------------------------------------------------------------------------------------------------------\n");
    int count = 1;
    for (int i = 1; i <= 20; i++) {
        if (i % 4 == 0) {
            printf("---------------------------------------------------------------------------------------------------------------------------------");
        } else {
            printf("%s", "|");
            // reset j to 1 at the beginning of each row
            int j = 1;
            for (; j <= 8; j++) {
                if (i % 4 == 1) {
                    printf("  %s %d\t", "COMP", count);
                    count++;
                }
                if (i % 4 == 2) {
                    if (status[count] == 0) printf("  %s\t\t", "OFF");
                    else printf("  %s\t\t", "ON");
                }
                if (i % 4 == 3) {
                    printf("  %d%s\t\t", consume[count], "W");
                }
                printf("%s", "|");
            }
        }
        printf("\n");
    }   
}

void setup(int status[], int consume[]) {
	for (int i = 1; i <= 40; i++) {
		status[i] = 0;
		consume[i] = 0;
	}
}

void turn_on(int n, int status[]) {
	status[n] = 1;
	consume[n] = consume[n] + 40;
	more[n]++;
}

int find_max(int more[]) {
	int maxx = 0, index;
	for (int i = 0; i < 40; i++) {
		if (maxx < more[i]) {
			maxx = more[i];
			index = i;
		}
	}
	
	return index;
}

int find_min(int more[]) {
	int minn = 999999999, index;
	for (int i = 0; i < 40; i++) { 
		if (minn > more[i]) {
			minn = more[i];
			index = i;
		}
	}
	
	return index;
}

void turn_off(int n, int status[]) {
	status[n] = 0;
}

int calculate(int consume[]) {
	int bill = 0;
	for (int i = 0; i < 40; i++) {
		bill = bill + consume[i];
	}
	return bill;
}

int main() {
	int choice;
	setup(status, consume);
	do {
		printf("WELCOME TO THE LAB 381\n");
		printf("MENU\n");
		printf("1. Turn on the computer\n");
		printf("2. Turn off the computer\n");
		printf("3. Print the status of the LAB 381\n");
		printf("4. Print the total electricity and the bill of electricity\n");
		printf("5. The most use computer and the least use computer\n");
		printf("6. Quit\n");
		printf("-----------------------------------------------------\n");
		printf("Choose your option:");
		scanf("%d", &choice);
	
		switch (choice) {
			case 1: {
					int number;
					printf("Computer number: ");
					scanf("%d", &number);
					turn_on(number, status);
					break;
			}
				
			case 2: {
					int number;
					printf("Computer number: ");
					scanf("%d", &number);
					turn_off(number, status);
				break;
			}
			
			case 3: {
					room_Menu(status, consume);	
				break;
			}
			
			case 4: {
					printf("The total electricity consumption: %d\n", calculate(consume));
					printf("The bill: %d\n", calculate(consume) * 750);
				break;
			}
			
			case 5: {
					printf("The most use computer: %d\n", find_max(more));
					printf("The least use computer: %d\n", find_min(more));				
				break;
			}
			
			case 6: {
				printf("Thank you for using our service!!\n");
				exit(0);
				break;
			}
			
			default: {
				printf("Please choose another choice!\n");
				break;
			}
		}
	} while (1);
	
	return 0;
}