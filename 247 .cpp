#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <map>
using namespace std;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
int main(){
	string str;
	char n[];
	queue<int> num; //Êý×Ö¶ÓÁÐ 
	stack<int> op; 	//·ûºÅÕ» 
	map<char, int> mp;
	mp['+'] = mp['-'] = 1;
	mp['*'] = mp['/'] = 2;
	
	while(getline(cin,str), str != "0"){
		for(int i=0;i<str.length(); i++ ){
			if(str[i] >='0' && str[i]<='9'){
				
			}
		}
	}
	
	return 0;
}
