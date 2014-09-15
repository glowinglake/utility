#include <stdio.h>
#include "myString.h"
#include "myHash.h"
#include "utility/prefixTree.h"
#include <string>
#include <iostream>
using namespace std;
#if 0
int testString() {
	myString s;
	myString s2("dsf");
	cout<<s.length()<<s2.length()<<s2.value();
	s=s2;
	s[2]='t';
	s.push_back('q');
	cout<<s.value()<<s.length()<<endl;
	cout<<s.push_back('x').value()<<endl;;
	myString s3;
	s3=(s+s2);
	cout<<s3.value()<<"  "<<s3.length()<<endl;
	myString nil;
	s3=s3+nil;
	cout<<s3.value()<<"  "<<s3.length()<<endl;
};

int testHash() {
	Hash<int,int> h;
	cout<<h.size()<<endl;
	h.put(444,0);
	if(h.find(4) != h.end())
		cout<<"found"<<endl;
	cout<<h.find(4);
	return 0;
}
void testTrie() {
	prefixTree tree;
	string a="haha";
	string b="hahaba";
	tree.insert(a);
	vector<string> ret = tree.find(a);
	cout<<"size="<<ret.size()<<endl;
};
#endif
class O{
	public:
	~O () {
		cout<<"O dest"<<endl;
	}
};
double division(int a, int b)
{
	O o;
   if( b == 0 )
   {
      throw "Division by zero condition!";
   }
   return (a/b);
}
O foo() {
	O o1;
	//O o2;
	return o1;
}
int main ()
{
   int x = 50;
   int y = 0;
   double z = 0;
 	//O myO;
   O o = foo();
   cout<<"1"<<endl;
   return 0;
}