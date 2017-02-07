//求第一个大于等于x的元素的位置
//使用二分法 
#include <cstdio>
//传入初值[0,n]，该位置一定存在 
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
