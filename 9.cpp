#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=10010;
int A[maxn],n; //���飬���鳤�� 
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
	if(left == right) return; //�߽�
	int p = randPartition(A,left,right);
	int M = p-left+1; //��M�����
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
	int sum=0,sum1=0; //�ܺͣ��ָ����������ĺ�
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
		sum+=A[i]; 
	}
	randSelect(A,0,n-1,n/2); //�ָ�
	for(int i=0;i<n/2;i++){
		sum1+=A[i];
	} 
	printf("�������������Ĳ�Ϊ��%d",sum-sum1-sum1);
	getchar();
	getchar();
	return 0; 
}
