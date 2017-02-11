//数字黑洞，任意不完全相同的四位数，各数字非递增排序的值减去非递减的值
//以此类推，最终会等于 6174
#include <cstdio>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
void to_array(int n,int num[]){
	 for(int i=0;i<4;i++){
 		num[i] = n%10;
 		n/=10; 
 	}
}
int to_number(int num[]){
	int sum = 0;
	for(int i=0;i<4;i++){
		sum = sum*10+num[i];
	}
	return sum;
} 
int main(){
	int MAX,MIN,n,num[4];
	scanf("%d",&n);
	while(1){ //这是为了防止出现达到6174结果时未输出 
		to_array(n,num);
		sort(num,num+4);
		MIN = to_number(num);
		sort(num,num+4,cmp);
		MAX = to_number(num);
		n = MAX-MIN;
		printf("%04d-%04d=%04d\n",MAX,MIN,n);
		if(n ==0 || n== 6174) break; 
	}
	getchar();
	return 0;
}
