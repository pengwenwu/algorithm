#include <cstdio>
const int maxn = 1000;
int a[maxn];
int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&x);
	int k=0;
	for(;k<n;k++){
		if(a[k]==x){
			printf("%d\n",k);
			break;
		}
	}
	if(k == n){
		printf("-1");
	}
		
	getchar();
	getchar();
	return 0;
}
