#include <stdio.h>
#define MAX 10000
int mang[MAX],mang1[MAX];
void Merge(int h,int t){

    int mid=(h+t)/2;
    int a[MAX],b[MAX],c[MAX];
    for(int i=1;i<=mid-h+1;i++)a[i]=mang[i+h-1];
    for(int i=1;i<=t-mid;i++)b[i]=mang[i+mid];

    int zui=1,dem=1;
    for(int i=1;i<=mid-h+1;i++){
        while(b[zui]<=a[i]&&zui<=t-mid){
            c[dem++]=b[zui];
            zui++;
        }
        c[dem++]=a[i];
    }
    for(int i=zui;i<=t-mid;i++)c[dem++]=b[i];
    for(int i=h;i<=t;i++){

        mang[i]=c[i-h+1];
    }
}
void Sort(int h,int t){
    if(h==t)return ;
    int mid=(h+t)/2;
    Sort(h,mid);
    Sort(mid+1,t);
    Merge(h,t);

}
int main(){
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&mang[i]);
    Sort(1,n);
    for(int i=1;i<=n;i++)mang1[i]=mang[i];
    scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d",&mang[i]);
    Sort(1,m);
    int t1=1,t2=1;
    while(t1<=n&&t2<=m){
        if(mang1[t1]<mang[t2]&&t1<=n)t1++;
        else if(mang1[t1]>mang[t2]&&t2<=m)t2++;
        else if(mang1[t1]==mang[t2])printf("%d ",mang1[t1]),t1++,t2++;
    }
}
