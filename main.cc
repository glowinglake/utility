#include <stdio.h>
#include "myString.h"
#include <iostream>
using namespace std;

int main() {
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