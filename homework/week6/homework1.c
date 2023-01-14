#include <stdio.h>
#include <math.h>
int main(){
    float rad = 180/3.14;
    /*Nhập thông tin tọa độ của 2 john và jane*/
    float x1,y1,x2,y2;
    printf("Nhap toa do x,y cua John (x,y):");
    scanf("%f%*c%f",&x1,&y1);
    printf("Nhap toa do x,y cua Jane (x,y):");
    scanf("%f%*c%f",&x2,&y2);
    
    /*Khoảng cách giữa bạn và John */
    float distance1 = sqrt(x1*x1+y1*y1);
    printf("\nKhoang cach giua ban va John la: %.2f (km)",distance1);

    /*Hướng của john*/
    if(x1==0 && y1==0){
        printf("\nJohn dang o Center!");
    }
    else if(x1==0 && y1>0){
        printf("\nJohn dang o North!");
    }
    else if(x1==0 && y1<0){
        printf("\nJohn dang o South!");
    }
    else if(y1==0 && x1>0){
        printf("\nJohn dang o East!");
    }
    else if(y1==0 && x1<0){
        printf("\nJohn dang o West!");
    }
    else if(x1>0 && y1>0){
        printf("\nJohn dang o Northeast!");
        printf("\n\tGoc : %.1f (do)",atan(y1/x1)*rad);
    }
    else if(x1>0 && y1<0){
        printf("\nJohn dang o Southeast!");
        printf("\n\tGoc : %.1f (do)",360 + atan(y1/x1)*rad);
    }
    else if(x1<0 && y1>0){
        printf("\nJohn dang o Northwest!");
        printf("\n\tGoc : %.1f (do)",180 + atan(y1/x1)*rad);
    }
    else if(x1<0 && y1<0){
        printf("\nJohn dang o Southwest!");
        printf("\n\tGoc : %.1f (do)",180 + atan(y1/x1)*rad);
    }

    /*Khoảng cách giữa bạn và Jane*/
    float distance2 = sqrt(x2*x2+y2*y2);
    printf("\nKhoang cach giua ban va Jane la: %.2f (km)",distance2);

    /*Hướng của jane*/
    if(x2==0 && y2==0){
        printf("\nJane dang o Center!");
    }
    else if(x2==0 && y2>0){
        printf("\nJane dang o North!");
    }
    else if(x2==0 && y2<0){
        printf("\nJane dang o South!");
    }
    else if(y2==0 && x2>0){
        printf("\nJane dang o East!");
    }
    else if(y2==0 && x2<0){
        printf("\nJane dang o West!");
    }
    else if(x2>0 && y2>0){
        printf("\nJane dang o Northeast!");
         printf("\n\tGoc : %.1f (do)",atan(y2/x2)*rad);
    }
    else if(x2>0 && y2<0){
        printf("\nJane dang o Southeast!");
        printf("\n\tGoc : %.1f (do)",360 + atan(y2/x2)*rad);
    }
    else if(x2<0 && y2>0){
        printf("\nJane dang o Northwest!");
        printf("\n\tGoc : %.1f (do)",180 + atan(y2/x2)*rad);
    }
    else if(x2<0 && y2<0){
        printf("\nJane dang o Southwest!");
        printf("\n\tGoc : %.1f (do)",180 + atan(y2/x2)*rad);
    }
   


    return 0;
}
