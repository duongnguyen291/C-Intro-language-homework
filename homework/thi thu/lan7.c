#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 8

typedef struct {
	char teamName[4][20];
	int points[4];
	int goals[4];
} team_t;

typedef struct {
	char groupID[2];
	char teamName[4][20];
	int points[4];
	int goals[4]; 
} group;

void printGroup(group g[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Group %s\n", g[i].groupID);
		printf("%-20s%-10s%-20s\n", "Team", "Point", "Goal Difference");
		for (int j = 0; j < 4; j++) {
			printf("%-20s%-10d%-20d\n", g[i].teamName[j], g[i].points[j], g[i].goals[j]);
		}
		printf("--------------------------------------------\n");
	}
}

void searchTeam(group g[], int n, char s[]) {
	int index_1 = -1;
	int index_2 = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			if (strcmp(g[i].teamName[j], s) == 0) {
				index_1 = i;
				index_2 = j;
			}
		}
	}

	if (index_1 == -1) printf("No result\n");
	else {
		printf("Group %s, %d point(s), %d Goal difference\n", g[index_1].groupID, g[index_1].points[index_2], g[index_1].goals[index_2]);
	}
}

int findGroup(char team[], int n, group g[]) {
	int index = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			if (strcmp(team, g[i].teamName[j]) == 0)
				index = i;
		}
	}
	return index;
}

int findPosition(char team[], int n, group g[]) {
	int index = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			if (strcmp(team, g[i].teamName[j]) == 0)
				index = j;
		}
	}
	return index;
}

void checkInGroup(group g[], int n, char team1[], char team2[], int goal_1, int goal_2) {
	int g1 = findGroup(team1,n, g);
	int g2 = findGroup(team2,n, g);
	int x1 = findPosition(team1,n, g);
	int x2 = findPosition(team2,n, g);
	
	if (g1 == g2) {
		if (goal_1 > goal_2) {
			g[g1].points[x1] = g[g1].points[x1] + 3;
			g[g1].goals[x1] = g[g1].goals[x1] + (goal_1 - goal_2);
			g[g2].points[x2] = g[g2].points[x2] + 0;
			g[g2].goals[x2] = g[g2].points[x2] + (goal_2 - goal_1);
		}
		else if (goal_1 == goal_2) {
			g[g2].points[x2] = g[g2].points[x2] + 1;
			g[g1].points[x1] = g[g1].points[x1] + 1;
		}
		else {
			g[g2].points[x2] = g[g2].points[x2] + 3;
			g[g2].goals[x2] = g[g2].goals[x2] + (goal_2 - goal_1);
			g[g1].points[x1] = g[g1].points[x1] + 0;
			g[g1].goals[x1] = g[g1].points[x1] + (goal_1 - goal_2);
		}		
	} else {
		printf("Different group\n");
	}
} 
/*
void sort(group g[], int n) {
	group temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 1; k < 4; k++) {
				if (g[i].points[j] > g[i].points[k]) {
					temp = g[i];
					g[i] = g[j];	
				}
		}
	}
}
*/
int main() {
    int choice, n;
    group g[MAX];
    do {
        printf("MENU\n");
        printf("1. Read\n");
        printf("2. Search\n");
        printf("3. Add\n");
        printf("4. Sort\n");
        printf("5. Count\n");
        printf("6. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your number: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: {
                do {
                    printf("Enter the number of group: ");
                    scanf("%d", &n);
                    if (n <= 0 || n > 8)  printf("Must be > 0 and <= 8\n");
                } while (n <= 0 || n > 8);

                for (int i = 0; i < n; i++) {
                    printf("Enter the group name: ");
                    scanf(" %[^\n]%*c", g[i].groupID);
                    for (int j = 0; j < 4; j++) {
                    	printf("Enter the team name: ");
                    	scanf(" %[^\n]%*c", g[i].teamName[j]);
                    	printf("Enter the point of team %s: ", g[i].teamName[j]);
                    	scanf("%d", &g[i].points[j]);
                    	printf("Enter the goal difference of team %s: ", g[i].teamName[j]);
                    	scanf("%d", &g[i].goals[j]);
					}
					printf("-----------------------------------------------------\n");
                }
				 
				break;
            }
            case 2: {
                printGroup(g, n);
			    break;
            }
            case 3: {
            	char s[20];
            	printf("Enter the team you want: ");
            	scanf(" %[^\n]%*c", s);
            	searchTeam(g, n, s);
            	break;
            }
            case 4: {
            	char team_1[20], team_2[20];
            	int goal_1, goal_2;
				printf("Enter the result of the match: ");
				scanf(" %[^\n]%*c  %[^\n]%*c %d %d", team_1, team_2, goal_1, goal_2);				
				checkInGroup(g,n,team_1,team_2,goal_1,goal_2);
				break;
            }
            case 5: {
				break;				
            }
            case 6: {
                printf("Thank you for using our service!!!");
                exit(0);
            }
            default: {
                printf("Please enter another number from 1 to 6 once again!!!\n");
                break;
            }
        }
    } while(1);

    return 0;
}