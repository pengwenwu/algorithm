#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Student{
	char id[15];	//׼��֤��
	int score;	//����
	int location_number;//������
	int local_rank;	//�����ڵ����� 
}stu[3000];
bool cmp(Student a, Student b){
	if(a.score != b.score) 
		return a.score>b.score;	//�����ɸߵ�������
	else 	
		return strcmp(a.id, b.id)<0;	//������ͬ����׼��֤�Ŵ�С�������� 
} 
int main(){
	int n,k,num=0;	//num����ѧ������
	scanf("%d",&n);	//n ��������	
	for(int i=1;i<=n;i++){
		scanf("%d",&k);	//ÿ�������ڵ�����
		for(int j=0;j<k;j++){
			scanf("%s %d",stu[num].id, &stu[num].score);
			stu[num].location_number = i;	//������ 
			num++;
		}
		sort(stu + num - k, stu+num, cmp);//ÿ��������ѧ����Ӧ�������±�Ϊ[num-k,num)
		stu[num-k].local_rank = 1;	//�����ڵ�һ����local_rankΪ1 
		for(int j=num-k+1;j<num;j++){	//ʣ��ѧ�� 
			if(stu[j].score == stu[j-1].score){	//����һ��ѧ��������ͬ 
				stu[j].local_rank=stu[j-1].local_rank;	//��ͬ��������ͬ 
			} else {
				stu[j].local_rank=j-(num-k)+1;//��ǰ�±�+1 
			} 
		} 		 
	} 
	printf("%d\n",num);	//�����ǰѧ������
	sort(stu, stu+num, cmp);//����ǰ����ѧ������;
	int r=1;	//��ǰ��������
	for(int i=0;i<num;i++){
		if(i>0 && stu[i].score != stu[i-1].score){//��ǰ������ǰһ�������ɼ���ͬ 
			r = i+1;	//��ô��������Ϊ��ǰ�±�+1 
		}
		printf("%s %d %d %d\n",stu[i].id,r,stu[i].location_number, stu[i].local_rank);
	} 
	getchar();
	getchar();
	return 0;
}

