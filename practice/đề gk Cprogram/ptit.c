/*Một số được coi là số đẹp nếu các chữ số ở vị trí chẵn của nó là số chẵn 
và các chữ số ở vị trí lẻ của nó là số lẻ. Ví dụ N = 1658347 là một số đẹp. 
Nhiệm vụ của bạn là kiểm tra xem các số đã cho có phải là số đẹp hay không?
Gợi ý : Chú ý trường hợp N âm
Input Format
Dòng đầu tiên là T : số lượng trường hợp
T dòng tiếp theo mỗi dòng là một số nguyên N
Constraints
1<=T<=1000
-10^18<=N<=10^18
Output Format
Đối với mỗi trường hợp in ra YES hoặc NO tương ứng nếu N là số đẹp hoặc không*/
#include <stdio.h>
#include <math.h>
void hoanvi(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    //Nhập số n 
    int sonhap;
    printf("Enter n: ");
    scanf("%d",&sonhap);
    int n=fabs(sonhap);

    //chuyển n vào mảng
    int a[21];
    int cs=0;
    while(n){
        cs++;
        a[cs]=n%10; //(1)
        n/=10; 
    }
    //đảo ngược lại thứ tự của mảng 
    for(int i=1;i<=cs/2;i++){
        hoanvi(&a[i],&a[cs-i+1]);
    }  
    //check điều kiện
    for(int i=1;i<=cs;i++){//bắt đầu ở đây là int =1 vì đoạn (1) ta gán bắt đầu từ [1]
        if((i%2==1&&a[i]%2==1)||(i%2==0&&a[i]%2==0)){
            printf("N la so dep!");
            break;
        }
        else {
            printf("N la so xau!");
            break;
        }
    }

    
    return 0;
}