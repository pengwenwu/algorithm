#include <cstdio>
const int maxn = 30;
int n,V,maxValue=0; //件数n，背包容量V，最大价值maxValue
int w[maxn],c[maxn]; //w[i]为每件物品的重量，c[i]为每件物品的价值
void DFS(int index, int sumW,int sumC){
	if(index == n){ //死胡同 
		return;
	}
	//岔道口 
	DFS(index+1, sumW,sumC); //不选第index件物品
	if(sumW+w[index]<=V){
		if(sumC+c[index]>maxValue){
			maxValue = sumC+c[index];
		}
		DFS(index+1,sumW+w[index],sumC+c[index]); 
	}
	
}
int main(){
	scanf("%d%d",&n,&V);
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	DFS(0,0,0); //初始为第0件物品，当前总重量和总价值为0
	printf("%d\n",maxValue);
	return 0; 
}
