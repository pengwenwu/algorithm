#include <cstdio>
const int maxn = 11;
//���1~n��ȫ����
int n, P[maxn], hashTable[maxn] = {false};

void generateP(int index){
	if(index == n+1){
		for(int i=1;i<=n;i++){
			printf("%d", P[i]);
		}
		printf("\n");
		return;
	}
	for(int x = 1;x<=n;x++){
		if(hashTable[x]==false){
			P[index] = x;
			hashTable[x] = true;
			generateP(index+1);
			hashTable[x] = false; //�ݹ鴦����֮�󣬽���ǰx�ͷ� 
		} 
	}
}

int main(){
		printf("������һ��������11��С��1����\n");
		scanf("%d",&n);
		//n =3;
		generateP(1);
		getchar();
		return 0;
} 

