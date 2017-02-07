#include <cstdio>
int main(){
	int a,b,d; //将 十进制数 a，b的和，转化为d进制数 
	scanf("%d %d %d",&a,&b,&d);
	int sum = a+b;
	int ans[31],num=0;
	do{
		ans[num++] = sum % d;
		sum /= d;	
	} while (sum != 0);
	for(int i=num-1; i >= 0; i--){
		printf("%d",ans[i]);
	}
	getchar();
	getchar();
	return 0;
}
 