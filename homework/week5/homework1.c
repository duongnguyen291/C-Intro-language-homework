#include <stdio.h>
int main(){
    int ipod, ipad;
    printf("Ban muon mua bao nhieu IPOD?");
    scanf("%d",&ipod);
    printf("Ban muon mua bao nhieu IPAD?");
    scanf("%d",&ipad);
    printf("\nSIEU THI TOPCARE - HOA DON THANH TOAN\n");
    int net= (ipod * 148) + (ipad * 288) ;
    float discount = ((ipod>=3 && ipad>=2)||(net>1020))? net*0.1:0;
    
    printf("Ipod\t%d x %d = %d\n",ipod,148,ipod * 148);
    printf("Ipad\t%d x %d = %d\n",ipad,288,ipad * 288);
    printf("Net\t\t%d\n",net );
    printf("Discount %d x %d = %.2f\n",net,((ipod>=3 && ipad>=2)||(net>1020))?10:0, discount );
    printf("You pay:%d - %f = %.2f",net,discount, net -discount);
    return 0;
}