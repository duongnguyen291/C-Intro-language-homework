#include <stdio.h>
#include <stdlib.h>
#define month 12
void get_by_range(int *n, int a, int b);
void enter_value(int spending[month],int residual[month]);
void table_report(int spending[month],int residual[month]);
int find_max(int spending[month]);
int find_min(int spending[month]);
void total_report(int spending[month]);
int main(){
    int spending[month];
    int home;
    int spending_mode;
    int residual[month];
    do{       
        printf("\nHUST Money Lover Program! ");
        printf("\n1.Enter value");
        printf("\n2.Table report");
        printf("\n3.Total report");
        printf("\n4.Quit");
        printf("\nYour chose is:");
        get_by_range(&home,1,5);
        switch (home)
        {
        case 1:
            enter_value(spending,residual);
            break;
        case 2:
            table_report(spending,residual);
            break;
        case 3:
            total_report(spending);
            break;
        case 4:
            printf("\nThanks for using our service");
            exit(0);
            break;     
        default:
            printf("\nYour choice is incorrect!");
            break;
        }        

    }while(1);
    return 0;
}
void get_by_range(int *n, int a, int b){
    do{
            printf("\nEnter: ");
            scanf("%d", &*n);
            if((*n < a)||(*n > b)){
                printf("\nThe answer is incorrect!Please enter again!");
            }
        }while((*n<a)||(*n>b));
}
void enter_value(int spending[month],int residual[month]){
        int count_month = 0;
        int mode;
        int residual_one = 0;
    do{
        count_month++;
        printf("\nSpending of month: %d",count_month);
        printf("\nChoose the spending mode: \n\t1.Safe\n\t2.Flexible");
        get_by_range(&mode,1,2);
        if(mode == 1){
            printf("\nEnter your spending of month %d ", count_month);
            get_by_range(&spending[count_month-1],0,3000);
        }
        else if(mode == 2){
            printf("\nEnter your spending of month %d ", count_month);
            get_by_range(&spending[count_month-1],0,3000+residual_one);
        }       
        if(spending[count_month-1] <=3000){
                residual_one += (3000-spending[count_month-1]);   
            residual[count_month-1] = residual_one;             
        }
        else if(spending[count_month - 1] > 3000){
                residual_one -= (spending[count_month -1] - 3000);
            residual[count_month-1] = residual_one;             

        }        
    }while(count_month<12);
}
void table_report(int spending[month],int residual[month]){
    printf("\n-----------------------------------------");
    printf("\n|Month\t|Spending\t|\tResidual|");
    printf("\n-----------------------------------------");
    for(int i = 0;i < month; i++){
        printf("\n|%5d\t|\t%5d\t|\t%5d\t|",i+1,spending[i],residual[i]);
    }
    printf("\n-----------------------------------------");
}
void total_report(int spending[month]){
    int sum = 0;
    printf("\nThe month spent the most: %d ", find_max(spending));
    printf("\nThe month spent the least: %d ", find_min(spending));
    for(int i = 0;i < month; i++){
        sum += spending[i];
    }
    printf("\nThe total spending of the year: %d (Thousand VND)",sum);
    printf("\nThe remaining money after the year is: %d (Thousand VND)",3000*12 - sum);
}
int find_max(int spending[month]){
    int max = spending[0], n = 0 ;
    for(int i = 1; i <month;i++){
        if(max <= spending[i]){
            max = spending[i];
            n = i + 1;
        }
    }
    return n;
}
int find_min(int spending[month]){
    int min= spending[0], n = 0 ;
    for(int i = 1; i < month;i++){
        if(min >= spending[i]){
            min = spending[i];
            n = i + 1;
        }
    }
    return n;
}