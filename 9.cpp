#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=10010;
int A[maxn],n; //数组，数组长度 
void swap(int &m,int &n){
	int temp=m;
	m=n;
	n=temp;
}
int randPartition(int A[], int left,int right){
	int p=(round(1.0*rand()/RAND_MAX*(right-left)+left));
	swap(A[p],A[left]);
	int temp=A[left];
	while(left<right){
		while(left<right && A[right]>temp) right--;
			A[left] = A[right];
		while(left<right && A[left]<=temp) left++;
			A[right] = A[left];
	}
	A[left] = temp;
	return left;
}
void randSelect(int A[],int left,int right,int K){
	if(left == right) return; //边界
	int p = randPartition(A,left,right);
	int M = p-left+1; //第M大个数
	if(K == M) return;
	if(K<M){
		randSelect(A, left, p-1, K);
	} else {
		randSelect(A, p+1, right, K-M);
	}
}
int main(){
	srand((unsigned)time(NULL));
	scanf("%d",&n);
	int sum=0,sum1=0; //总和，分割后左子区间的和
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		sum+=A[i]; 
	}
	randSelect(A,0,n-1,n/2); //分割
	for(int i=0;i<n/2;i++){
		sum1+=A[i];
	} 
	printf("两个自区间最大的差为：%d",sum-sum1-sum1);
	getchar();
	getchar();
	return 0; 
}
