#include <cstdio>
//斐波那契数列递归和循环写法

int Fib(int x){
	int m=1,n=1,temp;
	if(x<0) return 0;
	if(x==0 || x==1) return 1;
	else{
		for(int i=2;i<=x;i++){
			temp = m+n;
			m = n;
			n = temp;
		}
		return temp;
	}
} 
int main(){
	int n;
	printf("请输入一个整数\n");
	scanf("%d",&n);
	printf("%d\n",Fib(n));
	getchar();
	getchar();
	return 0; 
}
