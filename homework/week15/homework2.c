#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10

typedef struct aw {
    char answer_1[N];
    char answer_2[N];
    char answer_3[N];
    char answer_4[N];
    char answer_5[N];
} answer;

typedef struct qs {
    char question[100];
    char a[N];
    char b[N];
    char c[N];
    char d[N];
} question;

typedef struct sc {
	char question_1[N];
	char question_2[N];
	char question_3[N];
	char question_4[N];
	char question_5[N];
} score;

int check_Result(score exam_result, answer candidate[], int sbd) {
    int sum = 0;
	    if (candidate[sbd].answer_1 == exam_result.question_1) sum++;
	    if (candidate[sbd].answer_2 == exam_result.question_2) sum++;
	    if (candidate[sbd].answer_3 == exam_result.question_3) sum++;
	    if (candidate[sbd].answer_4 == exam_result.question_4) sum++;
	    if (candidate[sbd].answer_5 == exam_result.question_5) sum++;
    return sum;
}

/*int check_Result(char score[][5], answer candidate[], int sbd) {
    int result = 0;
    int i = 0;
    for (int i = 0; i < 5; i++) {
        if (score[i] == *(candidate[sbd].answer_1))
            result += 1;
        if (score[i] == *(candidate[sbd].answer_2))
            result = result + 1;
        if (score[i] == *(candidate[sbd].answer_3))
            result = result + 1;
        if (score[i] == *(candidate[sbd].answer_4))
            result = result + 1;
        if (score[i] == *(candidate[sbd].answer_5))
            result = result + 1;
    }
    return result;
}
*/

int main() {
    int choice;
    question exam[5];
    answer candidate[5];
    score exam_result;

    do {
        printf("\nWELCOME TO THE ICT FINAL EXAM\n");
        printf("1. Enter the exam test\n");
        printf("2. Candidate answer\n");
        printf("3. Result\n");
        printf("4. Ranking table\n");
        printf("5. Exit\n");

        printf("Enter your number (from 1 to 5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the exam question: ");
                for (int i = 0; i < 5; i++) {
                    printf("Question %d:", i+1);
                    getchar(); // clear input buffer
                    fgets(exam[i].question, sizeof(exam[i].question), stdin);
                    exam[i].question[strcspn(exam[i].question, "\n")] = '\0'; // remove newline character from input
                    printf("Answer A: ");
                    getchar(); // clear input buffer
                    fgets(exam[i].a, sizeof(exam[i].a), stdin);
                    exam[i].a[strcspn(exam[i].a, "\n")] = '\0'; // remove newline character from input
                    printf("Answer B: ");
                    getchar(); // clear input buffer
                    fgets(exam[i].b, sizeof(exam[i].b), stdin);
                    exam[i].b[strcspn(exam[i].b, "\n")] = '\0'; // remove newline character from input
                    printf("Answer C: ");
                    getchar(); // clear input buffer
                    fgets(exam[i].c, sizeof(exam[i].c), stdin);
                    exam[i].c[strcspn(exam[i].c, "\n")] = '\0'; // remove newline character from input
                    printf("Answer D: ");
                    getchar(); // clear input buffer
                    fgets(exam[i].d, sizeof(exam[i].d), stdin);
                    exam[i].d[strcspn(exam[i].d, "\n")] = '\0'; // remove newline character from input
                    printf("----------------------------------\n");
                }
                
                    printf("Correct answer question 1: ");
                    scanf("%[^\n]%*c", exam_result.question_1);
                    printf("Correct answer question 2: ");
                    scanf("%[^\n]%*c", exam_result.question_2);
                	printf("Correct answer question 3: ");
                    scanf("%[^\n]%*c", exam_result.question_3);
                    printf("Correct answer question 4: ");
                    scanf("%[^\n]%*c", exam_result.question_4);
                    printf("Correct answer question 5: ");
                    scanf("%[^\n]%*c", exam_result.question_5);
                    
                break;
            }

            case 2: {
                printf("Answer sheet\n");
                for (int i = 0; i < 5; i++) {
                    printf("---------------------------------\n");
                    printf("Candidate %d:\n", i+1);
                    printf("Answer Question 1: \n");
                    getchar(); // clear input buffer
                    scanf("%s", &candidate[i].answer_1);
                    candidate[i].answer_1[strcspn(candidate[i].answer_1, "\n")] = '\0'; // remove newline character from input
                    printf("Answer Question 2: \n");
                    scanf("%s", &candidate[i].answer_2);
                    printf("Answer Question 3: \n");
                    scanf("%s", &candidate[i].answer_3);
                    printf("Answer Question 4: \n");
                    scanf("%s", &candidate[i].answer_4);
                    printf("Answer Question 5: \n");
                    scanf("%s", &candidate[i].answer_5);
                }
                break;
            }

            case 3: {
                printf("RESULT\n");
                printf("--------------------------------------\n");
                for (int i = 0; i < 5; i++) {
                    printf("Candidate %d score: %d\n", i+1, check_Result(exam_result, candidate, i));
                }
                break;
            }

            case 4: {
                printf("RANKING TABLE\n");
                printf("--------------------------------------------\n");
                printf("%-4d%-5d%-5s%-5s%-5s%-5s%-5s%-10d\n","No","SBD","Q1","Q2","Q3","Q4","Q5","Result");
                for (int i = 0; i < 5; i++) {
                    printf("%-4d%-5d%-5s%-5s%-5s%-5s%-5s%-10d\n", i+1, i+1, candidate[i].answer_1, candidate[i].answer_2, candidate[i].answer_3,
                    candidate[i].answer_4, candidate[i].answer_5, check_Result(exam_result, candidate, i));
                }
            }

            case 5: {
                printf("Thank you for using our service!!!");
                exit(0);
            }        
            default: {
                printf("Please enter another number from 1 to 5 once again!!!");
                break;
            }
        }
        printf("\n");
    } while(1);

    return 0;
}