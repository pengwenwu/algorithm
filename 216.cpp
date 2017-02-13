//mapÓ³ÉäÖĞµÄeraseÉ¾³ı
#include <cstdio>
#include <map>
using namespace std;

int main(){
	map<char,int> mp;
	mp['b'] = 20;
	mp['c'] = 30;
	mp['a'] = 10;
	mp['d'] = 40;
	map<char,int>::iterator it = mp.find('c');
	mp.erase(it,mp.end());
	for(map<char,int>::iterator it=mp.begin();it != mp.end();it++){
		printf("%c %d\n",it->first,it->second);
	}
	return 0;
}
