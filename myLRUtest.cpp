#include "lru.h""
using namespace std;
void test() {
	LRU<int, char> cache(2);
	bool res;
	cache.find(4, res);
	if(res) cout<<"4"<<endl;
	cache.insert(4, 'd');
	cache.find(4, res);
	if(res) cout<<"44"<<endl;
	cache.insert(1,'t');
	cache.find(4, res);
	if(res) cout<<"444"<<endl;
	cache.insert(1,'q');
	cache.find(4, res);
	if(res) cout<<"4444"<<endl;
	cache.insert(2,'m');
	cache.find(1, res);
	if(res) cout<<"1"<<endl;
	cout<<cache.find(6,res);



	cache.reportStat();
}
#include "H2O.h"
int main() {
	//test();
	H2O();
}