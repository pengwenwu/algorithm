#include <cstdio>
int main(){
	int a,b,d; //�� ʮ������ a��b�ĺͣ�ת��Ϊd������ 
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
 