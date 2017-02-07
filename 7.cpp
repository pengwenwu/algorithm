#include <cstdio>
int main(){
	int x=0;
	while(x>=0){
		if(x%5==1 && x%6==5 && x%7==4 && x%11==10){
			printf("%d",x);
			break;
		}
		x++;		
	}
	
	getchar();
	return 0;
}
