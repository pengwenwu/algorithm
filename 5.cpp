#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct Student{
	char id[15];	//准考证号
	int score;	//分数
	int location_number;//考场号
	int local_rank;	//考场内的排名 
}stu[3000];
bool cmp(Student a, Student b){
	if(a.score != b.score) 
		return a.score>b.score;	//分数由高到低排列
	else 	
		return strcmp(a.id, b.id)<0;	//分数相同按照准考证号从小到大排列 
} 
int main(){
	int n,k,num=0;	//num代表学生数量
	scanf("%d",&n);	//n 考场数量	
	for(int i=1;i<=n;i++){
		scanf("%d",&k);	//每个考场内的人数
		for(int j=0;j<k;j++){
			scanf("%s %d",stu[num].id, &stu[num].score);
			stu[num].location_number = i;	//考场号 
			num++;
		}
		sort(stu + num - k, stu+num, cmp);//每个考场内学生对应的数组下标为[num-k,num)
		stu[num-k].local_rank = 1;	//考场内第一名的local_rank为1 
		for(int j=num-k+1;j<num;j++){	//剩余学生 
			if(stu[j].score == stu[j-1].score){	//与上一个学生分数相同 
				stu[j].local_rank=stu[j-1].local_rank;	//相同则排名相同 
			} else {
				stu[j].local_rank=j-(num-k)+1;//当前下标+1 
			} 
		} 		 
	} 
	printf("%d\n",num);	//输出当前学生总数
	sort(stu, stu+num, cmp);//将当前所有学生排序;
	int r=1;	//当前考生排名
	for(int i=0;i<num;i++){
		if(i>0 && stu[i].score != stu[i-1].score){//当前考生与前一个考生成绩不同 
			r = i+1;	//那么他的排名为当前下标+1 
		}
		printf("%s %d %d %d\n",stu[i].id,r,stu[i].location_number, stu[i].local_rank);
	} 
	getchar();
	getchar();
	return 0;
}

