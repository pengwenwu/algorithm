#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	int a[6] = {
		9,4,2,5,6,-1
	};
	//��a[0]~a[3]������������ 
	sort(a,a+4,cmp);
	for(int i=0;i<6;i++)
		printf("%d ",a[i]);
	getchar();
	return 0;
}
