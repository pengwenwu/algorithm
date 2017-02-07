#include <stdio.h>
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
int main(){
	int a=1,b=2;
	//int* p1= &a, *p2=&b;
	swap(a,b);
	printf("%d,%d",a,b);
	getchar();
}

