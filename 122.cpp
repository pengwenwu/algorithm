#include <cstdio>
#include <cstring>
//最长回文前缀长度
int judge(char str[]){
	int len = strlen(str);
	int j=len-1;
	int i=0,count=0;
	while(i < j){
		if(str[i] == str[j]){
			i++;
			j--;
		} else {
			count++;
			i=0;
			j = len-1-count;
		}
	}
	if(i==j){
		return 2*i+1;
	} else {
		return 2*i;
	}
}
int main(){
	char str[100];
	gets(str);
	printf("%d",judge(str));
	getchar();
}
