#include <cstdio>
#include <queue>
using namespace std;
const int maxn=100;
int n,m; //n*m矩阵
int A[maxn][maxn]; //01矩阵
int X[4]={0,0,1,-1};//相邻点 
int Y[4]={1,-1,0,0}; 
bool isqueue[maxn][maxn] = {false}; //是否入列 
struct node{
	int x;
	int y;
}Node;

bool judge(int x,int y){
	if(x<0||x>=n||y<0||y>=m) return false;
	if(A[x][y] ==0 || isqueue[x][y] == true) return false;
	return true;
}

void BFS(int x,int y){
	queue<node> Q;
	Node.x= x,Node.y=y;
	Q.push(Node);
	isqueue[x][y] = true;
	while(!Q.empty()){
		node top = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int NewX = top.x+X[i];
			int NewY = top.y+Y[i];
			if(judge(NewX,NewY)){
				Node.x=NewX,Node.y=NewY;
				Q.push(Node);
				isqueue[NewX][NewY] = true;
			}
		}	
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			scanf("%d",&A[x][y]);
		}
	}
	int ans = 0;
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			if(A[x][y]==1 && isqueue[x][y] == false){
				ans++;
				BFS(x,y);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
  
