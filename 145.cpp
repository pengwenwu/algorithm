//快速排序，随机主元写法
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}
int randPartition(int A[],int left,int right){
	
	int p = (int)(round(1.0*rand()/RAND_MAX*(right-left)+left));
	swap(A[left], A[p]);
	//之后还是原来的写法 
	int temp = A[left];
	while(left<right){
		while(left<right && A[right]>temp) right--;
		A[left] = A[right];
		while(left<right && A[left]<= temp) left++;
		A[right] = A[left];
	}
	A[left] = temp;
	return left;
}
void quickSort(int A[], int left,int right){
	if(left<right){
		int pos = randPartition(A,left,right);
		quickSort(A,left,pos-1);
		quickSort(A,pos+1,right);
	}	
}
int main(){
	srand((unsigned)time(NULL));
	int A[10] = {9,5,14,-4,11,556,26,4,99,-1};
	quickSort(A,0,9);
	for(int i=0;i<10;i++){
		printf("%d ",A[i]);
	}
	getchar();
}
