//n�ʺ����⣬���ݷ�
#include <cstdio>
#include <cstdlib>
const int maxn = 11;
int count=0,n,P[maxn], hashTable[maxn]={false};
void generateP(int index){
	if(index == n+1){//�ݹ�߽� 
		count++;
		return;
	}
	for(int i=1;i<=n;i++){ //�� 
		if(hashTable[i] == false){//��ǰ�л�û�лʺ� 
			bool flag = true; //flagΪtrue����ǰ�ʺ���֮ǰ��û�г�ͻ
			for(int pre=1;pre<index;pre++){ //����֮ǰ�Ļʺ� 
				if(abs(index-pre) == abs(i-P[pre])){
					flag = false;
					break; //�г�ͻ��ѭ����ֹ 
				}
			}
			if(flag){ //û�г�ͻ 
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
	generateP(1); //��1��ʼ
	printf("��������Ϊ��%d",count);
	getchar(); 
	return 0;
}
