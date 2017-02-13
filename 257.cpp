//´´½¨Á´±í
#include <cstdio>
#include <cstdlib>
struct node{
	int data;
	node* next;
};

node* createNode(int arr[]){
	node* head, *p, *pre;
	head = new node;
	head->next= NULL;
	pre = head;
	for(int i=0;i<5;i++){
		p = new node;
		p->data = arr[i];
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	return head;
}
int main(){
	int arr[5] = {1,2,3,4,5};
	node* L = createNode(arr);
	L=L->next;
	while(L != NULL){
		printf("%d ",L->data);
		L = L->next;
	}
	return 0;	
}
