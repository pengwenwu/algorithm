#include <cstdio>
#include <cstring>
const int maxn = 10010;
char str[maxn]; //�ַ��� 
int leftP[maxn] = {0}; //ÿһλ��ߣ�����p�ĸ��� 
int main(){
	gets(str);
	int len = strlen(str);
	for(int i=0;i<len ;i++){
		if(i>0){ //������λ 
			leftP[i] = leftP[i-1];
		}
		if(str[i]=='P'){
			leftP[i]++;
		} 
	}
	int ans=0,rightT=0;//������ұ�T�ĸ���
	for(int i=len-1; i>=0;i--){
		if(str[i]=='T'){
			rightT++;
		} else if(str[i]=='A'){
			ans+=leftP[i]*rightT;
		}
	}
	printf("%d",ans);
	getchar(); 
	return 0;
}
