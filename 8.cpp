#include <cstdio>
#include <cstring>
const int maxn = 10010;
char str[maxn]; //字符串 
int leftP[maxn] = {0}; //每一位左边（含）p的个数 
int main(){
	gets(str);
	int len = strlen(str);
	for(int i=0;i<len ;i++){
		if(i>0){ //不是首位 
			leftP[i] = leftP[i-1];
		}
		if(str[i]=='P'){
			leftP[i]++;
		} 
	}
	int ans=0,rightT=0;//结果，右边T的个数
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
