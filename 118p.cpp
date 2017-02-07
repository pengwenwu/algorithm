//n皇后问题，回溯法
#include <cstdio>
#include <cstdlib>
const int maxn = 11;
int count=0,n,P[maxn], hashTable[maxn]={false};
void generateP(int index){
	if(index == n+1){//递归边界 
		count++;
		return;
	}
	for(int i=1;i<=n;i++){ //行 
		if(hashTable[i] == false){//当前行还没有皇后 
			bool flag = true; //flag为true代表当前皇后与之前的没有冲突
			for(int pre=1;pre<index;pre++){ //遍历之前的皇后 
				if(abs(index-pre) == abs(i-P[pre])){
					flag = false;
					break; //有冲突，循环终止 
				}
			}
			if(flag){ //没有冲突 
				P[index] = i;
				hashTable[i] = true;
				generateP(index+1);
				hashTable[i] = false;
			} 
			
		}
	}
	/*
	if(index == n+1){
		bool flag = true;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(i-j) == abs(P[i]-P[j])){
					flag = false;
				}
			}
		}
		if(flag) count++;
		return;
	}
	for(int x=1;x<=n;x++){
		if(hashTable[x] == false){
			P[index] = x;
			hashTable[x] = true;
			generateP(index+1);
			hashTable[x] = false;
		}
	}*/
}
int main(){
	n =5;
	generateP(1); //从1开始
	printf("方案总数为：%d",count);
	getchar(); 
	return 0;
}
