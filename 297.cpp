//根据后序序列和中序序列，求二叉树的层次遍历
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=30;
int post[maxn],in[maxn]; //后序序列，中序序列
int n; //节点个数
struct node{
	int data;
	node* lchild;
	node* rchild;
};
node* create(int postL,int postR, int inL, int inR){
	if(postL>postR) return NULL;
	node* root = new node;
	root->data=post[postR];
	int k;
	for(k=inL; k<=inR;k++){
		if(post[postR] == in[k]) break; 
	}
	int numberLeft = k-inL;
	root->lchild = create(postL, postL+numberLeft-1,inL, k-1);
	root->rchild = create(postL+numberLeft, postR-1, k+1, inR);
	return root;
}
int num=0;//已输出节点个数 
void BFS(node* root){
	queue<node*> Q;
	Q.push(root);
	while(!Q.empty()){
		node* now = Q.front();
		Q.pop();
		printf("%d",now->data);
		num++;
		if(num<n) printf(" ");
		if(now->lchild != NULL) Q.push(now->lchild);
		if(now->rchild != NULL) Q.push(now->rchild);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	node* root = create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}

