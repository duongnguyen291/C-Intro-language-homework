#include <stdio.h>
#define electrolux_refrigerator 8
#define sony_lcd_tv 15
#define hp_laptop 12
int main(){
    int a,b,c;
    int best_selling, worst_selling,highest_sales,lowest_sales;
    char a1[]="Electrolux Refrigerator", b1[]="Sony LCD TV",c1[]="HP Laptop";
    printf("Enter the Electrolux Refrigerator: ");
    scanf("%d",&a);
    printf("Enter the Sony LCD TV: ");
    scanf("%d",&b);
    printf("Enter the HP Laptop: ");
    scanf("%d",&c);
    int total_sales = a*8 + b*15 + c*12;


    printf("Sales for the Electrolux Refrigerator : %d",a);    
    printf("\nSales for the Sony LCD TV : %d",b);
    printf("\nSales for the HP Laptop : %d",c);
    printf("\n-------------------------------------------");
    printf("\nThe total sales is: %dx8 + %dx15 + %dx12 = %d (VND)",a,b,c,total_sales);
    best_selling = (a>=b?(a>=c?a:c):(b>=c?b:c));
    printf("\nThe best selling item: %d (%s)",best_selling,(a>=b?(a>=c?a1:c1):(b>=c?b1:c1)));
    worst_selling = (a>=b?(b>=c?c:b):(a>=c?c:a));
    printf("\nThe worst selling item: %d (%s)",worst_selling,a>=b?(b>=c?c1:b1):(a>=c?c1:a1));
    
    




    
    
    return 0;
}