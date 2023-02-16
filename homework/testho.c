tinhthanh v[1000];
int m=0;
int findpos(char diachi[]){
	for(int i=0;i<m;i++){
		if(strcamp(v[i].ten,diachi)==0)
		return 1;
	}
	return -1;
}
int cmp(const void*a; const void*b){
	tinhthanh*x=(tinhthanh*)a;
	tinhthanh*y=(tinhthanh*)b;
	return strcmp(x->ten,y->ten);
}
int main(){
	int n;
    scanf("%d",&n);
	sinhvien a[n];
	for(int i=0;i<n;i++){
		getchar();
		gets(a[i].ten);
		gets(a[i].ngaysinh);
		gets(a[i].diachi);
		scanf("%lf", &a[i].gpa);
	    int pos=findpos(a[i].diachi);
    if(pos == -1){
    	sctrcmp(v[m].ten,a[i].diachi);
    	v[m].sl=1;
    	++m;
	}
	else  v[pos].sl++;
}
    

	for(int i=0;i<n;i++){
    	if(v[i].sl > max_free) max_free = v[i].sl;
}
qsort(v,m,sizeof(tinhthanh),cmp);
for(int i=0;i<n;i++){
	if(v[i].sl==max_free){
		printf("%s\n",v[i].ten);
	}
}
}