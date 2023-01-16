#include <stdio.h>
#include <stdlib.h>
#define column_size 3
#define row_size 5
void reset(int a[row_size][column_size],int consume[row_size][column_size]);
void getpositive(int *n);
void get_by_range(int *n, int a, int b);
void print_status(int a[row_size][column_size]);
void turn_row(int a[row_size][column_size],int consume[row_size][column_size]);
void lietke(int a[row_size][column_size]);
void turn_column(int a[row_size][column_size],int consume[row_size][column_size]);
int check_row(int a[row_size][column_size],int row);
int check_column(int a[row_size][column_size],int column);
void turn_position(int a[row_size][column_size],int consume[row_size][column_size]);
int bill(int consume[row_size][column_size]);
int main(){
    //intialization variables 
    int a[row_size][column_size];
    int home;
    int row,column;
    int consume[row_size][column_size];
    //reset all the elements of array
    for(int i = 0;i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
            a[i][j] = 0;
        }
    }
    for(int i = 0; i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
            consume[i][j] = 0;
        }
    }
    //Write menu
    do{
        printf("\nWelcome to the light control of LAB");
        printf("\n0. Print the status");
        printf("\n1. Turn on the lights in rows");
        printf("\n2. Turn on the lights in columns");
        printf("\n3. Turn on the lights by position");
        printf("\n4. View the power comsumption of the luminaire according to the current state");
        printf("\n5. Reset");
        printf("\n6. Quit");
        printf("\nYour choice is : ");
        get_by_range(&home,0,6);
    switch (home)
    {
    case 0:
        printf("\n-------------------------------------------------");
            for(int i = 0; i < row_size;i++){
                printf("\n");
                for(int j = 0; j < column_size;j++){
                    if(a[i][j] == 1){
                        printf("|\tON\t|");
                    }                   
                    else if(a[i][j] == 0){
                        printf("|\tOFF\t|");
                    }
                }
                printf("\n-------------------------------------------------");
            }
        break;
    case 1:
        turn_row(a,consume);       
        break;
    case 2:
        turn_column(a,consume);
        break;
    case 3:
        turn_position(a,consume);
        break;
    case 4:
        printf("\nThe total power consumption of the entire light is : %d", bill(consume));
        break;
    case 5:
        reset(a,consume);
        break;
    case 6:
        printf("\nThanks for using our service !");
        exit(0);
        break;
    default:
        printf("\nYour choice is incorrect!");
        break;
    }
    }while(1);
    return 0;
}
void lietke(int a[row_size][column_size]){
    for(int i = 0;i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
           printf("%5d",a[i][j]);
        }
        printf("\n");
    }
}
void reset(int a[row_size][column_size],int consume[row_size][column_size]){   
    for(int i = 0;i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
            a[i][j] = 0;
        }
    }
    for(int i = 0; i < row_size;i++){
        for(int j = 0;j < column_size ;j++){
            consume[i][j] = 0;
        }
    }
}
void getpositive(int *n){
    do{
        printf("\nEnter: ");
        scanf("%d", &*n);
        if(*n<0){
            printf("\nThe answer is incorrect!Please enter again!");
        }
    }while(*n<0);
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
void turn_row(int a[row_size][column_size],int consume[row_size][column_size]){
    //turn all the row 
    int n,check;
    printf("\nChoose the number of row: ");
    get_by_range(&n,1,5);
    if(check_row(a,n) == 1){
        printf("\nAll the light of row %d is turn on! ", n);
        printf("\nDo you want turn off the row?\n\t1.Yes\n\t2.No");
        get_by_range(&check,1,2);
        if (check == 1){
            for(int i = 0; i < column_size;i++){
                a[n-1][i] = 0;
            }
        }      
    }
    else{
        printf("\nDo you want turn on the row?\n\t1.Yes\n\t2.No");
        get_by_range(&check,1,2);
        if (check == 1){
            for(int i = 0; i < column_size;i++){
                a[n-1][i] = 1;
                //count the power consumption
                if(((n)%2==0)&&((i+1)%2==0)){
                    consume[n-1][i] += 20;
                }
                else if(((n)%2==1)&&((i+1)%2==1)){
                    consume[n-1][i] +=10;
                }
                else{
                    consume[n-1][i] +=15;
                }
            }
            
        } 
    }   
}
void turn_column(int a[row_size][column_size],int consume[row_size][column_size]){
    int n,check;
    printf("\nChoose the number of column: ");
    get_by_range(&n,1,3);
    if(check_column(a,n) == 1){
        printf("\nAll the light of column %d is turn on! ", n);
        printf("\nDo you want turn off the column?\n\t1.Yes\n\t2.No");
        get_by_range(&check,1,2);
        if (check == 1){
            for(int i = 0; i < row_size;i++){
                a[i][n-1] = 0;
            }
        }      
    }
    else{
        printf("\nDo you want turn on the row?\n\t1.Yes\n\t2.No");
        get_by_range(&check,1,2);
        if (check == 1){
            for(int i = 0; i < row_size;i++){
                a[i][n-1] = 1;
                if(((n)%2==0)&&((i+1)%2==0)){
                    consume[n-1][i] += 20;
                }
                else if(((n)%2==1)&&((i+1)%2==1)){
                    consume[n-1][i] +=10;
                }
                else{
                    consume[n-1][i] +=15;
                }
            }          
        }  
    }
}
int check_row(int a[row_size][column_size],int row){
    int check = 1;
    for(int i = 0; i < column_size; i++){
        if(a[row-1][i] == 1){
            check*=check;
        }
        else{
            check = 0;
        }
    }
    return check;
}
int check_column(int a[row_size][column_size],int column){
    int check = 1;
    for(int i = 0; i < row_size; i++){
        if(a[i][column-1] == 1){
            check*=check;
        }
        else{
            check = 0;
        }
    }
    return check;
}
void turn_position(int a[row_size][column_size],int consume[row_size][column_size]){
    int r,c;
    int check;
        printf("\nChoose the position (row/column): ");
        scanf("%d%*c%d",&r,&c);
        if(a[r][c] == 1){
            printf("\nthe light of [%d][%d] is turn on! ",r,c);
            printf("\nDo you want turn off the light?\n\t1.Yes\n\t2.No");
            get_by_range(&check,1,2);
            if (check == 1){
                    a[r-1][c-1] = 0;           
            }      
        }
        else{
            printf("\nDo you want turn on the light?\n\t1.Yes\n\t2.No");
            get_by_range(&check,1,2);
            if (check == 1){
                    a[r-1][c-1] = 1;
                    if((r%2==0)&&(c%2==0)){
                        consume[r-1][c-1] += 20;
                    }
                    else if((r%2==1)&&(c%2==1)){
                        consume[r-1][c-1] +=10;
                    }
                    else{
                        consume[r-1][c-1] +=15;               
                    }               
            }  
        }
}
int bill(int consume[row_size][column_size]){
	int bill = 0;
	for (int i = 0; i < row_size; i++) {
		for(int j = 0;j <column_size;j++ ){
            bill += consume[i][j];
        }
	}
	return bill;
}
