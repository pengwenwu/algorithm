//���һ�����ڵ���x��Ԫ�ص�λ��
//ʹ�ö��ַ� 
#include <cstdio>
//�����ֵ[0,n]����λ��һ������ 
int lower_bound(int A[],int left,int right,int x){
	int mid; 
	while(left<right){
		mid = left + (right-left)/2;
		if(A[mid] >= x){
			right = mid;
		} else {
			left = mid+1;
		}
	}
	return left;
}
int main(){
	int A[10]= {1,3,7,7,7,8,10,11,12,15};
	printf("%d",lower_bound(A,0,10,7));
	getchar();
}
